#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template <typename T> void f(T const &a)
{
    std::cout << a << "\n";
}

template <typename T> void iter(T *arry, int y, void (*f)(T const &x))
{
    for (int i = 0; i < y; i++)
       f(arry[i]);
}


# endif