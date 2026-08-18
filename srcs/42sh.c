/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyy <yyyyyy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 18:46:19 by yyyyyy            #+#    #+#             */
/*   Updated: 2026/08/17 20:15:02 by yyyyyy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
main(int argc, char *argv[])
{
	char *line;
	char  buffer[2048];

	while (1)
	{
		line = ft_readline("> ", buffer, sizeof(buffer));
		if (!line)
			break;
		write(1, line, ft_strlen(line));
	}
	(void) argc;
	(void) argv;
}
