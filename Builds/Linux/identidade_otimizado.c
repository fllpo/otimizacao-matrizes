#include <stdio.h>
#include <stdlib.h>

int verificarIdentidade(FILE *matriz, int tamanhoMatriz)
{
    return 0;
}

int main(int argc, char *argv[])
{

    FILE *matriz = fopen("txt/matrizIdentidade.txt", "r");

    verificarIdentidade(matriz, atoi(argv[1])) ? printf("Verdadeiro\n") : printf("Falso\n");
    fclose(matriz);

    return 0;
}