#ifndef COMPLEXO_H
#define COMPLEXO_H

typedef struct complex Complex;

Complex* cpx_cria(float a, float b);
void cpx_libera(Complex* p);
int cpx_pega(Complex* p, float *a, float *b);
int cpx_seta(Complex* p, float a, float b);
Complex* cpx_soma(Complex* x, Complex* y);
Complex* cpx_subtrai(Complex* x, Complex* y);
Complex* cpx_multiplica(Complex* x, Complex* y);
Complex* cpx_divide(Complex* x, Complex* y);
void cpx_imprime(Complex* p, char * msg);

#endif