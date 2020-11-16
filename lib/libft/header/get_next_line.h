/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:20:48 by agautier          #+#    #+#             */
/*   Updated: 2020/11/10 13:06:01 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# elif BUFFER_SIZE < 0
#  define BUFFER_SIZE 0
# endif

# define GNL_OK 1
# define GNL_END 0
# define GNL_ERR -1

int		get_next_line(int fd, char **line);

#endif
