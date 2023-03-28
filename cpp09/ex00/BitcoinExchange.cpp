/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:50:36 by iouazzan          #+#    #+#             */
/*   Updated: 2023/03/28 15:27:27 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int check_date_utl(size_t i, int if_d, std::string dt)
{
    std::string str;
    if (if_d == 2)
    {
        while (i < dt.length())
        {
            if  ((dt[i] < '0' || dt[i] > '9') && (dt[i] != ' ' && i == dt.length()))
            {
                std::cout << "Error: bad input => " << dt << std::endl;
                return 0;
            }
            i++;
        }
        return i;
    }
    while (i < dt.length() && (dt[i] != '-'))
    {
        str += dt[i];
        i++;
    }
    if (dt[i] != '-')
    {
        std::cout << "Error: bad input => " << dt << std::endl;
        return 0;
    }
    return i;
}

bool check_date(std::string dt)
{
    size_t i = 0;
    i = check_date_utl(i, 0, dt);
    if (i == 0)
        return false;
    i++;
    i = check_date_utl(i, 1, dt);
    if (i == 0)
        return false;
    i++;
    i = check_date_utl(i, 2, dt);
    if (i == 0)
        return false;
    return true;

}

int check_nb(std::string nb)
{
    size_t i = 0;
    
    while (i < nb.length())
    {
        while (nb[i] == ' ' || nb[i] == '\t')
            i++;
        if (nb[i] == '+')
            i++;
        if (nb[i] < '0' || nb[i] > '9')
        {
            if (nb[i] == '.' || nb[i] == ',')
            {
                if ((i == 0 || i == (nb.length() - 1) || (i != 0 && (nb[i - 1] == '.' || nb[i - 1] == ','))))
                    return 1;
                i++;
            }
            else
                return 1;
        }
        else
            i++;
    }
    return 0;
}

pair *check_line(std::string line)
{
    char pipe = '|';
    size_t i = 0;
    std::string nb ;
    pair *pr = new pair();
    pr->valide = -1;
    while (i < line.length() && line[i] != pipe)
    {
        pr->key += line[i];
        i++;
    }
    if (i >= line.length())
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return pr;
    }
    i++;
    while (line[i])
    {
        if (line[i] == ',')
           nb += '.';
        else
            nb += line[i];
        i++;
    }
    if(check_nb(nb) == 1)
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return pr;
    }
    try{
        pr->value = atof(nb.c_str());
    }
    catch (const std::invalid_argument & e) {
        std::cout << "Error: bad input => " << line << std::endl;
        return pr;
    }

    catch (const std::out_of_range & e) {
        std::cout << "Error: too large a number." << "\n";
        return pr;
    }
    if (pr->value < 0 || pr->value > 1000)
    {
        if (pr->value < 0)
            std::cout << "Error: negative number." << "\n";
        else
            std::cout << "Error: too large a number." << "\n";
        return pr;
    }
    pr->valide = 1;
    return pr;
}

bool valide_date(std::string date)
{
    struct tm time;

    std::memset(&time, 0, sizeof(time));
    const char* format = "%Y-%m-%d "; 
    char* endptr = strptime(date.c_str(), format, &time);
    if (endptr == NULL || *endptr != '\0')
        return false;
    if ((time.tm_year + 1900 < 2009 || time.tm_year + 1900 > 2022) || time.tm_mday < 1)
        return false;
    for (int i = 1; i < 13; i++)
    {
        if ((time.tm_mon + 1) == 2)
        {
            if ((time.tm_year + 1900 != 2012 && time.tm_year + 1900 != 2016 && time.tm_year + 1900 != 2020) && time.tm_mday > 28)
                return false;
        }
        else if (((time.tm_mon + 1) % 2) != 0)
        {
            if (time.tm_mday > 30)
                return false;
        }
        if (time.tm_year + 1900 == 2009 && time.tm_mon + 1 == 1 && time.tm_mday < 2)
            return false;
    }
    return true;
}
