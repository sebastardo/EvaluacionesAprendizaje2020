/**//* 27.940.642-ROSSI,SebastianPablo-(05-1965) *//**/

#ifndef FIGURA_H_
#define FIGURA_H_

#include "FiguraInvalidaException.h"

using namespace std;

class Figura{

  protected:
    float base,altura;

  public:
    Figura(const float,  const float);
    virtual float area() = 0;
    virtual ~Figura();
};



#endif // FIGURA_H_
