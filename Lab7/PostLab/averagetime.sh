# Ryan Grayson
# rtg5xkh
# PostLab 7
# averagetime.sh
# 4/6/2021

#!/bin/bash

echo 'enter the exponent for counter.cpp:'
read exp
q="quit"

total=0

if [[ "$exp" == "$q" ]] ; then
    exit 1
fi

for i in {1..5} ; do
    echo "Running iteration ${i}..."
    runtime=`./a.out $exp`
    total=$((total + runtime))
    echo "time taken: ${runtime} ms"
done

iterations=5
avg=$((total / iterations))
echo "5 iterations took ${total} ms"
echo "Average time was ${avg} ms"

exit 0
