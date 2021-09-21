file="input.txt"
lock="input.txt.lock"

if [ ! -f $file ]; then
	touch $file
fi

counter=0
while [ $counter -le 1500 ]; do
	if ln -sv $file $lock
	then
		expr $counter >> $file 
		((counter++))
		rm $lock
	fi
done

