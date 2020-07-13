/**//* 27.940.642-ROSSI,SebastianPablo-(05-1965) *//**/

#include "Figura.h"


Figura::Figura(const float _base, const float _altura)
{
     if (_base <= 0 || _altura <= 0)
        throw FiguraInvalidaException();

     this->base = _base;
     this->altura = _altura;
}

Figura::~Figura(){}
