/**//* 27.940.642-ROSSI,SebastianPablo-(05-1965) *//**/

#include "funciones.h"


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* FUNCIONES A DESARROLLAR                                            *//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//* PUNTO 2                                            *//**//**//**/

int  cargarCuadrMagico_MIO(int m[][TAM_MAT], int filas, int colum)
{
    unsigned int numero = 0;
    do
    {
        m[(filas*colum-numero+2*(numero/filas))%filas][(colum/2+numero-numero/colum)%colum] = numero+1;
    }while(++numero<filas*colum);

    return filas*colum;
}


int mostrarMat_MIO(int m[][TAM_MAT], int filas, int colum, FILE *fp)
{
    int i, j;
    int sumatoria = 0,
        totDiagP = 0,
        totDiagS = 0;

    for(i=0;i<filas;i++)
    {
        totDiagP += m[i][i];
        totDiagS += m[i][(colum-1)-i];
        for(j=0;j<colum;j++)
        {
            sumatoria += m[i][j];
            fprintf(fp,"%5d",m[i][j]);
        }
        fprintf(fp," %5d\n",sumatoria);
        sumatoria=0;
    }
    fprintf(fp,"\n");


    for(i=0;i<colum;i++)
    {
        for(j=0;j<filas;j++)
            sumatoria += m[j][i];
        fprintf(fp,"%5d",sumatoria);
        sumatoria=0;
    }
    fprintf(fp," %5d%5d\n\n",totDiagP,totDiagS);

    return filas*colum;
}


/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

