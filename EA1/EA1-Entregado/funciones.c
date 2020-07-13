
#include "funciones.h"
#define aMinusculas(x) ((x)>='A'&&(x)<='Z'?(x)+32:(x))
#define minimo(A,B) ((A)<(B)?(A):(B))

#define ERROR_PONER_EN_PILA -3
#define ERROR_SACAR_DE_PILA -4

int corregir_linea(char *);
int cantidad_palabras(const char *);
int palabra_mas_larga(const char *);
int valor_caracteres(const char *);
int mayor(const char *, const char *);



/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES A DESARROLLAR                                            *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

int contarOcurrencias1_MIO(const char *cad, const char *sub)
{
    char *inicioSub = sub;
    char *inicioCad = cad;
    int contador = 0;

    if(!*sub)
        return 1;

    while(*inicioCad != '\0')
    {
        while(aMinusculas(*sub) == aMinusculas(*cad))
        {
            sub++;
            cad++;
            if(*sub == '\0')
                contador++;
        }
        inicioCad++;
        cad = inicioCad;
        sub = inicioSub;
    }

    return contador;
}

int contarOcurrencias2_MIO(const char *cad, const char *sub)
{
    char *inicioSub = sub;
    char *inicioCad = cad;
    int contador = 0;

    if(!*sub)
        return 1;

    while(*inicioCad != '\0')
    {
        while(aMinusculas(*sub) == aMinusculas(*cad))
        {
            sub++;
            cad++;
            if(*sub == '\0')
            {
                contador++;
                inicioCad = cad-1;
            }
        }
        inicioCad++;
        cad = inicioCad;
        sub = inicioSub;
    }
    return contador;
}

void rotarMat180_MIO(int m[][COLUM], int filas, int colum)
{
    int aux;
    int *inicio = *m;
    int *fin = *(m+filas-1)+colum-1;

    while(inicio<fin)
    {
        aux = *inicio;
        *inicio=*fin;
        *fin=aux;

        inicio++;
        fin--;
    }
}


int  mostrarMatTriangDerInf_MIO(int m[][COLUM], int filas, int colum)
{
    int fin = colum-1;
    int datos = 0;
    int i=0, j;


    for(i;i<filas;i++)
    {
        if(fin==-1)
            fin=0;

        if(fin)
            printf("%*c", (fin)*4, ' ');

        for(j=fin;j<colum;j++)
        {
            datos++;
            printf("%4d", m[i][j]);
        }
        fin--;
        printf("\n");
    }
    return datos;
}


int cantidad_palabras(const char *linea)
{
    int contador=0, bandera=0;

    while(*linea!='\0' || *linea!='\n')
    {
        while(*linea!=' ' && *linea!='\0' && *linea!='\n')
        {
            linea++;
            bandera=1;
        }
        if(bandera)
        {
            contador++;
            bandera=0;
        }
        if(*linea=='\0')
            return contador;
        linea++;
    }
    return contador;
}


int palabra_mas_larga(const char *linea)
{
    int palabra=0, letras=0;

    while(*linea!='\0' || *linea!='\n')
    {
        while(*linea!=' ' && *linea!='\0' && *linea!='\n')
        {
            letras++;
            linea++;
        }
        if(letras>palabra)
        {
            palabra=letras;
            letras=0;
        }
        if(*linea=='\0')
            return palabra;
        linea++;
    }
    return palabra;
}

int valor_caracteres(const char *linea)
{
    int contador = 0;
    while(*linea!='\n' && *linea!='\0')
    {
        contador+=(int)*linea;
        linea++;
    }
    return contador;
}

int mayor(const char *linea, const char *lineaAux)
{

    int cantPalabrasA, cantPalabrasB;
    int palabraLargaA, palabraLargaB;

    cantPalabrasA = cantidad_palabras(linea);
    cantPalabrasB = cantidad_palabras(lineaAux);

    palabraLargaA = palabra_mas_larga(linea);
    palabraLargaB = palabra_mas_larga(lineaAux);

    if(cantPalabrasA!=cantPalabrasB)
        return cantPalabrasA>cantPalabrasB;

    if(palabraLargaA!=palabraLargaB)
        return palabraLargaA > palabraLargaB;

    return valor_caracteres(linea)>valor_caracteres(lineaAux);

}

int corregir_linea(char *linea)
{
    char *inicio = linea;
    while(*linea!='\0' )
        linea++;
    linea--;
    if(*linea!='\n')
    {
        linea++;
        *linea = '\n';
        linea++;
        *linea = '\0';
        linea=inicio;
        return 1;
    }
    return 0;
}


int  ordenarArchivo_MIO(const char *archEnt, const char *archSal)
{
    char linea[100], lineaAux[100];
    FILE *entrada;
    FILE *salida;
    tPila pila1, pila2;
    int bandera=0;

    if(!(entrada = fopen(archEnt, "rt")))
        return ERROR_ARCH_ENT;

    crearPila_MIO(&pila1);
    crearPila_MIO(&pila2);



    while(fgets(linea, sizeof(linea), entrada))
    {
        corregir_linea(linea);

        if(pilaVacia_MIO(&pila1))
        {
            if(!ponerEnPila_MIO(&pila1, linea, sizeof(linea)))
                return ERROR_PONER_EN_PILA;
        }
        else
        {
            verTope_MIO(&pila1, &lineaAux, sizeof(lineaAux));

            while(!pilaVacia_MIO(&pila1) && mayor(linea, lineaAux))
            {
                if(!sacarDePila_MIO(&pila1, lineaAux, sizeof(lineaAux)))
                    return ERROR_SACAR_DE_PILA;

                if(!ponerEnPila_MIO(&pila2, lineaAux, sizeof(lineaAux)))
                    return ERROR_PONER_EN_PILA;

                verTope_MIO(&pila1, &lineaAux, sizeof(lineaAux));


                bandera = 1;

            }

            if(!pilaVacia_MIO(&pila2) && !bandera)
            {

                verTope_MIO(&pila2, &lineaAux, sizeof(lineaAux));

                while(!pilaVacia_MIO(&pila2) && mayor(lineaAux,linea))
                {
                    if(!sacarDePila_MIO(&pila2, &lineaAux, sizeof(lineaAux)))
                        return ERROR_SACAR_DE_PILA;

                    if(!ponerEnPila_MIO(&pila1, &lineaAux, sizeof(lineaAux)))
                        return ERROR_PONER_EN_PILA;

                    verTope_MIO(&pila2, &lineaAux, sizeof(lineaAux));

                }
            }

            if(!ponerEnPila_MIO(&pila1, linea,sizeof(linea)))
                return ERROR_PONER_EN_PILA;

            bandera = 0;
        }
    }


    fclose(entrada);

    while(!pilaVacia_MIO(&pila2))
    {
        if(!sacarDePila_MIO(&pila2, &lineaAux, sizeof(lineaAux)))
            return ERROR_SACAR_DE_PILA;

        if(!ponerEnPila_MIO(&pila1, &lineaAux, sizeof(lineaAux)))
            return ERROR_PONER_EN_PILA;
    }



    if(!(salida = fopen(archSal, "wt")))
    {
        // no se abrio el archivo
        while(!pilaVacia(&pila1))
        {
            if(!sacarDePila_MIO(&pila1, linea, sizeof(linea)))
                return ERROR_SACAR_DE_PILA;
            else
                printf("%s",linea);
        }
        return ERROR_ARCH_SAL;
    }
    else
    {
        // se pudo abrir el archivo
        while(!pilaVacia(&pila1))
        {
            if(!sacarDePila_MIO(&pila1, linea, sizeof(linea)))
                return ERROR_SACAR_DE_PILA;
            else
                fprintf(salida,linea);
        }
    }

    fclose(salida);

    return 1;
}



void crearPila_MIO(tPila *p)
{
    p->tope = TAM_PILA;
}

int  pilaLlena_MIO(const tPila *p, unsigned cantBytes)
{
    return p->tope < cantBytes+sizeof(unsigned);
}

int  ponerEnPila_MIO(tPila *p, const void *d, unsigned cantBytes)
{

    if(p->tope < cantBytes + sizeof(unsigned))
        return 0;

    p->tope -= cantBytes;
    memcpy(p->pila+p->tope, d, cantBytes);

    p->tope-=sizeof(unsigned);
    memcpy(p->pila + p->tope, &cantBytes, sizeof(unsigned));

    return 1;
}

int  verTope_MIO(const tPila *p, void *d, unsigned cantBytes)
{
    unsigned tamInfo;
    if(p->tope == TAM_PILA)
        return 0;

    memcpy(&tamInfo, p->pila + p->tope, sizeof(unsigned));
    memcpy(d,p->pila+p->tope+sizeof(unsigned),minimo(cantBytes, tamInfo));
    return 1;
}

int  pilaVacia_MIO(const tPila *p)
{
    return p->tope == TAM_PILA;
}


int sacarDePila_MIO(tPila *p, void *d, unsigned cantBytes)
{
    unsigned tamInfo;
    if(p->tope == TAM_PILA)
        return 0;
    memcpy(&tamInfo, p->pila+p->tope, sizeof(unsigned));
    p->tope+=sizeof(unsigned);
    memcpy(d, p->pila+p->tope, minimo(cantBytes,tamInfo));
    p->tope += tamInfo;

    return 1;
}



void vaciarPila_MIO(tPila *p)
{
    p->tope = TAM_PILA;
}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
