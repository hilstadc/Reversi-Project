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
void printScores (HighScore scores[], int count);
void sortScores (HighScore scores[], int count);
void readScores (HighScore scores[], int *count);
void writeScores (HighScore scores[], int count);
void checkScore (int new_score, int color);

#endif