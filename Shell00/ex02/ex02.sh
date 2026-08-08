#!/bin/sh

mkdir test0
chmod 751 test0
touch -t 202306012047 test0

echo "1234" > tset1
chmod 754 test1
touch -t 202306012146 test1

mkdir test2
chmod 554 test2
touch -t 202306012245 test2

echo "a" > test3
chmod 444 test3
touch -t 202306012344 test3

echo "ab" > test4
chmod 651 test4
touch -t 202306012343 test4

ln test3 test5
touch -t 202306012344 test5

ln -s test0 test6
touch -t 202306012220 test6

tar -cf ex02.tar *
