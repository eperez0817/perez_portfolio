#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>
#include <cmath>

int main(int argc, char** argv)
{
    std::string expression = argv[1];
    std::stack<std::string> output;
    std::stack<std::string> numbers;
    std::stringstream check(expression);
    std::string hold;
    double x, y, z;
    int l;
    while(getline(check, hold, ' ')){
        if(hold == "+" || hold == "-" || hold == "/" || hold == "*" || hold == "^"){
            x = stoi(numbers.top());
            numbers.pop();
            y = stoi(numbers.top());
            numbers.pop();
            if(hold == "+"){
                z = y + x;
                numbers.push(std::to_string(z));
            }
            else if(hold == "-"){
                z = y - x;
                numbers.push(std::to_string(z));
            }
            else if(hold == "*"){
                z = y*x;
                numbers.push(std::to_string(z));
            }
            else if(hold == "/"){
                z = floor(y/x);
                numbers.push(std::to_string(z));
            }
            else if(hold == "^"){
                z = pow(y, x);
                numbers.push(std::to_string(z));
            }
        }
        else{
            numbers.push(hold);
        }
    }
    l = stoi(numbers.top());
    std::cout << l << std::endl;
}
