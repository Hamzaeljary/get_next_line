#include "get_next_line.h"

int main() 
{
    int fd;
    char *line = NULL;
    fd = open("file.txt",O_RDONLY);
    line = rd_line(fd, line);
    printf("%s\n", line);
    free(line);
    close(fd);

    return 0;
}
