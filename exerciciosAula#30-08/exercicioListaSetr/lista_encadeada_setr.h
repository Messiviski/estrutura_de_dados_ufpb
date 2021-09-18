#ifndef LISTA_ENCADEADA_SETR_H
#define LISTA_ENCADEADA_SETR_H

typedef struct no Lista;

Lista *lst_setr_cria(float info);
Lista *lst_setr_uniao(Lista *primeira_lista, Lista *segunda_lista);
int lst_setr_insere_fim(Lista **lista, float info);
int lst_setr_remove_elemento(Lista **lista, float info);
Lista *lst_setr_intersec(Lista *primeira_lista, Lista *segunda_lista);
int lst_setr_existe(Lista *lista, float info);
int lst_setr_igual(Lista *primeira_lista, Lista *segunda_lista);
int lst_setr_tamanho(Lista *lista);
int lst_setr_vazia(Lista *lista);
void lst_setr_limpa(Lista **lista);
void lst_setr_mostra(Lista *lista, char *mensagem);

#endif