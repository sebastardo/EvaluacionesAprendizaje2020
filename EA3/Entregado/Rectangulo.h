/**//* 27.940.642-ROSSI,SebastianPablo-(05-1965) *//**/

#ifndef RECTANGULO_H_
#define RECTANGULO_H_
#include "Figura.h"

class Rectangulo : public Figura
{
  public:
    Rectangulo(const float, const float);
    float area();
};

#endif // RECTANGULO_H_
