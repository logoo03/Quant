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
        char input = getchar(); getchar();
        while (input < '1' || input > '0' + q.choice_count) {
            printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n");
            printf("�� : ");
            input = getchar(); getchar();
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
        printf("������ �ֽ� ���� �ڹ��� �����ðڽ��ϱ�?\n�亯 : "); scanf("\n%c", &Y_N);
        if (Y_N == 'Y') {
            printf("�Ʒ��� ���� ����� ���� 10%%�� �����ͷ��� ����ϰ� �ֽ��ϴ�\n");
        }
        else if (Y_N == 'N') {
            printf("���� ��ȸ�� �˵��� �ϰڽ��ϴ�.\n");
        }
    }
    // �������� ���ο� ��ġ�� ������
    // ������, ROE, EPS, ���ͷ�
    else if (Class == 2) {

    }
    else {

    }
}