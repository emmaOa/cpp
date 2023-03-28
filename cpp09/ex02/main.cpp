/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:50:46 by iouazzan          #+#    #+#             */
/*   Updated: 2023/03/28 15:04:11 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int arc, char *arv[])
{
    if (arc < 2)
        return 1;
    std::vector<int> v;
    std::deque<int> d;
    std::vector<int>::iterator it;

    for (int i = 1; i < arc; i++)
    {
        if (check_nb(arv[i]) == 1)
        {
            std::cout << "Error\n";
            return 1;
        }
       int nb = atoi(arv[i]);
        if (nb < 0)
        {
            std::cout << "Error\n";
            return 1;
        }
        v.push_back(nb);
    }
    
    for (int i = 0; i < arc - 1; i++)
    {
        d.push_back(v[i]);
    }
    
    std::cout << "Before: ";
    for (it = v.begin(); it < v.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    clock_t start_v = clock();
    mrgsrt(v, 0, arc - 1);
    clock_t end_v = clock();
    std::cout << "After: ";
    for (it = v.begin(); it < v.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    std::cout << "Time to process a range of " << arc - 1 << " elements with std::vector : " \
    << (float)(end_v - start_v) / CLOCKS_PER_SEC * 1000000 << " us\n";

    clock_t start_d = clock();
    mrgsrt_D(d, 0, arc - 1);
    clock_t end_d = clock();

    std::cout << "Time to process a range of " << arc - 1 << " elements with std::deque : " \
    << (float)(end_d - start_d) / CLOCKS_PER_SEC * 1000000 << " us\n";
}