# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-verd <ade-verd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/26 18:08:32 by aroulin           #+#    #+#              #
#    Updated: 2018/03/12 14:11:26 by ade-verd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

if [ $# -ne 2 ]
then
	read -p "How many range of number [from ... to] (2 number needed) : " NBRBOT NBRTOP
else
	NBRBOT=$1;
	NBRTOP=$2;
fi

ARG=$(ruby -e "puts ($NBRBOT..$NBRTOP).to_a.shuffle.join(' ')")
#NBRCOUP=$(./push_swap $ARG | wc -l);
NBRCOUP=$(./push_swap $ARG | grep "sa\|sb\|ss\|pa\|pb\|ra\|rb\|rr\|rra\|rrb\|rrr" | wc -l);
if [ $NBRCOUP -ne 0 ]
then
	((NBRCOUP--))
fi
#TEST=$(./push_swap $ARG | ./checker $ARG);
./push_swap $ARG
echo "Number of movements: $NBRCOUP"