#pragma once

class Maze{
    private:
        int seed;
        std::string OutputName;

    public:
        int rows;
        int columns;
        Maze(char* temp_seed, char* temp_row, char* temp_column, std::string Output);
        std::vector<std::vector<int>> Field;
        std::vector<std::vector<bool>> Status;

        void CreateBox();

        void CreateMaze();

        void NotVisited();

        void MazeGenerator();

        void Maze_Out();   
};
