/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:30:30 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/25 18:38:21 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    /*const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;*/
    // system("leaks Animal");

    Animal* animals[10];
    int i = 0;

    while (i < 10)
    {
        if (i < 5)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
        i++;
    }
    for (int j = 0; j < 10; j++) {
       animals[j]->makeSound();
    }

    for (int j = 0; j < 10; j++) {
        delete animals[j];
    }
    return 0;
}
