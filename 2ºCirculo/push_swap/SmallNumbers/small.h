/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 10:52:52 by oscar             #+#    #+#             */
/*   Updated: 2025/09/06 20:49:59 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMALL_H
# define SMALL_H

# include <unistd.h>
# include "../structs.h"

void	sort3(t_stack *a);
void	push_min_to_b(t_stack *a, t_stack *b);
void	sort_upto5(t_stack *a, t_stack *b);

int		top(const t_stack *s);
int		second(const t_stack *s);
int		bottom(const t_stack *s);

#endif /* SMALL_H*/