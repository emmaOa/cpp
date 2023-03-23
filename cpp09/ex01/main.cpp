#include "RPN.hpp"

int is_opr(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/')
        return 1;
    return -1;
}

int opr(int a, int b, char op)
{
    if (op == '+')
        return (a + b);
    if (op == '-')
        return (a - b); 
    if (op == '*')
        return (a * b);
    else
        return (a / b);
}


int main(int arc, char *arv[])
{
    std::stack<int> stc;
    std::stack<char> op;
    int i = 0;
    int a, b;
    if (arc != 2)
        return 1;
    while (arv[1][i])
    {
        while (arv[1][i] && arv[1][i] == ' ')
            i++;
        if (!arv[1][i])
        {
            // std::cout << "----->> "<< arv[1][i] << std::endl;
            break;
        }
        if (isdigit(arv[1][i]) || is_opr(arv[1][i]) == 1)
        {
            if (isdigit(arv[1][i]))
                stc.push(arv[1][i] - '0');
            else{
                op.push(arv[1][i]);
                if (stc.size() == 2)
                {
                    a = stc.top();
                    stc.pop();
                    b = stc.top();
                    stc.pop();
                    // std::cout << b << ' ' << a << std::endl;
                    stc.push(opr(b, a, op.top()));
                    op.pop();
                }
            }
        }
        else
        {
            // std::cout << arv[1][i - 1] << std::endl;
            std::cout << "Error\n";
            return 1;
        }
        i++;
    }
    if (stc.size() > 0)
        std::cout << stc.top() << std::endl;
    return 0;
}
