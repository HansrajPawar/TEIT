#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define MaxBuffer 1024

int main() {
    int fd, c = 0;
    char *fifo1 = "fifo1";
    char *fifo2 = "fifo2";
    int fd1;
    int words = 0, lines = 0, chars = 0;
    char buff[MaxBuffer];
    
    mkfifo(fifo1, 0666);
    fd = open(fifo1, O_WRONLY);

    printf("\nEnter a string :- ");
    char str;
    while ((str = getchar()) != '#') {
        buff[c++] = str;
    }
    buff[c] = '\0';

    write(fd, buff, strlen(buff));
    close(fd);

    unlink(fifo1);

    mkfifo(fifo2, 0666);
    fd1 = open(fifo2, O_RDONLY);
    read(fd1, buff, sizeof(buff));
    
    printf("\nThe contents of the file are %s\n", buff);

    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == ' ' || buff[i] == '\n') {
            words++;
        } else {
            chars++;
        }
        if (buff[i] == '\n') {
            lines++;
        }
    }

    printf("\nNo of Words: %d", words);
    printf("\nNo of Characters: %d", chars);
    printf("\nNo of Lines: %d", lines);
    printf("\n");

    close(fd1);
    return 0;
}
// -lrt will try for exe