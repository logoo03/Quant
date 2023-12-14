#include "company.h"

ROE* load_roe() {
	FILE* f;
	f = fopen("Y2022_ROE_TOP50_Data.csv", "r");
	char str[8192];
	str[0] = '\0';
	char buf[128];

	while ((fgets(buf, 128, f) != NULL)) {
		strcat(str, buf);
	}

	fclose(f);
	
	ROE* roeArray = (ROE*)malloc(sizeof(ROE) * DATA_ROE_COUNT);
	int i = 0;
	char* ptr = strtok(str, "\n");
	ptr = strtok(NULL, ",");
	while (ptr != NULL) {
		strcpy(roeArray[i].name, ptr);
		ptr = strtok(NULL, "\n");
		roeArray[i++].score = atof(ptr);
		ptr = strtok(NULL, ",");
	}

	return roeArray;
}


Industry* load_industry() {
	FILE* f;
	f = fopen("Y2022_ROE_Data.csv", "r");
	char str[8192];
	str[0] = '\0';
	char buf[256];

	while ((fgets(buf, 256, f) != NULL)) {
		strcat(str, buf);
	}

	fclose(f);

	Industry* industryArray = (Industry*)malloc(sizeof(Industry) * DATA_INDUSTRY_COUNT);
	int i = 0;
	char* ptr = strtok(str, "\n");
	ptr = strtok(NULL, ",");
	while (ptr != NULL) {
		strcpy(industryArray[i].name, ptr);
		ptr = strtok(NULL, ",");
		strcpy(industryArray[i].industry, ptr);
		ptr = strtok(NULL, "\n");
		industryArray[i++].score = atof(ptr);
		ptr = strtok(NULL, ",");
	}

	return industryArray;
}