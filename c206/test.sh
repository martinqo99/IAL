#!/bin/bash
rm c206-test.own.output
cp Makefile.basic Makefile

make clean
clear && make && read && valgrind ./c206-test | tee c206-test.own.output | most

rm Makefile
