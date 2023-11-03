#include "./FDEs/funcoesFDEsRefMovel.c"
// #include "./Atividade 2 - João Guilherme Vargas/Apresentacao/FDEs/funcoesFDEcRefMovel.c"

#define TAMANHO_NUM_CASOS 18

int main(int argc, char const *argv[]) {

  //////////////////////////////////////////////////////////////////////////
  //Gerar sequencia aleatora para base de casos
  int listaNumCasos[TAMANHO_NUM_CASOS] = {500, 1000, 1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000, 5500, 6000, 6500, 7000, 7500, 8000, 8500, 9000};
  int sequencia10kBase[10000];
  int **sequenciaPorNumCasos;

  sequenciaPorNumCasos = (int **) malloc(TAMANHO_NUM_CASOS * sizeof(int *)); // Matriz de tamanho baseado no num de nums de casos

  for (size_t i = 0; i < 10000; i++){ //Preenchendo o array com a sequencia
    sequencia10kBase[i] = i;
  }
  for (size_t i = 0; i < 10000; i++) { // Randomizando a sequencia
    int j = rand() % 10000;
    int aux;

    aux = sequencia10kBase[i];
    sequencia10kBase[i] = sequencia10kBase[j];
    sequencia10kBase[j] = aux;
  }

  for (size_t i = 0; i < TAMANHO_NUM_CASOS; i++) {
    sequenciaPorNumCasos[i] = (int *) malloc(listaNumCasos[i] * sizeof(int));

    for (size_t t = 0; t < listaNumCasos[i]; t++) { //Preencendo cada sequecnia de casos aleatoriamente
      sequenciaPorNumCasos[i][t] = sequencia10kBase[t];
    }

    for (size_t i = 0; i < 10000; i++) { // Re-randomizando a sequencia 10k
      int j = rand() % 10000;
      int aux;

      aux = sequencia10kBase[i];
      sequencia10kBase[i] = sequencia10kBase[j];
      sequencia10kBase[j] = aux;
    }
  }
  //////////////////////////////////////////////////////////////////////////

  //////////////////////////////////////////////////////////////////////////
  //Botar o csv num vetor pra ser mais facil de colocar nas FDEs
  char dataset[10000][256];
  char linha[256];

  FILE *datasetCSV = fopen("/home/jotausr/Projetos/UDESC/2023.2.EDA/Atividade 2/Atividade 2 - João Guilherme Vargas/Apresentacao/Aux/dataset_v1.csv", "r");

  fgets(linha, 256, datasetCSV);// Ignorar a primeira linha
  for (size_t i = 0; i < 10000; i++){
    if (fgets(linha, 256, datasetCSV)) {
      strcpy(dataset[i], linha);
    } else {
      break;
    }
  }

  printf("%s", dataset[1]);
  //////////////////////////////////////////////////////////////////////////

  //////////////////////////////////////////////////////////////////////////
  

  return 0;
}
