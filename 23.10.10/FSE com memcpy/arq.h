#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define SIM 1
#define NAO 0
#define SUCESSO 1
#define FRACASSO 0


typedef struct{ int idade;
		char nome[30];
	}info;
			


struct noFSE {
    info dados;
    struct noFSE *defronte;
};

struct descF { 
    int tamInfo;
    struct noFSE *cauda;
    struct noFSE *frente;
};
//======================APLICACAO=====================


//======================FILA=====================
struct descF * cria(int tamInfo);
int insere(info *novo,struct descF *p);
int tamanhoDaFila(struct descF *p);
int reinicia(struct descF *p);
struct descF * destroi(struct descF *p);
int buscaNaCauda(info *reg, struct descF *p);
int buscaNaFrente(info *reg, struct descF *p);
int remove_(info *reg, struct descF *p);
int testaVazia(struct descF *p);
int inverte(struct descF *p);
struct descF * destroi(struct descF *p);











