gcc -o geraArquivos geraArquivos.c

gcc -o identidade_original identidade_original.c -O0
gcc -o multiplicacao_original multiplicacao_original.c -O0

gcc -mavx -o identidade_otimizado identidade_otimizado.c -O4
gcc -mavx -o multiplicacao_otimizado multiplicacao_otimizado.c -O4

if [ $? -eq 0 ];then 

   echo "Gerando matrizes 256x256"
   ./geraArquivos 256
   echo "OK"

   echo "---Programas originais---"
   
   echo -e "\nVerificação de matriz identidade"
   time ./identidade_original 256

   echo -e "\nMultiplicação de matrizes"
   time ./multiplicacao_original 256

   echo -e "\n---Programas otimizados---"
  
   echo -e "\nVerificação de matriz identidade"
   time ./identidade_otimizado 256

   echo -e "\nMultiplicação de matrizes"
   time ./multiplicacao_otimizado 256

   echo "--------------------------------"

   echo "Gerando matrizes 512x512"
   ./geraArquivos 512
   echo "OK"

   echo "---Programas originais---"
   
   echo -e "\nVerificação de matriz identidade"
   time ./identidade_original 512

   echo -e "\nMultiplicação de matrizes"
   time ./multiplicacao_original 512

   echo -e "\n---Programas otimizados---"
  
   echo -e "\nVerificação de matriz identidade"
   time ./identidade_otimizado 512

   echo -e "\nMultiplicação de matrizes"
   time ./multiplicacao_otimizado 512

   echo "--------------------------------"

   echo "Gerando matrizes 1024x1024"
   ./geraArquivos 1024
   echo "OK"

   echo "---Programas originais---"
   
   echo -e "\nVerificação de matriz identidade"
   time ./identidade_original 1024

   echo -e "\nMultiplicação de matrizes"
   time ./multiplicacao_original 1024

   echo -e "\n---Programas otimizados---"
  
   echo -e "\nVerificação de matriz identidade"
   time ./identidade_otimizado 1024

   echo -e "\nMultiplicação de matrizes"
   time ./multiplicacao_otimizado 1024

   echo "--------------------------------"

   echo "Gerando matrizes 2048x2048"
   ./geraArquivos 2048
   echo "OK"

   echo "---Programas originais---"
   
   echo -e "\nVerificação de matriz identidade"
   time ./identidade_original 2048

   echo -e "\nMultiplicação de matrizes"
   time ./multiplicacao_original 2048

   echo -e "\n---Programas otimizados---"
  
   echo -e "\nVerificação de matriz identidade"
   time ./identidade_otimizado 2048

   echo -e "\nMultiplicação de matrizes"
   time ./multiplicacao_otimizado 2048

   echo "--------------------------------"

   echo "Gerando matrizes 4096x4096"
   ./geraArquivos 4096
   echo "OK"

   echo "---Programas originais---"
   
   echo -e "\nVerificação de matriz identidade"
   time ./identidade_original 4096

   echo -e "\nMultiplicação de matrizes"
   time ./multiplicacao_original 4096

   echo -e "\n---Programas otimizados---"
  
   echo -e "\nVerificação de matriz identidade"
   time ./identidade_otimizado 4096

   echo -e "\nMultiplicação de matrizes"
   time ./multiplicacao_otimizado 4096

   #echo "--------------------------------"

   echo "Gerando matrizes 8192x8192"
   ./geraArquivos 8192
   echo "OK"

   echo "---Programas originais---"
   
   echo -e "\nVerificação de matriz identidade"
   time ./identidade_original 8192

   echo -e "\nMultiplicação de matrizes"
   time ./multiplicacao_original 8192

   echo -e "\n---Programas otimizados---"
  
   echo -e "\nVerificação de matriz identidade"
   time ./identidade_otimizado 8192

   echo -e "\nMultiplicação de matrizes"
   time ./multiplicacao_otimizado 8192

else
   echo "Erro de compilação"
fi




