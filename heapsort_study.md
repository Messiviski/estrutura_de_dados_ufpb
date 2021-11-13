# Estudo sobre *heapsort*

- **Anotações**

  - No *heapsort* por ser um vetor existe algumas formas de acessar um vetor

  - As formas existentes são:

    - **Acessar o pai:** 

      `vetor[((i-1)/2)]`

    - **Acessar o filho a esquerda:**
      - `vetor[(2*i+1)]`
    - **Acessar o filho a direita:**
      - `vetor[(2*i+2)]`

  - A **inserção** usando essa estrutura de dados é feita de forma a preservar a árvore cheia, portanto inicialmente o valor é inserido como uma *folha* e então é verificado se o pai do nó o qual ele foi inserido é menor do que ele, caso seja o elemento inserido trocará de lugar com o pai e assim por diante até que ele encontre um ele elemento que seja maior que ele.
  
  - A **remoção** usando essa estrutura de dados é feita da seguinte maneira, o valor que será removido sempre será o valor que se encontra na *raiz* então o último valor que se encontra no vetor é colocado na raiz e o valor que está na raiz é retirado, após isso é necessário verificar se o valor que está na raiz é maior que seus dois filhos, que provavelmente não será, e então *descer* com esse valor até o seu devido lugar.
