#include "quant.h"
#include "question_data.h"

int Propensity_Diagnosis() {
    double Score = 0;
    for (int i = 0; i < 7; i++) {
        Question q = questions[i];
        printf("%d. %s\n\n", i + 1, q.prompt);
        for (int j = 0; j < q.choice_count; j++) {
            printf("%d. %s\n", j + 1, q.choices[j]);
        }
        printf("답 : ");
        char input = getchar(); getchar();
        while (input < '1' || input > '0' + q.choice_count) {
            printf("잘못 입력하셨습니다. 다시 입력해주세요.\n");
            printf("답 : ");
            input = getchar(); getchar();
        }
        Score += q.scores[input - 1];
    }
    if (Score >= 80.0) {
        printf("투자 점수는 %.lf이며 투자 성향은 '공격투자형'입니다.\n", Score);
        return 1;
    }
    else if (Score >= 60.0) {
        printf("투자 점수는 %.lf이며 투자 성향은 '적극투자형'입니다.\n", Score);
        return 2;
    }
    else if (Score >= 40.0) {
        printf("투자 점수는 %.lf이며 투자 성향은 '위험중립형'입니다.\n", Score);
        return 3;
    }
    else if (Score >= 20.0) {
        printf("투자 점수는 %.lf이며 투자 성향은 '안정추구형'입니다.\n", Score);
        return 4;
    }
    else {
        printf("투자 점수는 %.lf이며 투자 성향은 '안정형'입니다.\n", Score);
        return 5;
    }
}

void Investment_Tendency_Wording(int Class) {
    if (Class == 4 || Class == 5) {
        printf("고객님은 주식 투자가 적합하지 않은 투자자입니다!");
    }
    else if (Class == 3) {
        char Y_N;
        printf("고객님은 고위험 주식 투자가 적합하지 않은 투자자입니다!\n");
        printf("저위험 주식 투자 자문을 받으시겠습니까?\n답변 : "); scanf("\n%c", &Y_N);
        if (Y_N == 'Y') {
            printf("아래와 같은 기업이 상위 10%%의 배당수익률을 기록하고 있습니다\n");
        }
        else if (Y_N == 'N') {
            printf("다음 기회에 뵙도록 하겠습니다.\n");
        }
    }
    // 유저에게 새로운 수치를 질문함
    // 배당수익, ROE, EPS, 수익률
    else if (Class == 2) {

    }
    else {

    }
}