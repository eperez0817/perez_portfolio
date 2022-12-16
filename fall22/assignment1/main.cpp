#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

void readFile(std::vector<std::vector<double>> &image_data, std::string inputfile, std::vector<std::vector<double>> &image_edit){

    std::ifstream inFile(inputfile);
    std::string line_hold;

    while (std::getline(inFile, line_hold)) {
        std::vector <double> new_row;
        std::istringstream stream(line_hold);
        double val;
        while(stream >> val) {
            new_row.push_back(val);
        }
        image_data.push_back(new_row);
        image_edit.push_back(new_row);
    }
}

void writeFile(std::string outputname, std::vector<std::vector<double>> &image_edit, double threshold) {

    std::ofstream output_file(outputname);

    for (std::vector<std::vector<double>>::const_iterator i = (image_edit).begin(); i != (image_edit).end(); ++i) {
        for (std::vector<double>::const_iterator j = i->begin(); j != i->end(); ++j) {
            if (*j < threshold){
                output_file << 0 << " ";
            }
            else{
                output_file << 255 << " ";
            }
        }
        output_file << "\n";
    }
}   

void writeLocFile(std::string outputname, std::vector<std::vector<double>> &Image_data) {

    std::ofstream output_file(outputname);

    for (std::vector<std::vector<double>>::const_iterator i = (Image_data).begin(); i != (Image_data).end(); ++i) {
        for (std::vector<double>::const_iterator j = i->begin(); j != i->end(); ++j) {
            output_file << *j << " ";
        }
        output_file << "\n";
    }
}

double localThresh(std::vector<std::vector<double>> &image_data, int point_i, int point_j, int offset, double R){
    double sd = 0;
    double mean = 0;
    double base = 0;
    double threshold = 0;
    int hori = point_j - offset;
    int vert = point_i - offset;
    int hori_end = point_j + offset;
    int vert_end = point_i + offset;


    std::vector<double> data_store;

    //The following commands parse through the local neighborhood and store the contents into a 1D vector
    for(int i = vert; i <= vert_end; i++){       
        if(i < 0){
                continue;
        }
        else if(i >= image_data.size()){
                continue;
        }
        else{
            for(int j = hori; j <= hori_end; j++){
                if(j < 0){
                    continue;
                }
                else if(j >= image_data[0].size()){
                    continue;
                }
                else{
                    data_store.push_back(image_data[i][j]);              
                }
            }        
        }

    }
    //The following commands are responsible for finding the mean of the neighborhood
    for(int i = 0; i < data_store.size(); i++){
        mean = mean + data_store[i];
    }
    mean = mean / (data_store.size());
    
    //The following commands are responsible for finding the standard deviation of the neighborhood
    for (int i = 0; i < data_store.size(); i++){
        base = data_store[i] - mean;
        sd += pow(base, 2);
    }
    sd = sd / ((data_store.size()));
    sd = sqrt(sd);

    threshold = ((sd) / R);
    threshold = threshold - 1;
    threshold = (threshold * 0.2);
    threshold = (threshold + 1);
    threshold = threshold * mean;
    return threshold;
}

int main(int argc, char** argv){
    //The following commands are responsible for taking in the command line arguments
    std::string type = argv[1];
    std::string inputname = argv[2];
    std::string outputname = argv[3];
    std::string temp = "None";
    std::vector<std::vector<double>> image_data;
    std::vector<std::vector<double>> image_edit;
    double R = 0;
    double threshold = 0;
    int offset = 0;
    double pmax = 0;
    double pmin = 0;
    int neigh_size = 0;
    if(argc == 5){
        temp = argv[4];
        neigh_size = stoi(temp); // converts the given dimension size from the command line argument from string to integer
    }

    //The following commands read the numbers from a desired file and stores them into a one-dimensional array
    std::ifstream inputfile(inputname);
    std::vector<double> numbers;
    double input;
    while(inputfile >> input)
    {
        numbers.push_back(input);
    }
    // sorts the values of the numbers from the desires file into ascending order
    std::sort(numbers.begin(), numbers.end());
    pmin = numbers.front();
    pmax = numbers.back();

    //Reads the values from the original file and stores them into a 2D array
    readFile(image_data, inputname, image_edit);

    //The following commands determine the type of file, and do the corresponding binarizing
    if(type == "global"){
        if(numbers.size() % 2 == 0){
            threshold = ((numbers[numbers.size()/2]) + (numbers[(numbers.size()/2) - 1]))/2;
        }
        else{
            threshold = numbers[numbers.size()/2];
        }
        //The following command is responsible for editing each individual pixel of a file and publishing it to a new file
        writeFile(outputname, image_edit, threshold);    
    }
    else if(type == "local"){
        R = (0.5) * (pmax - pmin);
        offset = (neigh_size)/2;
        for(int i = 0; i < image_data.size(); i++){
            for(int j = 0; j < image_data[i].size(); j++){
                    threshold = localThresh(image_data, i, j, offset, R);
                    
                    //std::cout << image_data[i][j] << " " << threshold << std::endl;
                    if (image_data[i][j] < threshold){
                        image_edit[i][j] = 0;
                    }
                    else{
                        image_edit[i][j] = 255;
                    }
            }
        }
        writeLocFile(outputname, image_edit);
    }
}
