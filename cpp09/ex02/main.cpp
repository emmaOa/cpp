/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:50:46 by iouazzan          #+#    #+#             */
/*   Updated: 2023/03/23 12:29:18 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// void mrg(std::vector<int>& vc, int b, int m, int l)
// {
    
// }

// void insrt(std::vector<int>& vc, int b, int l)
// {
    
// }

void mrgsrt(std::vector<int>& vc, int b, int l)
{
    if (l - b <= 5)
    {
        std::cout << "hi\n";
        // insrt(vc, b, l);        
    }
    else
    {
        int m = (b + l) / 2;
        mrgsrt(vc, b, m);
        mrgsrt(vc, m + 1, l);
        std::cout << "no\n";
        // mrg(vc, b, m + 1 , l);
    }
    
}

int main(int arc, char *arv[])
{
    if (arc < 2)
        return 1;
    int len = arc - 1;
    int nb;
    
    std::vector<int> v;
    std::vector<int>::iterator it;
    v.reserve(arc);
    for (int i = 1; i < arc; i++)
    {
        nb = atoi(arv[i]);
        if (nb < 0)
        {
            std::cout << "Error\n";
            return 1;
        }
        v.push_back(nb);
    }
    for (it = v.begin(); it < v.end(); ++it)
    {
        std::cout << *it << ", ";
    }
    std::cout << "\n";
    mrgsrt(v, 0, len);
}