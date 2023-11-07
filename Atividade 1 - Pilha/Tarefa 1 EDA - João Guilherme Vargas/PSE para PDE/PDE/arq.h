#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct dados{  	
	char nome[50];
	int idade;
	}info;

typedef struct nodePDE{	
	info dados;
	struct nodePDE *acima;
	struct nodePDE *abaixo;
} node;

typedef struct PDE{
  node *topo;
  int tamPilha;
} pilha;

pilha *cria(void);
int vazia(pilha *pil);
int empilha(pilha *pil, info *reg);
int desempilha(pilha *pil, info *reg);
int busca(pilha *pil, info *reg);
int buscaBase(pilha *pil, info *reg);
void reinicia(pilha *pil);
pilha *destroi(pilha *pil);