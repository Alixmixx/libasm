#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

size_t ft_strlen(const char *s);
char *ft_strcpy(char *dst, const char *src);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
char *strdup(const char *s);

#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define RED     "\x1b[31m"
#define RESET   "\x1b[0m"

int main()
{
    char *strings[] = {
        "miao",
        "miao miao",
        "",
        "How many characters are there in this string?",
        "Oh my god this is a very long string, what will happen if I put it here? I don't know, let's try! I hope it works!",
        "Special\tCharacters\nTest",
        "漢字のテスト",
        "1234567890",
        "1234567890",
        NULL
    };

    char dst[150] = {0};
    char dst2[150] = {0};

    printf(YELLOW "\n################################\n" RESET);
    printf(YELLOW "####   Test ft_strlen       ####\n" RESET);
    printf(YELLOW "################################\n\n" RESET);

    for (int i = 0; strings[i]; i++) {
        printf("Test %d\t%s\n", i + 1, (ft_strlen(strings[i]) == strlen(strings[i])) ? (GREEN "OK" RESET) : (RED "KO" RESET));
    }

    printf(YELLOW "\n################################\n" RESET);
    printf(YELLOW "####   Test ft_strcpy       ####\n" RESET);
    printf(YELLOW "################################\n\n" RESET);

    for (int i = 0; strings[i]; i++) {
        strcpy(dst, strings[i]);
        ft_strcpy(dst2, strings[i]);
        printf("Test %d\t%s\n", i + 1, (strcmp(dst, dst2) == 0) ? (GREEN "OK" RESET) : (RED "KO" RESET));
    }

    printf(YELLOW "\n################################\n" RESET);
    printf(YELLOW "####   Test ft_strcmp       ####\n" RESET);
    printf(YELLOW "################################\n\n" RESET);

    for (int i = 0; strings[i + 1]; i++) {
        printf("Test %d\t%s\n", i + 1, (ft_strcmp(strings[i], strings[i + 1]) == strcmp(strings[i], strings[i + 1])) ? (GREEN "OK" RESET) : (RED "KO" RESET));
    }

    printf(YELLOW "\n################################\n" RESET);
    printf(YELLOW "####   Test ft_write        ####\n" RESET);
    printf(YELLOW "################################\n\n" RESET);

    for (int i = 0; strings[i]; i++) {
        printf("Test %d\t%s\n", i + 1, (ft_write(1, strings[i], strlen(strings[i])) == write(1, strings[i], strlen(strings[i]))) ? (GREEN "OK" RESET) : (RED "KO" RESET));
    }

    printf(YELLOW "\n################################\n" RESET);
    printf(YELLOW "####   Test ft_read         ####\n" RESET);
    printf(YELLOW "################################\n\n" RESET);

    char files[5][20] = {
        "src/ft_strlen.s",
        "src/ft_strcpy.s",
        "src/ft_strcmp.s",
        "",
        "src/ft_read.s",
    };
    for (int i = 0; i < 5; i++)
    {
        int fd = open(files[i], O_RDONLY);
        char buff[500] = {0};
        char buff2[500] = {0};
        int a = read(fd, buff, 100);
        close(fd);
        fd = open(files[i], O_RDONLY);
        int b = ft_read(fd, buff2, 100);
        close(fd);

        printf("Test %d\t%s\t%s\n", 1, (a == b) ? (GREEN "OK" RESET) : (RED "KO" RESET),
                (strcmp(buff, buff2) == 0) ? (GREEN "OK" RESET) : (RED "KO" RESET));
        //printf("%s\n%s\n", buff, buff2);
    }
    return 0;
}
