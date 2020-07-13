/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//* 27.940.642-ROSSI,SebastianPablo-(05-1965) *//**/
/**//**   DEBE MODIFICAR LA LÍNEA DE COMENTARIO ANTERIOR CON SUS DATOS   **//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/
/**//**//**   DESARROOLLE LAS "FUNCIONES MIEMBRO" DE LA CLASE    **//**//**//**/

#include "Prisma.h"

Prisma::Prisma(string color, int alto, int ancho, int profundidad):
    alto(alto), ancho(ancho), profundidad(profundidad),color(color) {};


Prisma::Prisma(const Prisma &objeto)
{
    alto = objeto.alto;
    ancho = objeto.ancho;
    profundidad = objeto.profundidad;
    color = objeto.color;
}

Prisma& Prisma::operator=(const Prisma &objeto)
{
    alto = objeto.alto;
    ancho = objeto.ancho;
    profundidad = objeto.profundidad;
    color = objeto.color;

    return *this;
}

Prisma operator*(const int &numero, const Prisma &objeto)
{
    Prisma auxiliar(objeto.color,
                    objeto.alto * numero,
                    objeto.ancho * numero,
                    objeto.profundidad * numero);
    return auxiliar;
}


Prisma Prisma::operator++(int)
{
    Prisma temp(this->color, this->alto, this->ancho, this->profundidad);
    alto++;
    ancho++;
    profundidad++;
    return temp;
}

Prisma& Prisma::operator--()
{
    alto--;
    ancho--;
    profundidad--;
    return *this;
}

ostream &operator<<(ostream &o, const Prisma &objeto)
{
    o<<objeto.alto<<"x"<<objeto.ancho<<"x"<<objeto.profundidad<<"-"<<objeto.color;
    return o;
}
