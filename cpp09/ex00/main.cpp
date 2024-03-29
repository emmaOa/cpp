/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:50:43 by iouazzan          #+#    #+#             */
/*   Updated: 2023/03/28 15:25:05 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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
        pr.value = strtod(s.c_str(), NULL);
        s.clear();
        mp[pr.key] = pr.value;
        pr.key.clear();
    }
    data.close();

    std::map<std::string, float>::iterator it;
    std::map<std::string, float>::iterator up;
    pair *pr2;
    int dt_vl = 0;
    std::string f_line = "date | value";
    std::ifstream file;
    file.open(arv[1]);
    if (!file.is_open())
        file.open(arv[1], std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
    std::string sp = " ";
    std::string line2;
    while (getline(file, line2))
    {
        if (!(line2 == f_line && dt_vl == 0))
        {
            pr2 = check_line(line2);
            if (pr2->valide == 1)
            {
                if (valide_date(pr2->key) == true && check_date(pr2->key) == true)
                {
                    up = mp.upper_bound(pr2->key);
                    if (up != mp.begin())
                        up--;
                    std::cout << pr2->key << " => " << pr2->value << " = " << pr2->value * up->second << "\n";
                }
                else
                {
                    std::cout << "Error: bad input\n";
                }
            }
        }
        dt_vl++;
    }
    file.close();
    return 0;
}
