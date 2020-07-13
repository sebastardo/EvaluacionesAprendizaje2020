/**//* 27.940.642-ROSSI,SebastianPablo-(05-1965) *//**/

#include "Triangulo.h"

Triangulo::Triangulo(const float _base, const float _alto):
        Figura(_base, _alto){}

float Triangulo::area()
{
    return (this->base * this->altura)/2;
}

