/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:26:19 by iouazzan          #+#    #+#             */
/*   Updated: 2023/02/13 19:52:56 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    Base * p, * g;
    Base * r = new C;
    p = new B;
    g = generate();
    identify(g);    identify(*g);
    identify(p);    identify(*p);
    identify(r);    identify(*r);
    delete g;
    delete r;
    delete p;
}