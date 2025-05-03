/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:29:40 by ealves            #+#    #+#             */
/*   Updated: 2023/01/10 00:27:51 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char		*line[1024];
	ssize_t			count;

	count = 0;
	if (fd < 0 || BUFFER_SIZE < 1 || fd >= 1024)
		return (NULL);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (ft_strlen(line[fd], '\n') == -1)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count <= 0)
			break ;
		buff[count] = '\0';
		if (!line[fd])
			line[fd] = ft_strdup(buff, count);
		else
			line[fd] = ft_strjoin(line[fd], buff);
	}
	free(buff);
	if (count == -1)
		return (NULL);
	return (cutline(&line[fd]));
}

// int	main(int argc, char **argv)
// {
// 	(void) argc;
// 	(void) argv;
// 	int	fd;

// 	fd = open("tripouille/files/41_with_nl", O_RDWR);
// 	char	*str = NULL;
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	if (str)
// 		free(str);
// 	int fd2 = open("tripouille/files/41_no_nl", O_RDONLY);
// 	while ((str = get_next_line(fd2)))
// 	{
// 		str = get_next_line(fd2);
// 		printf("%s", str);
// 	}
// 	// free(str);
// 	// free(str2);
// 	close(fd);
// }
// int	main(int argc, char **argv)
// {
// 	(void) argc;
// 	int	fd;
// 	int fd2;
// 	int i = 0;

// 	fd = open(argv[1], O_RDWR);
// 	fd2 = open(argv[2], O_RDONLY);
// 	char	*str = NULL;
// 	char *str2 = NULL;
// 	while (i < 456)
// 	{
// 		str = get_next_line(fd);
// 		str2 = get_next_line(fd2);
// 		if (str)
// 			printf("line [%d] : %s", i, str);
// 		if (str2)
// 			printf("line [%d] : %s", i, str2);
// 		free(str);
// 		free(str2);
// 		i++;
// 	}
// 	// free(str);
// 	// free(str2);
// 	close(fd);
// 	close(fd2);
// }

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
// 	int fd2;
// 	int i = 0;

// 	fd = open(argv[1], O_RDWR);
// 	fd2 = open(argv[2], O_RDONLY);
// 	char	*str = NULL;
// 	char *str2 = NULL;
// 	while (i < 456)
// 	{
// 		str = get_next_line(fd);
// 		str2 = get_next_line(fd2);
// 		if (str)
// 			printf("line [%d] : %s", i, str);
// 		if (str2)
// 			printf("line [%d] : %s", i, str2);
// 		free(str);
// 		free(str2);
// 		i++;
// 	}
// 	// free(str);
// 	// free(str2);
// 	close(fd);
// 	close(fd2);
// }

// int	main(int argc, char **argv)
// {
// 	int	fd = open(argv[1], O_RDONLY);
// 	char	*str;
// 	str = NULL;
// 	while ((str = get_next_line(fd)))
// 	{
// 		free(str);
// 	}
// }