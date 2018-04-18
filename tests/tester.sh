#!/bin/bash

if [ $# -ne 2 ]
then
	read -p "How many range of number [from ... to] (2 number needed) : " NBRBOT NBRTOP
else
	NBRBOT=$1;
	NBRTOP=$2;
fi

export ARG=$(ruby -e "puts ($NBRBOT..$NBRTOP).to_a.shuffle.join(' ')")

read -p "Display visual mode [yY] ? " -n 1 -r
echo    # (optional) move to a new line
if [[ $REPLY =~ ^[Yy]$ ]]
then
#    [[ "$0" = "$BASH_SOURCE" ]] && exit 1 || return 1 # handle exits from shell or function but don't exit interactive shell
	read -p "Display graphical mode [yY] ? " -n 1 -r
	echo    # (optional) move to a new line
	if [[ $REPLY =~ ^[Yy]$ ]]
	then
		./push_swap $ARG | ./checkerkh -lv $ARG
	else
		./push_swap -v $ARG
		./push_swap $ARG | ./checkerkh -l $ARG
	fi
else
#	./push_swap $ARG
	./push_swap $ARG | ./checkerkh -l $ARG
fi
echo "List: $ARG"

exec $SHELL -i
