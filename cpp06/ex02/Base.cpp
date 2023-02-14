/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:08:08 by iouazzan          #+#    #+#             */
/*   Updated: 2023/02/13 19:53:31 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
    std::cout << "Base destructor called\n";
}

Base * generate(void)
{
    srand(time(0));
    int i = (rand() % 3);
    Base* b;

    switch (i)
    {
        case 0:
            b = new A;
            break;
        case 1:
            b = new B;
            break;
        case 2:
            b = new C;
            break;
    }
    return b;
}

void identify(Base* p)
{
    A* a = dynamic_cast<A *>(p);
    B* b = dynamic_cast<B *>(p);
    C* c = dynamic_cast<C *>(p);
    
    if (a)
    {
        std::cout << "his type is A\n";
        return ;
    }
    else if (b)
    {
        std::cout << "his type is B\n";
        return ;
    }
    else if (c)
    {
        std::cout << "his type is C\n";
        return ;
    }
    else
        std::cout << "it's not a Base type\n";
    return ;
}

void identify(Base& p)
{
    try{
        A& a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "his type is A\n";
        return ;
    }
    catch(std::bad_cast &e){
    }

    try{
        C& c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "his type is C\n";
        return ;
    }
    catch(std::bad_cast &e){
    }

    try{
        B& b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "his type is B\n";
        return ;
    }
    catch(std::bad_cast &e){
    }
}