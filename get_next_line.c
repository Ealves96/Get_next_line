/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:04:53 by ealves            #+#    #+#             */
/*   Updated: 2023/01/10 15:49:55 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// '\n' trouve dans la ligne : je coupe la ligne
char	*cutline(char **line)
{
	char	*new_line;
	char	*rline;
	int		endl;

	rline = NULL;
	endl = ft_strlen(*line, '\n');
	if (endl != -1)
	{	
		rline = ft_strdup(*line, endl + 1);
		new_line = ft_strdup(*line + (endl + 1),
				ft_strlen(*line, '\0'));
		free(*line);
		*line = new_line;
	}
	else
	{
		if (*line && *line[0])
			rline = ft_strdup(*line, ft_strlen(*line, '\0'));
		if (*line)
		{
			free(*line);
			*line = NULL;
		}
	}
	return (rline);
}

char	*get_next_line(int fd)
{
	char			*buff;
	static char		*line;
	ssize_t			count;

	count = 0;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (ft_strlen(line, '\n') == -1)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count <= 0)
			break ;
		buff[count] = '\0';
		if (!line)
			line = ft_strdup(buff, count);
		else
			line = ft_strjoin(line, buff);
	}
	free(buff);
	if (count == -1)
		return (NULL);
	return (cutline(&line));
}

// int	main(int argc, char **argv)
// {
// 	char	*str = ft_strdup("test\ntest2", 10);
// 	int	endl = ft_strlen(str, '\n');
// 	printf("%s\n", ft_strdup(str, endl));
// 	printf("%s\n", ft_strdup(str + endl + 1, ft_strlen(str + endl + 1, '\0')));
// }

// int	main(int argc, char **argv)
// {
// 	(void) argc;
// 	int	fd;
// 	int i = 0;

// 	fd = open(argv[1], O_RDWR);
// 	char	*str = NULL;
// 	while (i < 456)
// 	{
// 		str = get_next_line(fd);
// 		if (str)
// 			printf("%s", str);
// 		free(str);
// 		i++;
// 	}
// 	// free(str);
// 	// free(str2);
// 	close(fd);
// }
