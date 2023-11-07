#include "pilhaSE.c"

void criarPastaLogs();
void formatarSaida(char* arg, char* final);
void strrev(char* str);
void lerPilha(pilha* pil, FILE* saida);

int main(int argc, char* argv[]) {
  char* linhaAtual;
  linhaAtual = (char*)malloc(500 * sizeof(char));
  char* saidaAux;
  saidaAux = (char*)malloc(500 * sizeof(char));
  info *infoAux = NULL;
  infoAux = (info*)malloc(sizeof(info));

  pilha *pil = NULL;

  FILE* fEntrada;
  FILE* fSaida;

  int numLinhaAtual = 1;
  int autorizador = 0;

  criarPastaLogs();

  for (int i = 1; i < argc; i++) {
    pil = cria();

    formatarSaida(argv[i], saidaAux);

    fEntrada = fopen(argv[i], "r");
    if (fEntrada == NULL) {
      printf("Erro: Abrir arquivo %s", argv[i]);
      continue;
    }
    fSaida = fopen(saidaAux, "w");
    if (fSaida == NULL) {
      printf("Erro: Criar log de %s", argv[i]);
      continue;
    }


    //LOOP DE LEITURA E VEIRIFCAÇAO DE TAGS
    while (fgets(linhaAtual, 500, fEntrada)) { //Le a linha
      while (*linhaAtual != '\000') { // Loop pela linha até achar o fim
        if (*linhaAtual == '<') {
          autorizador = 1;
          strcpy(infoAux->tag, "");
        } else if (*linhaAtual == '>') {
          autorizador = 0;

          infoAux->linha = numLinhaAtual;

          if (strstr(infoAux->tag, "!DOCTYPE html") != NULL ||
              strstr(infoAux->tag, "input") != NULL ||
              strstr(infoAux->tag, "frame") != NULL ||
              strstr(infoAux->tag, "br") != NULL ||
              strstr(infoAux->tag, "img") != NULL ||
              strstr(infoAux->tag, "option") != NULL ||
              strstr(infoAux->tag, "!--") != NULL) {

            free(infoAux);
            infoAux = (info*)malloc(1 * sizeof(info));
            linhaAtual++;
            continue;
          }

          // fprintf(fSaida, "%d - %s\n", infoAux->linha, infoAux->tag);
          empilha(infoAux, pil);

          free(infoAux);
          infoAux = (info*)malloc(sizeof(info));
        } else if (autorizador == 1) {
          strncat(infoAux->tag, linhaAtual, 1);
        }

        linhaAtual++;
      }
      
      linhaAtual = NULL;
      linhaAtual = (char*)malloc(500 * sizeof(char));
      numLinhaAtual++;
    }

    //le a pilha criada e escreve a saida
    lerPilha(pil, fSaida);



    destroi(pil);
    free(infoAux);
    fclose(fSaida);
    fclose(fEntrada);
    numLinhaAtual = 1;
  }

  return 1;
}

void criarPastaLogs() {
  struct stat st = {0};

  if (stat("./logs", &st) == -1) {
    mkdir("./logs", 0777);
  }

  if (stat("./logs", &st) == -1) {
    printf("ERRO: Criar pasta logs");
  }
}

void formatarSaida(char* arg, char* final) {
  char aux[150] = "";

  strcpy(final, arg);

  int len = strlen(final);

  for (int i = 0; i < 6; i++) {
    final[len - i] = '\000';
  }
  len = strlen(final);

  for (int i = 1; i <= len; i++) {
    if (final[len - i] != '/') {
      aux[i - 1] = final[len - i];
    } else {
      break;
    }
  }

  strrev(aux);

  strcpy(final, "./logs/");
  strcat(final, aux);
  strcat(final, "-log.txt");
}

void strrev(char* str) {
  // if the string is empty
  if (!str) {
    return;
  }
  // pointer to start and end at the string
  int i = 0;
  int j = strlen(str) - 1;

  // reversing string
  while (i < j) {
    char c = str[i];
    str[i] = str[j];
    str[j] = c;
    i++;
    j--;
  }
}

void lerPilha(pilha* pil, FILE* saida){
  info* infoAux = NULL;
  infoAux = (info*)malloc(sizeof(info));

  char* tagAux;
  tagAux = (char*)malloc(100 * sizeof(char));

  pilha* pilAux = NULL;
  pilAux = cria();

  while (desempilha(infoAux, pil)) {
    if (pilAux->tamPilha == 0) {
      empilha(infoAux, pilAux);
      continue;
    }

    if (strstr(infoAux->tag, "/") != NULL) {
      empilha(infoAux, pilAux);
      continue;
    }

    strcpy(tagAux, "/");
    strcat(tagAux, infoAux->tag);

    if (strcmp(tagAux, pilAux->topo->dados.tag) == 0) {
      pilAux->topo = pilAux->topo->abaixo;
      pilAux->tamPilha--;
      continue;
    }

    fprintf(saida, "Erro com a tag <%s> aberta na linha %d\n", infoAux->tag, infoAux->linha);
  }

  free(pilAux);
  // free(infoAux);
  // free(tagAux);
}
