/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:19:02 by lcalvie           #+#    #+#             */
/*   Updated: 2022/10/11 15:23:02 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ten_queens_puzzle_rec(char t[11], int n, int *count, int i)
{
	int	j;

	while (++i < n)
	{
		j = i;
		while (++j < n)
			if (t[i] == t[j] || t[j] == t[i] + j - i || t[j] == t[i] - j + i)
				return ;
	}
	if (n > 9)
		return (write(1, t, 11), (*count)++, (void)0);
	i = -1;
	while (++i < 10)
	{
		t[n] = i + '0';
		ft_ten_queens_puzzle_rec(t, n + 1, count, -1);
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	t[11];
	int		count;

	count = 0;
	t[10] = '\n';
	ft_ten_queens_puzzle_rec(t, 0, &count, -1);
	return (count);
}
