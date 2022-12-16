#include <iostream>
#include <string>
#include <vector>
#include "maze.h"

int main(int argc, char** argv)
{
    //Takes in the command line arguments
    Maze Grid(argv[1], argv[2], argv[3], argv[4]);

    //Creates the initial maze for usage, of all values 15 save for the first and final cell
    if(Grid.rows == 1 && Grid.columns == 1){
        Grid.CreateBox();
    }
    else{
    Grid.CreateMaze();

    //Creates a vector that stores the unvisited status of the Maze elements
    Grid.NotVisited();

    //Generates the Maze using the provided algorithm
    Grid.MazeGenerator();   
    }
    //Outputs the generated Maze to a file
    Grid.Maze_Out();     
}
