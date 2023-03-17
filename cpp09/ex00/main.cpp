/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:50:43 by iouazzan          #+#    #+#             */
/*   Updated: 2023/03/17 20:32:03 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int dt_to_int(date_ln *date, int tst, std::string str)
{
    if (tst == 0)
    {
        try{
            date->y = atof(str.c_str());
        }
        catch (const std::invalid_argument & e) {
            std::cout << "Error: bad input [d :0 - 3]=> " << str << std::endl;
            return -1;
        }

        catch (const std::out_of_range & e) {
            std::cout << "Error: too large a number [d : 0 - 4]." << "\n";
            return -1;
        }
    }
    else if (tst == 1)
    {

        try{
            date->m = atof(str.c_str());
        }
        catch (const std::invalid_argument & e) {
            std::cout << "Error: bad input [d : 1 - 3]=> " << str << std::endl;
            return -1;
        }

        catch (const std::out_of_range & e) {
            std::cout << "Error: too large a number [d : 1 - 4]." << "\n";
            return -1;
        }  
    }
    else
    {
        try{
            date->d = atof(str.c_str());
        }
        catch (const std::invalid_argument & e) {
            std::cout << "Error: bad input [d : 2 - 3]=> " << str << std::endl;
            return -1;
        }

        catch (const std::out_of_range & e) {
            std::cout << "Error: too large a number [d : 2 - 4]." << "\n";
            return -1;
        }
    }
    return 1;
}

int check_date_utl(date_ln *date, size_t i, int if_d, std::string dt)
{
    std::string str;
    while (i < (dt.length() - 1) && (dt[i] != '-' || (dt[i] != ' ' && if_d == 2)))
    {
        if ((dt[i] < '0' || dt[i] > '9'))
        {
            std::cout << "Error: bad input [d : 1]=> " << dt << std::endl;
            return 0;
        }
        str += dt[i];
        i++;
    }
    if (dt[i] != '-')
    {
        if (if_d == 0 || if_d == 1)
        {
            std::cout << "Error: bad input [d : 2]=> " << dt << std::endl;
            return 0;
        }
        else{
            if (dt[i] != ' ')
            {
                std::cout << "Error: bad input [d : 3]=> " << dt << std::endl;
                return 0;
            }
            if (dt_to_int(date, if_d, str) < 1)
                return 0;
        }
    }
    else{
        if (dt_to_int(date, if_d, str) < 1)
            return 0;
    }
    return i;
}

date_ln *check_date(std::string dt)
{
    date_ln *date = new date_ln();
    size_t i = 0;
    
    date->v = -1;
    i = check_date_utl(date, i, 0, dt);
    if (i == 0)
        return date;
    if (date->y <  2009 || date->y >  2011)
    {
        std::cout << "Error: bad input [d : 5]=> " << date->y << std::endl;
        return date;
    }
    i++;
    i = check_date_utl(date, i, 1, dt);
    if (i == 0)
        return date;
    if (date->m <  1 || date->m >  12)
    {
        std::cout << "Error: bad input [d : 6]=> " << date->m << std::endl;
        return date;
    }
    i++;
    i = check_date_utl(date, i, 2, dt);
    if (i == 0)
        return date;
    if (date->d <  1 || date->d >  30)
    {
        std::cout << "Error: bad input [d : 7]=> " << date->m << std::endl;
        return date;
    }
    date->v = 1;
    return date;

}

int check_nb(std::string nb)
{
    size_t i = 0;
    
    while (i < nb.length())
    {
        while (nb[i] == ' ' || nb[i] == '\t')
            i++;
        
        if (nb[i] < '0' || nb[i] > '9')
        {
            if (nb[i] == '.')
            {
                if ((i == 0 || i == (nb.length() - 1) || (i != 0 && nb[i - 1] == '.')))
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
    while (line[i] != pipe)
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
    if (pr->value / line.length() != 0)
    {
        
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

int main(int arc, char *arv[])
{
    if (arc != 2 || !arv[1][0])
    {
        if (arc < 2)
            printf("Error: could not open file.");
        else
            printf("Error: NB arguments not valide");
        return 1;
    }

    
    std::map<std::string, float>mp;
    std::ifstream data;
    std::string line1;
    pair pr;
    

    char separator = ',';

    data.open("data.csv");
    if (!data.is_open()){
        std::cout << "Open failed" << std::endl;
        return 1;
    }

    size_t i;
    std::string s;
    getline(data, line1);
    while (getline(data, line1)) {
        i  = 0;
        while (line1[i] != separator)
        {
            pr.key += line1[i];
            i++;
        }
        i++;
        while (i < line1.length())
        {
            s += line1[i];
            i++;
        }
        pr.value = std::stof(s);
        s.clear();
        mp[pr.key] = pr.value;
        pr.key.clear();
    }
    data.close();

    // std::map<std::string, float>::iterator it;
    // for(it=mp.begin();it!=mp.end();it++)
    // {
    //     std::cout<<it->first<<" "<<it->second<< std::endl;
    // }
        //  exit(0);
    date_ln *date;
    pair *pr2;
    std::ifstream file;
    file.open(arv[1]);
    if (!file.is_open()){
        std::cout << "Open failed" << std::endl;
        return 1;
    }
    std::string line2;
    getline(file, line2);
    while (getline(file, line2))
    {
        pr2 = check_line(line2);
        if (pr2->valide == 1)
        {
            // std::cout<<pr2->key<<" "<<pr2->value<< std::endl;
            date = check_date(pr2->key);
            if (date->v == 1)
            {
                
                // std::cout << date->y << "-" << date->m << "-" << date->d << "\n";
                std::cout << pr2->key << "\n";
            }
        }
    }
    file.close();
    return 0;
}
