#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <time.h>

#define FALSE 0
#define TRUE 1
#define MAIOR 1
#define IGUAL 0
#define MENOR -1

typedef struct info {
  char nome[30];
  int matricula;
  int ranking;
  char curso[30];
} infoNode;

typedef struct node {
  infoNode dados;
  struct node *atras;
  struct node *afrente;
} nodeFDE;

typedef struct desc {
  nodeFDE *frente;
  nodeFDE *cauda;
  int tamLista;
  int tamInfo;
  nodeFDE *refMovel;
} descFDE;

//======================APLICACAO=====================
infoNode transformaCSV(char *linha);
//==================FDE S/ REF MOVEL==================
descFDE *criaSRM(int tamInfo);
int insereSRM(infoNode *novo, descFDE *p, int (*compara)(infoNode *novo, infoNode *visitado), int *total);
int tamanhoDaFilaSRM(descFDE *p);
int reiniciaSRM(descFDE *p);
descFDE *destroiSRM(descFDE *p);
int buscaNaCaudaSRM(infoNode *reg, descFDE *p);
int buscaNaFrenteSRM(infoNode *reg, descFDE *p);
int removeFrenteSRM(infoNode *reg, descFDE *p);
int testaVaziaSRM(descFDE *p);
int comparaSRM(infoNode *inf1, infoNode *inf2);
//==================FDE C/ REF MOVEL==================
descFDE *criaCRM(int tamInfo);
int insereCRM(infoNode *novo, descFDE *p, int (*compara)(infoNode *novo, infoNode *visitado));
int tamanhoDaFilaCRM(descFDE *p);
int reiniciaCRM(descFDE *p);
descFDE *destroiCRM(descFDE *p);
int buscaNaCaudaCRM(infoNode *reg, descFDE *p);
int buscaNaFrenteCRM(infoNode *reg, descFDE *p);
int removeFrenteCRM(infoNode *reg, descFDE *p);
int testaVaziaCRM(descFDE *p);
int comparaCRM(infoNode *inf1, infoNode *inf2);
