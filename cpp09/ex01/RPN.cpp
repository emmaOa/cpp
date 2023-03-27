/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 20:25:14 by iouazzan          #+#    #+#             */
/*   Updated: 2023/03/26 21:40:45 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
