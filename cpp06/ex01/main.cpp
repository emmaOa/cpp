/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:37:38 by iouazzan          #+#    #+#             */
/*   Updated: 2023/02/12 17:49:05 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main()
{
    Data* a = NULL;
    Data* c = NULL;
    a = new Data;
    uintptr_t b = 0;
    a->a = 0;
    a->b = 1;
    b = serialize(a);
    c = deserialize(b);
    std::cout << c->a << "\n";
    std::cout << c->b << "\n";
    
}