#ifndef _LISTA_CIRCULAR_H
#define _LISTA_CIRCULAR_H

typedef struct lista Lista;

Lista *lst_cria(int info);
int lst_vazia(Lista *lista);
int lst_tamanho(Lista *lista);
int lst_insere_inicio(Lista **lista, int info);
int lst_insere_fim(Lista **lista, int info);
int lst_existe(Lista *lista, int info);
void lst_mostra(Lista *lista, char *mensagem);
void lst_limpa(Lista **lista);
int lst_remove_elemento(Lista **lista, int info);
int lst_insere_ordenado(Lista **lista, int info);

#endif