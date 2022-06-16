if [ -f "./file.txt" ];then
rm file.txt
fi

if [ -f "./file2.txt" ];then
rm file2.txt
fi

gcc random-write.c -o random-write
./random-write