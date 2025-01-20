/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:39:52 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/11/15 16:46:41 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024

# endif

/* get_next_line.c */
char	*get_next_line(int fd);
void	read_and_stash(char **stash, int fd);
void	extract_line(char *stash, char **line);
void	clean_stash(char **stash);

/* get_nex_line_utils.c */
int		found_newline(char *stash);
void	stasher(char **stash, char	*buffer);

#endif
