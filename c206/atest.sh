#!/bin/bash
rm c206-advanced-test.own.output
cp Makefile.advanced Makefile

make clean
clear && make && read && valgrind ./c206-test | tee c206-advanced-test.own.output | most

rm Makefile
