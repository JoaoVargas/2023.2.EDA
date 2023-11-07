
#include "arq.h"



int main(void)
{ 
    MP *ptr = NULL; 
    int nPilha, lPilha;
    
    printf(">Digite o numero de pilhas da MPE:\n");
    scanf("%d", &nPilha);
    printf(">Digite o tamanho das pilhas da MPE:\n");
    scanf("%d", &lPilha);
     
    if( (ptr=cria(ptr, nPilha, lPilha, sizeof(info))) != NULL ) 
	{	printf(">>criadas %d pilhas de tamanho maximo = %d\n\n", nPilha, lPilha);
		printf("Tecle! %s", "\U0001F64F");

	}	
    else 
        return 1;
	
    getchar(); getchar();
    system("clear");	
    
      
    menu(ptr, nPilha, lPilha);
    
    return 0;
}


int menu(MP *ptr, int nPilha, int lPilha)
{
    int opc;
    info infoAux;

    do {
        printf("1. inserir \n2. remover \n3. consultar topo\n4. Exibir tamanho da MP\n0. sair\n\n> ");
        scanf("%d", &opc);
        
        switch(opc){
 
            case 1:
                printf("\nDigite a pilha para insercao:\n> ");
                scanf("%d", &nPilha);
                printf("\nDigite a idade:\n> ");
                scanf("%i", &infoAux.idade);
                printf("\nDigite o nome:\n> ");
                scanf("%s", infoAux.nome);
                if( insereNaPilha(ptr, nPilha, &infoAux) == SUCESSO ) {
                    printf("\nsucesso na insercao!\n");
				}
	
                break;
            case 2:
                printf("\nDigite a pilha para remocao:\n> ");
                scanf("%d", &nPilha);
                if( removeDaPilha(ptr, nPilha, &infoAux) == SUCESSO ) {
                    printf("\nELEMENTO REMOVIDO:\n-------------------\n%s-%d\n-------------------\n", infoAux.nome, infoAux.idade);
                    printf("\nsucesso na remocao!\n");
                }
  
                break;
            case 3:
                printf("\nDigite a pilha para consulta:\n> ");
                scanf("%d", &nPilha);
                if( consultaTopo(ptr, nPilha, &infoAux) == SUCESSO ) {
                    printf("\nTOPO ATUAL:\n-------------------\n%s-%d\n-------------------\n", infoAux.nome, infoAux.idade);
                    printf("\nsucesso na consulta!\n");
                }

                break;
            case 4:
                exibeTamanhoMP(ptr);

                break;
        }

	printf("Tecle! %s", "\U0001F64F");
        getchar(); getchar();
        system("clear");
    } while(opc!=0);
    
    printf("\n\n Coleta de lixo! %s\n\n", "\U0001F6AE");
    ptr= destroi(ptr);
    printf("FIM! \n\n");    
    return opc;
}

