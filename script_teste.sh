gcc -mavx -o testeAVX testeAVX.c

if [ $? -eq 0 ];then 

   ./testeAVX

else
   echo "Erro de compilação"
fi
