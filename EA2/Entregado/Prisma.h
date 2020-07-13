/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* 27.940.642-ROSSI,SebastianPablo-(05-1965) *//**/
/**//**   DEBE MODIFICAR LA LÍNEA DE COMENTARIO ANTERIOR CON SUS DATOS   **//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**         COMPLETE LA DECLARACIÓN DE LA CLASE          **//**//**//**/

#ifndef PRISMA_H_
#define PRISMA_H_

#include <iostream>
#include <string>

using namespace std;

class Prisma
{
private:
    int alto;
    int ancho;
    int profundidad;
    string color;     /// <--preferentemente, de lo contrario:  char *color;

public:
    // constructores
    Prisma(string = "Incoloro",int = 1, int = 1, int = 1);
    Prisma(const Prisma &);
    Prisma &operator=(const Prisma&);
    Prisma &operator--();
    Prisma operator++(int);
    friend Prisma operator*(const int&, const Prisma&);
    friend ostream& operator<<(ostream&, const Prisma &);
};


#endif // PRISMA_H_

