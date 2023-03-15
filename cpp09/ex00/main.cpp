/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:50:43 by iouazzan          #+#    #+#             */
/*   Updated: 2023/03/15 17:00:35 by iouazzan         ###   ########.fr       */
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

    std::ifstream file;
    file.open(arv[1]);
    if (!file.is_open()){
        std::cout << "Open failed" << std::endl;
        return 1;
    }
    std::string line;
    // getline(file, line);
    while (getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
    return 0;
}