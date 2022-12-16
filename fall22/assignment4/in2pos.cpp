#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>

int precedence(std::string check)
{
    if(check == "+"){
        return 1;
    }
    if(check == "-"){
        return 1;
    }
    else if(check == "/"){
        return 2;
    }
    else if(check == "*"){
        return 2;
    }
    else if(check == "^"){
        return 3;
    }
}

int main(int argc, char** argv)
{
    std::string expression = argv[1];
    std::stack<std::string> output;
    std::stack<std::string> operators;
    std::stringstream check(expression);
    std::string hold;
    std::stack<std::string> end;
    while(getline(check, hold, ' ')){
        if(hold == "+" || hold == "-" || hold == "*" || hold == "/" || hold == "^"){
            if(operators.empty() == true || operators.top() == "("){
                operators.push(hold);
            }
            else if(hold == "^" && operators.top() == "^"){
                operators.push(hold);
            }
            else if(operators.top() == "^"){
                output.push(operators.top());
                operators.pop();
                operators.push(hold);
            }
            else if(precedence(hold) > precedence(operators.top())){
                operators.push(hold);
            }
            else if(precedence(hold) <= precedence(operators.top()) && (hold != "^" && operators.top() != "^")){
                while(precedence(hold) <= precedence(operators.top())){
                    output.push(operators.top());
                    operators.pop();
                    if(operators.empty() == true){
                        break;
                    }
                }
                operators.push(hold);
            }
        }
        else if(hold == "("){
            operators.push(hold);
        }
        else if(hold == ")"){
            while(operators.top() != "("){
                if(!operators.empty()){
                    output.push(operators.top());
                    operators.pop();                    
                }
            }
            operators.pop();
        }
        else{
            output.push(hold);
        }
    }
    while(!operators.empty()){
        output.push(operators.top());
        operators.pop();
    }
    while(!output.empty()){
        end.push(output.top());
        output.pop();
    }
    while(!end.empty()){
        std::cout << end.top() << " ";
        end.pop();
    }
}
