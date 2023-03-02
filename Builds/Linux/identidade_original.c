#include <stdio.h>
#include <stdlib.h>

int verificarIdentidade(FILE *matriz, int tamanhoMatriz)
{
    float **A = malloc(tamanhoMatriz * sizeof(int *));
    int i, j;

    for (i = 0; i < tamanhoMatriz; i++)
    {
        *(A + i) = malloc(tamanhoMatriz * sizeof(int));
        for (j = 0; j < tamanhoMatriz; j++)
        {
            fscanf(matriz, "%f", &A[i][j]);
        }
    }

    for (i = 0; i < tamanhoMatriz; i++)
    {
        for (j = 0; j < tamanhoMatriz; j++)
        {
            if (i == j)
            {
                if (A[i][j] != 1)
                {
                    return 0;
                }
            }
            else if (i != j)
            {
                if (A[i][j] != 0)
                {
                    return 0;
                }
            }
        }
    }
    return 1;
    free(A);
}

int main(int argc, char *argv[])
{

    int tamanhoMatriz = atoi(argv[1]);

    FILE *matriz;
    matriz = fopen("txt/matrizIdentidade.txt", "r");

    if (verificarIdentidade(matriz, tamanhoMatriz))
    {
        printf("Verdadeiro\n");
    }
    else
        printf("Falso\n");

    fclose(matriz);

    return 0;
}