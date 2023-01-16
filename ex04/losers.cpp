/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   losers.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:14:03 by iouazzan          #+#    #+#             */
/*   Updated: 2023/01/14 01:11:31 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "losers.hpp"

std::string new_cont(std::string cont, std::string s1, std::string s2)
{
	std::string ret;
	size_t i = 0;
	size_t pt = cont.find(s1);

	if (pt == std::string::npos)
		return cont;

	while (pt != std::string::npos)
	{
		if (pt == 0)
			ret.append(s2);
		else
		{
			ret.append(cont.substr(i, pt - i));
			ret.append(s2);
		}
		i = pt + s1.length();
		pt = cont.find(s1, i);
	}
	ret.append(cont.substr(i, cont.length() - i));
    std::cout << ret << std::endl;
	return ret;
}