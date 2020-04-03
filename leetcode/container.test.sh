#!/bin/zsh

for i in $(seq 1 $1); do
    a=$(./gen $i)
    echo $i
    echo $a > /tmp/input

    diff -w <(./impl < /tmp/input) <(./ref < /tmp/input) || break
done
