#include <stdio.h>
#include <stdlib.h>
#include <immintrin.h>
#define ALIGN 32

int verificarIdentidade(FILE *matriz, int tamanhoMatriz)
{
    float *A = aligned_alloc(ALIGN, tamanhoMatriz * tamanhoMatriz * sizeof(float)), C, D = 0;

    __m256 _A;                                                   // 8x float
    __m128 _segundaMetade128, _primeiraMetade128, _resultado128; // 4x float

    for (int i = 0; i < tamanhoMatriz * tamanhoMatriz; i++)
        fscanf(matriz, "%f", &A[i]);

    for (int i = 0; i < tamanhoMatriz; i++)
    {
        C = 0;
        for (int j = 0; j < tamanhoMatriz; j += 8)
        {
            // carrega 8 floats nos registradores
            _A = _mm256_loadu_ps(A + (i * tamanhoMatriz) + j);

            // extrai as metades do vetor _resultado256
            _primeiraMetade128 = _mm256_extractf128_ps(_A, 0);
            _segundaMetade128 = _mm256_extractf128_ps(_A, 1);

            // sequência de somas
            _resultado128 = _mm_add_ps(_primeiraMetade128, _segundaMetade128);
            _resultado128 = _mm_hadd_ps(_resultado128, _resultado128);
            _resultado128 = _mm_hadd_ps(_resultado128, _resultado128);

            // armazena _resultado128 em C
            C += _mm_cvtss_f32(_resultado128);
        }
        if (!(C || *(A + i * tamanhoMatriz + i)))
        {
            free(A);
            return 0;
        }
    }
    free(A);
    return 1;
}

int main(int argc, char *argv[])
{
    FILE *matriz = fopen("txt/matrizIdentidade.txt", "r");

    verificarIdentidade(matriz, atoi(argv[1])) ? printf("Verdadeiro\n") : printf("Falso\n");

    fclose(matriz);

    return 0;
}