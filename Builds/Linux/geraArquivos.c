#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int atoi_tamMatriz(const char *str)
{
    int val = 0;
    while (*str)
    {
        val = val * 10 + (*str++ - '0');
    }
    return val;
}

void randomizaArquivo(FILE *arquivo, int tamanhoMatriz)
{

    for (int i = 0; i < tamanhoMatriz; i++)
    {
        for (int j = 0; j < tamanhoMatriz; j++)
        {
            fprintf(arquivo, "%d ", rand() % 1000);
        }
        fprintf(arquivo, "\n");
    }
    fclose(arquivo);
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

    fclose(arquivo);
}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    FILE *matrizA = fopen("txt/matrizA.txt", "w"), *matrizB = fopen("txt/matrizB.txt", "w"), *matrizIdentidade = fopen("txt/matrizIdentidade.txt", "w");
    
    escreveIdentidade(matrizIdentidade, atoi_tamMatriz(argv[1])), randomizaArquivo(matrizA, atoi_tamMatriz(argv[1])), randomizaArquivo(matrizB, atoi_tamMatriz(argv[1]));

    return 0;
}
