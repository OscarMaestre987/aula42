/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:59:02 by oscar             #+#    #+#             */
/*   Updated: 2025/09/06 21:13:47 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <unistd.h>

typedef struct s_stack
{
	int	*buf;
	int	cap;
	int	size;
	int	head;
}	t_stack;

typedef struct s_cost
{
	int	ta;
	int	tb;
	int	rra;
	int	rrb;
	int	total;
	int	mode;
}	t_cost;

typedef struct s_ctx
{
	t_stack	a;
	t_stack	b;
	int		*rank;
	int		*sorted_vals;
	int		*nums;
	int		n;
}	t_ctx;

#endif /* STRUCTS_H*/