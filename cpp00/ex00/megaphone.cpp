#include <iostream>

int main(int arc, char **arv)
{
	int i = 1;
	int j;
	if (arc > 1)
	{
		while (arv[i])
		{
			j = 0;
			while (arv[i][j])
			{
				std::cout << (char)toupper(arv[i][j]);
				j++;
			}
			++i;
 		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}