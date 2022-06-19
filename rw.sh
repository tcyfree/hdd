if [ -f "./big.txt" ];then
rm big.txt
fi
gcc big.c -o big
./big big.txt 1

gcc random-write.c -o random-write
./random-write