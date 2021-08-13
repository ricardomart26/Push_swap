/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 02:20:18 by ricardo           #+#    #+#             */
/*   Updated: 2021/08/12 02:23:03 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

stacks_t	ra_funct(stacks_t main, int option)
{
	int	size;
	int	x;
	int	temp;

	temp = main.A[0];
	x = 0;
	size = main.sizeA - 1;
	while (size--)
	{
		main.A[x] = main.A[x + 1];
		x++;
	}
	main.A[x] = temp;
	if (option)
		write(1, "ra\n", 4);
	return (main);
}

stacks_t	rb_funct(stacks_t main, int option)
{
	int	size;
	int	x;
	int	temp;

	temp = main.B[0];
	x = 0;
	size = main.sizeB - 1;
	while (size--)
	{
		main.B[x] = main.B[x + 1];
		x++;
	}
	main.B[x] = temp;
	if (option)
		write(1, "rb\n", 4);
	return (main);
}

stacks_t	rr_funct(stacks_t main, int opt)
{
	main = ra_funct(main, 0);
	main = rb_funct(main, 0);
	if (opt)
		write(1, "rr\n", 4);
	return (main);
}

stacks_t	rra_funct(stacks_t main, int option)
{
	int	size;
	int	last;

	last = main.A[main.sizeA - 1];
	size = main.sizeA;
	while (size--)
		main.A[size] = main.A[size - 1];
	main.A[0] = last;
	if (option)
		write(1, "rra\n", 5);
	return (main);
}

stacks_t	rrb_funct(stacks_t main, int option)
{
	int	size;
	int	last;

	last = main.B[main.sizeB - 1];
	size = main.sizeB;
	while (size--)
		main.B[size] = main.B[size - 1];
	main.B[0] = last;
	if (option)
		write(1, "rrb\n", 5);
	return (main);
}
