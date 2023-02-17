/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 22:24:02 by iouazzan          #+#    #+#             */
/*   Updated: 2023/02/16 16:33:28 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <class T> MutantStack<T>::MutantStack()
{
}

template <class T> MutantStack<T>::MutantStack(const MutantStack &obj)
{
    *this = obj;
}

template <class T> MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &a)
{
    return *this;
}

template <class T> MutantStack<T>::~MutantStack()
{
}
