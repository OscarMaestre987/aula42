/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:38:24 by oscar             #+#    #+#             */
/*   Updated: 2025/09/08 09:24:34 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "Utils/utils.h"
#include "SmallNumbers/small.h"

static int	parse_args(int argc, char **argv, int **nums, int *n)
{
	*nums = NULL;
	*n = 0;
	if (!collect_numbers(argc, argv, nums, n) || *n <= 0)
	{
		puterr("Error\n");
		return (1);
	}
	if (has_dups(*nums, *n))
	{
		free(*nums);
		puterr("Error\n");
		return (1);
	}
	if (is_sorted_ints(*nums, *n))
	{
		free(*nums);
		return (1);
	}
	return (0);
}

static void	finalize_all(t_ctx *ctx)
{
	stack_free(&ctx->a);
	stack_free(&ctx->b);
	free(ctx->rank);
	free(ctx->sorted_vals);
	free(ctx->nums);
	ctx->nums = NULL;
	ctx->rank = NULL;
	ctx->sorted_vals = NULL;
}

static int	init_data_and_index(t_ctx *ctx)
{
	ctx->sorted_vals = NULL;
	ctx->rank = compress_coords_with_sorted(ctx->nums,
			ctx->n, &ctx->sorted_vals);
	if (!ctx->rank)
		return (puterr("Error\n"), free(ctx->nums), 1);
	if (!init_stack_from_array(&ctx->a, ctx->rank, ctx->n))
	{
		finalize_all(ctx);
		puterr("Error\n");
		return (1);
	}
	if (!stack_init(&ctx->b, ctx->n))
	{
		finalize_all(ctx);
		puterr("Error\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	if (argc <= 1)
		return (0);
	if (parse_args(argc, argv, &ctx.nums, &ctx.n))
		return (1);
	if (init_data_and_index(&ctx))
	{
		finalize_all(&ctx);
		return (1);
	}
	if (ctx.n <= 5)
		sort_upto5(&ctx.a, &ctx.b);
	else
		sort_lis_greedy(&ctx.a, &ctx.b);
	finalize_all(&ctx);
	return (0);
}
