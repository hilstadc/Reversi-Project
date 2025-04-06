/*
    * Name: Cameron Hilstad
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SCORES 5
#define FILE_NAME "highscores.txt"

void read_scores (int scores[], int *count) {
    //open highscore file for reading
    FILE* fptr;
    fptr = fopen(FILE_NAME, "r");

    //if can't read, assume doesn't exist
    if (!fptr) {
        *count = 0;
        printf("No esiting highscores found!");
        return;
    }

    //check if data is on each line and store it in scores
    //stop when either no more data or when max is reached
    while (fscanf(fptr, "%d", &scores[*count]) == 1 && *count < MAX_SCORES) {
        (*count)++;
    }

    //close file
    fclose(fptr);
}

void write_scores (int scores[], int count) {
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
    for (i = 0; i < count; i++) {
        fprintf(fptr, "%d\n", scores[i]);
    }

    //close file
    fclose(fptr);
}

void check_scores (int new_score) {
    //add one for new score
    int scores[MAX_SCORES + 1];
    //number of scores in file
    int count = 0;

    //store the existing scores in a variable with the amount
    read_scores(scores, &count);
    //add the new score to the end of the existing scores
    scores[count++] = new_score;

    //bubble sort
    int i, j;
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (scores[j] < scores[j + 1]) {
                int temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }

    // reset count to 10 if max scores is full
    if (count > MAX_SCORES) count = MAX_SCORES;
    // save sorted scores
    saveScores(scores, count);
}