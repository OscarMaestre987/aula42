/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:27:00 by oscar             #+#    #+#             */
/*   Updated: 2025/09/06 20:41:47 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include "../structs.h"
# include "../Operations/operations.h"

int		stack_init(t_stack *s, int capacity);
void	stack_free(t_stack *s);
void	putop(const char *s, size_t len);
int		idx_next(const t_stack *s, int i);
int		idx_prev(const t_stack *s, int i);

char	**split_words(const char *s, int *outc);
void	free_words(char **w);
int		parse_int(const char *s, int *ok);
int		append_int(int **arr, int *n, int *cap, int v);
int		collect_numbers(int argc, char **argv, int **outv, int *outn);
int		alloc_and_copy_token(char **dst, const char *s,
			size_t i, size_t len);
int		init_nulls(char **v, int total);
size_t	token_len(const char *s, size_t i);
size_t	skip_spaces(const char *s, size_t i);
int		append_words_from_arg(const char *arg,
			int **arr, int *n, int *cap);

size_t	my_strlen(const char *s);
void	puterr(const char *s);
int		is_space(char c);

int		is_sorted_ints(const int *a, int n);
int		has_dups(const int *a, int n);

int		*compress_coords_with_sorted(const int *a, int n, int **out_sorted);

int		init_stack_from_array(t_stack *s, const int *vals, int n);
int		stack_at(const t_stack *s, int i);

void	mark_lis_keep(const t_stack *a, int *keep);
void	push_non_lis_to_b(t_stack *a, t_stack *b);

void	apply_mode_0(t_stack *a, t_stack *b, t_cost c);
void	apply_mode_1(t_stack *a, t_stack *b, t_cost c);
void	apply_mode_2(t_stack *a, t_stack *b, t_cost c);
void	apply_mode_3(t_stack *a, t_stack *b, t_cost c);
void	apply_rotations_and_push(t_stack *a, t_stack *b, t_cost c);

int		target_pos_in_a(const t_stack *a, int v);
t_cost	eval_costs(const t_stack *a, const t_stack *b, int ta, int tb);
void	greedy_reinsert_from_b(t_stack *a, t_stack *b);
int		pos_min(const t_stack *a);
void	final_rotate_a_min_top(t_stack *a);
void	sort_lis_greedy(t_stack *a, t_stack *b);
int		find_next_bigger(const t_stack *a, int v);
int		lis_best_index(const int *len, int n);
void	repeat_ra(t_stack *a, int n);
void	repeat_rb(t_stack *b, int n);
void	repeat_rra(t_stack *a, int n);
void	repeat_rrb(t_stack *b, int n);
void	repeat_rr(t_stack *a, t_stack *b, int n);
void	repeat_rrr(t_stack *a, t_stack *b, int n);
#endif /* UTILS_H*/