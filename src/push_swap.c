/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypetruzz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:48:10 by ypetruzz          #+#    #+#             */
/*   Updated: 2021/11/16 17:48:51 by ypetruzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = parsing_args(argc, argv);
	b = new_stack();
	check_for_dup(a);
	solver(a, b);
	free(a);
	free(b);
	return (0);
}
