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
        if (isdigit(arv[1][i]))
        {
            stc.push(arv[1][i] - '0');
        }
        else if (is_opr(arv[1][i]) == 1)
        {
            op.push(arv[1][i]);
            if (stc.size() > 1)
            {
                a = stc.top();
                stc.pop();
                b = stc.top();
                stc.pop();
            // std::cout << a << ' ' << b << std::endl;
            // std::cout << opr(b, a, arv[1][i]) << std::endl;
                stc.push(opr(b, a, op.top()));
            }
        }
        else
        {
            std::cout << "Error\n";
            return 1;
        }
        i++;
    }
    std::cout << stc.top() << std::endl;
    return 0;
}

// int main(int arc, char *arv[])
// {
//     std::stack<int> nb;
//     std::stack<char> op;
//     int i = 0;
//     int a, b;
//     if (arc != 2)
//         return 1;
//     while (arv[1][i])
//     {
//         while (arv[1][i] && arv[1][i] == ' ')
//             i++;
//         if (isdigit(arv[1][i]))
//             nb.push(arv[1][i] - '0');
//         else if (is_opr(arv[1][i]) == 1)
//             op.push(arv[1][i]);
//         else
//         {
//             std::cout << "Error\n";
//             return 1;
//         }
//         i++;
//     }
//     while (!op.empty())
//     {
//         a = nb.top();
//         nb.pop();
//         b = nb.top();
//         nb.pop();
//             std::cout << a << ' ' << b << std::endl;
//             std::cout << opr(b, a, op.top()) << std::endl;
//         nb.push(opr(b, a, op.top()));
//         op.pop();
//     }
//     std::cout << nb.top() << std::endl;
//     return 0;
// }