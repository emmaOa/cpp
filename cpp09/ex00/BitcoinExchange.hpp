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

int check_date_utl(size_t i, int if_d, std::string dt);
bool check_date(std::string dt);
int check_nb(std::string nb);
pair *check_line(std::string line);
bool valide_date(std::string date);
#endif