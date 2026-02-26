#include <stdio.h>
#include <cs50.h>

int getHeight(void);

int main(void)
{
    int height = getHeight();
    int spaces = height - 1;
    int j = 1;
    int numHashes = 1;
    for (int i = 0; i < height; i++)
    {
        for (true; spaces > 0; spaces--)
        {
            printf(" ");
        }

        for (int lefthash = 0; lefthash < numHashes; lefthash++)
        {
            printf("#");
        }
        printf("  ");
        for (int righthash = 0; righthash < numHashes; righthash++)
        {
            printf("#");
        }

        printf("\n");
        j++;
        numHashes++;
        spaces = height - j;
    }
}

int getHeight(void)
{
    int x;
    do
    {
        x = get_int("What's the heigh of pyramid? 1-8\n");
    }
    while (x <= 0 || x > 8);
    return x;
}
