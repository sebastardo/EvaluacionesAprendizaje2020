/**//* 27.940.642-ROSSI,SebastianPablo-(05-1965) *//**/

#include "Rectangulo.h"

Rectangulo::Rectangulo(const float _base, const float _alto):
        Figura(_base, _alto){}

float Rectangulo::area()
{
    return this->base * this->altura;
}
