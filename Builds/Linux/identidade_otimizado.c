#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int verificarIdentidade(FILE *matriz, int tamanhoMatriz)
{
/*
    int linhas = tamanhoMatriz, colunas = tamanhoMatriz, **A = malloc(linhas * sizeof(int *)),lin, col;

    for (int i = 0; i < tamanhoMatriz * tamanhoMatriz; i++)
    {
        lin = i / colunas;
        col = i % colunas;

        *(A + lin) = malloc(colunas * sizeof(int));

        fscanf(matriz, "%d", (*(A + lin) + col));

        if ((lin == col && *(*(A + lin) + col) != 1) || (lin != col && *(*(A + lin) + col) != 0))
        {
            free(A);
            return 0;
        }
    }
    free(A);
    return 1;
*/
}

int atoi_tamMatriz(const char *str)
{
    int val = 0;
    while (*str)
    {
        val = val * 10 + (*str++ - '0');
    }
    return val;
}

int main(int argc, char *argv[])
{

    FILE *matriz = fopen("txt/matrizIdentidade.txt", "r");

    verificarIdentidade(matriz, atoi_tamMatriz(argv[1])) ? printf("Verdadeiro\n") : printf("Falso\n");
    
    fclose(matriz);

    return 0;
}