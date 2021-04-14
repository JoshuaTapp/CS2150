#!/bin/bash

    
    echo "enter the exponent for counter.cpp to continue:"
    read input

    TIME=0
    for i in {1..5}; do
        echo "Running iteration ${i}..."
        RUNNING_TIME=`./a.out ${input}`
        TIME=$((TIME+RUNNING_TIME))
        echo "time taken: $RUNNING_TIME ms"
    done
    echo "5 iterations took ${TIME} ms"
    echo "Average time was $(($TIME/5)) ms"
