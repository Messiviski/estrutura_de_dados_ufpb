#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complexo.h"
// #include <complex.h>

#ifndef COMPLEXO_C
#define COMPLEXO_C

struct complex {
  float a;
  float b;
};

Complex* cpx_cria(float a, float b) {
  Complex* new_complex_number = NULL;

  new_complex_number = (Complex*) malloc(sizeof(Complex));
  if(!new_complex_number) return 0;

  new_complex_number->a = a;
  new_complex_number->b = b;

  return new_complex_number;
}

void cpx_libera(Complex* p) {
  free(p);

  p = NULL;
}

int cpx_pega(Complex* p, float *a, float *b) {
  if(p != NULL) {
    *a = p->a;
    *b = p->b;
    
    return 1;
  }

  return 0;
}

int cpx_seta(Complex* p, float a, float b) {
  if(p != NULL) {
    p->a = a;
    p->b = b;

    return 1;
  }

  return 0;
}

Complex* cpx_soma(Complex* x, Complex* y) {
  Complex* new_complex_number = NULL;

  if(x != NULL && y != NULL) {
    new_complex_number = (Complex*) malloc(sizeof(Complex));
    if(!new_complex_number) return(0);

    new_complex_number->a = (x->a + y->a);
    new_complex_number->b = (x->b + y->b);
    
    return new_complex_number;
  }
  return 0;
}

Complex* cpx_subtrai(Complex* x, Complex* y) {
  Complex* new_complex_number = NULL;

  if(x != NULL && y != NULL) {
    new_complex_number = (Complex*) malloc(sizeof(Complex));
    if(!new_complex_number) return 0;

    new_complex_number->a = (x->a - y->a);
    new_complex_number->b = (x->b - y->b);
    
    return new_complex_number;
  }
  return 0;
}

Complex* cpx_multiplica(Complex* x, Complex* y) {
  Complex* new_complex_number = NULL;

  if(x != NULL && y != NULL) {
    new_complex_number = (Complex*) malloc(sizeof(Complex));
    if(!new_complex_number) return(0);

    new_complex_number->a = ((x->a * y->a) - (x->b * y->b));
    new_complex_number->b = ((x->b * y->a) + (x->a * y->b));
    
    return new_complex_number;
  }
  return 0;
}

Complex* cpx_divide(Complex* x, Complex* y) {
  Complex* new_complex_number = NULL;

  if(x != NULL && y != NULL) {
    new_complex_number = (Complex*) malloc(sizeof(Complex));
    if(!new_complex_number) return(0);

    new_complex_number->a = (
      ((x->a * y->a) + (x->b * y->b)) / (sqrt(y->a) + sqrt(y->b))
    );

    new_complex_number->b = (
      ((x->b * y->a) - (x->a * y->b)) / (sqrt(y->a) + sqrt(y->b))
    );
    
    return new_complex_number;
  }
  return 0;
}

#endif
