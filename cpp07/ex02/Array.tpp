/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:50:05 by iouazzan          #+#    #+#             */
/*   Updated: 2023/02/13 21:52:44 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include<array>

template <class T> Array<T>::Array() : number(), s(0){
    std::cout << "constructor called\n";
}

template <class T> Array<T>::Array(unsigned int n){
    number = new T[n];
    s = n;
    std::cout << "Construction with parameter called\n";
}

template <class T> T &Array<T>::operator[](int i) {
     try{
          if (i > s )
            throw(i);
    }
       catch( int i){
        std::cout << i << " is out of bounds\n";
    }
   return number[i];
}

template <class T> Array<T>::Array(const Array &obj){
    if (this != &obj) {
        number = new T (*obj.number);
    }
    *this = obj;
    std::cout << "Construction with parameter called\n";
}

template <class T> Array<T> &Array<T>::operator=(const Array<T> &a)
{
    std::cout << "Copy assignment operator called\n";
        if (this != &a) {
        delete number;
        number = new T(*a.number);
    }
    s = a.s;
    number = a.number;
    return *this; 
}

template <class T> int  Array<T>::size() const
{
    return s;
}

template <class T> Array<T>::~Array(){
    std::cout << "destructor called\n";
}