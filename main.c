#include <stdio.h>
#include <string.h>

size_t ft_strlen(const char *s);

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
        "Special\tCharacters\nTest",
        "漢字のテスト",
        "1234567890",
        NULL
    };

    printf(YELLOW "################################\n" RESET);
    printf(YELLOW "####   Test ft_strlen       ####\n" RESET);
    printf(YELLOW "################################\n\n" RESET);

    for (int i = 0; strings[i]; i++) {
        printf("Test %d\t%s\n", i + 1, (ft_strlen(strings[i]) == strlen(strings[i])) ? (GREEN "OK" RESET) : (RED "KO" RESET));
    }

    return 0;
}
