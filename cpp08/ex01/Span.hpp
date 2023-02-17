#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <stdexcept>
# include <vector>

class Span
{
private:
    unsigned int _n;
    std::vector<int> _v;
public:
    Span();
    Span(unsigned int N);
    Span(const Span &obj);
    Span &operator=(const Span &a);
    void addNumber(int nb);
    void add_range(std::vector<int> &v2);
    int longestSpan();
    int shortestSpan();
    ~Span();
};




# endif
