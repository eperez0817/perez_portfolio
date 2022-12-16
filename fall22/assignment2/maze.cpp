#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <utility>
#include "maze.h"

Maze::Maze(char* temp_seed, char* temp_row, char* temp_column, std::string Output)
{
    seed = atoi(temp_seed);
    rows = atoi(temp_row);
    columns = atoi(temp_column);
    OutputName = Output;
}

void Maze::CreateBox()
{
    std::vector<int> onebyone;
    onebyone.push_back(3);
    Field.push_back(onebyone);
}

void Maze::CreateMaze()
{
    for(int i = 0; i < rows; i++){
        std::vector<int> new_row;
        for(int j = 0; j < columns; j++){
            if(i == 0 && j == 0){
            new_row.push_back(7);
            }
            else if(i == rows - 1 && j == columns - 1){
            new_row.push_back(11);
            }
            else{
            new_row.push_back(15);
            } 
        }
        Field.push_back(new_row);
    }  
}

void Maze::NotVisited()
{
    for(int i = 0; i < rows; i++){
        std::vector<bool> new_bool;
        for(int j = 0; j < columns; j++){
        new_bool.push_back(false);
        }
    Status.push_back(new_bool);
    } 
}

void Maze::MazeGenerator()
{
    std::srand(seed);
    std::vector<std::pair<int, int>> track;
    std::pair<int, int> current;
    std::pair<int, int> neigh;
    std::vector<std::pair<int, int>> neighbors;
    Status[0][0] = true;
    track.push_back(std::make_pair(0, 0));
    while(!track.empty()){
        std::vector<std::pair<int, int>> neighbors;
        current = track.back();
        track.pop_back();
        //North
        if(current.first - 1 >= 0){
            if(Status[current.first - 1][current.second] == false){
                neighbors.push_back(std::make_pair(current.first - 1, current.second));
            }
        }
        //South
        if(current.first + 1 < rows){
            if(Status[current.first + 1][current.second] == false){
                neighbors.push_back(std::make_pair(current.first + 1, current.second));
            }
        }
        //East
        if(current.second + 1 < columns){
            if(Status[current.first][current.second + 1] == false){
                neighbors.push_back(std::make_pair(current.first, current.second + 1));
            }    
        }
        //West
        if(current.second - 1 >= 0){
            if(Status[current.first][current.second - 1] == false){
                neighbors.push_back(std::make_pair(current.first, current.second - 1));
            }
        }
        if(!neighbors.empty()){
            track.push_back(std::make_pair(current.first, current.second));
            int idx = std::rand() / ((RAND_MAX + 1u) / neighbors.size());
            neigh = neighbors[idx];
            //std::cout << neigh.first << neigh.second << ") "; 
            if(neigh.first < current.first){
                Field[current.first][current.second] -= 8;
                Field[neigh.first][neigh.second] -= 4;
            }
            else if(neigh.first > current.first){
                Field[current.first][current.second] -= 4;
                Field[neigh.first][neigh.second] -= 8;
            }
            else if(neigh.second > current.second){
                Field[current.first][current.second] -= 2;
                Field[neigh.first][neigh.second] -= 1;
            }
            else{
                Field[current.first][current.second] -= 1;
                Field[neigh.first][neigh.second] -= 2;
            }
            Status[neigh.first][neigh.second] = true;
            track.push_back(std::make_pair(neigh.first, neigh.second));
        }
    }   
} 

void Maze::Maze_Out()
{
    std::ofstream output_file(OutputName);
    for (std::vector<std::vector<int>>::const_iterator i = (Field).begin(); i != (Field).end(); ++i) {
        for (std::vector<int>::const_iterator j = i->begin(); j != i->end(); ++j) {
            output_file << *j << " ";
        }
        output_file << "\n";
    }    
}  
