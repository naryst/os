counter=1
gcc ex1.c -o 1ex
while [ $counter -le 10 ]
do
	echo "running " $counter " time"
	./1ex
	((counter++))
done
