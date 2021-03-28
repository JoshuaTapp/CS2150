#!/bin/bash
echo 'enter name of dictionary file:' 
read dictionary
echo 'enter name of grid file:' 
read grid

TIME=0
for i in {1..5}; do
    RUNNING_TIME=`./a.out $dictionary $grid | tail -1`
    TIME=($TIME+$RUNNING_TIME)
done

echo $(($TIME/5))