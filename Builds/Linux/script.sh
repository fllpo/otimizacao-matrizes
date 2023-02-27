
gcc -o geraArquivos geraArquivos.c

gcc -o identidade_original identidade_original.c -O0
gcc -o multiplicacao_original multiplicacao_original.c -O0

#gcc -o identidade_otimizado identidade_otimizado.c -O0
#gcc -o multiplicacao_otimizado multiplicacao_otimizado.c -O0

if [ $? -eq 0 ];then 

   echo "Gerando arquivos"
   ./geraArquivos $1
   echo "OK"

   echo "---Programas originais---"
   
   echo -e "\nVerificação de matriz identidade"
   time ./identidade_original $1

   echo -e "\nMultiplicação de matrizes"
   time ./multiplicacao_original $1

   #echo "---Programas otimizados---"
  
   #echo -e "\nVerificação de matriz identidade"
   #time ./identidade_otimizado $1

   #echo -e "\nMultiplicação de matrizes"
   #time ./multiplicacao_otimizado $1

else
   echo "Erro de compilação"
fi




