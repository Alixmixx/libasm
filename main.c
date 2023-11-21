#include "libasm.h"

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
        printf("Test \n%d\t%s\n", i + 1, (ft_write(2, strings[i], strlen(strings[i])) == write(1, strings[i], strlen(strings[i]))) ? (GREEN "OK" RESET) : (RED "KO" RESET));
    }
  
    printf("\t%serrno%s\n", RED, RESET);
    ft_write(-1, strings[0], strlen(strings[0]));
    printf("Test %d\t%d\t", 1, errno);
    write(-1, strings[0], strlen(strings[0]));
    printf("%d\n", errno);

    ft_write(1, NULL, strlen(strings[0]));
    printf("Test %d\t%d\t", 2, errno);
    write(1, NULL, strlen(strings[0]));
    printf("%d\n", errno);

    printf(YELLOW "\n#############################  ###\n" RESET);
    printf(YELLOW "####   Test ft_read         ####\n" RESET);
    printf(YELLOW "################################\n\n" RESET);

    char files[5][20] = {
        "src/ft_strlen.s",
        "src/ft_strcpy.s",
        "src/ft_strcmp.s",
        "",
        "src/ft_read.s",
    };

    char buff[500] = {0};
    char buff2[500] = {0};
    for (int i = 0; i < 5; i++)
    {
        int fd = open(files[i], O_RDONLY);
        int a = read(fd, buff, 100);
        close(fd);
        fd = open(files[i], O_RDONLY);
        int b = ft_read(fd, buff2, 100);
        close(fd);

        printf("Test %d\t%s\t%s\n", i, (a == b) ? (GREEN "OK" RESET) : (RED "KO" RESET),
                (strcmp(buff, buff2) == 0) ? (GREEN "OK" RESET) : (RED "KO" RESET));
    }

    printf("\t%serrno%s\n", RED, RESET);
    ft_read(-1, buff2, 100);
    printf("Test %d\t%d\t", 1, errno);
    read(-1, buff, 100);
    printf("%d\n", errno);

    int fd = open(files[0], O_RDONLY);
    ft_read(fd, NULL, 100);
    printf("Test %d\t%d\t", 2, errno);
    read(fd, NULL, 100);
    printf("%d\n", errno);
    close(fd);
    
    fd = open("./src", O_RDONLY);
    ft_read(fd, buff, 100);
    printf("Test %d\t%d\t", 3, errno);
    read(fd, buff2, 100);
    printf("%d\n", errno);
    close(fd);

    printf(YELLOW "\n################################\n" RESET);
    printf(YELLOW "####   Test ft_strdup       ####\n" RESET);
    printf(YELLOW "################################\n\n" RESET);

    char *s = "miao";
	char *s2 = ft_strdup(s);

    return 0;
}
