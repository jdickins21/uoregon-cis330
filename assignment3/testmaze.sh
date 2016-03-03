#!/bin/bash

./maze maze_input.txt > maze_output.txt
diff -y  output.txt maze_output.txt
