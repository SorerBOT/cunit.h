#!/bin/bash

make clean # couldn't be asked to add .h as deps
make

./bin/test
