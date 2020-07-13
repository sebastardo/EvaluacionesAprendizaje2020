/**//* 27.940.642-ROSSI,SebastianPablo-(05-1965) *//**/

#include "Cuadrado.h"

Cuadrado::Cuadrado(const float _lado):
    Figura(_lado, _lado){}

float Cuadrado::area()
{
    return this->base * this->altura;
}

