#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arq.h"



/*************** CRIA ***************/
struct descF * cria(int tamInfo)
{   	
    struct descF *desc = (struct descF*) malloc(sizeof(struct descF));
    if(desc != NULL) {
        desc->cauda = NULL;
        desc->frente = NULL;
	    desc->tamInfo= tamInfo;
    }
    return desc;
}

/*************** INSERE NA CAUDA ***************/
int insere(info *novo, struct descF *p)
{  	
    struct noFSE *temp;
    int ret;

    if( (temp = (struct noFSE*) malloc(sizeof(struct noFSE))) != NULL ) { 
            temp->dados=*novo;  //memcpy(&(temp->dados), novo, p->tamInfo);
            temp->defronte = p->cauda;
            if(p->cauda == NULL && p->frente == NULL) {	
                p->frente = temp;
            }
            p->cauda = temp;
            ret = SUCESSO;
    }
    else 
      ret = FRACASSO;
   

    return ret;
}

/*************** REMOVE DA FRENTE ***************/
int remove_(info *reg, struct descF  *p)
{
	int ret = FRACASSO;
	struct noFSE *aux = p->cauda;

    	if(p->cauda != NULL && p->frente != NULL) 
    	{
            *reg = p->frente->dados; //	memcpy(reg, &(p->frente->dados), p->tamInfo);

		    if(aux == p->frente) 
		    { // caso tenha 1 elemento apenas
			    free(p->frente);
			    p->frente = p->cauda = NULL;
		    }
		    else {  	
			        while(aux->defronte != p->frente) 
			        {
				        aux = aux->defronte;
			        }
        		
	                free(p->frente);
        		    p->frente = aux;
			        aux->defronte = NULL;
		}
		ret = SUCESSO;
	}

	return ret;
}

/*************** BUSCA NA FRENTE ***************/
int buscaNaFrente(info *reg, struct descF *p)
{  
    int ret = FRACASSO;

    if(p->frente != NULL && p->cauda != NULL) { 	
        *reg = p->frente->dados; //memcpy(reg, &(p->frente->dados), p->tamInfo);
        ret = SUCESSO;
    }

    return ret;
}

/*************** BUSCA NA CAUDA ***************/
int buscaNaCauda(info *reg, struct descF *p)
{
    int ret = FRACASSO;

    if(p->cauda != NULL && p->frente != NULL) 
    {
        *reg = p->frente->dados; //memcpy(reg, &(p->cauda->dados), p->tamInfo);
	    ret = SUCESSO;
    }

    return ret;
}

/*************** VAZIA? ***************/
int testaVazia(struct descF *p)
{
    if(p->frente == NULL && p->cauda == NULL) 
        return SIM;
    else
        return NAO;
}

/*************** TAMANHO ***************/
int tamanhoDaFila(struct descF *p)
{ 
    int tam = 0;
    struct noFSE *aux = p->cauda;

    while(aux != NULL) 
    { 	
        aux = aux->defronte;
        tam++;
    }

    return tam;
}

/*************** PURGA ***************/
int reinicia(struct descF *p)
{   int ret=FRACASSO;
    struct noFSE *aux=NULL;

    if(p->frente != NULL && p->cauda != NULL) 
    {  
        aux = p->cauda->defronte;
        while(aux != NULL) 
        {
            free(p->cauda);
            p->cauda = aux;
            aux = aux->defronte;
        }
        
        free(p->cauda);
        p->frente = NULL;
        p->cauda = NULL;
        ret=SUCESSO; 
    }
    return ret;	
}

/*************** DESTROI ***************/
struct descF * destroi(struct descF *p)
{
    reinicia(p);
    free(p);
    return NULL; // aterra o ponteiro externo, declarado na aplicaÃ§Ã£o
}
