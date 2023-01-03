# Assignment 2
## Maze Generation
The purpose of this assignment was to use classes and dynamic arrays in C++ within the context of a random maze generator. The program should be capable of taking in a randomize seed value, the dimensions of the maze array, and the name of the output file.

A maze array is initialized, with the starting cell located at the top left of the array and the ending cell would be located on the bottom right of the array. In addition, a boolean array that would keep track of whether or not cells had been visited previously is also initialized. The program would then randomly decide which direction to connect to as part of the maze generation, and if the selected cell had not been visited previously, then a connection would be made between the starting and connecting cell. This would continue until every single cell had been visited, and there is one path from the starting cell to the ending cell.

Each cell of the maze is represented by a value ranging from 0 to 15, as the walls are encoded using 4 bits. Connections to cells are made by subtracting the respective bit values representing a desired wall from the given cells. The top wall was represented by 8, the bottom wall by 4, the right wall by 2, and the left wall by 1.

To compile and run the code, download the 3 provided files within this folder, and compile using the following line:
```
$ g++ -std=c++11 -Wall main.cpp maze.cpp -o generator
```
Then, to run the code, use the following line as an example:
```
$ ./generator 0 10 10 example.txt
```
