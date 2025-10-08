echo "=======Start======="

whoami
date

echo My machine has this many processors

nproc

echo Generating 1000000 random numbers
sleep 1
#./generate 1000000 -1000000 1000000

sleep 1
echo Starting system sort
sleep 1

{ time sort -n numbers.dat > systemsort.out; } 2>> sortrace.log
sleep 1

echo Starting my sort:
sleep 1


{ time ./mysort numbers.dat mysort.out; } 2>> sortrace.lo
sleep 1

ls -1 systemsort.out
ls -1 mysort.out

echo Comparing systemsort.out to mysort.out
diff systemsort.out mysort.out 2>> sortrace.log

echo All done with diff compare
echo "=======End======="
date