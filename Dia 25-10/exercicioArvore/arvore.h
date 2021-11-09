#ifndef _ARVORE_H
#define _ARVORE_H

typedef struct arvno ArvoreNo;
typedef struct arv Arvore;

Arvore* arv_cria(ArvoreNo *raiz);
ArvoreNo* arv_criano(char caractere, ArvoreNo *esq, ArvoreNo *dir);
void arv_libera(Arvore *arvore_principal);
void arv_imprime(Arvore *arvore_principal);
int arv_pertence(Arvore *arvore_principal, char caractere);
ArvoreNo* arv_busca(Arvore *arvore_principal, char caractere);

#endif