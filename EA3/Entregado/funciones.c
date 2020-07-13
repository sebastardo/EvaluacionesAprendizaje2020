/**//* 27.940.642-ROSSI,SebastianPablo-(05-1965) *//**/


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
#include <stdlib.h>
#include <math.h>
#include <string.h>


/**//**//* CUALQUIER INCLUDE DE BIBLIOTECA QUE NECESITE, HÁGALO ACÁ   *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
#include "funciones.h"
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//* ACÁ DEBE DESARROLLAR LAS FUNCIONES Y PRIMITIVAS PEDIDAS    *//**//**/
/**//**//* ADEMÁS DE CUALQUIER OTRA FUNCIÓN QUE SE REQUIERA           *//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES Y PRIMITIVAS A DESARROLLAR                               *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* para la información                                                *//**/

void mostrarFinal_MIO(const void *d, FILE *fp)
{
    const tFinal *dato = (const tFinal *) d;

    if(dato)
        fprintf(fp, "%-11s%-31s%4d%3d\n", dato->dni,
                                             dato->apYNom,
                                             dato->codMat,
                                             dato->calif);
    else
        fprintf(fp, " %-10s%-31s%-4s%4s\n", "D. N. I.","Apellido(s), Nombre(s)","CodM", "Cal");
}


int  compararFinal_MIO(const void *d1, const void *d2)
{
    char *daux1 = ((tFinal *)d1)->dni;
    char *daux2 = ((tFinal *)d2)->dni;

    return strcmp(daux1, daux2);
}


int  acumularCalif_MIO(void **dest, unsigned *tamDest,
                       const void *orig, unsigned tamOrig)
{
    tFinal **d = (tFinal **)dest;
    tFinal *o  = (tFinal *)orig;

    (*d)->calif += o->calif;

    return 1;
}


void mostrarProm_MIO(const void *d2, int cantCalif, FILE *fp)
{
    fprintf(fp, "   --- Rindio %2d final(es) con un promedio de: %2.0f\n\n",
                        cantCalif, round(((tFinal *)d2)->calif/(float)cantCalif));
}




tNodo *buscaMayor(tNodo *nodo, int (*comparar)(const void *, const void *))
{
    /**
     * Funcion para buscar el dato que mas veces se repite
     */

    tNodo *comp, *aux, *mayor;
    int comparado, cant, max;

    // si el nodo llega vacio, el mayor devuelto sera NULL
    if(!nodo)
        return NULL;



    /*
     * comp: el dato contra el que se comprara
     * aux: el dato comparado
     * mayor: dato que mas veces se repite
     * cant: cantidad de repeticiones
     * max: la cantidad de repeticiones del dato que mas veces se repite
     * comparado: auxiliar para comprobar si no es un dato que ya se controlo
     */
    comp=nodo;
    aux=comp->ant;
    mayor = NULL;
    cant = 0;
    max = 0;
    comparado = 0;



    // buscara el mayor mientras no sea nulo
    while(comp)
    {
        // si el dato no fue controlado, no debe
        // aparecer antes de si mismo, si aparece
        // no se lo verifica
        while(aux && !comparado)
        {
            if(!comparar(comp->info, aux->info))
                comparado=1;
            aux = aux->ant;
        }

        aux = comp;


        // si el dato no fue controlado anteriormente
        // se empieza a contar sus apariciones
        while(aux && !comparado)
        {
            if(!comparar(comp->info, aux->info))
                cant++;
            aux = aux->sig;
        }

        // si el dato fue el que mas veces se repitio,
        // se lo guarda en mayor y sus repeticiones en max
        if(cant>max)
        {
            max = cant;
            mayor = comp;
        }

        // se resetea
        cant = 0;
        comparado = 0;

        // aux para a ser el comparador para verificar
        // si no se lo controlo antes
        aux = comp;

        // se pasa a controlar al siguiente
        comp = comp->sig;
    }

    // encontrado el que mas se repite, se lo devuelve
    return mayor;
}




/**//* para el TDA LISTA                                                  *//**/

int  mostrarDeIzqADer_MIO(const tLista *p,
                          void(*mostrar)(const void *, FILE *), FILE *fp)
{
    tNodo   *act = *p;
    int     cant = 0;

    if(act)
    {
        // muestra titulo
        mostrar(NULL, fp);

        // pone puntero al comienzo de la lista
        while(act->ant)
            act = act->ant;

        // mientras el nodo tengo contenido lo mostrara
        while(act)
        {
            mostrar(act->info, fp);
            act = act->sig;
            cant++;
        }
    }
    return cant;
}


void ordenarLista_MIO(tLista *p, int (*comparar)(const void *, const void *))
{
    /**
     * para ordenar la lista, primero se buscara el dni que aparezca mas veces
     * respetando su orden cronologico y se lo comparara con toda la lista
     * poniendo todos los que son iguales a él antes del inicio.
     * El inicio se ira moviendo para no buscar repetidos y terminara el orden
     * cuando sea NULL
     */


    tNodo   *inicio = *p,
            *aux,
            *mayor,
            *proximo;


    //si la lista esta vacia, termina la primitiva
    if(!inicio)
        return;

    // pone el puntero al comienzo de la lista
    while(inicio->ant)
        inicio = inicio->ant;


    /*
     * siempre que se busque el mayor
     */
    aux = inicio;
    mayor = buscaMayor(aux, comparar);



    while(mayor)
    {
        // si el dni del nodo actual es igual al dni
        // del nodo que mas veces se repite (en este caso)
        // se procede a ordenar
        if(!comparar(aux->info, mayor->info))
        {

            // si uno de los datos a ordenan esta en inicio
            // se correra inicio hacia el siguiente, para que
            // los datos del grupo se detras de él y delante
            // del que fue ingresado antes cuando se armo la lista
            if(aux==inicio)
            {
                inicio=inicio->sig;
                aux=inicio;
            }
            else
            {
                // como el dato esta en medio de la lista
                // de lo mover antes de inicio

                // se guarda el proximo a aux para no tener
                // que recorrer toda la lista nuevamente y
                // poder seguir verificando desde ahi
                proximo = aux->sig;

                /** se pasa a acomodar los nodos entre los que esta el que se quitara **/
                // el siguiente del anterior a aux sera
                // el siguiente de aux
                aux->ant->sig = aux->sig;

                // si aux no es el ultimo nodo, el anterior
                // al siguiente de aux sera el anterior de aux
                if(aux->sig)
                    aux->sig->ant = aux->ant;

                /** se pasa a acomodar en el grupo el nodo **/
                // el anterior de aux sera igual al anterior de inicio
                aux->ant = inicio->ant;
                //el siguiente de aux sera inicio
                aux->sig = inicio;

                // si no es el comienzo de la lista, el siguiente del nodo que esta
                // antes de inicio, dejara de ser inicio y sera aux
                if(inicio->ant)
                    inicio->ant->sig = aux;

                // el anterior a inicio sera aux
                inicio->ant = aux;

                // aux pasa a ser el nodo que se guardo al comienzo para
                // continuar buscando
                aux=proximo;

            }
        }
        else
        {
            // si no es igual al mayor, se verifica con el proximo nodo
            aux=aux->sig;
        }


        // si se llega al final de la lista se pone al inicio y se busca
        // el proxima que mas veces se repita
        // inicio siempre se ira moviento, ya que algunas veces el mayor
        // estara en su posicion. Cuando llegue al final de la lista
        // inicio y aux sera NULL, se le pasa a funcion y devolvera NULL
        // terminando el bucle y el ordenamiento
        if(!aux)
        {
            aux = inicio;
            mayor = buscaMayor(aux, comparar);
        }

    }
}


int  vaciarMostrarDetalleYProm_MIO(tLista *p, FILE *fp,
                                   int (*comparar)(const void *, const void *),
                                   int (*acumular)(void **, unsigned *,
                                                   const void *, unsigned),
                                   void (*mostrar)(const void *, FILE *),
                                   void (*mostrar2)(const void *, int, FILE *))
{
    int cant = 0, promDivisor = 0;
    tNodo *act = *p;


    if (!act)
        return 0;

    while(act->ant)
        act = act->ant;

    while(act)
    {
        tNodo *aux = act->sig;

        // se muestra titulo y el primero dato
        mostrar(NULL,fp);
        mostrar(act->info,fp);

        promDivisor++;

        // act esta posicionado al incio de la lista
        // mientras en la lista haya informacion se ira borrando
        // como es por grupo, mientras el siguiente sea igual al
        // anterior, se imprime en archivo
        while(aux && !comparar(act->info, aux->info))
        {
            // se acumula en el primero, el de comparacion
            // que se borrara al final
            acumular(&act->info, &act->tamInfo,aux->info, aux->tamInfo);

            mostrar(aux->info,fp);


            /* La manera en que se hace el borrado es el siguiente
             * Comienza con lo nodos de esta manera:
             *
             * [] <=> {} <=> O
             * act   aux
             *
             * se realiza el primer cambio
             * y act pasa a apuntar al siguiente de aux
             *
             *    ----------->
             *   [] <- {} <=> O
             *   act  aux
            */

            act->sig = aux->sig;


            /*
             * ahora el siguiente de aux
             * pasa a apuntar a act
             *  ---------->
             * [] <- {} -> O
             *  <----------
             * act   aux
             */
            act->sig->ant = act;


            // se puede borrar aux
            free(aux->info);
            free(aux);

            /*
             * aux pasa a apuntar al que
             * era su siguiente
             *  [] <======> O
             *  act        aux
             */
            aux=act->sig;

            promDivisor++;
            cant++;

        }
        mostrar2(act->info,promDivisor,fp);

        // aux se apunta al primero del grupo
        // act se apunta a su siguiente, que no
        // ya que no era parte del grupo
        aux = act;
        act = act->sig;

        // se borra el nodo
        free(aux->info);
        free(aux);

        promDivisor=0;
        cant++;
    }
    // la lista queda vacia
    *p = NULL;

    return cant;
}

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

