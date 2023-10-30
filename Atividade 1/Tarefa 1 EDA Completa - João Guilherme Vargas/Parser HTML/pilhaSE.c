#include "arq.h"

int vazia(pilha *pil) {
  if (pil->topo == NULL) {
    return 1;
  }

  return 0;
}

pilha *cria(void) {
  pilha *p = NULL;
  p = (pilha *)malloc(sizeof(pilha));
  if (p) {
    p->topo = NULL;
    p->tamPilha = 0;
  }

  return p;
}

int empilha(info *novo, pilha *pil) {
  node *aux = NULL;
  aux = (node *)malloc(sizeof(node));
  if (aux != NULL) {
    memcpy(&(aux->dados), novo, sizeof(info));
    aux->abaixo = pil->topo;
    pil->topo = aux;
    (pil->tamPilha)++;

    return 1;
  }

  return 0;
}

int desempilha(info *reg, pilha *pil) {
  node *aux = NULL;
  
  if (vazia(pil) == 0) {
    memcpy(reg, &(pil->topo->dados), sizeof(info));
    aux = pil->topo->abaixo;
    free(pil->topo);
    pil->topo = aux;
    (pil->tamPilha)--;

    return 1;
  }

  return 0;
}

int busca(info *reg, pilha *pil) {
  if (vazia(pil) == 0) {
    memcpy(reg, &(pil->topo->dados), sizeof(info));

    return 1;
  }

  return 0;
}

void reinicia(pilha *pil) {
  node *aux = NULL;
  if (vazia(pil) == 0) {
    aux = pil->topo->abaixo;
    while (aux != NULL) {
      free(pil->topo);
      pil->topo = aux;
      aux = aux->abaixo;
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
