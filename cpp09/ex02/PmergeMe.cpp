/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:50:01 by iouazzan          #+#    #+#             */
/*   Updated: 2023/03/26 17:00:55 by iouazzan         ###   ########.fr       */
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

void mrg(std::vector<int>& vc, int b, int m, int l)
{
    int i = b;
    int k = b;
    int j = m;
    int tp[4000];

    while ((i < m) && (j < l))
    {
        if (vc[i] < vc[j])
        {

            tp[k] = vc[i];
            i++;
        }
        else
        {
            tp[k] = vc[j];
            j++; 
        }
        k++;
    }
    while (j < l)
    {
        tp[k] = vc[j];
        k++;
        j++;
    }
    while (i <= m)
    {
        tp[k] = vc[i];
        k++;
        i++;
    }
    for (i = b; i < l; i++)
        vc[i] = tp[i];
}

void mrgsrt(std::vector<int>& vc, int b, int l)
{
    if (l - b <= 5)
        insrt(vc, b, l);
    else
    {
        int m = (b + l) / 2;
        mrgsrt(vc, b, m);
        mrgsrt(vc, m , l);
        mrg(vc, b, m , l);
    } 
}

void mrgsrt_D(std::deque<int>& d, int b, int l)
{
    if (l - b <= 5)
        insrt_D(d, b, l);
    else
    {
        int m = (b + l) / 2;
        mrgsrt_D(d, b, m);
        mrgsrt_D(d, m , l);
        mrg_D(d, b, m , l);
    } 
}

void insrt_D(std::deque<int>& d, int b, int l)
{
    for (int i = b; i < l; i++)
    {
        int j = i;
        int tmp = d[i];
        while ((j > b) && (tmp < d[j - 1]))
        {
            d[j] = d[j - 1];
            j--;
        }
        d[j] = tmp;
    }
}

void mrg_D(std::deque<int>& d, int b, int m, int l)
{
    int i = b;
    int k = b;
    int j = m;
    int tp[40000];

    while ((i < m) && (j < l))
    {
        if (d[i] < d[j])
        {

            tp[k] = d[i];
            i++;
        }
        else
        {
            tp[k] = d[j];
            j++; 
        }
        k++;
    }


    while (j < l)
    {
        tp[k] = d[j];
        k++;
        j++;
    }

    while (i <= m)
    {
        tp[k] = d[i];
        k++;
        i++;
    }

    for (i = b; i < l; i++)
        d[i] = tp[i];
}