#include <stdio.h>
#include <complex.h>
// #include "complexo.h"

int main(void) {
  double x = 1.0;
  double y = 2.0;
  double complex z = x + y * I;
  printf("%f + %fi\n", creal(z), cimag(z));

  double a = 3.0;
  double b = 4.0;
  double complex g = a + b * I;
  printf("%f + %fi\n", creal(g), cimag(g));

  double complex w = z + g;
  double complex h = z / g;

  printf("%f + %fi\n", creal(w), cimag(w));
  printf("%f + %fi\n", creal(h), cimag(h));
}