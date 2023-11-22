#include "./FDEs/funcoesFDEsRefMovel.c"
// #include "./Atividade 2 - João Guilherme Vargas/Apresentacao/FDEs/funcoesFDEcRefMovel.c"

#define TAMANHO_NUM_CASOS 18

int main(int argc, char const *argv[]) {

  //////////////////////////////////////////////////////////////////////////
  //Gerar sequencia aleatora para base de casos
  int listaNumCasos[TAMANHO_NUM_CASOS] = {500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000};
  int sequencia10kBase[10000];
  int **sequenciaPorNumCasos;
  srand(time(NULL));

  sequenciaPorNumCasos = (int **) malloc(TAMANHO_NUM_CASOS * sizeof(int *)); // Matriz de tamanho baseado no num de conjuntos de casos

  for (size_t i = 0; i < 10000; i++){ //Preenchendo o array 10k com a sequencia
    sequencia10kBase[i] = i;
  }

  for (size_t i = 0; i < 10000; i++) { // Randomizando a sequencia do array 10k
    int j = rand() % 10000;
    int aux;

    aux = sequencia10kBase[i];
    sequencia10kBase[i] = sequencia10kBase[j];
    sequencia10kBase[j] = aux;
  }

  for (size_t i = 0; i < TAMANHO_NUM_CASOS; i++) { // Habitando a matriz
    sequenciaPorNumCasos[i] = (int *) malloc(listaNumCasos[i] * sizeof(int));

    for (size_t t = 0; t < listaNumCasos[i]; t++) { //Preencendo cada sequecnia de casos aleatoriamente
      sequenciaPorNumCasos[i][t] = sequencia10kBase[t];
    }

    for (size_t t = 0; t < 10000; t++) { // Re-randomizando a sequencia 10k
      int j = rand() % 10000;
      int aux;

      aux = sequencia10kBase[t];
      sequencia10kBase[t] = sequencia10kBase[j];
      sequencia10kBase[j] = aux;
    }
  }
  //////////////////////////////////////////////////////////////////////////

  //////////////////////////////////////////////////////////////////////////
  //Botar o csv num vetor pra ser mais facil de colocar nas FDEs
  char dataset[10000][256];
  char linha[256];

  //LOCALIZAÇÃO DO CSV
  FILE *datasetCSV = fopen("/home/jotausr/Projetos/UDESC/2023.2.EDA/Atividade 2 - Fila/Atividade 2 - João Guilherme Vargas/Apresentacao/Aux/dataset_v1.csv", "r");

  fgets(linha, 256, datasetCSV);// Ignorar a primeira linha
  
  for (size_t i = 0; i < 10000; i++){
    if (fgets(linha, 256, datasetCSV)) {
      linha[strcspn(linha, "\n")] = 0; // Remove a quebra de linha

      strcpy(dataset[i], linha);
      strcpy(linha, "");
    } else {
      break;
    }
  }
  //////////////////////////////////////////////////////////////////////////

  //////////////////////////////////////////////////////////////////////////
  // Menu principal gerar iteraçoes medias por num de casos
  descFDE *descritor = NULL;
  infoNode auxInfo;
  int totalIteracoes = 0;
  int listaMediaPorNumCasos[TAMANHO_NUM_CASOS];

  for (size_t i = 0; i < TAMANHO_NUM_CASOS; i++) { // Zerando a lista de medias por numero de casos
    listaMediaPorNumCasos[i] = 0;
  }

  clock_t clo;
  double time_taken;

  for (size_t k = 0; k < 1; k++) { // Loop para repetir o estudo 50 vezes e pegar uma media

    for (size_t i = 0; i < TAMANHO_NUM_CASOS; i++) { // Loop inicial percorre o numero de conjuntos aka 18
      clo = clock();

      if ((descritor = criaSRM(sizeof(infoNode))) == 0) { // Cria um descritor de FDE S/ RM
        printf("ERRO: Criacao do FDE s/ RM");
      }

      for (size_t t = 0; t < listaNumCasos[i]; t++) { // Loop secundario percorre o numero de casos de cada conjunto
        auxInfo = transformaCSV(dataset[sequenciaPorNumCasos[i][t]]); // Funçao devlve um struct tipo info a partir do csv armazenado
        insereSRM(&auxInfo, descritor, comparaSRM, &totalIteracoes); // Insere info na fila e recebe o numero de iteraçoes
      }

      descritor = destroiSRM(descritor); // Ao fim destroi o descritor
      listaMediaPorNumCasos[i] += totalIteracoes / listaNumCasos[i]; // Salva no vetor as medias por caso
      totalIteracoes = 0;

      clo = clock() - clo;
      time_taken = ((double)clo) / CLOCKS_PER_SEC;

      printf("%f \n", time_taken);
      clo = 0;
    }
  }
  


  for (size_t i = 0; i < TAMANHO_NUM_CASOS; i++) { // Printar os resultados na tela
    printf("%d,%d\n", listaNumCasos[i], listaMediaPorNumCasos[i] / 1);
  }
  

  return 0;
}

infoNode transformaCSV(char *linha){ // Tokenização dos itens do csv e salvar como info
  infoNode infoAux;
  char *token;

  char *teste = (char *) malloc(256 * sizeof(char));
  strcpy(teste, linha);
  
  token = strtok(teste, ",");
  strcpy(infoAux.nome, token);

  token = strtok(NULL, ",\n");
  infoAux.matricula = atoi(token);

  token = strtok(NULL, ",\n");
  infoAux.ranking = atoi(token);

  token = strtok(NULL, ",\n");
  strcpy(infoAux.curso, token);

  free(teste);
  
  return infoAux;
}

int comparaSRM(infoNode *a, infoNode *b) { // Função de comparaçao
  if (a->ranking < b->ranking)
    return MAIOR;
  else if (a->ranking > b->ranking)
    return MENOR;
  else
    return IGUAL;
}
