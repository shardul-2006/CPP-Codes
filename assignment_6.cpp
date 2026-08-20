#include <iostream>
#include <cctype>
using namespace std;

class stack
{
public:
    char stack_array[50];
    int top;

    stack()
    {
        top = -1;
    }

    void push(char symbol)
    {
        if(full())
            cout << "\nStack Overflow";
        else
        {
            top += 1;
            stack_array[top] = symbol;
        }
    }

    char pop()
    {
        if(empty())
            return '#';
        else
            return(stack_array[top--]);
    }

    int empty()
    {
        if(top == -1)
            return 1;
        else
            return 0;
    }

    int full()
    {
        if(top == 49)
            return 1;
        else
            return 0;
    }

    char peek()
    {
        if(empty())
            return '#';
        else
            return stack_array[top];
    }
};

// Function to determine precedence of operators
int precedence(char symbol)
{
    if(symbol == '+' || symbol == '-')
        return 1;

    if(symbol == '*' || symbol == '/')
        return 2;

    return 0;
}

// Function to convert infix expression to postfix
void infixToPostfix(char infix[], char postfix[])
{
    stack s;
    int i = 0;
    int j = 0;

    while(infix[i] != '\0')
    {
        char symbol = infix[i];

        // If operand, add directly to postfix
        if(isalnum(symbol))
        {
            postfix[j] = symbol;
            j++;
        }

        // If opening bracket, push into stack
        else if(symbol == '(')
        {
            s.push(symbol);
        }

        // If closing bracket, pop until '('
        else if(symbol == ')')
        {
            while(!s.empty() && s.peek() != '(')
            {
                postfix[j] = s.pop();
                j++;
            }

            if(!s.empty() && s.peek() == '(')
                s.pop();
        }

        // If operator
        else if(symbol == '+' || symbol == '-' ||
                symbol == '*' || symbol == '/')
        {
            while(!s.empty() &&
                  s.peek() != '(' &&
                  precedence(s.peek()) >= precedence(symbol))
            {
                postfix[j] = s.pop();
                j++;
            }

            s.push(symbol);
        }

        i++;
    }

    // Pop remaining operators
    while(!s.empty())
    {
        postfix[j] = s.pop();
        j++;
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[50];
    char postfix[50];

    cout << "Enter infix expression: ";
    cin >> infix;

    infixToPostfix(infix, postfix);

    cout << "Postfix expression: " << postfix;

    return 0;
}