#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template <class T>
class Array
{
    private:
        T *number;
        int s;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &obj);
        Array &operator=(const Array &a);
        T &operator[](int i);
        int size() const;
        ~Array();
};
# endif