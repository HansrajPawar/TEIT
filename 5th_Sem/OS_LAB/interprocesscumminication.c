#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define MaxBuffer 1024

int main()
{
	int fd, c = 0;

	char *fifo1 = "fifo1";
	char *fifo2 = "fifo2";

	int fd1;
	int words, lines, chars = 0;

	char buff[MaxBuffer];

	mkfifo(fifo1, 0666);
	fd = open(fifo1, O_RDWR);

	printf("\nEnter a string :- ");
	char str;
	while (str = getchar() != '#')
	{
		buff[c++];
	}
	buff[c] = '\0';

	write(fd, buff, sizeof(buff));
	close(fd);
	unlink(fifo1);

	fd1 = open(fifo2, O_RDWR);
	read(fd1, buff, sizeof(buff));

	printf("\nThe contents of the file are %s\n", buff);
	int i = 0;

	while (buff[i] == '\0')
	{
		if (buff[i] == ' ' || buff[i] == '\n')
		{
			words++;
		}
		else
		{
			chars++;
		}
		if (buff[i] == '\n')
		{
			lines++;
		}
	}

	printf("\n No of Words: %d", words);
	printf("\n No of Characters: %d", chars);
	printf("\n No of Lines: %d", lines);
	printf("\n");
	close(fd1);
	return 0;
}
