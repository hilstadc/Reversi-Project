#ifndef HIGHSCORE_H_
#define HIGHSCORE_H_

#define MAX_SCORES 10
#define NAME_LEN 16
#define FILE_NAME "highscores.txt"

typedef struct {
    char name[NAME_LEN];
    int score;
} HighScore;

//function declarations
void print_scores (HighScore scores[], int count);
void sort_scores (HighScore scores[], int count);
void read_scores (HighScore scores[], int *count);
void write_scores (HighScore scores[], int count);
void check_scores (int new_score, int color);

#endif