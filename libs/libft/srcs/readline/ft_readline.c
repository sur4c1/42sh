/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyy <yyyyyy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 19:03:44 by yyyyyy            #+#    #+#             */
/*   Updated: 2026/08/17 20:04:44 by yyyyyy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <unistd.h>

char *
ft_readline(char *prompt, char *buf, size_t buflen)
{
	ssize_t len;
	char	c;
	size_t	next_idx;

	next_idx = 0;
	write(STDOUT_FILENO, prompt, ft_strlen(prompt));
	while ((len = read(STDIN_FILENO, &c, 1)) >= 0)
	{
		if (!len)
		{
			if (!next_idx)
				return (NULL);
			else
				c = 0;
		}
		switch (c)
		{
		case '\0':
			break;
		case '\n':
			if (next_idx == 0 || buf[next_idx - 1] != '\\')
			{
				buf[next_idx++] = '\n';
				buf[next_idx] = '\0';
				return (buf);
			}
		default:
			if (next_idx < buflen - 2)
				buf[next_idx++] = c;
			break;
		}
	}
	return (NULL);
}
