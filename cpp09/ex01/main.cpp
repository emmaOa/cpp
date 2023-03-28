/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:25:36 by iouazzan          #+#    #+#             */
/*   Updated: 2023/03/28 14:52:43 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"

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
            break;
        if (isdigit(arv[1][i]) || is_opr(arv[1][i]) == 1)
        {
            if (isdigit(arv[1][i]))
            {
                stc.push(arv[1][i] - '0');
            }
            else{
                    op.push(arv[1][i]);
                    if (stc.size() > 1)
                    {
                        a = stc.top();
                        stc.pop();
                        b = stc.top();
                        stc.pop();
                        if (a == 0 && op.top() == '/')
                        {
                            std::cout << "Error\n";
                            return 1;
                        }
                        stc.push(opr(b, a, op.top()));
                        op.pop();
                    }
                }
        }
        else
        {
            std::cout << "Error\n";
            return 1;
        }
        i++;
    }
    if (stc.size() != 1)
    {
        std::cout << "Error\n";
        return 1;
    }
    std::cout << stc.top() << std::endl;
    return 0;
}
