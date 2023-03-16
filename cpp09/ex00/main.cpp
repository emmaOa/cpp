/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:50:43 by iouazzan          #+#    #+#             */
/*   Updated: 2023/03/16 19:48:59 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


date_ln *check_date(std::string dt)
{
    date_ln *date = new date_ln();
    size_t i = 0;
    std::string str;
    
    date->v = -1;
    std::cout <<"---->>" << dt << std::endl;

    while (dt[i] == ' ' || dt[i] == '\t')
        i++;
    while (dt[i] != '-' && i < dt.length())
    {
        if (dt[i] < '0' || dt[i] > '9')
        {
            std::cout << "Error: bad input [d : 1]=> " << dt << std::endl;
            return date;
        }
        str += dt[i];
        i++;
    }
    std::cout << dt[i - 1] << "\n";
    if (i == dt.length() || dt[i] != '-' || (dt[i] == '-' && dt[i - 1] == '-'))
    {
        std::cout << "Error: bad input [d : 2]=> " << dt << std::endl;
        return date;
    }
    
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
        pr->value =atof(nb.c_str());
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
            check_date(pr2->key);
        }
    }
    file.close();
    return 0;
}
