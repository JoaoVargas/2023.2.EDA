#include "arq.h"
#include "math.h"

int main(void)
{	int tamData, i;
	info data[]={{23,"Pedro"},{32,"Maria"},{18,"Ana"},{81,"Vania"}}, tmp;
	struct descF *p=NULL;

	tamData=sizeof(data)/sizeof(info);
	printf("\ntamanho do conjunto de dados %i\n", tamData);
		
	p=cria(sizeof(info));
	i= tamanhoDaFila(p);
	printf("tamanho da fila %i\n\n", i);
	
	
	for(i=0;i<tamData;i++)
	{   printf("inserido na fila: %i %s \n",data[i].idade,data[i].nome);
		insere(&data[i], p);
	}		 
	i= tamanhoDaFila(p);
	printf("tamanho da fila %i\n", i);

	buscaNaCauda(&tmp,p);
	printf("final da fila %i %s \n", tmp.idade,tmp.nome);

	buscaNaFrente(&tmp,p);
	printf("frente da fila %i %s \n\n", tmp.idade,tmp.nome);

	for(i=0; i<round(tamData/2);i++)
		if (remove_(&tmp,p) == FRACASSO)
			printf("erro na remocao\n");
		else
			printf("Removido da fila %i %s \n", tmp.idade,tmp.nome);
	
	buscaNaCauda(&tmp,p);
	printf("final da fila %i %s \n", tmp.idade,tmp.nome);

	buscaNaFrente(&tmp,p);
	printf("frente da fila %i %s \n", tmp.idade,tmp.nome);
	i= tamanhoDaFila(p);
	printf("tamanho da fila %i\n", i);
	if(insere(&data[0], p)==FRACASSO)
		printf("Erro na tentativa de insercao");
	getchar();
	p=destroi(p);
	return 1;
}





