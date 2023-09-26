#include <math.h>
// #include "arq.h"
#include "pilhaDE.c"

int main() {
  info reg, data[] = {{"Wilson", 60}, {"Ponte", 15}, {"Marialucia", 10}, {"Uva", 13}, {"Veneza", 60}, {"Tania", 25}};
  int num_of_students = sizeof(data) / sizeof(info);
  pilha *pil = NULL;

  pil = cria();

  printf("Empilhando \n");
  for (int i = 0; i < num_of_students; i++) {
    empilha(pil, &data[i]);
    printf("Nome: %s \n", data[i].nome);
  }
  printf("\n");

  busca(pil, &reg);
  printf("\nTopo da pilha: %s \n", reg.nome);
  buscaBase(pil, &reg);
  printf("Base da pilha: %s \n", reg.nome);
  printf("\n");

  printf("Desempilhando \n");
  for (int i = 1; i <= num_of_students; i++) {
    desempilha(pil, &reg);
    printf("Nome: %s; Idade: %i; \n", reg.nome, reg.idade);
  }

  return 0;
}