#ifndef  PMERGEME_HPP
# define  PMERGEME_HPP
# include <iostream>
# include <algorithm>
# include <stdexcept>
# include <fstream>
# include <ctime>
# include <climits>
#include <cmath>
#include <vector>
#include <sstream>


void insrt(std::vector<int>& vc, int b, int l);
void mrg(std::vector<int>& vc, int b, int m, int l);
void mrgsrt(std::vector<int>& vc, int b, int l);
void mrgsrt_D(std::deque<int>& d, int b, int l);
void insrt_D(std::deque<int>& d, int b, int l);
void mrg_D(std::deque<int>& d, int b, int m, int l);

# endif