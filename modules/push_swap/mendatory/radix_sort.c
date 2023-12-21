/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:40:52 by achappui          #+#    #+#             */
/*   Updated: 2023/12/21 22:15:13 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned int get_digit(unsigned int number, unsigned int digitpos)
{
	while (digitpos-- > 0)
        number /= 10;
    return (number % 10);
}

static void	rearange_sorted_array(int *arr, int *tmp_arr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (arr[i] >= 0)
		i++;
	j = 0;
	while (i < size)
		tmp_arr[j++] = arr[i++];
	i = 0;
	while (j < size)
		tmp_arr[j++] = arr[i++]; 
	i = -1;
	while (++i < size)
		arr[i] = tmp_arr[i];
}

static void	unsigned_sorting(unsigned int *arr, unsigned int *tmp_arr, \
								unsigned int size)
{
	unsigned int	digitpos;
	unsigned int	buckets[10];
	unsigned int	i;

	digitpos = 0;
	while (digitpos < 10)
	{
        i = -1;
		while (++i < 10)
			buckets[i] = 0;
		i = -1;
		while (++i < size)
			buckets[get_digit(arr[i], digitpos)]++;
        i = 0;
		while (++i < 10)
			buckets[i] += buckets[i - 1];
		i = size;
		while (i-- > 0)
			 tmp_arr[--buckets[get_digit(arr[i], digitpos)]] = arr[i];
        i = -1;
		while (++i < size)
			arr[i] = tmp_arr[i];
        digitpos++;
    }
}

int *radix_sort(int arr[], unsigned int size)
{
    int	*tmp_arr;

	if (size <= 1)
		return (arr);
	tmp_arr = malloc(size * sizeof(int));
	if (!tmp_arr)
		return (NULL);
	unsigned_sorting((unsigned int *)arr, (unsigned int *)tmp_arr, size);
	if (arr[size - 1] < 0)
		rearange_sorted_array(arr, tmp_arr, size);
    free(tmp_arr);
	return (arr);
}
