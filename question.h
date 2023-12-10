#pragma once

typedef struct {
    char prompt[200];
    char* choices[5];
    int scores[5];
    int choice_count;
} Question;
