#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomizaArquivo(FILE *arquivo, int tamanhoMatriz)
{

    for (int i = 0; i < tamanhoMatriz; i++)
    {
        for (int j = 0; j < tamanhoMatriz; j++)
        {
            fprintf(arquivo, "%.1f ", (float)(rand() % 100));
        }
        fprintf(arquivo, "\n");
    }
}

void Transposta(FILE *arquivo1, FILE *arquivo2, int tamanhoMatriz)
{
    float *B = malloc(tamanhoMatriz * tamanhoMatriz * sizeof(float));

    for (int i = 0; i < tamanhoMatriz; i++)
    {
        for (int j = 0; j < tamanhoMatriz; j++)
        {
            fscanf(arquivo1, "%f", &B[(i * tamanhoMatriz) + j]);
        }
    }

    for (int j = 0; j < tamanhoMatriz; j++)
    {
        for (int i = 0; i < tamanhoMatriz; i++)
        {
            fprintf(arquivo2, "%.1f ", B[(i * tamanhoMatriz) + j]);
        }
        fprintf(arquivo2, "\n");
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

    FILE *matrizA = fopen("txt/matrizA.txt", "w"),
         *matrizB = fopen("txt/matrizB.txt", "w+"),
         *matrizBTransposta = fopen("txt/matrizBTransposta.txt", "w"),
         *matrizIdentidade = fopen("txt/matrizIdentidade.txt", "w");

    escreveIdentidade(matrizIdentidade, atoi(argv[1])),
        randomizaArquivo(matrizA, atoi(argv[1])),
        randomizaArquivo(matrizB, atoi(argv[1])),
        rewind(matrizB), Transposta(matrizB, matrizBTransposta, atoi(argv[1]));

    fclose(matrizA),
        fclose(matrizB),
        fclose(matrizBTransposta),
        fclose(matrizIdentidade);

    return 0;
}
