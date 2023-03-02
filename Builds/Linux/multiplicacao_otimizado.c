#include <stdio.h>
#include <stdlib.h>
#include <immintrin.h>
#define ALIGN 32

void multiplicacao(FILE *matrizA, FILE *matrizBTransposta, FILE *matrizC, int tamanhoMatriz) // multiplica A pela transposta de B
{
    float *A = aligned_alloc(ALIGN, tamanhoMatriz * tamanhoMatriz * sizeof(float)),
          *B = aligned_alloc(ALIGN, tamanhoMatriz * tamanhoMatriz * sizeof(float)),
          *C = aligned_alloc(ALIGN, tamanhoMatriz * tamanhoMatriz * sizeof(float));

    __m256 _A, _B, _resultado256;                                // 8x float
    __m128 _segundaMetade128, _primeiraMetade128, _resultado128; // 4x float

    for (int i = 0; i < tamanhoMatriz * tamanhoMatriz; i++)
    {
        fscanf(matrizA, "%f", &A[i]);
        fscanf(matrizBTransposta, "%f", &B[i]);
    }

    for (int i = 0; i < tamanhoMatriz; i++)
    {
        for (int j = 0; j < tamanhoMatriz; j++)
        {
            *(C + (i * tamanhoMatriz) + j) = 0;
            for (int k = 0; k < tamanhoMatriz; k += 8)
            {
                // carrega 8 floats nos registradores
                _A = _mm256_loadu_ps(A + (i * tamanhoMatriz) + k);
                _B = _mm256_loadu_ps(B + (j * tamanhoMatriz) + k);

                // multiplica _A e _B
                _resultado256 = _mm256_mul_ps(_A, _B);

                // extrai as metades do vetor _resultado256
                _primeiraMetade128 = _mm256_extractf128_ps(_resultado256, 0);
                _segundaMetade128 = _mm256_extractf128_ps(_resultado256, 1);

                // sequência de somas
                _resultado128 = _mm_add_ps(_primeiraMetade128, _segundaMetade128);
                _resultado128 = _mm_hadd_ps(_resultado128, _resultado128);
                _resultado128 = _mm_hadd_ps(_resultado128, _resultado128);

                // armazena em C[i][j]
                C[(i * tamanhoMatriz) + j] += _mm_cvtss_f32(_resultado128);
            }
            fprintf(matrizC, "%.1f ", C[(i * tamanhoMatriz) + j]);
        }
        fprintf(matrizC, "\n");
    }

    free(A);
    free(B);
    free(C);
}

int main(int argc, char *argv[])
{
    int tamanhoMatriz = atoi(argv[1]);

    FILE *matrizA = fopen("txt/matrizA.txt", "r"),
         *matrizBTransposta = fopen("txt/matrizBTransposta.txt", "r"),
         *matrizC = fopen("txt/matrizC_otimizado.txt", "w");

    multiplicacao(matrizA, matrizBTransposta, matrizC, tamanhoMatriz);

    fclose(matrizA);
    fclose(matrizBTransposta);
    fclose(matrizC);

    return 0;
}
