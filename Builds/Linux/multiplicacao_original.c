#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiplicarMatrizes(FILE *matrizA, FILE *matrizB, FILE *matrizC, int tamanhoMatriz)
{
    int A[tamanhoMatriz][tamanhoMatriz], B[tamanhoMatriz][tamanhoMatriz], C = 0;
    int i, j, k;

    for (i = 0; i < tamanhoMatriz; i++)
    {
        for (j = 0; j < tamanhoMatriz; j++)
        {
            fscanf(matrizA, "%d", &A[i][j]);
            fscanf(matrizB, "%d", &B[i][j]);
        }
    }

    for (i = 0; i < tamanhoMatriz; i++)
    {
        for (j = 0; j < tamanhoMatriz; j++)
        {
            for (k = 0; k < tamanhoMatriz; k++)
            {
                C += A[i][k] * B[k][j];
            }
            fprintf(matrizC, "%d ", C);
            C = 0;
        }

        fprintf(matrizC, "\n");
    }

    fclose(matrizA);
    fclose(matrizB);
    fclose(matrizC);
}

int main(int argc, char *argv[])
{

    int tamanhoMatriz = atoi(argv[1]);

    FILE *matrizA, *matrizB, *matrizC;
    matrizA = fopen("txt/matrizA.txt", "r");
    matrizB = fopen("txt/matrizB.txt", "r");
    matrizC = fopen("txt/matrizC.txt", "w");

    multiplicarMatrizes(matrizA, matrizB, matrizC, tamanhoMatriz);

    return 0;
}
