/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 01:11:23 by ricardo           #+#    #+#             */
/*   Updated: 2021/08/12 02:24:42 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

stacks_t	gen_moves_fake(stacks_t main, int option, int counter, int pb_pa)
{
	while (counter)
	{
		if (option == 0)
			main = ra_funct(main, 0);
		if (option == 1)
			main = rra_funct(main, 0);
		if (option == 2)
			main = rb_funct(main, 0);
		if (option == 3)
			main = rrb_funct(main, 0);
		if (option == 4)
			main = rr_funct(main, 0);
		if (option == 5)
			main = rrr_funct(main, 0);
		counter--;
	}
	if (pb_pa == 1)
		main = pb_funct(main, 0);
	else if (pb_pa == 2)
		main = pa_funct(main, 0);
	return (main);
}

stacks_t	gen_moves_real(stacks_t main, int option, int counter, int pb_pa)
{
	while (counter)
	{
		if (option == 0)
			main = ra_funct(main, 1);
		if (option == 1)
			main = rra_funct(main, 1);
		if (option == 2)
			main = rb_funct(main, 1);
		if (option == 3)
			main = rrb_funct(main, 1);
		if (option == 4)
			main = rr_funct(main, 1);
		if (option == 5)
			main = rrr_funct(main, 1);
		counter--;
	}
	if (pb_pa == 1)
		main = pb_funct(main, 1);
	else if (pb_pa == 2)
		main = pa_funct(main, 1);
	return (main);
}
