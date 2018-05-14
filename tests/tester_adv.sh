#!/bin/bash

if [ $# -ne 2 ]
then
	read -p "How many range of number [from ... to] (2 number needed) : " NBRBOT NBRTOP
else
	NBRBOT=$1;
	NBRTOP=$2;
fi

export ARG=$(ruby -e "puts ($NBRBOT..$NBRTOP).to_a.shuffle.join(' ')")

read -p "Display graphical viewer [yY] ? " -n 1 -r
if [[ $REPLY =~ ^[Yy]$ ]]
then
#    [[ "$0" = "$BASH_SOURCE" ]] && exit 1 || return 1 # handle exits from shell or function but don't exit interactive shell
	echo -e "\n——————" && ./push_swap -h | grep "^-" && echo "——————"
	read -p "with option -s [sS] or -option -c [cC] ? " -n 1 -r
	if [[ $REPLY =~ ^[sS]$ ]]
	then
		echo -e "\n——————" && ./push_swap -h | grep "^Viewer" && echo "——————"
		./push_swap $ARG | ./checker -lvs $ARG
	elif [[ $REPLY =~ ^[cC]$ ]]
	then
		echo -e "\n——————" && ./push_swap -h | grep "^Viewer" && echo "——————"
		./push_swap $ARG | ./checker -lvc $ARG
	else
		echo -e "\n——————" && ./push_swap -h | grep "^Viewer" && echo "——————"
		./push_swap $ARG | ./checker -lv $ARG
	fi
else
	./push_swap $ARG | ./checker -l $ARG
fi
echo "List: $ARG"

exec $SHELL -i
