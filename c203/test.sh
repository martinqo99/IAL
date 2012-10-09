#!/bin/bash
rm c203-test.own.output
cp Makefile.basic Makefile

make clean
clear && make && read && valgrind ./c203-test | tee c203-test.own.output | most

rm Makefile
