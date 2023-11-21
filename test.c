#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>


ssize_t ft_write(int fd, const void *buf, size_t count);

int main()
{
    int a = 0;
    a = ft_write(-2, "miao", 5);
    printf("%d\n", errno);
    printf("%d\n", a);
    return 0;
}