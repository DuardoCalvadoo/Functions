#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validate_key(int argc, string argv[], const int alphabet_lenght, const int case_difference);
int main(int argc, string argv[])
{
    const int alphabet_lenght = 26;
    const int case_difference = 32;
    const string alphabet = {"abcdefghijklmnopqrstuvwxyz"};
    validate_key(argc, argv, alphabet_lenght, case_difference);
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        argv[1][i] = tolower(argv[1][i]);
    }

    printf("/substitution $ ./substitution abcdefghijklmnopqrstuvwxyz\n");

    string plaintext = get_string("Plaintext: ");
    printf("ciphertext: ");

    for (int i = 0, lenght = strlen(plaintext); i < lenght; i++)
    {
        if (isalpha(plaintext[i]))
        {
            for (int alphabetCharacter = 0; alphabetCharacter < alphabet_lenght;
                 alphabetCharacter++)
            {
                if (plaintext[i] == alphabet[alphabetCharacter] ||
                    (plaintext[i] + case_difference) == alphabet[alphabetCharacter])
                {
                    if (isupper(plaintext[i]))
                    {
                        printf("%c", argv[1][alphabetCharacter] - case_difference);
                    }
                    else
                    {
                        printf("%c", argv[1][alphabetCharacter]);
                    }
                }
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
int validate_key(int argc, string argv[], const int alphabet_lenght, const int case_difference)
{
    if (argc < 2 || argc > 2)
    {
        printf("Usage: ./substitution key\n");
        exit(1);
    }
    if (!(strlen(argv[1]) == alphabet_lenght))
    {
        printf("Key must contain 26 letters\n");
        exit(1);
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must contain just letters\n");
            exit(1);
        }
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (argv[1][i] == argv[1][j] || argv[1][i] - case_difference == argv[1][j] ||
                argv[1][i] == argv[1][j] - case_difference)
            {
                printf("Key must contain 26 diferent letters\n");
                exit(1);
            }
        }
    }

    return 0;
}
