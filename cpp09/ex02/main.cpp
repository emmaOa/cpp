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

void insrt(std::vector<int>& vc, int b, int l)
{
    for (int i = b; i < l; i++)
    {
        int j = i;
        int tmp = vc[i];
        while ((j > b) && (tmp < vc[j - 1]))
        {
            vc[j] = vc[j - 1];
            j--;
        }
        vc[j] = tmp;
    }
}

void mrg(std::vector<int>& vc, std::vector<int>& vc2, int b, int m, int l)
{
    int i = b;
    int k = b;
    int j = m;

    while ((i < m) && (j < l))
    {
        if (vc[i] < vc[j])
        {
            vc2[k] = vc[i];
            i++;
        }
        else
        {
            vc2[k] = vc[j];
            j++; 
        }
        k++;
    }

    while (j < l)
    {
        vc2[k] = vc[j];
        k++;
        j++;
    }

    while (i <= m)
    {
        vc2[k] = vc[i];
        k++;
        i++;
    }

    for (i = b; i < l; i++)
        vc[i] = vc2[i];
}

void mrgsrt(std::vector<int>& vc, std::vector<int>& vc2, int b, int l)
{
    if (l - b <= 5)
        insrt(vc, b, l);
    else
    {
        int m = (b + l) / 2;
        mrgsrt(vc, vc2, b, m);
        mrgsrt(vc, vc2, m , l);
        mrg(vc, vc2, b, m , l);
    } 
}

int main(int arc, char *arv[])
{
    if (arc < 2)
        return 1;
    int len = arc - 1;
    int nb;
    
    std::vector<int> v, v2;
    std::vector<int>::iterator it;
    v.reserve(arc);
    v2.reserve(arc);
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
        std::cout << *it << " ";
    }
    std::cout << "\n";
    mrgsrt(v, v2, 0, len);
    for (it = v.begin(); it < v.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}