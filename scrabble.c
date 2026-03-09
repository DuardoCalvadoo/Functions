#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string getString(int i);
void determine_winner(int i, int j);

int main(void)
{
    const int numberOfPlayers = 2;
    const ASCII_A = 65
    const ASCII_Z = 90
    int sumPlayer1 = 0;
    int sumPlayer2 = 0;
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    string wordsTyped[numberOfPlayers];
    wordsTyped[0] = getString(1);
    wordsTyped[1] = getString(2);

    // put all the word in uppercase
    for (int i = 0; i < numberOfPlayers; i++)
    {
        for (int j = 0; j < strlen(wordsTyped[i]); j++)
        {
            wordsTyped[i][j] = toupper(wordsTyped[i][j]);
        }
    }

    // reaching each point for each caracter of the word
    for (int i = 0; i < numberOfPlayers; i++)
    {
        for (int j = 0; j < strlen(wordsTyped[i]); j++)
        {
            if (wordsTyped[i][j] >= ASCII_A && wordsTyped[i][j] <= ASCII_Z)
            {
                if (i == 0)
                {
                    sumPlayer1 += points[wordsTyped[i][j] - 65];
                }
                else if (i == 1)
                {
                    sumPlayer2 += points[wordsTyped[i][j] - 65];
                }
            }
        }
    }

    //printf("%i %i\n", sumPlayer1, sumPlayer2);
    // printf("%s %s\n", wordsTyped[0], wordsTyped[1]);
    determine_winner(sumPlayer1, sumPlayer2);
}

string getString(int i)
{
    string prompt = get_string("Player %i: ", i);
    return prompt;
}

void determine_winner(int i, int j)
{
    if (i > j)
    {
        printf("Player 1 wins!");
    }
    else if (i < j)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }
}
