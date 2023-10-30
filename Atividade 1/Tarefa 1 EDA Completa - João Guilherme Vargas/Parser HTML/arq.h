#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct palavra{  	
	char tag[100];
  int linha;
}info;

typedef struct noPSE {
  info dados;
  struct noPSE *abaixo;
} node;

typedef struct pilhaSE {
  node *topo;
  int tamPilha;
} pilha;

pilha * cria(void);
int vazia(pilha *pil);
int empilha(info *reg, pilha *pil);
int desempilha(info *reg, pilha *pil);
int busca(info *reg, pilha *pil);
void reinicia(pilha *pil);
pilha *destroi(pilha *pil);
