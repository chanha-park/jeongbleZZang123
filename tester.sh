#!/bin/bash

num_exercise="4"

testdir="./srcs/"
userdir="../"
utilsdir="./utils/"

ckheader="check_forbidden_header.c"
ckleaks="check_leaks.c"
gnl="get_next_line.c"

filename[0]="eleven_number_checker.c"
filename[1]="phone_number_checker.c"
filename[2]="simple_password_validator.c"
filename[3]="push_swap_instruction_validator.c"
filename[4]="snake_ToCamel.c"

fail=0

gcc -Wall -Wextra -Werror "$utilsdir""$gnl" "$utilsdir""$ckheader" -o "header_checker"

for num in $(seq 0 $num_exercise)
do
	# compile and check error
	testsrc="$testdir""ex0$num/""${filename[$num]}"
	usersrc="$userdir""ex0$num/""${filename[$num]}"
	main="$testdir""ex0$num/""main.c"

	./header_checker "$usersrc"
	if [ $? != 0 ]
	then
		fail=1
		break
	fi
	gcc -Wall -Wextra -Werror "$main" "$testsrc" "$utilsdir""$ckleaks" -o "test0$num.out"
	gcc -Wall -Wextra -Werror "$main" "$usersrc" "$utilsdir""$ckleaks" -o "user0$num.out"
	if [ $(echo $?) -gt 0 ]
	then
		echo "compile error in ex0$num"
		fail=1
		break
	fi

	./test0$num.out > test.output 2> test.error
	ret1=$(echo $?)
	./user0$num.out > user.output 2> user.error
	ret2=$(echo $?)

	# check unexpected exit
	if [ $ret1 != $ret2 ]
	then
		echo "Fail in ex0$num"
		echo "exit status: $ret1 vs $ret2"
		fail=1
		break
	fi

	diff user.output test.output > diff.output
	diff user.error test.error > diff.error

	# diff stdout && stderr
	if [ $(cat diff.output | wc -l) -gt 0 ]
	then
		echo "Fail in ex0$num"
		fail=1
		break
	else
		if [ $(cat diff.error | wc -l) -gt 0 ]
		then
			echo "Fail in ex0$num"
			fail=1
			break
		else
			echo "Success"
		fi
	fi
done

rm -rf header_checker

rm -rf test*.out
rm -rf user*.out

rm -rf test*.output
rm -rf user*.output
rm -rf diff.output

rm -rf test*.error
rm -rf user*.error
rm -rf diff.error

if [ $fail == 0 ]
then
	echo "Success!"
fi
exit $fail

# ARG[0]="testcase 0"
# ARG[1]="testcase 1"
# ARG[2]="testcase 2"
# ARG[3]="testcase 3"
# ARG[4]="testcase 4"
# ARG[5]="testcase 5"
# ARG[6]="testcase 6"
# ARG[7]="testcase 7"

# for f in ${ARG[@]}
# do
#     echo "$f"
# done
