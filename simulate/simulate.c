/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 01:03:17 by ricardo           #+#    #+#             */
/*   Updated: 2021/08/12 01:13:14 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	simulate_next_f(stacks_t temp, int *chunks, int moves)
{
	stacks_t	temp2;

	temp2 = pass_stacks_to_temp(temp);
	moves += simulate_num1(&temp2, chunks, 0);
	return (moves);
}

int	simulate_next_s(stacks_t temp, int *chunks, int moves)
{
	stacks_t	temp2;

	temp2 = pass_stacks_to_temp(temp);
	moves += simulate_num2(&temp2, chunks, 0);
	return (moves);
}

int	simulate_num2(stacks_t *temp, int *chunks, int opt)
{
	moves_t	cmd;

	init_cmd(&cmd);
	closer_to_end2(*temp, chunks, &cmd);
	cmd = get_cmds(*temp, cmd, temp->sizeB);
	if (opt)
		cmd.total = num2(&temp, cmd);
	else
		cmd.total = num2_fake(&temp, cmd);
	return (cmd.total);
}

int	simulate_num1(stacks_t *temp, int *chunks, int opt)
{
	moves_t	cmd;

	init_cmd(&cmd);
	closer_to_beginning2(*temp, chunks, temp->sizeA, &cmd);
	cmd = get_cmds(*temp, cmd, temp->sizeB);
	if (opt)
		cmd.total = num1(&temp, cmd);
	else
		cmd.total = num1_fake(&temp, cmd);
	return (cmd.total);
}
