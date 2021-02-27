#!/bin/bash

# This script was written by Joshua Tapp (jct7bm)
# to help automate the testing for lab 03 in CS2150
# Date: 02/27/21

echo "beginning testing...."

a=$(./a.out < /Users/tapp/Documents/GitHub/CS2150/CS2150/labs/lab03/input/addition.txt)
b=$(./a.out < /Users/tapp/Documents/GitHub/CS2150/CS2150/labs/lab03/input/subtraction.txt)
c=$(./a.out < /Users/tapp/Documents/GitHub/CS2150/CS2150/labs/lab03/input/multiplication.txt)
d=$(./a.out < /Users/tapp/Documents/GitHub/CS2150/CS2150/labs/lab03/input/division.txt)
e=$(./a.out < /Users/tapp/Documents/GitHub/CS2150/CS2150/labs/lab03/input/negation.txt)

echo $a
echo $b
echo $c
echo $d
echo $e

#if [$a = 15]; then
 #   echo "Addition Passed"
#fi

#if ["$b" == "21"]; then
    echo "Subtraction Passed"
#fi

#if ["$c" == "120"]; then
 #   echo "Multiplication Passed"
#fi

#if ["$d" == "42"]; then
#    echo "Division Passed"
#fi

#if ["$e" == "1"]; then
#    echo "negation Passed"
#fi


