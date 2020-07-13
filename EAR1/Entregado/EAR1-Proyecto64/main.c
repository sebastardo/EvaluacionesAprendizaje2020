
#include "main.h"

int main()
{

    FILE *fpPant = fopen("pantalla.txt", "wt");

    if(fpPant == NULL)      // si no puede abrir el archivo
        fpPant = stdout;        // mostrará por consola

        //FILE *fpPant = stdout;



    //probarMatrices(fpPant);

    probarArchivosYPila(fpPant);

    if(fpPant != stdout && fpPant != stderr && fpPant != NULL)
    {
        fclose(fpPant);
        system("start notepad pantalla.txt");
    }

    return 0;
}



void probarMatrices(FILE *fpPant)
{
    int     mat[TAM_MAT][TAM_MAT];

/**//**//**//**//**//**//**//**//**//**//**//**//**/
   cargarCuadrMagico_MIO(mat, TAM_MAT, TAM_MAT);
/**//**//**//**//**//**//**//**//**//**//**//**//**/
    fprintf(fpPant,
            "///////////////// Ini - Parte 2 /////////////////\n"
            "El cuadrado magico es:\n");
/**//**//**//**//**//**//**//**//**//**//**//**//**/
mostrarMat(mat, TAM_MAT, TAM_MAT, fpPant);
//    mostrarMat_MIO(mat, TAM_MAT, TAM_MAT, fpPant);
/**//**//**//**//**//**//**//**//**//**//**//**//**/
    fprintf(fpPant, "///////////////// Fin - Parte 2 /////////////////\n\n");
}


void probarArchivosYPila(FILE *fpPant)
{
    FILE   *fpPedi,
           *fpPend,
           *fpMayo,
           *fpMeno;

    fprintf(fpPant, "///////////////// Ini - Parte 3 /////////////////\n");
    int     retVal = abrirLosArchivos(&fpPedi, ARCH_PEDIDOS, "rb",
                                      &fpPend, ARCH_PENDIENTES, "wb",
                                      &fpMayo, ARCH_MAYORES, "wt",
                                      &fpMeno, ARCH_MENORES, "wt",
                                      fpPant);
    if(retVal)
    {
        fprintf(fpPant,
                "ERROR - abriendo %d archivo%s - Imposible seguir",
                retVal, retVal > 1 ? "s" : "");
        return;
    }
    mostrarPediOPend(ARCH_PEDIDOS, fpPant);
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
    //procesarPedidos(fpPedi, fpPend, fpMayo, fpMeno, fpPant));
  printf("QUE ES %d\n",procesarPedidos_MIO(fpPedi, fpPend, fpMayo, fpMeno, fpPant));
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
    fclose(fpPend);
    fclose(fpMayo);
    fclose(fpMeno);
    mostrarPediOPend(ARCH_PENDIENTES, fpPant);
    fprintf(fpPant, "///////////////// Fin - Parte 3 /////////////////\n");
}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

