for f in *
do
	if [[ $f = *.c ]]
	then
		`gcc $f -lm -Wall -o $f.out`

		echo "$f"

		if [ -e ${f%.c}.in ]
		then
			echo "`./$f.out < ${f%.c}.in`"
		else
			echo "`./$f.out`"
		fi
	elif [[ $f = *.cpp ]]
	then
		`g++ $f -Wall -o $f.out`

		echo "$f"

		if [ -e ${f%.*}.in ]
		then
			echo "`./$f.out < ${f%.*}.in`"
		else
			echo "`./$f.out`"
		fi
	fi
done
