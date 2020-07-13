/**//* 27.940.642-ROSSI,SebastianPablo-(05-1965) *//**/

#ifndef TRIANGULO_H_
#define TRIANGULO_H_
#include "Figura.h"

class Triangulo : public Figura
{
  public:
    Triangulo(const float, const float);

    float area();
};


#endif // TRIANGULO_H_
