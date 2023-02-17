#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <algorithm>
# include <stdexcept>
# include <vector>

template<typename T>
typename T::iterator easyfind(T& container, int val) {
    typename T::iterator it = std::find(container.begin(), container.end(), val);
    if (it == container.end())
        throw std::invalid_argument("Value not found");
    return it;
}

# endif