#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

double evaluate(istringstream& iss)
{
    string token;
    if(iss >> token)
    {
        if(token == "+" || token == "-" || token == "*" || token == "/")
        {
            double a = evaluate(iss);
            double b = evaluate(iss);
            if(token == "+")
                return a + b;
            if(token == "-")
                return a - b;
            if(token == "*")
                return a * b;
            if(token == "/")
                return a / b;
        }
        else
        {
            return stod(token);
        }
    }
    return 0;
}

int main()
{
    string line;
    getline(cin, line);
    istringstream iss(line);
    double result = evaluate(iss);
    printf("%f\n", result);
    return 0;
}