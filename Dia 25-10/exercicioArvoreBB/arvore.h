#ifndef _ARVORE_H
#define _ARVORE_H

typedef struct arvno ArvoreNo;
typedef struct arv Arvore;

Arvore* arv_cria(void);
void arv_insere(Arvore *arvore_principal, int valor);
void arv_retira(Arvore *arvore_principal, int valor);
void arv_libera(Arvore *arvore_principal);
void arv_imprime(Arvore *arvore_principal);
int arv_pertence(Arvore *arvore_principal, int valor);
void arv_busca(Arvore *arvore_principal, int valor);
int arv_qntd_folhas(Arvore *arvore_principal);

#endif