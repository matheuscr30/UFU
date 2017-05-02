#!/bin/bash

for i in {0..20};
do
    gcc syscall.c -o syscall
    gcc library.c -o library
    sync; echo 3 > /proc/sys/vm/drop_caches
    (time ./syscall $((2**i)) <datafile >/dev/null) &>> outputsyscall.txt
    sync; echo 3 > /proc/sys/vm/drop_caches
    (time ./library $((2**i)) <datafile >/dev/null) &>> outputlibrary.txt
done 

