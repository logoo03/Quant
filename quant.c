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
        printf("�� : ");
        int input; scanf("%d", &input);
        while (input < 1 || input > q.choice_count) {
            int retry;
            printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n");
            printf("�� : ");
            scanf("%d", &input);
        }
        Score += q.scores[input - 1];
    }
    if (Score >= 80.0) {
        printf("���� ������ %.lf�̸� ���� ������ '����������'�Դϴ�.\n", Score);
        return 1;
    }
    else if (Score >= 60.0) {
        printf("���� ������ %.lf�̸� ���� ������ '����������'�Դϴ�.\n", Score);
        return 2;
    }
    else if (Score >= 40.0) {
        printf("���� ������ %.lf�̸� ���� ������ '�����߸���'�Դϴ�.\n", Score);
        return 3;
    }
    else if (Score >= 20.0) {
        printf("���� ������ %.lf�̸� ���� ������ '�����߱���'�Դϴ�.\n", Score);
        return 4;
    }
    else {
        printf("���� ������ %.lf�̸� ���� ������ '������'�Դϴ�.\n", Score);
        return 5;
    }
}

void Investment_Tendency_Wording(int Class) {
    if (Class == 4 || Class == 5) {
        printf("������ �ֽ� ���ڰ� �������� ���� �������Դϴ�!");
    }
    else if (Class == 3) {
        char Y_N;
        printf("������ ������ �ֽ� ���ڰ� �������� ���� �������Դϴ�!\n");
        printf("������ �ֽ� ���� �ڹ��� �����ðڽ��ϱ�? ���Ͻø� Y ������ �����ø� N�� �Է����ּ���.\n�亯 : "); scanf("\n%c", &Y_N);
        if (Y_N == 'Y') {
            printf("������ �ֽ� ���ڴ� �⺻������ ������ �Ǵ� ä�� ���ڷ� �̷�����ϴ�.\n");
            printf("ä�� ���� �ڹ� ���񽺴� ���� �غ����̸� ������ ������ ���� �ڹ��� �����մϴ�.\n");
            printf("������ ���ڴ� ���� ���� �����ϱ⺸��, ������ ETF�� �������ڸ� ���ص帮�� �ֽ��ϴ�.\n");
            printf("ETF(Exchange Trade Fund, ���������ݵ�)�� ������ �����ôٸ� �Ʒ� ��ũ�� ���� ���� �������� �Ѿ�� �� �ֽ��ϴ�.\n");
        }
        else if (Y_N == 'N') {
            printf("���� ��ȸ�� �˵��� �ϰڽ��ϴ�.\n");
        }
    }
    else {
        char Q1, Q2;
        printf("���� �ڹ��� ���ؼ��� �� ������ ������ �� �����ּž��մϴ�\n\n");
        printf("ù ��° �����Դϴ�.\n");
        printf("���Բ��� ��������� ������ ����� ���ڸ� ���Ͻʴϱ�? ���Ͻø� Y ������ �����ø� N�� �Է����ּ���.\n�亯 : "); scanf("\n%c", &Q1);
        printf("�� ��° �����Դϴ�.\n");
        printf("���Բ��� �л����ڸ� ������ �� 1��Ģ�̶�� �����Ͻʴϱ�? ���Ͻø� Y ������ �����ø� N�� �Է����ּ���.\n�亯 : "); scanf("\n%c", &Q2);
        if (Q1 == 'Y') {
            int cnt; 
            printf("������ ���� �Դϴ�.\n�ּ� �� ���� ����� �����Ͻ� ��ȹ�̽Ű���? 50������ ���ڸ� �Է����ּ���.\n�亯 : "); scanf("\n%d", &cnt);
            printf("�Ʒ��� %d���� �������Ʈ�Դϴ�.\n", cnt);
            for (int i = 0; i < cnt; i++) {
                ROE* roedata = load_roe();
                printf("Company%d : %s\n", i + 1 ,roedata[i].name);
            }
            if (Q2 == 'Y') {
                printf("�Ʒ��� 9���� ����� �پ��� ������� ����� ��ǥ�� ���̴� �������Ʈ�Դϴ�.\n");
                for (int j = 0; j < 9; j++) {
                    Industry* industrydata = load_industry();
                    printf("Company%d : %s\n",j+1,industrydata[j].name);
                }
                
            }
        }
        else {
            if (Q2 == 'Y') {
                printf("�Ʒ��� 9���� ����� �پ��� ������� ����� ��ǥ�� ���̴� �������Ʈ�Դϴ�.\n");
                for (int j = 0; j < 9; j++) {
                    Industry* industrydata = load_industry();
                    printf("Company%d : %s\n", j+1, industrydata[j].name);
                }

            }
            else {
                printf("������� �غ�� ���񽺷δ� ���� �ڹ��� �Ұ����մϴ�. ���� ��ȸ�� �̿����ּ���.");
            }
        }
    }
    return 0;
}