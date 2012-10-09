#!/bin/bash
rm c203-advanced-test.own.output
cp Makefile.advanced Makefile

make clean
clear && make && read && valgrind ./c203-test | tee c203-advanced-test.own.output | most

rm Makefile
