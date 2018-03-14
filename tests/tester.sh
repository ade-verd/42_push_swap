#!/bin/bash

if [ $# -ne 2 ]
then
	read -p "How many range of number [from ... to] (2 number needed) : " NBRBOT NBRTOP
else
	NBRBOT=$1;
	NBRTOP=$2;
fi

ARG=$(ruby -e "puts ($NBRBOT..$NBRTOP).to_a.shuffle.join(' ')")
./push_swap $ARG
echo "List: $ARG"