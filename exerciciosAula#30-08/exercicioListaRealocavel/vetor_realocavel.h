#ifndef VETOR_REALOCAVEL_H
#define VETOR_REALOCAVEL_H

typedef struct vetordin VetorDin;

VetorDin *cria_vetor(int dim);
int insere_vetord(VetorDin *vetor_dinamico, float novo_valor);
int tamanho_vetord(VetorDin *vetor_dinamico);
int acessa_vetord(VetorDin *vetor_dinamico, int pos, float *valor);
void libera_vetord(VetorDin **vetor_dinamico);

#endif