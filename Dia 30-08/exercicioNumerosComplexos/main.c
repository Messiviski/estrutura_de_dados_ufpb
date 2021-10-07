#include <stdio.h>
#include "complexo.h"

// To compile this program -lm needs to be added at the end of compile command

int main(void) {
  Complex *z = NULL;
  Complex *w = NULL;
  Complex *s = NULL;
  Complex *sub = NULL;
  Complex *m = NULL;
  Complex *d = NULL;
  float acessa_a = 0, acessa_b = 0;

  z = cpx_cria(2.00f, 3.00f);
  cpx_pega(z, &acessa_a, &acessa_b);
  printf("%f - %f\n", acessa_a, acessa_b);

  w = cpx_cria(4.00f, 5.00f);
  cpx_pega(w, &acessa_a, &acessa_b);
  printf("%f - %f\n", acessa_a, acessa_b);

  s = cpx_soma(z, w);
  cpx_pega(s, &acessa_a, &acessa_b);
  printf("%f - %f\n", acessa_a, acessa_b);

  sub = cpx_subtrai(z, w);
  cpx_pega(sub, &acessa_a, &acessa_b);
  printf("%f - %f\n", acessa_a, acessa_b);

  m = cpx_multiplica(z, w);
  cpx_pega(m, &acessa_a, &acessa_b);
  printf("%f - %f\n", acessa_a, acessa_b);

  d = cpx_divide(z, w);
  cpx_pega(d, &acessa_a, &acessa_b);
  printf("%f - %f\n", acessa_a, acessa_b);

  cpx_libera(z);
  cpx_libera(w);
  cpx_libera(s);
  cpx_libera(sub);
  cpx_libera(m);
  cpx_libera(d);
}