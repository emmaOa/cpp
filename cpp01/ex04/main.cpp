/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:25:56 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/14 01:22:27 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "losers.hpp"

int main(int argc, char *argv[])
{
    if (argc != 4 || !argv[2][0] || !argv[3][0])
    {
 		std::cout << "invaled input \n";
        return (0);
    }
	std::string new_name = ".replace";
	std::string content;

    std::ifstream file;
    file.open(argv[1]);
    if (!file.is_open()){
        std::cout << "Open failed" << std::endl;
        return 1;
    }

	std::ofstream new_file;
 	new_file.open(argv[1] + new_name);
	if (!new_file.is_open()){
        std::cout << "Open failed" << std::endl;
        return 1;
    }
	while (getline(file, content))
		new_file << new_cont(content, argv[2], argv[3]) << std::endl;
}
