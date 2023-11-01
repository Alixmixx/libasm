#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t ft_strlen(const char *s);
char *ft_strcpy(char *dst, const char *src);

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
        NULL
    };

    char dst[150] = {0};
    char dst2[150] = {0};

    printf(YELLOW "################################\n" RESET);
    printf(YELLOW "####   Test ft_strlen       ####\n" RESET);
    printf(YELLOW "################################\n\n" RESET);

    for (int i = 0; strings[i]; i++) {
        printf("Test %d\t%s\n", i + 1, (ft_strlen(strings[i]) == strlen(strings[i])) ? (GREEN "OK" RESET) : (RED "KO" RESET));
    }

    printf(YELLOW "################################\n" RESET);
    printf(YELLOW "####   Test ft_strcpy       ####\n" RESET);
    printf(YELLOW "################################\n\n" RESET);

    for (int i = 0; strings[i]; i++) {
        strcpy(dst, strings[i]);
        ft_strcpy(dst2, strings[i]);
        printf("Test %d\t%s\n", i + 1, (strcmp(dst, dst2) == 0) ? (GREEN "OK" RESET) : (RED "KO" RESET));
    }

    return 0;
}
