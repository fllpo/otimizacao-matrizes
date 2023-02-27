#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomizaArquivo(FILE *arquivo, int tamanhoMatriz)
{

    for (int i = 0; i < tamanhoMatriz; i++)
    {
        for (int j = 0; j < tamanhoMatriz; j++)
        {
            fprintf(arquivo, "%f ", (float)rand());
        }
        fprintf(arquivo, "\n");
    }
}
void escreveIdentidade(FILE *arquivo, int tamanhoMatriz)
{
    for (int i = 0; i < tamanhoMatriz; i++)
    {
        for (int j = 0; j < tamanhoMatriz; j++)
        {
            if (i == j)
            {
                fprintf(arquivo, "%d ", 1);
            }
            else
                fprintf(arquivo, "%d ", 0);
        }
        fprintf(arquivo, "\n");
    }
}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    FILE *matrizA = fopen("txt/matrizA.txt", "w"), *matrizB = fopen("txt/matrizB.txt", "w"), *matrizIdentidade = fopen("txt/matrizIdentidade.txt", "w");

    escreveIdentidade(matrizIdentidade, atoi(argv[1])), randomizaArquivo(matrizA, atoi(argv[1])), randomizaArquivo(matrizB, atoi(argv[1]));

    fclose(matrizA);
    fclose(matrizB);
    fclose(matrizIdentidade);

    return 0;
}
