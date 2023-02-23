#include <stdio.h>
#include <stdlib.h>

int verificarIdentidade(FILE *matriz, int tamanhoMatriz)
{
    int A[tamanhoMatriz][tamanhoMatriz];

    for (int i = 0; i < tamanhoMatriz; i++)
    {
        for (int j = 0; j < tamanhoMatriz; j++)
        {
            fscanf(matriz, "%d", &A[i][j]);
        }
    }

    for (int i = 0; i < tamanhoMatriz; i++)
    {
        for (int j = 0; j < tamanhoMatriz; j++)
        {
            if ((i == j && A[i][j] != 1))
            {
                return 0;
            }
            else if ((i != j && A[i][j] != 0))
            {
                return 0;
            }
        }
    }
    return 1;
}

int main(int argc, char *argv[])
{

    int tamanhoMatriz = atoi(argv[1]);

    FILE *matriz;
    matriz = fopen("txt/matrizIdentidade.txt", "r");


    if (verificarIdentidade(matriz, tamanhoMatriz) == 1)
    {
        printf("Verdadeiro\n");
    }
    else if (verificarIdentidade(matriz, tamanhoMatriz) == 0)
    {
        printf("Falso\n");
    }

    fclose(matriz);

    return 0;
}