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
        int input; scanf("%d", &input);
        while (input < 1 || input > q.choice_count) {
            int retry;
            printf("잘못 입력하셨습니다. 다시 입력해주세요.\n");
            printf("답 : ");
            scanf("%d", &input);
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
        printf("저위험 주식 투자 자문을 받으시겠습니까? 원하시면 Y 원하지 않으시면 N을 입력해주세요.\n답변 : "); scanf("\n%c", &Y_N);
        if (Y_N == 'Y') {
            printf("저위험 주식 투자는 기본적으로 고배당주 또는 채권 투자로 이루어집니다.\n");
            printf("채권 투자 자문 서비스는 아직 준비중이며 지금은 고배당주 투자 자문만 가능합니다.\n");
            printf("고배당주 투자는 개별 종목에 투자하기보다, 고배당주 ETF에 간접투자를 권해드리고 있습니다.\n");
            printf("ETF(Exchange Trade Fund, 상장지수펀드)에 관심이 있으시다면 아래 링크를 눌러 관련 페이지로 넘어가실 수 있습니다.\n");
        }
        else if (Y_N == 'N') {
            printf("다음 기회에 뵙도록 하겠습니다.\n");
        }
    }
    else {
        char Q1, Q2;
        printf("투자 자문를 위해서는 몇 가지의 질문을 더 답해주셔야합니다\n\n");
        printf("첫 번째 질문입니다.\n");
        printf("고객님께서 장기적으로 유망한 기업에 투자를 원하십니까? 원하시면 Y 원하지 않으시면 N을 입력해주세요.\n답변 : "); scanf("\n%c", &Q1);
        printf("두 번째 질문입니다.\n");
        printf("고객님께서 분산투자를 투자의 제 1원칙이라고 생각하십니까? 원하시면 Y 원하지 않으시면 N을 입력해주세요.\n답변 : "); scanf("\n%c", &Q2);
        if (Q1 == 'Y') {
            int cnt; 
            printf("마지막 질문 입니다.\n최소 몇 개의 기업에 투자하실 계획이신가요? 50이하의 숫자를 입력해주세요.\n답변 : "); scanf("\n%d", &cnt);
            printf("아래의 %d개의 기업리스트입니다.\n", cnt);
            for (int i = 0; i < cnt; i++) {
                ROE* roedata = load_roe();
                printf("Company%d : %s\n", i + 1 ,roedata[i].name);
            }
            if (Q2 == 'Y') {
                printf("아래의 9개의 기업은 다양한 산업에서 우수한 지표를 보이는 기업리스트입니다.\n");
                for (int j = 0; j < 9; j++) {
                    Industry* industrydata = load_industry();
                    printf("Company%d : %s\n",j+1,industrydata[j].name);
                }
                
            }
        }
        else {
            if (Q2 == 'Y') {
                printf("아래의 9개의 기업은 다양한 산업에서 우수한 지표를 보이는 기업리스트입니다.\n");
                for (int j = 0; j < 9; j++) {
                    Industry* industrydata = load_industry();
                    printf("Company%d : %s\n", j+1, industrydata[j].name);
                }

            }
            else {
                printf("현재까지 준비된 서비스로는 투자 자문이 불가능합니다. 다음 기회에 이용해주세요.");
            }
        }
    }
    return 0;
}