/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyyyyy <yyyyyy@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 19:03:44 by yyyyyy            #+#    #+#             */
/*   Updated: 2026/08/18 20:33:52 by yyyyyy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_put.h"
#include "ft_string.h"
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

static struct termios
activate_raw(void)
{
	struct termios original;
	struct termios raw;

	ioctl(0, TCGETS, &original);
	raw = original;
	raw.c_lflag &= ~(ICANON | ECHO);
	raw.c_cc[VMIN] = 1;
	raw.c_cc[VTIME] = 0;
	ioctl(0, TCSETS, &raw);
	return (original);
}

static void
evaluate_string_size(char *str, int win_w, int *w, int *h)
{
	while (*str)
	{
		if (*str == '\n')
		{
			*w = 0;
			(*h)++;
		}
		else if (*w == win_w)
		{
			*w = 1;
			(*h)++;
		}
		else
			(*w)++;
		str++;
	}
}

static void
reset_cursor(char *prompt, char *buf)
{
	struct winsize win;
	int			   text_h;
	int			   text_w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
	text_h = 1;
	text_w = 0;
	evaluate_string_size(prompt, win.ws_col, &text_w, &text_h);
	evaluate_string_size(buf, win.ws_col, &text_w, &text_h);
	if (text_h == 1)
		ft_putstr_fd("\x1B[G", STDOUT_FILENO);
	else
	{
		ft_putstr_fd("\x1B[", STDOUT_FILENO);
		ft_putnbr_fd(text_h - 1, STDOUT_FILENO);
		ft_putstr_fd("F", STDOUT_FILENO);
	}
	ft_putstr_fd("\x1B[J", STDOUT_FILENO);
}

static void
handle_escape(size_t *cursor, size_t buflen)
{
	char c;

	read(STDIN_FILENO, &c, 1);
	if (c != '[')
		return;
	read(STDIN_FILENO, &c, 1);
	switch (c)
	{
	case 'D':
		if (*cursor)
			(*cursor)--;
		break;
	case 'C':
		if (*cursor < buflen - 2)
			(*cursor)++;
		break;
	default: // skip and ignore
		while (c && c != 4 && !(c >= 0x40 && c <= 0x7E))
			read(STDIN_FILENO, &c, 1);
		break;
	}
}

char *
ft_readline(char *prompt, char *buf, size_t buflen)
{
	char		   c;
	size_t		   cursor;
	struct termios saved;

	cursor = 0;
	saved = activate_raw();
	ft_bzero(buf, buflen);
	write(STDOUT_FILENO, prompt, ft_strlen(prompt));
	while (read(STDIN_FILENO, &c, 1) >= 0)
	{
		reset_cursor(prompt, buf);
		ft_putstr_fd("Recieved ", STDERR_FILENO);
		ft_putnbr_fd(c, STDERR_FILENO);
		ft_putendl_fd(" from read.", STDERR_FILENO);
		switch (c)
		{
		case 0x04:
			if (cursor == 0)
				return (NULL);
		case 0x1B:
			handle_escape(&cursor, buflen);
			break;
		case 0x7F:
			if (cursor)
				buf[--cursor] = 0;
			break;
		case '\t':
			// handle autocomplete
			break;
		case '\n':
			buf[cursor++] = c;
			write(STDOUT_FILENO, "\n", 1);
			return (buf);
		default:
			if (cursor < buflen - 2)
				buf[cursor++] = c;
		}
		write(STDOUT_FILENO, prompt, ft_strlen(prompt));
		write(STDOUT_FILENO, buf, ft_strlen(buf));
	}
	ioctl(0, TCSETS, &saved);
	return (NULL);
}
