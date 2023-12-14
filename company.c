#include "company.h"

ROE* load_roe() {
	FILE* f;
	f = fopen("Y2022_ROE_TOP50_Data.csv", "r");
	char str[16384];
	str[0] = '\0';
	char buf[128];

	while ((fgets(buf, 128, f) != NULL)) {
		strcat(str, buf);
	}

	fclose(f);
	char** parsed = parse_csv(str);
	
	ROE* roeArray = (ROE*)malloc(sizeof(ROE) * DATA_ROE_COUNT);
	for (int i = 1; i < DATA_ROE_COUNT + 1; i++) {
		strcpy(roeArray[i].name, parsed[i * 2]);
		roeArray[i].score = atof(parsed[i * 2 + 1]);
	}
	free_csv_line(parsed);

	return roeArray;
}


Industry* load_industry() {
	FILE* f;
	f = fopen("Y2022_ROE_Data.csv", "r");
	char str[16384];
	str[0] = '\0';
	char buf[256];

	while ((fgets(buf, 256, f) != NULL)) {
		strcat(str, buf);
	}

	fclose(f);
	char** parsed = parse_csv(str);

	Industry* industryArray = (Industry*)malloc(sizeof(Industry) * DATA_INDUSTRY_COUNT);
	for (int i = 1; i < DATA_INDUSTRY_COUNT + 1; i++) {
		strcpy(industryArray[i].name, parsed[i * 2]);
		strcpy(industryArray[i].industry, parsed[i * 2 + 1]);
		industryArray[i].score = atof(parsed[i * 2 + 2]);
	}
	free_csv_line(parsed);

	return industryArray;
}