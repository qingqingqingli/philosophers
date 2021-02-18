//
// Created by qli on 18/02/2021.
//

#include "../headers/support_functions.h"

int		ft_atoi(const char *str)
{
	long int i;
	long int neg;
	long int output;

	i = 0;
	neg = 1;
	output = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		neg = neg * -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if (output * 10 + str[i] - '0' < output && neg == 1)
			return (-1);
		if (output * 10 + str[i] - '0' < output && neg == -1)
			return (0);
		output = output * 10 + str[i] - '0';
		i++;
		if (str[i] < '0' || str[i] > '9')
			return ((int)output * neg);
	}
	return ((int)output * neg);
}