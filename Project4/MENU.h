#ifndef _MENU_
#define _MENU_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#endif
#include "Function.h"
//һ�����˵�
void Main_Menu();
void MenuPrint();
void Benke_Menu();
void Yanjiu_Menu();
//�������ݹ����˵�
void baseDataMenuPrint();//�����ظ��˵���ӡ����
void deleteDate_Menu();//ɾ����������
void searchData_Menu();//��ѯ��������
void Benke_baseDataManage_Menu();//�������������ݹ����˵�
void Benke_addData_Menu();//��������Ϣ����¼��
void Yanjiu_baseDataManage_Menu();//�о����������ݹ����˵�
void Yanjiu_addData_Menu();//�о�����Ϣ����¼��
//�ɼ������˵�
void scoreMenuPrint();//�����ظ��˵���ӡ����
void deleteScore_Menu();//ɾ���ɼ�
void Benke_scoreManage_Menu();//�������ɼ������˵�
void Yanjiu_scoreManage_Menu();//�о����ɼ������˵�
//�ɼ�����˵�
void sortMenuPrint();//�����ظ��˵���ӡ����
void Benke_sort_Menu();//���Ƴɼ�����˵�
void Benke_sort_ByClass_Menu();//���Ƴɼ����༶����˵�
void Yanjiu_sort_Menu();//�о����ɼ�����˵�
void Yanjiu_sort_ByClass_Menu();//�о����ɼ����༶����˵�
//����ͳ�Ʋ˵�
void statisticsMenuPrint();//�����ظ��˵���ӡ����
void Benke_statistic_Menu();//����������ͳ�Ʋ˵�
void Benke_countByClass_Menu();//���������༶ͳ�Ʋ˵�
void Yanjiu_statistic_Menu();//�о�������ͳ�Ʋ˵�
void Yanjiu_countByClass_Menu();//�о������༶ͳ�Ʋ˵�
//��ѯ�˵�
void searchMenuPrint();//�����ظ��˵���ӡ����
void Benke_search_Menu();//��������ѯ�˵�
void Benke_search_class_Menu();//��ѯĳ���༶��ȫ��ѧ����Ϣ
void Benke_search_name_Menu();//��ѯĳ��ѧ����Ϣ
void Benke_search_fail_Menu();//��ѯĳ��ĳ��Ŀ������ѧ����Ϣ
void Yanjiu_search_Menu();//�о�����ѯ�˵�
void Yanjiu_search_class_Menu();//��ѯĳ���༶��ȫ��ѧ����Ϣ
void Yanjiu_search_name_Menu();//��ѯĳ��ѧ����Ϣ
void Yanjiu_search_fail_Menu();//��ѯĳ��ĳ��Ŀ������ѧ����Ϣ



//���˵�
void Main_Menu() {
    while (1) {
        system("cls");
        char choice[10];
        printf("*************************** �˵� ***************************\n");
        printf("_1_�������ɼ�����ϵͳ\n");
        printf("_2_�о����ɼ�����ϵͳ\n");
        printf("_0_�˳�\n");
        printf("ѡ��ϵͳ:");
        scanf("%s", choice);
        if (isdigit(choice[0])) 
        {//isdigit �����ж�������Ƿ���ʮ��������,�Ƿ��ط��㣬�񷵻�0
            switch (choice[0]) {
            case '1':
                system("cls");
                Benke_Menu();
                break;
            case '2':
                system("cls");
                Yanjiu_Menu();
                break;
            case '0':
                saveToFile();
            default:
                printf("�����������������\n");
                system("pause");
                system("cls");
            }
        }
        else {
            printf("�����������������\n");
            system("pause");
            system("cls");
        }
    }
}
//�˵���ӡ��ѡ������ʾ��
void MenuPrint() {
    printf("_1_���л�����������ά������\n");
    //����ѧ���������ϣ�ɾ��ѧ���������ϣ��޸�ѧ���������ϣ���ѯ��������
    printf("_2_���гɼ����ݹ���\n");
    //����ѧ���ɼ���ɾ��ѧ���ɼ����޸�ѧ���ɼ�����ѯѧ���ɼ�
    printf("_3_���гɼ�����\n");
    //ȫУ���������ܳɼ��ߵ���������ʾ��ĳ���༶���������ܳɼ��ߵ���������ʾ
    printf("_4_����ͳ��\n");
    //ͳ�Ʋ���ʾĳ�ſ�ÿ�����ƽ���ɼ�, ĳ������ͳ�Ʋ���ʾĳ�ſγ̲�ͬ�ȼ�ѧ��������
    printf("_5_��ѯ\n");
    //�������ȫ��ѧ����Ϣ����������༶ȫ��ѧ����Ϣ����ѯѧ����Ϣ����ѯĳ��ĳ�ſ�Ŀ������ѧ����Ϣ
    printf("_0_�����ϼ�\n");
    printf("�������:");
}


//��������Ϣ�����˵�
void Benke_Menu() {
    while (1) {
        char choice[10];
        printf("********************�������ɼ�����ϵͳ********************\n");
        MenuPrint();//��ѡ����ʾ
        scanf("%s", choice);
        if (isdigit(choice[0])) {
            switch (choice[0]) {
            case '1':
                system("cls");
                Benke_baseDataManage_Menu();//������Ϣ�����˵�
                break;
            case '2':
                system("cls");
                Benke_scoreManage_Menu();
                break;//�ɼ���Ϣ�����˵�
            case '3':
                system("cls");
                Benke_sort_Menu();//��������˵�
                break;
            case '4':
                system("cls");
                Benke_statistic_Menu();//����ͳ��
                break;
            case '5':
                system("cls");
                Benke_search_Menu();//��ѯ�˵�
                break;
            case '0':
                return;
            default:
                printf("�����������������\n");
                system("pause");
                system("cls");
            }
        }
        else {
            printf("�����������������\n");
            system("pause");
            system("cls");
        }
    }
}

//�о�����Ϣ�����˵�
void Yanjiu_Menu() {
    while (1) {
        char choice[10];
        printf("********************�о����ɼ�����ϵͳ********************\n");
        MenuPrint();//��ʾѡ��
        scanf("%s", choice);
        if (isdigit(choice[0])) {
            switch (choice[0]) {
            case '1':
                //������Ϣ�����˵�
                system("cls");
                Yanjiu_baseDataManage_Menu();
                break;
            case '2'://���������˵�
                system("cls");
                Yanjiu_scoreManage_Menu();
                break;
            case '3'://��������˵�
                system("cls");
                Yanjiu_sort_Menu();
                break;
            case '4'://����ͳ�Ʋ˵�
                system("cls");
                Yanjiu_statistic_Menu();
                break;
            case '5'://��ѯ�˵�
                system("cls");
                Yanjiu_search_Menu();
                break;
            case '0':
                return;
            default:
                printf("�����������������\n");
                system("pause");
                system("cls");
            }
        }
        else {
            printf("�����������������\n");
            system("pause");
            system("cls");
        }
    }
}

//������Ϣ���������˵���ʾ
void baseDataMenuPrint() {
    printf("_1_����ѧ������\n");
    printf("_2_ɾ��ѧ������\n");
    printf("_3_�޸�ѧ����������\n");
    printf("_4_��ѯѧ������\n");
    printf("_0_�����ϼ�\n");
    printf("������ţ�");
}
//������������Ϣ���������˵�
void Benke_baseDataManage_Menu() {
    while (1) {
        char choice[10];
        printf("********************�������ɼ�����ϵͳ********************\n");
        baseDataMenuPrint();//��ʾѡ��
        scanf("%s", choice);
        if (isdigit(choice[0])) {
            switch (choice[0]) {
            case '1':
                system("cls");
                Benke_addData_Menu();
                break;
            case '2':
                system("cls");
                deleteDate_Menu();
                break;
            case '3':
                system("cls");
                modifyStudent();
                break;
            case '4':
                system("cls");
                searchData_Menu();
                break;
            case '0':
                system("cls");
                return;
            default:
                printf("�����������������\n");
                system("pause");
                system("cls");
                break;
            }
        }
        else {
            printf("�����������������\n");
            system("pause");
            system("cls");
        }
    }
}
//�о���������Ϣ���������˵�
void Yanjiu_baseDataManage_Menu() {
    while (1) {
        char choice[10];
        printf("********************�о����ɼ�����ϵͳ********************\n");
        baseDataMenuPrint();
        scanf("%s", choice);
        if (isdigit(choice[0])) {
            switch (choice[0]) {
            case '1':
                system("cls");
                Yanjiu_addData_Menu();
                break;
            case '2':
                system("cls");
                deleteDate_Menu();
                break;
            case '3':
                system("cls");
                modifyStudent();
                break;
            case '4':
                system("cls");
                searchData_Menu();
                break;
            case '0':
                system("cls");
                return;
            default:
                printf("�����������������\n");
                system("pause");
                system("cls");
                break;
            }
        }
        else {
            printf("�����������������\n");
            system("pause");
            system("cls");
        }
    }
}


//�ɼ���Ϣ�����˵�������ѡ�
void scoreMenuPrint() {
    printf("_1_����ѧ���ɼ�\n");
    printf("_2_ɾ��ѧ���ɼ�\n");
    printf("_3_�޸�ѧ���ɼ�\n");
    printf("_4_��ѯѧ���ɼ�\n");
    printf("_0_�����ϼ�\n");
    printf("������ţ�");
}
//�������ɼ��������������˵�
void Benke_scoreManage_Menu() {
    while (1) {
        char choice[10];
        printf("********************�������ɼ�����ϵͳ********************\n");
        scoreMenuPrint();//��ʾѡ��
        scanf("%s", choice);
        if (isdigit(choice[0])) {
            switch (choice[0]) {
            case '1':
                system("cls");
                Benke_addData_Menu();
                break;
            case '2':
                system("cls");
                deleteScore_Menu();
                break;
            case '3':
                system("cls");
                modifyScore();
                break;
            case '4':
                system("cls");
                searchData_Menu();
                break;
            case '0':
                system("cls");
                return;
            default:
                printf("�����������������\n");
                system("pause");
                system("cls");
                break;
            }
        }
        else {
            printf("�����������������\n");
            system("pause");
            system("cls");
        }
    }
}
//�о����ɼ��������������˵�
void Yanjiu_scoreManage_Menu() {
    while (1) {
        char choice[10];
        printf("********************�о����ɼ�����ϵͳ********************\n");
        scoreMenuPrint();
        scanf("%s", choice);
        if (isdigit(choice[0])) {
            switch (choice[0]) {
            case '1':
                system("cls");
                Yanjiu_addData_Menu();
                break;
            case '2':
                system("cls");
                deleteScore_Menu();
                break;
            case '3':
                system("cls");
                modifyScore();
                break;
            case '4':
                system("cls");
                searchData_Menu();
                break;
            case '0':
                system("cls");
                return;
            default:
                printf("�����������������\n");
                system("pause");
                system("cls");
                break;
            }
        }
        else {
            printf("�����������������\n");
            system("pause");
            system("cls");
        }
    }
}


//�������ѡ��˵���ʾ
void sortMenuPrint() {
    printf("_1_ȫУ���ܳɼ��ߵ���������ʾ\n");
    printf("_2_�༶���ܳɼ��ߵ���������ʾ\n");
    printf("_0_�����ϼ�\n");
    printf("������ţ�");
}
//���������򣨶������˵�
void Benke_sort_Menu() {
    while (1) {
        char choice[10];
        printf("********************�������ɼ�����ϵͳ********************\n");
        sortMenuPrint();
        scanf("%s", choice);
        if (isdigit(choice[0])) {
            switch (choice[0]) {
            case '1':
                system("cls");
                sortAllAndShow_1();
                break;
            case '2':
                system("cls");
                Benke_sort_ByClass_Menu();
                break;
            case '0':
                system("cls");
                return;
            default:
                printf("�����������������\n");
                system("pause");
                system("cls");
                break;
            }
        }
        else {
            printf("�����������������\n");
            system("pause");
            system("cls");
        }
    }
}
//�о������򣨶������˵�
void Yanjiu_sort_Menu() {
    while (1) {
        char choice[10];
        printf("********************�о����ɼ�����ϵͳ********************\n");
        sortMenuPrint();
        scanf("%s", choice);
        if (isdigit(choice[0])) {
            switch (choice[0]) {
            case '1':
                system("cls");
                sortAllAndShow_2();
                break;
            case '2':
                system("cls");
                Yanjiu_sort_ByClass_Menu();
                break;
            case '0':
                system("cls");
                return;
            default:
                printf("�����������������\n");
                system("pause");
                system("cls");
                break;
            }
        }
        else {
            printf("�����������������\n");
            system("pause");
            system("cls");
        }
    }
}

//����ͳ�Ʋ˵���ʾ
void statisticsMenuPrint() {
    printf("_1_ͳ��ĳ�ſ�ÿ�����ƽ���ɼ�\n");
    printf("_2_ͳ��ĳ������ĳ�ſγ̲�ͬ�ȼ�ѧ��������\n");
    printf("_0_�����ϼ�\n");
    printf("������ţ�");
}
//����������ͳ�Ʋ˵�
void Benke_statistic_Menu() {
    while (1) {
        char choice[10];
        printf("********************�������ɼ�����ϵͳ********************\n");
        statisticsMenuPrint();
        scanf("%s", choice);
        if (isdigit(choice[0])) {
            switch (choice[0]) {
            case '1':
                system("cls");
                countAverScore();
                break;
            case '2':
                system("cls");
                Benke_countByClass_Menu();
                break;
            case '0':
                system("cls");
                return;
            default:
                printf("�����������������\n");
                system("pause");
                system("cls");
                break;
            }
        }
        else {
            printf("�����������������\n");
            system("pause");
            system("cls");
        }
    }
}
//�о�������ͳ�Ʋ˵�
void Yanjiu_statistic_Menu() {
    while (1) {
        char choice[10];
        printf("********************�о����ɼ�����ϵͳ********************\n");
        statisticsMenuPrint();
        scanf("%s", choice);
        if (isdigit(choice[0])) {
            switch (choice[0]) {
            case '1':
                system("cls");
                countAverScore();
                break;
            case '2':
                system("cls");
                Yanjiu_countByClass_Menu();
                break;
            case '0':
                system("cls");
                return;
            default:
                printf("�����������������\n");
                system("pause");
                system("cls");
                break;
            }
        }
        else {
            printf("�����������������\n");
            system("pause");
            system("cls");
        }
    }
}


//��ѯ����ѡ��˵�
void searchMenuPrint() {
    printf("_1_��ѯȫ��ѧ����Ϣ\n");
    printf("_2_��ѯĳ���༶��ȫ��ѧ����Ϣ\n");
    printf("_3_��ѯĳ��ѧ����Ϣ\n");
    printf("_4_��ѯĳ��ĳ��Ŀ������ѧ����Ϣ\n");
    printf("_0_�����ϼ�\n");
    printf("������ţ�");
}
//��������ѯ�˵�
void Benke_search_Menu() {
    while (1) {
        char choice[10];
        printf("********************�������ɼ�����ϵͳ********************\n");
        searchMenuPrint();
        scanf("%s", choice);
        if (isdigit(choice[0])) {
            switch (choice[0]) {
            case '1'://��ʾȫ������ѧ����Ϣ
                system("cls");
                getPage_1();
                break;
            case '2'://���հ༶��ѯĳ���༶������ѧ��
                system("cls");
                Benke_search_class_Menu();
                break;
            case '3'://�������а�������Ѱ�Ҷ�Ӧѧ��
                system("cls");
                Benke_search_name_Menu();
                break;
            case '4'://���ұ������гɼ����ϸ��ѧ��
                system("cls");
                Benke_search_fail_Menu();
                break;
            case '0':
                system("cls");
                return;
            default:
                printf("�����������������\n");
                system("pause");
                system("cls");
                break;
            }
        }
        else {
            printf("�����������������\n");
            system("pause");
            system("cls");
        }
    }
}
//��ʾ�������ж�Ӧ�༶ѧ����Ϣ
void Benke_search_class_Menu() {
    while (1) {
        char choice[3];
        printf("********************�������༶�ɼ���ѯ********************\n");
        printf("������༶(����0�����ϼ�)��");
        scanf("%s", choice);
        if (choice[0] == '0') {
            system("cls");
            return;
        }
        else {
            system("cls");
            infoPrint_1();
            searchByClass_1(choice);
        }
    }
}
//��ѯ�����������ж�Ӧ���ֵ�ѧ��
void Benke_search_name_Menu() {
    while (1) {
        char name[20];
        printf("*********************�������ɼ���ѯ*********************\n");
        printf("����������(����0�����ϼ�)��");
        scanf("%s", name);
        if (name[0] == '0') {
            system("cls");
            return;
        }
        else {
            system("cls");
            infoPrint_1();//��Ӧ��Ӧ��Ŀ
            searchByName(name);
        }
    }
}
//��ѯ��������ĳһ�༶ĳһѧ�ƹҿƵ�ѧ����Ϣ
void Benke_search_fail_Menu() {
    while (1) {
        char banji[10];
        char course[10];
        printf("*********************�������ɼ���ѯ*********************\n");
        printf("������༶(����0�����ϼ�)��");
        scanf("%s", banji);
        if (banji[0] == '0') {
            system("cls");
            return;
        }
        else {
            printf("������γ�(����0�����ϼ�)��");
            scanf("%s", course);
            if (course[0] == '0') {
                system("cls");
                return;
            }
            else {
                system("cls");
                infoPrint_1();
                searnraiidyClassCourse_1(banji, course);
            }
        }
    }
}
//�԰༶Ϊ��λ��ʾ
void Benke_sort_ByClass_Menu() {
    while (1) {
        char banji[10];
        printf("********************�������ɼ�����********************\n");
        printf("������༶(����0�����ϼ�)��");
        scanf("%s", banji);
        if (banji[0] == '0') {
            system("cls");
            return;
        }
        else {
            system("cls");
            infoPrint_1();
            sortAllByClass_1(banji);//�԰༶����ĺ���
        }
    }
}

//�о�����ѯ�˵�
void Yanjiu_search_Menu() {
    while (1) {
        char choice[10];
        printf("********************�о����ɼ�����ϵͳ********************\n");
        searchMenuPrint();
        scanf("%s", choice);
        if (isdigit(choice[0])) {
            switch (choice[0]) {
            case '1':
                system("cls");
                getPage_2();
                break;
            case '2':
                system("cls");
                Yanjiu_search_class_Menu();
                break;
            case '3':
                system("cls");
                Yanjiu_search_name_Menu();
                break;
            case '4':
                system("cls");
                Yanjiu_search_fail_Menu();
                break;
            case '0':
                system("cls");
                return;
            default:
                printf("�����������������\n");
                system("pause");
                system("cls");
                break;
            }
        }
        else {
            printf("�����������������\n");
            system("pause");
            system("cls");
        }
    }
}
//�о�����Ӧ�༶ѧ����Ϣ
void Yanjiu_search_class_Menu() {
    while (1) {
        char major[3];
        int choice;
        printf("********************�о����༶�ɼ���ѯ********************\n");
        printf("������רҵ(����0�����ϼ�)��");
        scanf("%s", major);
        if (major[0] == '0') {
            system("cls");
            return;
        }
        else {
            printf("������༶(����0�����ϼ�)��");
            scanf("%d", &choice);
            if (choice == 0) {
                system("cls");
                return;
            }
            else {
                system("cls");
                infoPrint_2();
                searchByClass_2(major, choice);
            }
        }
    }
}
//�о����а�������ѧ��
void Yanjiu_search_name_Menu() {
    while (1) {
        char name[20];
        printf("*********************�о����ɼ���ѯ*********************\n");
        printf("����������(����0�����ϼ�)��");
        scanf("%s", name);
        if (name[0] == '0') {
            system("cls");
            return;
        }
        else {
            system("cls");
            infoPrint_2();
            searchByName(name);
        }
    }
}
//�о������԰༶��������ĳһ�γ̹ҿƵ�ѧ����Ϣ
void Yanjiu_search_fail_Menu() {
    while (1) {
        char major[3];
        char course[20];
        int Class;
        printf("*********************�о����ɼ���ѯ*********************\n");
        printf("������רҵ(����0�����ϼ�)��");
        scanf("%s", major);
        if (major[0] == '0') {
            system("cls");
            return;
        }
        else {
            printf("������༶(����0�����ϼ�)��");
            scanf("%d", &Class);
            if (Class == 0) {
                system("cls");
                return;
            }
            else {
                printf("������γ�(����0�����ϼ�)��");
                scanf("%s", course);
                if (course[0] == '0') {
                    system("cls");
                    return;
                }
                else {
                    system("cls");
                    infoPrint_2();
                    searnraiidyClassCourse_2(Class, major, course);
                }
            }
        }
    }
}
//�о����԰༶��ʾ��Ϣ
void Yanjiu_sort_ByClass_Menu() {
    while (1) {
        char major[20];
        int Class;
        printf("********************�о����ɼ�����********************\n");
        printf("������רҵ(����0�����ϼ�)��");
        scanf("%s", major);
        if (major[0] == '0') {
            system("cls");
            return;
        }
        else {
            printf("������༶(����0�����ϼ�)��");
            scanf("%d", &Class);
            if (Class == 0) {
                system("cls");
                return;
            }
            else {
                system("cls");
                infoPrint_2();//��Ӧ�༶ѧ����Ϣ
                sortAllByClass_2(major, Class);
            }
        }
    }
}


//��������ѧ����Ϣ
void Benke_addData_Menu() {
    while (1) {
        UND* stu;
        int i;
        printf("********************�������ɼ�¼��********************\n");
        printf("��������Ҫ¼��ĸ���(����0�����ϼ�)��");
        scanf("%d", &i);
        if (i == 0) {
            system("cls");
            return;
        }
        else {
            printf("���������� �Ա�(0�����У�1����Ů) רҵ �༶ �����ɼ� C���Գɼ� Ӣ��ɼ�:\n");
            for (int j = 0; j < i; j++) {
                stu = scanf_1();
                addNode_1(stu);
            }
            printf("¼��ɹ���\n");
            system("pause");
            system("cls");
            return;
        }
    }
}

//�����о�����Ϣ
void Yanjiu_addData_Menu() {
    while (1) {
        Gra* stu;
        int i;
        printf("********************�о����ɼ�¼��********************\n");
        printf("��������Ҫ¼��ĸ���(����0�����ϼ�)��");
        scanf("%d", &i);
        if (i == 0) {
            system("cls");
            return;
        }
        else {
            printf("���������������� �Ա�(0�����У�1����Ů) רҵ �༶ �о����� �ۺϳɼ� ���ĳɼ�:\n");
            for (int j = 0; j < i; j++) {
                stu = scanf_2();
                addNode_2(stu);
            }
            printf("¼��ɹ���\n");
            system("pause");
            system("cls");
            return;
        }
    }
}

void deleteDate_Menu() {
    int num = 0;
    while (1) {
        printf("********************ѧ������ɾ��********************\n");
        printf("��������Ҫɾ����ѧ����ѧ��(����0�����ϼ�)��");
        scanf("%d", &num);
        if (num == 0) {
            system("cls");
            return;
        }
        else {
            printf("ע�⣺��������Ĳ�������ɾ����ѧ�����������ݣ������������\n");
            printf("������1����������0�����ϼ��˵���");
            char i[10];
            scanf("%s", i);
            if (strcmp(i, "0") == 0) {
                system("cls");
                return;
            }
            else {
                deleteStudentByild(num);
                system("pause");
                system("cls");
                return;
            }
        }

    }
}

//��ѧ��ɾ���ɼ��Ĳ˵���������
void deleteScore_Menu() {
    int num = 0, k = 0;//K�������ж��Ƿ���ɾ��
    UND* Head_1 = Head1;
    Gra* Head_2 = Head2;
    while (1) {
        printf("********************ѧ���ɼ�ɾ��********************\n");
        printf("��������Ҫɾ���ɼ���ѧ����ѧ��(����0�����ϼ�)��");
        scanf("%d", &num);
        if (num == 0) {
            system("cls");
            return;
        }
        else {
            while (Head_1->next != NULL) {
                if (Head_1->next->num == num) {
                    for (int i = 0; i < 12; i++) {
                        Head_1->next->score[i] = -1;
                    }
                    printf("��ɾ��ѧ��Ϊ%d��ѧ�������гɼ�!\n", num);
                    k = 1;
                    break;
                }
                Head_1 = Head_1->next;
            }
            if (k == 0) {
                while (Head_2->next != NULL) {
                    if (Head_2->next->num == num) {
                        for (int i = 0; i < 3; i++) {
                            Head_2->next->score[i] = -1;
                        }
                        printf("��ɾ��ѧ��Ϊ%d��ѧ�������гɼ�!\n", num);
                        k = 1;
                        break;
                    }
                    Head_2 = Head_2->next;
                }
            }

        }
        if (k == 0) {
            printf("���޴�ѧ��!\n");
            break;
        }
        else {
            break;
        }
    }
    system("pause");
    system("cls");
}

//��ѯ��Ӧѧ�ţ����ֵ�ѧ����Ϣ����ʾ
void searchData_Menu() {
    while (1) {
        char num_Name[20];
        printf("********************ѧ�����ݲ�ѯ********************\n");
        printf("��������Ҫ��ѯ��ѧ����ѧ�Ż�����(����0�����ϼ�)��");
        scanf("%s", num_Name);
        if (num_Name[0] == '0') {
            system("cls");
            return;
        }
        else {
            searchstu(num_Name);
            printf("��ѯ����ɣ�\n");
            system("pause");
            system("cls");
        }
    }
}
//�԰༶ͳ��ĳѧ������
void Benke_countByClass_Menu() {
    while (1) {
        char banji[10];
        char course[10];
        printf("********************�༶�ɼ�ͳ��********************\n");
        printf("��������Ҫͳ�Ƶİ༶(����0�����ϼ�)��");
        scanf("%s", banji);
        if (banji[0] == '0') {
            system("cls");
            return;
        }
        else {
            printf("��������Ҫͳ�ƵĿγ�(����0�����ϼ�)��");
            scanf("%s", course);
            if (course[0] == '0') {
                system("cls");
                return;
            }
            else {
                countByClassScore_1(banji, course);
            }
        }
    }
}
//��רҵ�༶ͳ��ĳ�γ�����
void Yanjiu_countByClass_Menu() {
    while (1) {
        char major[10];
        char course[10];
        int Class;
        printf("********************�༶�ɼ�ͳ��********************\n");
        printf("��������Ҫͳ�Ƶ�רҵ(����0�����ϼ�)��");
        scanf("%s", major);
        if (major[0] == '0') {
            system("cls");
            return;
        }
        else {
            printf("��������Ҫͳ�Ƶİ༶(����0�����ϼ�)��");
            scanf("%d", &Class);
            if (course[0] == '0') {
                system("cls");
                return;
            }
            else {
                printf("��������Ҫͳ�ƵĿγ�(����0�����ϼ�)��");
                scanf("%s", course);
                if (course[0] == '0') {
                    system("cls");
                    return;
                }
                else {
                    countByClassScore_2(major, course, Class);
                }
            }
        }
    }
}
