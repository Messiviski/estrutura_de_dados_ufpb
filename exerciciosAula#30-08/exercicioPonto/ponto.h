#ifndef PONTO_H
#define PONTO_H

typedef struct ponto Ponto;

Ponto *cria_ponto(float x, float y);
void libera_ponto(Ponto *p);
int pega_ponto(Ponto *p, float *x, float *y);
int seta_ponto(Ponto *p, float x, float y);
float calcula_distancia(Ponto *p, Ponto *q);

#endif