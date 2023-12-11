#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>
#include <typeinfo>
#include <cstdlib>
#include <ctime>

template <typename arrAddr, typename arrLen, typename func>	void	iter(arrAddr *arr, arrLen len, func function(arrAddr&))
{
	for (int i = 0; i < len; i++)
		function(arr[i]);
}

#endif