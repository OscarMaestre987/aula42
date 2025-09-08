/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:04:02 by oscar             #+#    #+#             */
/*   Updated: 2025/09/03 12:09:31 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include <stddef.h>
# include "../Utils/utils.h"

int		op_swap(t_stack *s);
int		op_push(t_stack *dst, t_stack *src);
int		op_rotate(t_stack *s);
int		op_rev_rotate(t_stack *s);

void	sa(t_stack *a);
void	pa(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rra(t_stack *a);

void	sb(t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	rb(t_stack *b);
void	rrb(t_stack *b);

void	ss(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif /* OPERATIONS_H */
