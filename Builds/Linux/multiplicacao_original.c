#include <stdio.h>
#include <stdlib.h>

void multiplicarMatrizes(FILE *matrizA, FILE *matrizB, FILE *matrizC, int tamanhoMatriz)
{
    float **A = malloc(tamanhoMatriz * sizeof(float *)), **B = malloc(tamanhoMatriz * sizeof(float *)), C = 0;
    int i, j, k;

    for (i = 0; i < tamanhoMatriz; i++)
    {
        *(A + i) = malloc(tamanhoMatriz * sizeof(float));
        *(B + i) = malloc(tamanhoMatriz * sizeof(float));

        for (j = 0; j < tamanhoMatriz; j++)
        {
            fscanf(matrizA, "%f", &A[i][j]);
            fscanf(matrizB, "%f", &B[i][j]);
        }
    }

    for (i = 0; i < tamanhoMatriz; i++)
    {
        for (j = 0; j < tamanhoMatriz; j++)
        {
            for (k = 0; k < tamanhoMatriz; k++)
            {
                C = C + A[i][k] * B[k][j];
            }
            fprintf(matrizC, "%.1f ", C);
            C = 0;
        }

        fprintf(matrizC, "\n");
    }

    free(A);
    free(B);
}

int main(int argc, char *argv[])
{

    int tamanhoMatriz = atoi(argv[1]);

    FILE *matrizA = fopen("txt/matrizA.txt", "r"),
         *matrizB = fopen("txt/matrizB.txt", "r"),
         *matrizC = fopen("txt/matrizC_original.txt", "w");

    multiplicarMatrizes(matrizA, matrizB, matrizC, tamanhoMatriz);

    fclose(matrizA);
    fclose(matrizB);
    fclose(matrizC);

    return 0;
}
