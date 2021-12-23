#!/bin/bash

read dictionary
read grid

runtime1=`./a.out $dictionary $grid | tail -1`
runtime2=`./a.out $dictionary $grid | tail -1`
runtime3=`./a.out $dictionary $grid | tail -1`
runtime4=`./a.out $dictionary $grid | tail -1`
runtime5=`./a.out $dictionary $grid | tail -1`

#in milliseconds
combined=$((runtime1 + runtime2 + runtime3 + runtime4 + runtime5))
runs=5								     
avgruntime=$((combined / runs))

#milliseconds
echo $avgruntime

exit 0
