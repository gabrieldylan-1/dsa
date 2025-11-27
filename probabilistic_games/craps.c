#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
    char c;
    int wins, losses;

    srand(time(NULL));

    wins = 0, losses = 0;

    while (1) 
    {
        if(play_game()) wins++; else losses++;

        printf("\nPlay again? ");
        scanf(" %c", &c);

        c = toupper((unsigned char)c);

        if(c != 'Y') break; 
    }

    printf("Wins: %d Losses: %d\n", wins, losses);

    return 0;
}

int roll_dice(void)
{
    int n1, n2;

    n1 = 1 + (rand() % 6), n2 = 1 + (rand() % 6);

    return n1 + n2;
}

bool play_game(void)
{
    int point, roll;

    roll = roll_dice();
    printf("You rolled: %d\n", roll);

    if(roll == 11 || roll == 7)
    {
        printf("You win!\n");
        return true;
    }

    if(roll == 2 || roll == 3 || roll == 12) 
    {
        printf("You lose!\n");
        return false;
    }

    point = roll;
    printf("Your point is %d\n", point);

    while (1) 
    {
        roll = roll_dice();
        printf("You rolled: %d\n", roll);

        if (roll == 7)
        {
            printf("You lose!\n");
            return false;
        }

        if (roll == point)
        {
            printf("You win!\n");
            return true;
        }
    }
}