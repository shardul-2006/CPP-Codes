#include <iostream>
using namespace std;

class stack
{
    public:
    char stack_array[50];
    int top;
    stack(){
        top = -1;
    }
    void push(char symbol){
        if(full())
        cout << "\nStack Overflow";
        else{
            top += 1;
            stack_array[top] = symbol;
        }
    }
    char pop(){
        if(empty())
        return '#';
        else
        return(stack_array[top--]);
    }
    int empty(){
        if(top==1){
            return 1;
        }
        else
        return 0;
    }

    int full(){
        if(top==49){
            return 1;
        }
        else{
            return 0;
        }
    }
};

int main()
{
    
    return 0;
}