// #include "get_next_line.h"

// int buffer[1000];

// int main() {
//    int fd;
//    size_t nbytes; 

//     fd = open("file.txt", O_RDONLY);
//     nbytes = read(fd, buffer, sizeof(buffer));
//     write(STDOUT_FILENO, buffer, nbytes);
// }


# include <unistd.h>

int bytes_read;

bytes_read = read(fd, cup_buffer, 3);
