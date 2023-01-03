# Assignment 4
The purpose of this assignment was to practice using **recursion** and **stacks**.

## Counting Cells
For this task, the input would be a grid of cells that are denoted filled or empty, as 1 or 0 respectively. Blobs are cells that are connected in either 4 directions or 8 directions. The goal of this task was to use **recursion** to count the number of cells within a blob given the original file name, the number or rows, the number of columns, the x and y positions of a cell, and whether connections are in 4 directions or 8 directions.

An example input file is provided within this folder.

The program can be ran using the following command line:
```
$ ./cells grid.txt 10 10 3 4 4
```

## Counting Blobs
For this task, rather than counting cells in a blob, the program must be capable of counting the total number of blobs within a grid, based on connection type. The command line arguments include the original file name, the number of rows in a grid, the number of columns in a grid, and the connection type.

The program can be ran using the following command line:
```
$ ./blobs grid.txt 10 10 4
```

## Infix to Postfix
For this task, the program should be capable of converting from infix to postfix expressions, utilizing **stacks**.

The program can be ran using the following command line:
```
$ ./in2pos "-10 + 20 * ( 30 / 2 )"
```

## Evaluating Postfix
For this task, the program must be capable of evaluating a provided postfix expression.

The program can be ran using the following command line:
```
$ ./eval "-10 20 30 2 / * +"
```
