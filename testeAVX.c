#include <immintrin.h>
#include <stdio.h>
#include <stdlib.h>

void multiplicaLinhaColuna(float *A, float *B, float *C) // Testando produto escalar de vetores simples com AVX2 e XMM
{
    __m256 _A, _B, _resultado256;                                // 8x float
    __m128 _primeiraMetade128, _segundaMetade128, _resultado128; // 4x float

    _A = _mm256_loadu_ps(A);
    _B = _mm256_loadu_ps(B);

    // multiplica _A e _B
    _resultado256 = _mm256_mul_ps(_A, _B); // {9, 20, 33, 48, 65, 84, 105, 128}

    // extrai primeira metade do vetor para _primeiraMetade128
    _primeiraMetade128 = _mm256_extractf128_ps(_resultado256, 0); // {9, 20, 33, 48}

    // extrai segunda metade do vetor para _segundaMetade128
    _segundaMetade128 = _mm256_extractf128_ps(_resultado256, 1); // {65, 84, 105, 128}

    // sequência de somas
    _resultado128 = _mm_add_ps(_primeiraMetade128, _segundaMetade128); // {9, 20, 33, 48} + {65, 84, 105, 128} == {74, 104, 138, 176}
    _resultado128 = _mm_hadd_ps(_resultado128, _resultado128);         //       {74, 104} + {138, 176}         == {178, 314, 178, 314}
    _resultado128 = _mm_hadd_ps(_resultado128, _resultado128);         //      {178, 314} + {178, 314}         == {492, 492, 492, 492}

    // converte _resultado128 em float32 para matriz C
    *C = _mm_cvtss_f32(_resultado128); // *C = 492
}

int main(int argc, char **argv)
{
    float A[8] = {1, 2, 3, 4, 5, 6, 7, 8}, B[8] = {9, 10, 11, 12, 13, 14, 15, 16}, C[8];

    multiplicaLinhaColuna(A, B, C);

    printf("%.1f", C[0]);

    return 0;
}