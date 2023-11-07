#include <stdio.h>
#include <stdlib.h>

typedef struct noDados
{
  void *dados;
  struct noDados *abaixo;

} noDados;

typedef struct pilha2
{
  int tamifo;
  noDados *topo;

} descritor;

int main()
{
  descritor *p = NULL;
  noDados *q = NULL;
  void *r = NULL;

  int a = 3;

  p = (descritor *)malloc(sizeof(descritor));
  if (p)
  {
    p->topo = NULL;
    p->tamifo = 0;
  }

  q = (noDados *)malloc(sizeof(noDados));
  if (q)
  {
    q->dados = NULL;
    q->abaixo = NULL;
  }


  r = &a;

  q->dados = r;

  q->abaixo = q;

  p->topo = q;

  printf("%d", *((int *)p->topo->dados));


  return 0;
}
