/*
    * Name: Cameron Hilstad
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "highscore.h"


//for testing
#define MAX_SCORES 10
#define NAME_LEN 16
#define FILE_NAME "highscores.txt"

typedef struct {
    char name[NAME_LEN];
    int score;
} HighScore;


void print_scores (HighScore scores[], int count) {
    if (count == 0) {
        printf("No high scores yet.\n");
        return;
    }

    int i;
    for (i = 0; i < count; i++) {
        printf("%2d. %-15s %2d\n", i + 1, scores[i].name, scores[i].score);
    }
}

void sort_scores (HighScore scores[], int count) {
    //bubble sort
    int i, j;
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (scores[j].score < scores[j + 1].score) {
                HighScore temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }
}

void read_scores (HighScore scores[], int *count) {
    //open highscore file for reading
    FILE* fptr;
    fptr = fopen(FILE_NAME, "r");

    //if can't read, assume doesn't exist
    if (!fptr) {
        *count = 0;
        return;
    }

    //check if data is on each line and store it in scores
    //stop when either no more data or when max is reached
    while (fscanf(fptr, "%s %d", scores[*count].name, &scores[*count].score) == 2 && *count < MAX_SCORES) {
        (*count)++;
    }

    //close file
    fclose(fptr);
}

void write_scores (HighScore scores[], int count) {
    //open highscore file for writing
    FILE* fptr;
    fptr = fopen(FILE_NAME, "w");

    //if can't read, give error
    if (!fptr) {
        printf("ERROR: Could not write high scores!");
        return;
    }

    //store each value in scores up to the number of scores
    int i;
    for (int i = 0; i < count; i++) {
        fprintf(fptr, "%s %d\n", scores[i].name, scores[i].score);
    }

    //close file
    fclose(fptr);
}

void check_scores (int new_score, int color) {
    //add one for new score
    HighScore scores[MAX_SCORES + 1];
    //number of scores in file
    int count = 0;

    //store existing scores in highscore array
    read_scores(scores, &count);

    //print leaderboard before checking
    printf("\nCurrent Leaderboard:\n");
    print_scores(scores, count);

    if (count < MAX_SCORES || new_score > scores[count - 1].score) {
        //get player's name
        char name[NAME_LEN];
        if (color == 1) {
            printf("\nCongratulations! White got a high score!\n");
        } else {
            printf("\nCongratulations! Black got a high score!\n");
        }
        printf("Enter your name (max 15 characters): ");
        scanf("%15s", name);
        if (strlen(name) >= NAME_LEN - 1)
            printf("Name truncated to 15 characters.\n");

        //add new score and sort
        strncpy(scores[count].name, name, NAME_LEN);
        scores[count].score = new_score;
        count++;

        sort_scores(scores, count);

        if (count > MAX_SCORES) count = MAX_SCORES;

        write_scores(scores, count);

        printf("\nUpdated Leaderboard:\n");
        print_scores(scores, count);
    }
}

//test code
int main () {
    int score = 30;

    check_scores(score, 1);

    while(1);

    return 0;
}