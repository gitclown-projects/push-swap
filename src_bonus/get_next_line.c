#include "../includes/get_next_line.h"

/* ajoute ce qui etait dans ft_new_line pour la prochaine ligne */
char	*ft_add(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
		return (free(stash), NULL);
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!new_stash)
		return (NULL);
	while (stash[i])
		new_stash[j++] = stash[++i];
	new_stash[j++] = '\0';
	free(stash);
	return (new_stash);
}

/* supprime les char apres le '\n'*/
char	*ft_new_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	line [i] = '\0';
	while (--i >= 0)
		line [i] = stash [i];
	return (line);
}
/*Lis les n premier char jusqu'a un '\n' ou un '\0' et me les renvoie dans save ()*/

char	*read_and_join(int fd, char *save)
{
	char	*buffer;
	int		new_read;

	new_read = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (new_read > 0)
	{
		new_read = read(fd, buffer, BUFFER_SIZE);
		if (new_read == -1)
			return (free(buffer), NULL);
		buffer[new_read] = '\0';
		save = ft_strjoin(save, buffer);
		if (!save)
		{
			free(buffer);
			return (free(save), NULL);
		}
		if (ft_strrchr(save, '\n'))
			break ;
	}
	free (buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_join(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_new_line(stash);
	stash = ft_add(stash);
	return (line);
}
/*
int	main(void)
{
	int	fd;
	char	*line;

	line = "";
	fd = open("texte.txt", O_RDONLY);
	while ((line = get_next_line(fd)) !=0)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}*/
