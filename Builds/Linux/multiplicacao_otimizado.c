#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int atoi_tamMatriz(const char *string)
{
    int valor = 0;
    while (*string)
    {
        valor = valor * 10 + (*string++ - '0');
    }
    return valor;
}

void multiplicarMatrizes(FILE *matrizA, FILE *matrizB, FILE *matrizC, int tamanhoMatriz)
{
/*
    int linha = tamanhoMatriz, coluna = tamanhoMatriz, **A = malloc(linha * sizeof(int *)), **B = malloc(linha * sizeof(int *)), C = 0;

    for (int i = 0; i < linha; i++)
    {
        *(A + i) = malloc(coluna * sizeof(int));
        *(B + i) = malloc(coluna * sizeof(int));

        for (int j = 0; j < coluna; j++)
        {
            fscanf(matrizA, "%d", (*(A + i) + j));
            fscanf(matrizB, "%d", (*(B + i) + j));
        }
    }

    for (int i = 0; i < tamanhoMatriz; i++)
    {
        for (int j = 0; j < tamanhoMatriz; j++)
        {
            for (int k = 0; k < tamanhoMatriz; k++)
            {
                C += (*(*(A + i) + k)) * (*(*(B + k) + j)); // uso de +=
            }
            fprintf(matrizC, "%d ", C);
            C = 0;
        }
        fprintf(matrizC, "\n");
    }
*/
   
}

int main(int argc, char *argv[])
{

    FILE *matrizA, *matrizB, *matrizC;
    matrizA = fopen("txt/matrizA.txt", "r");
    matrizB = fopen("txt/matrizB.txt", "r");
    matrizC = fopen("txt/matrizC.txt", "w");

    multiplicarMatrizes(matrizA, matrizB, matrizC, atoi_tamMatriz(argv[1]));

    fclose(matrizA);
    fclose(matrizB);
    fclose(matrizC);

    return 0;
}
