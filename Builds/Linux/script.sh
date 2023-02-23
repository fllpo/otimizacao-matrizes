
gcc -o geraArquivos geraArquivos.c

gcc -o identidade_original identidade_original.c
gcc -o multiplicacao_original multiplicacao_original.c

gcc -o identidade_otimizado identidade_otimizado.c 
gcc -o multiplicacao_otimizado multiplicacao_otimizado.c 

if [ $? -eq 0 ];then 

   ./geraArquivos $1

   echo -e "---Programas originais---\n\nVerificação de matriz identidade"
   
   time ./identidade_original $1

   echo -e "\nMultiplicação de matrizes"

   time ./multiplicacao_original $1

   echo -e "\n---Programas otimizados---\n\nVerificação de matriz identidade"
   time ./identidade_otimizado $1

   echo -e "\nMultiplicação de matrizes"
   time ./multiplicacao_otimizado $1

else
   echo "Erro de compilação"
fi




