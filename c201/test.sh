#!/bin/bash
rm c201-test.own.output
cp Makefile.basic Makefile

make clean
clear && make && read && valgrind ./c201-test | tee c201-test.own.output | most

rm Makefile
