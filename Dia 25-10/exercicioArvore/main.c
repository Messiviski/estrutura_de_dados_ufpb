#include <stdio.h>
#include "arvore.h"

int main(void) {
  Arvore *arvore = NULL;

  arvore = arv_cria(
    arv_criano(5, 
      arv_criano(3,
        arv_criano(2, NULL, NULL),
        arv_criano(4, NULL, NULL)
      ),
      arv_criano(7,
        arv_criano(6, NULL, NULL),
        arv_criano(8, NULL, NULL)
      )
    )
  );

  arv_imprime(arvore);

  arv_libera(arvore);
}