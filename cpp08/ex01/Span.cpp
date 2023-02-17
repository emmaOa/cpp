/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:13:10 by iouazzan          #+#    #+#             */
/*   Updated: 2023/02/16 15:57:33 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0)
{
}

Span::Span(unsigned int N) : _n(N)
{
}

Span::Span(const Span &obj) : _n(obj._n)
{
    *this = obj;
}

Span &Span::operator=(const Span &a)
{
    _v = a._v;
    return *this; 
}

void Span::addNumber(int nb)
{
    if (_v.size() == _n)
        throw std::invalid_argument("we don't have size enough");
    _v.push_back(nb);
}

void Span::add_range(std::vector<int> &v2)
{
    std::vector <int>::iterator a;
    a = v2.begin();
    int len = v2.size();
    for (int i = 0; i < len; i++)
    {
        _v.push_back(*a);
        a++;
    }
}

int Span::longestSpan()
{
    if (_v.size() < 2)
        throw std::invalid_argument("we don't have enough argument");
    int mx = *max_element(_v.begin(), _v.end());
    int mn = *min_element(_v.begin(), _v.end());
    return (mx - mn);
}

int Span::shortestSpan()
{
    if (_v.size() < 2)
        throw std::invalid_argument("we don't have enough argument");

    sort(_v.begin(), _v.end());
    int tmp = _v[1] - _v[0];
    for (unsigned int i = 1; i < _v.size() - 1; i++)
    {
        if ((_v[i + 1] - _v[i]) < tmp)
            tmp = _v[i + 1] - _v[i];
    }
    return (tmp);
}

Span::~Span()
{
}