#include "./interface.h"

/*************** CRIA ***************/
descFDE *criaCRM(int tamInfo) {
  descFDE *descritor = (descFDE *)malloc(sizeof(descFDE));

  if (descritor != NULL) {
    descritor->cauda = NULL;
    descritor->frente = NULL;
    descritor->refMovel = NULL;
    descritor->tamInfo = tamInfo;
  }

  return descritor;
}

/*************** INSERE NA CAUDA ***************/
int insereCRM(info *novo, descFDE *descritor, int (*comparaCRM)(info *novo, info *visitado)) {
  int comparacao;
  nodeFDE *novoNodeFDE = NULL, *visitado = NULL;

  if ((novoNodeFDE = (nodeFDE *)malloc(sizeof(nodeFDE))) == NULL) {  // Caso problema com descritor
    return 0;
  }

  memcpy(&(novoNodeFDE->dados), novo, descritor->tamInfo);

  if (descritor->frente == NULL && descritor->cauda == NULL) {  // Caso fila vazia
    novoNodeFDE->atras = novoNodeFDE->afrente = NULL;
    descritor->frente = descritor->cauda = novoNodeFDE;

    return 1;
  }

  comparacao = (*comparaCRM)(novo, &(descritor->cauda->dados));

  if (comparacao == MENOR) {  // Novo node tem menos prioridade que o ultimo da fila
    novoNodeFDE->atras = NULL;
    novoNodeFDE->afrente = descritor->cauda;
    descritor->cauda->atras = novoNodeFDE;
    descritor->cauda = novoNodeFDE;

    return 1;
  }

  visitado = descritor->frente;  // Começa pela frente pois prioridade

  while (visitado->atras != NULL && (*comparaCRM)(novo, &(visitado->dados)) != MAIOR) {  // Move visitado enquanto novo for menor q ele
    visitado = visitado->atras;
  }

  comparacao = (*comparaCRM)(novo, &(visitado->dados));

  if (comparacao == MAIOR) {  // Novo fica a frente do visitado
    novoNodeFDE->atras = visitado;

    if (visitado->afrente != NULL) {  // Caso visitado não seja o primeiro
      novoNodeFDE->afrente = visitado->afrente;
      visitado->afrente->atras = novoNodeFDE;

    } else {  // novo item é o de maior prioridade de todos na fila, sendo a nova frente
      novoNodeFDE->afrente = NULL;
      descritor->frente = novoNodeFDE;
    }

    visitado->afrente = novoNodeFDE;
    novoNodeFDE->atras = visitado;
  }
  // else //<<<- novo item é o de menor prioridade de todos na fila, sendo a nova cauda:
  // condição já tratadana linha com comentário "novo elemento é o de menor prioridade"
  //{
  //	novoNoFila->afrente = visitado;
  //	novoNoFila->atras = NULL;
  //	visitado->atras = novoNoFila;
  //	p->cauda = novoNoFila;
  // }

  return 1;
}

/*************** REMOVE DA FRENTE ***************/
int removeFrenteCRM(info *reg, descFDE *descritor) {
  nodeFDE *aux = descritor->cauda;

  if (descritor->cauda != NULL && descritor->frente != NULL) {  // Caso exista algo na FDE
    memcpy(reg, &(descritor->frente->dados), descritor->tamInfo);

    if (aux == descritor->frente) {  // caso tenha 1 elemento apenas
      free(descritor->frente);
      descritor->frente = descritor->cauda = NULL;

      return 1;
    }

    descritor->frente = descritor->frente->atras;
    free(descritor->frente->afrente);
    descritor->frente->afrente = NULL;

    return 1;
  }

  return 0;
}

/*************** BUSCA NA FRENTE ***************/
int buscaNaFrenteCRM(info *reg, descFDE *descritor) {
  if (descritor->frente != NULL && descritor->cauda != NULL) {  // Caso exista algo na FDE
    memcpy(reg, &(descritor->frente->dados), descritor->tamInfo);

    return 1;
  }

  return 0;
}

/*************** BUSCA NA CAUDA ***************/
int buscaNaCaudaCRM(info *reg, descFDE *descritor) {
  if (descritor->cauda != NULL && descritor->frente != NULL) {  // Caso exista algo na FDE
    memcpy(reg, &(descritor->cauda->dados), descritor->tamInfo);

    return 1;
  }

  return 0;
}

/*************** VAZIA? ***************/
int testaVaziaCRM(descFDE *descritor) {
  if (descritor->frente == NULL && descritor->cauda == NULL) {  // Caso exista algo na FDE
    return 1;
  }

  return 0;
}

/*************** TAMANHO ***************/
int tamanhoDaFilaCRM(descFDE *descritor) {
  int tam = 0;
  nodeFDE *aux = descritor->cauda;

  while (aux != NULL) {
    tam++;
    aux = aux->afrente;
  }

  return tam;
}

/*************** PURGA ***************/
int reiniciaCRM(descFDE *descritor) {
  nodeFDE *aux = NULL;

  if (descritor->frente != NULL && descritor->cauda != NULL) {  // Caso exista algo na FDE
    aux = descritor->cauda->afrente;

    while (aux != NULL) {
      free(descritor->cauda);
      descritor->cauda = aux;
      aux = aux->afrente;
    }

    free(descritor->cauda);
    descritor->frente = NULL;
    descritor->cauda = NULL;

    return 1;
  }
  return 0;
}

/*************** DESTROI ***************/
descFDE *destroiCRM(descFDE *descritor) {
  reinicia(descritor);
  free(descritor);

  return NULL;  // aterra o ponteiro externo, declarado na aplicação
}
