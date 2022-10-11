/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:19:02 by lcalvie           #+#    #+#             */
/*   Updated: 2022/10/11 15:50:10 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_ten_queens_puzzle_rec(char t[11], int n, int *count, int i)
{
	int	j;

	while (++i < n)
	{
		j = i;
		while (++j < n)
			if (t[i] == t[j] || t[j] == t[i] + j - i || t[j] == t[i] - j + i)
				return (*count);
	}
	if (n > 9)
		return (write(1, t, 11), (*count)++, *count);
	t[n] = '/';
	while ((++t[n]) <= '9')
		ft_ten_queens_puzzle_rec(t, n + 1, count, -1);
	return (*count);
}

int	ft_ten_queens_puzzle(void)
{
	char	t[11];
	int		count;

	count = 0;
	t[10] = '\n';
	return (ft_ten_queens_puzzle_rec(t, 0, &count, -1));
}
