#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct teste
{
  int inteiro;
  float real;
  char nome[30];
} informacao;

// main(void)
// {
//   int a = 10, vet[] = {1, 2, 3, 4, 5}, *p = NULL;
//   float b = 35.75;
//   informacao y = {31, "Wilson"};

//   void *ptr; // Declaracao de um ponteiro para um tipo genérico (void)

//   ptr = &a; // Atribuindo o endereço de um inteiro.
//   printf("a = %d \n", *((int *)ptr));

//   ptr = &b; // Atribuindo o endereço de um float.
//   printf("b = %f \n", *((float *)ptr));

//   ptr = &y;
//   printf("nome= %s, idade = %i \n\n", ((info *)ptr)->nome, ((info *)ptr)->idade);

//   printf("\n\n Acessando um vetor por aritmetica de ponteiro void\n");
//   ptr = &vet[0];

//   for (int i = 0; i < 6; i++, ptr++)
//   {
//     printf("vet[%i] = %i \n", i, *((int *)ptr));
//   }
// }

main(void)
{
  int a = 10, vet[] = {1, 2, 3, 4, 5}, *p = NULL;
  float b = 35.75;

  size_t tamanhoArray = sizeof(vet) / sizeof(vet[0]);

  informacao y = {31, 0, "Wilson"};

  void *ptr; // Declaracao de um ponteiro para um tipo genérico (void)

  ptr = &a; // Atribuindo o endereço de um inteiro.
  printf("a = %d \n", *((int *)ptr));

  ptr = &b; // Atribuindo o endereço de um float.
  printf("b = %f \n", *((float *)ptr));

  ptr = &y;
  printf("nome= %s, idade = %i \n\n", ((informacao*)ptr)->nome, ((informacao*)ptr)->inteiro);

  printf("\n\n Acessando um vetor por aritmetica de ponteiro void\n");
  ptr = &vet;

  for (int i = 0; i < tamanhoArray; i++)
  {
    printf("vet[%i] = %i \n", i, *((int*)ptr));
    ptr += sizeof(int);
  }
}