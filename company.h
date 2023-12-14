#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DATA_ROE_COUNT 50
#define DATA_INDUSTRY_COUNT 9

typedef struct {
	char name[24];
	float score;
} ROE;


typedef struct {
	char name[24];
	char industry[24];
	float score;
} Industry;

ROE* load_roe();
Industry* load_industry();
