#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <algorithm>
# include <stdexcept>
# include <fstream>
# include <ctime>
#include <map>

struct pair
{
    std::string key;
    float value;
    int valide;
};

struct date_ln
{
    int y;
    int m;
    int d;
    int v;
};

#endif