#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//*  PUNTO 1                                                           *//**/

int buscarYReemplazar(char *cade, int tamCade,
                      const char *busc, const char *reem);

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//*  PUNTO 2                                                           *//**/
/// con hasta un máximo de 27 tendrá una salida legible por pantalla / archivo
/// TAM_MAT   debe ser IMPAR y mayor o igual a 3 (tres)

#define TAM_MAT     3

int  mostrarMat(int m[][TAM_MAT], int filas, int colum, FILE *fp);

int  cargarCuadrMagico(int m[][TAM_MAT], int filas, int colum);

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//*  PUNTO 3                                                           *//**/

#define ARCH_PRODUCTOS      "produc"
#define ARCH_PEDIDOS        "pedido"
#define ARCH_PENDIENTES     "pendie"
#define ARCH_MAYORES        "mayor.txt"
#define ARCH_MENORES        "menor.txt"

int  abrirLosArchivos(FILE **fpPedi, const char *nomPedi, const char *modoPedi,
                      FILE **fpPend, const char *nomPend, const char *modoPend,
                      FILE **fpMayo, const char *nomMayo, const char *modoMayo,
                      FILE **fpMeno, const char *nomMeno, const char *modoMeno,
                      FILE *fpPant);

int  mostrarPediOPend(const char *nomPediOPend, FILE *fpPant);



typedef struct
{
    char    codClie[11],
            codProd[11];
    int     cant;
    double  precUnit;
} tPedi;

#define MAYOR_QUE       50000.00

int  procesarPedidos(FILE *fpPedi, FILE *fpPend, FILE *fpMayo, FILE *fpMeno,
                     FILE *fpPant);

void mostrarListados(const char *nomArch, FILE *fpPant);

/* --------------------------------o---x---o--------------------------------
 *          para la pila con asignación DINÁMICA de memoria
 * --------------------------------o---x---o-------------------------------- */
typedef struct sNodo
{
    void           *info;
    unsigned        tamInfo;
    struct sNodo   *sig;
} tNodo;
typedef tNodo *tPila;

void crearPila(tPila *p);

int  pilaLlena(const tPila *p, unsigned cantBytes);

int  ponerEnPila(tPila *p, const void *d, unsigned cantBytes);

int  verTope(const tPila *p, void *d, unsigned cantBytes);

int  pilaVacia(const tPila *p);

int  sacarDePila(tPila *p, void *d, unsigned cantBytes);

void vaciarPila(tPila *p);



/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES A DESARROLLAR                                            *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//* PUNTO 1                                            *//**//**//**/

int buscarYReemplazar_MIO(char *cade, int tam,
                          const char *busc, const char *reem);

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//* PUNTO 2                                            *//**//**//**/

int  cargarCuadrMagico_MIO(int m[][TAM_MAT], int filas, int colum);

int mostrarMat_MIO(int m[][TAM_MAT], int filas, int colum, FILE *fp);

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//* PUNTO 3                                            *//**//**//**/

int  procesarPedidos_MIO(FILE *fpPedi, FILE *fpPend, FILE *fpMayo, FILE *fpMeno,
                         FILE *fpPant);

void crearPila_MIO(tPila *p);

int  pilaLlena_MIO(const tPila *p, unsigned cantBytes);

int  ponerEnPila_MIO(tPila *p, const void *d, unsigned cantBytes);

int  verTope_MIO(const tPila *p, void *d, unsigned cantBytes);

int  pilaVacia_MIO(const tPila *p);

int  sacarDePila_MIO(tPila *p, void *d, unsigned cantBytes);

void vaciarPila_MIO(tPila *p);


#endif // FUNCIONES_H_

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

