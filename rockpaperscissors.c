#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>  // For toupper()

// Function to determine the result of the game
int game(char you, char computer)
{
    // If both the user and computer choose the same thing
    if (you == computer)
        return -1;

    // Rock (R) beats Scissors (S)
    if (you == 'R' && computer == 'S')
        return 1;
    else if (you == 'S' && computer == 'R')
        return 0;

    // Paper (P) beats Rock (R)
    if (you == 'P' && computer == 'R')
        return 1;
    else if (you == 'R' && computer == 'P')
        return 0;

    // Scissors (S) beats Paper (P)
    if (you == 'S' && computer == 'P')
        return 1;
    else if (you == 'P' && computer == 'S')
        return 0;

    return -1;  // Draw condition
}

// Driver Code
int main()
{
    int userWins = 0, computerWins = 0;
    char you, computer;
    int round = 1;

    // Seed the random number generator
    srand(time(NULL));

    printf("\n\n\t\t\tBest 2 out of 3: Rock, Paper, Scissors\n");
    printf("\t\t\tEnter R for ROCK, P for PAPER, and S for SCISSORS\n\n");

    while (userWins < 2 && computerWins < 2) {
        printf("\n\t\t\tRound %d: Your choice (R/P/S): ", round);

        // Clean input buffer and read user input
        while ((you = getchar()) == '\n');  // Ignore newlines
        you = toupper(you);  // Convert to uppercase for simplicity

        if (you != 'R' && you != 'P' && you != 'S') {
            printf("\t\t\tInvalid choice! Please enter R, P, or S.\n");
            continue;  // Restart the current round if input is invalid
        }

        // Random computer choice
        int n = rand() % 100;
        if (n < 33)
            computer = 'R';  // Rock
        else if (n >= 33 && n < 66)
            computer = 'P';  // Paper
        else
            computer = 'S';  // Scissors

        printf("\t\t\tComputer chose: %c\n", computer);

        // Determine the result of the current round
        int result = game(you, computer);

        if (result == -1) {
            printf("\t\t\tIt's a draw!\n");
        }
        else if (result == 1) {
            printf("\t\t\tYou won this round!\n");
            userWins++;
        }
        else {
            printf("\t\t\tComputer won this round!\n");
            computerWins++;
        }

        printf("\t\t\tScore - You: %d, Computer: %d\n", userWins, computerWins);
        round++;
    }

    // Final result after best 2 out of 3
    if (userWins == 2) {
        printf("\n\n\t\t\tCongratulations! You won the best 2 out of 3!\n");
    }
    else {
        printf("\n\n\t\t\tOh no! The computer won the best 2 out of 3!\n");
    }

    return 0;
}
