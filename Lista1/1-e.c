#include <stdio.h>

struct teste
{
  int inteiro;
  float real;
  char nome[30];
  char rua[30];
  int *apont;
};

int main(void)
{
  struct teste *p = NULL, x = {321, 2.39, "Silva", "Timbo", NULL};
  int y = 101;
  p = &x;
  p->apont = &y;

  printf("%d \n", *x.apont);
  printf("%d \n", &x);
  printf("%d \n", *(p->apont));
  printf("%d \n", &p);

  // p = x
  // &(p->real) = &(x.real)
  // p->real = x.real
  // &(p->apont) = &(x.appont)
  // p->apont = x->apont
} // *(p->apont)