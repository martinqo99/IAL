#!/bin/bash
rm c201-advanced-test.own.output
cp Makefile.advanced Makefile

make clean
clear && make && read && valgrind ./c201-test | tee c201-advanced-test.own.output | most

rm Makefile
