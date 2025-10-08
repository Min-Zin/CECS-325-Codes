echo Generating 1000000 random numbers
sleep 1
./generate 1000000 -1000000 1000000
sleep 1

echo Starting system sort
sleep 1
{ time sort -n numbers.dat > systemsort.out; } 2>> sortrace.log
sleep 1

echo " "
echo Starting mysort
sleep 1
{ time ./mysort numbers.dat mysort.out; } 2>> sortrace.log
sleep 1
wc mysort.out
sort -c -n mysort.out 2>> sortrace.log