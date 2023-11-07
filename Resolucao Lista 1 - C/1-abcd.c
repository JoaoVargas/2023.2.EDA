// a)

// #include - Informa o pré-processador para incluir o conteúdo de um arquivo
// especificado no ponto onde a diretiva aparece.

// #define cria uma macro, que é a associação de um identificador ou
// identificador parametrizado com uma cadeia de caracteres de token

// #undef Remove (não define) um nome criado anteriormente com #define.

// #ifdef / #ifndef As diretivas de pré-processador #ifdef e #ifndef têm o
// mesmo efeito da diretiva #if quando usada com o operador defined.

// #if, #elif, #else e #endif A diretiva #if, com as diretivas #elif, #else e #endif,
// controla a compilação de partes de um arquivo de origem.
// Se a expressão escrita (após #if) tiver um valor diferente de zero, o grupo de linhas
// imediatamente após a diretiva #if será mantido na unidade de tradução.

// b)
//  memcpy - void *memcpy(void *dest, const void *src, size_t n)
//  copia n numero de bytes de um ponto src para um ponto dest

// typedef - criar estruturas
// typedef struct tipo_endereco
// {
//   char rua[50];
//   int numero;
//   char bairro[20];
//   char cidade[30];
//   char sigla_estado[3];
//   long int CEP;
// } TEndereco;

// c)

#include <stdio.h>

struct teste2
{
  int inteiro;
  float real;
  char nome[30];
  struct teste2 *self;
};

int main()
{
  int *p = NULL, **pp = NULL, x = 321, y = 101;
  // p    | 0   | &p
  // *p   | 0   | &p
  // pp   | 0   | &pp
  // *pp  | err | &pp
  // **pp | 0   | &pp
  // x    | 321 | &x
  // y    | 101 | &y

  p = &x;
  // p    | &x  | &p
  // *p   | x   | &x
  // pp   | 0   | &pp
  // *pp  | err | &pp
  // **pp | 0   | &pp
  // x    | 321 | &x
  // y    | 101 | &y

  pp = &p;
  // p    | &x  | &p
  // *p   | x   | &x
  // pp   | &p  | &pp
  // *pp  | &x  | &p
  // **pp | x   | &x
  // x    | 321 | &x
  // y    | 101 | &y

  *p = -3;
  // p    | &x  | &p
  // *p   | -3  | &-3
  // pp   | &p  | &pp
  // *pp  | &-3  | &p
  // **pp | -3   | &-3
  // x    | 321 | &x
  // y    | 101 | &y

  y = **pp;
  // p    | &x  | &p
  // *p   | -3  | &-3
  // pp   | &p  | &pp
  // *pp  | &-3 | &p
  // **pp | -3  | &-3
  // x    | 321 | &x
  // y    | -3  | &y

  struct teste2 x2 = {115, 2.5, "Smith", NULL}, *p2 = NULL;
  
  p2 = &x2;
  p2->self = &x2;



  return 0;
}