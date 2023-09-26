#include "arq.h"

int vazia(pilha *pil){
  if (pil->topo == NULL){
    return 1;
  } else {
    return 0;
  }
}

pilha *cria(void){
  pilha *p = NULL;
  p = (pilha *)malloc(sizeof(pilha));

  if (p){
    p->topo = NULL;
    p->tamPilha = 0;
  }

  return p;
}

int empilha(pilha *pil, info *novo){
  nodo *aux = NULL;
  aux = (nodo *)malloc(sizeof(nodo));

  if (pil != NULL){
    if (pil->tamPilha != 0) {
      memcpy(&(aux->dados), novo, sizeof(info));

      aux->abaixo = pil->topo;
      aux->acima = NULL;

      pil->topo->acima = aux;
      pil->topo = aux;

      (pil->tamPilha)++;

      return 1;
    }

    memcpy(&(aux->dados), novo, sizeof(info));

    aux->abaixo = pil->topo;
    aux->acima = NULL;

    pil->topo = aux;

    (pil->tamPilha)++;

    return 1;
  }

  return 0;
}

int desempilha(pilha *pil, info *reg) {
  nodo *aux = NULL;

  if (vazia(pil) == 0) {
    if (pil->tamPilha != 1)
    {
      memcpy(reg, &(pil->topo->dados), sizeof(info));

      aux = pil->topo->abaixo;
      aux->acima = NULL;
      free(pil->topo);
      pil->topo = aux;

      (pil->tamPilha)--;

      return 1;
    }

    memcpy(reg, &(pil->topo->dados), sizeof(info));

    free(pil->topo);

    (pil->tamPilha)--;

    return 1;
  }

  return 0;
}

int busca(pilha *pil, info *reg) {
  if (vazia(pil) == 0) {
    memcpy(reg, &(pil->topo->dados), sizeof(info));

    return 1;
  } else {
    return 0;
  }
}

int buscaBase(pilha *pil, info *reg) {
  if (vazia(pil) == 0) {
    nodo *aux = NULL;
    aux = (nodo *)malloc(sizeof(nodo));

    aux = pil->topo;

    while (aux->abaixo != NULL) {
      aux = aux->abaixo;
    }

    memcpy(reg, &(aux->dados), sizeof(info));

    return 1;
  } else {
    return 0;
  }
}

void reinicia(pilha *pil) {
  nodo *aux = NULL;

  if (vazia(pil) == 0) {
    aux = pil->topo;

    while (aux->abaixo != NULL) {
      aux = aux->abaixo;
      free(pil->topo);
      pil->topo = aux;
    }

    free(pil->topo);
    pil->topo = NULL;
    pil->tamPilha = 0;
  }
}

pilha *destroi(pilha *pil) {
  reinicia(pil);
  free(pil);

  return NULL;
}
