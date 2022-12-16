#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

//This function reads the input file of cells and moves the data to a 2D vector
void readFile(std::vector<std::vector<int>> &cells, std::string fname){

    std::ifstream inFile(fname);
    std::string line_hold;

    while (std::getline(inFile, line_hold)) {
        std::vector <int> new_row;
        std::istringstream stream(line_hold);
        int val;
        while(stream >> val) {
            new_row.push_back(val);
        }
        cells.push_back(new_row);
    }
}

//This function is responsible for counting the number of cells
int count_4(std::vector<std::vector<int>> &cells, std::vector<std::pair<int,int>> &hold, int cx, int cy, int stcell, int rows,int cols)
{
    //Base case
    if((cx-1 < 0 || cells[cx-1][cy] != stcell) && (cx+1 >= rows || cells[cx+1][cy] != stcell) && (cy-1 < 0 || cells[cx][cy-1] != stcell) && (cy+1 >= cols || cells[cx][cy+1] != stcell) && (hold.empty() == true)){
        return 0;
    }
    else{
        //North
        if(cx - 1 >= 0){
            if(cells[cx - 1][cy] == stcell){
                cells[cx-1][cy] = 0;
                hold.push_back(std::make_pair(cx-1, cy));
            }
        }
        //South
        if(cx + 1 < rows){
            if(cells[cx + 1][cy] == stcell){
                cells[cx+1][cy] = 0;
                hold.push_back(std::make_pair(cx+1, cy));       
            }
        }
        //West
        if(cy-1 >= 0){
            if(cells[cx][cy-1] == stcell){
                cells[cx][cy-1] = 0;
                hold.push_back(std::make_pair(cx, cy-1));                    
            }
        }
        //East
        if(cy + 1 < cols){
            if(cells[cx][cy+1] == stcell){
                cells[cx][cy+1] = 0;
                hold.push_back(std::make_pair(cx, cy+1));         
            }
        }
        if(!hold.empty()){
            cx = hold[0].first;
            cy = hold[0].second;
            hold.erase(hold.begin());
            return 1 + count_4(cells, hold, cx, cy, stcell, rows, cols);
        }
    }
}

//This function is responsible for counting the number of cells
int count_8(std::vector<std::vector<int>> &cells, std::vector<std::pair<int,int>> &hold, int cx, int cy, int stcell, int rows, int cols)
{
    //Base case
    if((cx+1 >= rows || cy-1 < 0 || cells[cx+1][cy-1] != stcell) && (cx+1 >= rows || cy+1 >= cols || cells[cx+1][cy+1] != stcell) && (cx-1 < 0 || cy-1 < 0 || cells[cx-1][cy-1] != stcell) && (cx-1 < 0 || cy+1 >= cols || cells[cx-1][cy+1] != stcell) && (cx-1 < 0 || cells[cx-1][cy] != stcell) && (cx+1 >= rows || cells[cx+1][cy] != stcell) && (cy-1 < 0 || cells[cx][cy-1] != stcell) && (cy+1 >= cols || cells[cx][cy+1] != stcell) && (hold.empty() == true)){
        return 0;
    }
    else{
        //Northwest
        if(cx-1 >= 0 && cy-1 >= 0){
            if(cells[cx-1][cy-1] == stcell){
                cells[cx-1][cy-1] = 0;
                hold.push_back(std::make_pair(cx-1, cy-1));
            }
        }
        //North
        if(cx-1 >= 0){
            if(cells[cx-1][cy] == stcell){
                cells[cx-1][cy] = 0;
                hold.push_back(std::make_pair(cx-1, cy));
            }
        }
        //Northeast
        if(cx-1 >= 0 && cy+1 < cells[cx].size()){
            if(cells[cx-1][cy+1] == stcell){
                cells[cx-1][cy+1] = 0;
                hold.push_back(std::make_pair(cx-1, cy+1));
            }
        }
        //Southwest
        if(cx+1 < rows && cy-1 >= 0){
            if(cells[cx+1][cy-1] == stcell){
                cells[cx+1][cy-1] = 0;
                hold.push_back(std::make_pair(cx+1, cy-1));
            }
        }
        //South
        if(cx+1 < rows){
            if(cells[cx+1][cy] == stcell){
                cells[cx+1][cy] = 0;
                hold.push_back(std::make_pair(cx+1, cy));       
            }
        }
        //Southeast
        if(cx+1 < rows && cy+1 < cols){
            if(cells[cx+1][cy+1] == stcell){
                cells[cx+1][cy+1] = 0;
                hold.push_back(std::make_pair(cx+1, cy+1));
            }
        }
        //East
        if(cy+1 < cols){
            if(cells[cx][cy+1] == stcell){
                cells[cx][cy+1] = 0;
                hold.push_back(std::make_pair(cx, cy+1));                    
            }
        }
        //West
        if(cy-1 >= 0){
            if(cells[cx][cy-1] == stcell){
                cells[cx][cy-1] = 0;
                hold.push_back(std::make_pair(cx, cy-1));         
            }
        }
        //Checks remaining coordinates
        if(!hold.empty()){
            cx = hold[0].first;
            cy = hold[0].second;
            hold.erase(hold.begin());
            return 1 + count_8(cells, hold, cx, cy, stcell, rows, cols);
        }
    }
}

int main(int argc, char** argv)
{
    std::string fname = argv[1];
    int rows = atoi(argv[2]);
    int cols = atoi(argv[3]);
    int curr_x = atoi(argv[4]);
    int curr_y = atoi(argv[5]);
    curr_x--;
    curr_y--;
    int conn = atoi(argv[6]);
    int total = 0;
    std::vector<std::vector<int>> cells;
    std::vector<std::pair<int,int>> hold;
    readFile(cells, fname);
    int stcell = 1;
    if(cells[curr_x][curr_y] == 1){
        total++;
        cells[curr_x][curr_y] = 0;
        if(conn == 4){
            total += count_4(cells, hold, curr_x, curr_y, stcell, rows, cols);
            std::cout << total << std::endl;
        }
        else{
            total += count_8(cells, hold, curr_x, curr_y, stcell, rows, cols);
            std::cout << total << std::endl;        
        }
    }
    else{
        std::cout << 0 << std::endl;
    }
}
