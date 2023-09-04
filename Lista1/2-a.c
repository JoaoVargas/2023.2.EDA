#include <stdio.h>
#include <stdlib.h>

typedef struct teste
{
  int inteiro;
  float real;
  char nome[30];
} informacao;

// main(void)
// {
//   informacao *p, x = {321, 2.39, "Silva"};

//   if (p)
//     printf("valores da struct X : %i, %f, %s", p->inteiro, p->real, p->nome);
//   else
//     printf("o ponteiro está anulado");
// }

main(void)
{
  informacao *p, x = {321, 2.39, "Silva"};

  p = &x;

  if (p)
  {
    printf("valores da struct X : %i, %f, %s", p->inteiro, p->real, p->nome);
  }
  else
  {
    printf("o ponteiro está anulado");
  }
}