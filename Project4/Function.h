#ifndef MENU
#define MENU
#include<stdio.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS 1
#endif
#ifndef MENU1
#define MENU1
#include<string.h>
#include<math.h>
#endif

#define LEN 10
#define Size 20
#define Status int
#define OK 1
#define ERROR 0

enum  Sex { male, female };

typedef struct graduate {
	int num;
	char name[10];
	enum  Sex sex;

	char turtor[LEN];
	char major[Size];
	int Class;
	char research[Size];
	int score[3];//�ۺϣ����ģ��ܳɼ�
	int class_rank;
	int sch_rank;
	struct graduate* next;
}Gra;
typedef struct undergraduate
{
	int num;           //ѧ��
	char name[15];     //����
	enum Sex sex;      //�Ա�  //enum Sex { male, female };
	char major[30];    //רҵ
	char banji[10];    //�༶
	/*�ɼ�*/
	int score[12];//�����ɼ���C���Գɼ���Ӣ��ɼ����ܳɼ����༶������У������
	struct undergraduate* next;
} UND;
UND* Head1 = { NULL };
Gra *Head2={NULL};
FILE* fp1 = NULL;
FILE* fp2 = NULL;

//��ȡ�ļ�
void readfile() {
	//Head1 = (Und*)malloc(sizeof(Und));
	//Head2 = (Gra*)malloc(sizeof(Gra));
	//Head2->num = 0;
	//Gra* Head_2 = Head2;
	//Gra* graduate2 = (Gra*)malloc(sizeof(Gra));
	//if ((fp2 = fopen("graduate.dat", "rb+")) == NULL) {
	//	printf("Can't open file!");
	//	exit(-1);
	//}
	//if (fread(graduate2, sizeof(Gra), 1, fp2)) {
	//	//��ȡfp2��һ��gra��С�����ݿ飬���Ƹ�graduate2
	//	do {
	//		Head_2->next = graduate2;
	//		Head_2 = Head_2->next;
	//		graduate2 = (Gra*)malloc(sizeof(Gra));

	//	} while (fread(graduate2, sizeof(Gra), 1, fp2));
	//}
	//Head_2->next = NULL;
	Head1 = (UND*)malloc(sizeof(UND));
	Head2 = (Gra*)malloc(sizeof(Gra));
	Head1->num = 0;
	Head2->num = 0;
	UND* Head_1 = Head1;   //Head_1��Head_2�ݴ�ͷָ��,��ֹͷָ�붪ʧ
	Gra* Head_2 = Head2;
	UND* graduate1 = (UND*)malloc(sizeof(UND));   //graduate1��graduate2�ݴ�ѧ������
	Gra* graduate2 = (Gra*)malloc(sizeof(Gra));
	if ((fp1 = fopen("undergraduate.dat", "rb+")) == NULL) {
		printf("�ļ���ʧ��!");
		exit(1);
	}
	if ((fp2 = fopen("graduate.dat", "rb+")) == NULL) {
		printf("�ļ���ʧ��!");
		exit(1);
	}
	if (fread(graduate1, sizeof(UND), 1, fp1)) {
		do {
			Head_1->next = graduate1;
			Head_1 = Head_1->next;
			graduate1 = (UND*)malloc(sizeof(UND));
		} while (fread(graduate1, sizeof(UND), 1, fp1));
	}
	Head_1->next = NULL;
	if (fread(graduate2, sizeof(Gra), 1, fp2)) {
		do {
			Head_2->next = graduate2;
			Head_2 = Head_2->next;
			graduate2 = (Gra*)malloc(sizeof(Gra));
		} while (fread(graduate2, sizeof(Gra), 1, fp2));
	}
	Head_2->next = NULL;
}
//����������ѧ�����������ݵ��ļ����ٹر��ļ�
void saveToFile() {
	rewind(fp2);
	Gra* Head_2= Head2;
	//��head_2�ݴ�ͷָ��
	while ((fwrite(Head_2->next, sizeof(Gra), 1, fp2)) == 1) {
		Head_2 = Head_2->next;
	}
	fclose(fp2);
	exit(0);
}

//�Ӽ��̶�ȡһ������������Ϣ
UND* scanf_1() {
	UND* stu;
	if ((stu = (UND*)malloc(sizeof(UND))) == NULL) {
		printf("δΪstu�����ڴ�ɹ�");
		exit(0);
	}
	stu->num = 0;
	int i;
	for (i = 0; i < 6; ++i) {
		stu->score[i] = 0;
	}
	scanf("%s%u%s%s%d%d%d", stu->name, &stu->sex, stu->major, stu->banji, &stu->score[0],
	 &stu->score[1],&stu->score[2]);
}


//�Ӽ��̶�ȡһ���о�������Ϣ
Gra* scanf_2() {
	Gra* stu;
	int i;
	if ((stu = (Gra*)malloc(sizeof(Gra))) == NULL) {
		printf("δΪstu�����ڴ�ɹ�");
		exit(0);
	}
	stu->num = 0;
	for (i = 0; i < 3; ++i) {
		stu->score[i] = 0;
	}
	stu->class_rank = 0;
	stu->sch_rank = 0;
	printf("��˳�����룺����  �Ա� רҵ �༶ �о����� ��ʦ �ۺϳɼ� ���ķ��� \n");
	scanf("%s%u%s%d%s%s%d%d", stu->num, &stu->sex, stu->major, &stu->Class,
		stu->research, stu->turtor, &stu->score[0], &stu->score[1]);
	return stu;
}

//�ܷ��Զ�ͳ��
void gradesCompute_1(UND* stu){
    stu->score[3]=stu->score[0]+stu->score[1]+stu->score[2];
}

//�ܷ��Զ�ͳ��
void gradesCompute_2(Gra* stu) {
	stu->score[2] = stu->score[1] + stu->score[0];
}

void addNode_1(UND*stu) {
	UND* Head_1 = Head1;
	Gra* Head_2 = Head2;   //Head_2�ݴ�ͷָ��,��ֹͷָ�붪ʧ
	int count = 0;
	int num1 = 0;
	int num2 = 0;
	if (Head_1->next == NULL && Head_2->next == NULL) {
		stu->num = 1;
		count = 1;
	}
	//ѧ�����ɣ��Ա��о����ͱ�������ѧ��
	while (Head_1->next != NULL) {
		if (Head_1->next->num != -1) {
			num1 = Head_1->next->num;
		}
		Head_1 = Head_1->next;
	}  //����β��ѧ��
	while (Head_2->next != NULL) {
		if (Head_2->next->num != -1) {
			num2 = Head_2->next->num;
		}
		Head_2 = Head_2->next;
	}
	if (count == 0) {
		if (Head_2->num == -1) {
			stu->num = num1 >= num2 ? num1 : num2 + 1;
		}
		if (Head_1->num <= Head_2->num) {
			stu->num = Head_2->num + 1;
		}
		else {
			stu->num = Head_1->num + 1;
		}
	}
	Head_1->next = stu;
	stu->next = NULL;
	gradesCompute_1(stu);
}


//����һ���о�������Ϣ
void addNode_2(Gra* stu) {
	UND* Head_1 = Head1;
	Gra* Head_2 = Head2;   //Head_2�ݴ�ͷָ��,��ֹͷָ�붪ʧ
	int count = 0;
	int num1 = 0;
	int num2 = 0;
	if (Head_1->next == NULL && Head_2->next == NULL) {
		stu->num = 1;
		count = 1;
	}
	//ѧ�����ɣ��Ա��о����ͱ�������ѧ��
	while (Head_1->next != NULL) {
		if (Head_1->next->num != -1) {
			num1 = Head_1->next->num;
		}
		Head_1 = Head_1->next;
	}
	while (Head_2->next != NULL) {
		if (Head_2->next->num != -1) {
			num2 = Head_2->next->num;
		}
		Head_2 = Head_2->next;
	}
	if (count == 0) {
		//�����ѧ��+1����ֵ����ѧ��
		if (Head_1->num == -1) {
			stu->num = num1 >= num2 ? num1 : num2 + 1;
		}
		if (Head_1->num <= Head_2->num) {
			stu->num = Head_2->num + 1;
		}
		else {
			stu->num = Head_1->num + 1;
		}
	}
	Head_2->next = stu;
	stu->next = NULL;
	gradesCompute_2(stu);
}

//ͳ�Ʊ���������
int numberPeople_1(UND* Head_1) {
	int i = 0;
	while (Head_1->next != NULL) {
		if (Head_1->next->num != -1) {
			i++;
			Head_1 = Head_1->next;
		}
	}
	return i;
}

//ͳ���о�������
int numberPeople_2(Gra* Head_2) {
	int i = 0;
	while (Head_2->next != NULL) {
		if (Head_2->next->num != -1) {
			i++;
			Head_2 = Head_2->next;
		}
	}
	return i;
}


//��ӡһ����������������Ϣ
void displayData_1(UND stu) {
	if (stu.num != -1) {
		switch (stu.sex) {
		case 0:
			printf("%-4d %-4s   ��   %-3s  %-9s  %-4d  %-5d  %-4d  %-3d    %-5d    %-3d\n", stu.num, stu.name, stu.major,
				stu.banji, stu.score[0],
				stu.score[1], stu.score[2], stu.score[3], stu.score[4], stu.score[5]);
			break;
		case 1:
			printf("%-4d %-4s   Ů   %-3s  %-9s  %-5d  %-4d  %-4d  %-3d    %-5d    %-3d\n", stu.num, stu.name, stu.major,
				stu.banji, stu.score[0],
				stu.score[1], stu.score[2], stu.score[3], stu.score[4], stu.score[5]);
			break;
		}
	}
}

//��ӡһ���о�����������Ϣ
void displayData_2(Gra stu) {
	if (stu.num != -1) {
		switch (stu.sex) {
		case 0:
			printf("%-4d  %-4s  ��   %-3s  %-3d  %-12s  %-5s  %-7d  %-7d  %-4d   %-6d   %-3d\n", stu.num, stu.name, stu.major,
				stu.Class,
				stu.research, stu.turtor, stu.score[0], stu.score[1], stu.score[2], stu.class_rank, stu.sch_rank);
			break;
		case 1:
			printf("%-4d  %-4s  Ů   %-3s  %-3d  %-12s  %-5s  %-7d  %-7d  %-4d   %-6d   %-3d\n", stu.num, stu.name, stu.major,
				stu.Class,
				stu.research, stu.turtor, stu.score[0], stu.score[1], stu.score[2], stu.class_rank, stu.sch_rank);
			break;
		}
	}
}


void infoPrint_1() {
	printf("\nѧ��  ���� �Ա�  רҵ  �༶      ����  C����  Ӣ�� �ܳɼ�  �༶���� У������\n");
}

void infoPrint_2() {
	printf("\nѧ��  ���� �Ա�  רҵ  �༶ �о�����    ��ʦ���� �ۺϳɼ� ���ĳɼ� �ܳɼ� �༶���� У������\n");
}


//�Ա����������е�ѧ�Ż������������Ҷ�Ӧѧ��
void searchstu(char* num_Name) {
	UND* Head_1 = Head1;
	Gra* Head_2 = Head2;
	int num1 = 0;
	int i, j, k = 0, h = 0;
	printf("********************ѧ�����ݲ�ѯ********************\n");
	if ('0' <= num_Name[0] && num_Name[0] <= '9') {    //�ж�num_Name�Ƿ���ѧ��
		for (i = 0; i < strlen(num_Name); i++) {     //�õ�int���͵�ѧ��
			j = num_Name[i] - '0';
			num1 = 10 * num1 + j;
		}
		//�Ȳ��ұ���ѧ�����Ƿ���num1
		while (Head_1->next != NULL) {
			if (Head_1->next->num == num1) {
				printf("�Ѳ��ҵ�ѧ��Ϊ%d��ѧ����Ϣ!\n\n", num1);
				printf("�Ѳ��ҵ�ѧ��Ϊ%d��ѧ����Ϣ!\n", num1);
				infoPrint_1();
				displayData_1(*Head_1->next);
				printf("\n");
				k = 1;
				break;
			}
			Head_1 = Head_1->next;
		}
		//����������û���ҵ������о�������
		if (k == 0) {
			while (Head_2->next != NULL) {
				if (Head_2->next->num == num1) {
					printf("�Ѳ��ҵ�ѧ��Ϊ%d��ѧ����Ϣ!\n\n", num1);
					printf("�Ѳ��ҵ�ѧ��Ϊ%d��ѧ����Ϣ!\n", num1);
					infoPrint_2();
					displayData_2(*Head_2->next);
					printf("\n");
					k = 1;
					break;
				}
				Head_2 = Head_2->next;
			}
		}
	}
	//����������ѧ��
	else {
		while (Head_1->next != NULL) {
			if (strcmp(num_Name, Head_1->next->name) == 0) {
				printf("�Ѳ��ҵ�����Ϊ%s��ѧ����Ϣ!\n\n", num_Name);
				infoPrint_1();
				displayData_1(*Head_1->next);
				printf("\n");
				k = 1;
				h++;
			}
			Head_1 = Head_1->next;
		}
		//
		while (Head_2->next != NULL) {
			if (strcmp(num_Name, Head_2->next->name) == 0) {
				printf("�Ѳ��ҵ�����Ϊ%s��ѧ����Ϣ!\n\n", num_Name);
				printf("�Ѳ��ҵ�����Ϊ%s��ѧ����Ϣ!\n", num_Name);
				infoPrint_2();
				displayData_2(*Head_2->next);
				printf("\n");
				k = 1;
				h++;
			}
			Head_2 = Head_2->next;
		}
		if (h > 1) {
			printf("�����ҵ�����Ϊ%s��ѧ����Ϣ%d��\n", num_Name, h);
		}
	}
	if (k == 0) {
		printf("���޴�ѧ��!\n");
	}
}


//�޸�ѧ��������Ϣ����
void modifyStudent() {
	UND* Head_1 = Head1;
	UND* Head__1 = Head1;
	Gra* Head_2 = Head2;
	Gra* Head__2 = Head2;
	int num1 = 0;
	int k = 0;
	int j = 0;
	int i = 0;
	printf("********************ѧ���ɼ�����ϵͳ********************\n");
	printf("���������޸�ѧ����ѧ�ţ�����0���أ�:");
	scanf("%d", &num1);
	if (num1 == 0) {
		//��ѧ��Ϊ0ʱ������,����С�ڴ�������
		system("cls");
		return;
	}
	//�ڱ����������о�������ѧ�Ų���
	while (Head__1->next != NULL) {
		if (Head__1->next->num == num1) {
			printf("�Ѳ��ҵ�ѧ��Ϊ%d��ѧ����Ϣ!\n", num1);
			printf("�Ѳ��ҵ�ѧ��Ϊ%d��ѧ����Ϣ!", num1);
			infoPrint_1();
			displayData_1(*Head__1->next);
			k = 1;
			break;
		}
		Head__1 = Head__1->next;
	}
	if (k == 0) {
		while (Head__2->next != NULL) {
			if (Head__2->next->num == num1) {
				printf("�Ѳ��ҵ�ѧ��Ϊ%d��ѧ����Ϣ!\n", num1);
				printf("�Ѳ��ҵ�ѧ��Ϊ%d��ѧ����Ϣ!", num1);
				infoPrint_2();
				displayData_2(*Head__2->next);
				k = 1;
				break;
			}
			Head__2 = Head__2->next;
		}
	}
	//�ҵ�������޸�ѡ��
	while (Head_1->next != NULL) {
		if (Head_1->next->num == num1) {
			printf("���������޸ĵ����ݵı��(-1-���� -2-�Ա� -3-רҵ -4-�༶ -0-�˳�):");
			scanf("%d", &i);
			switch (i) {
			case 1:
				printf("�����޸�����(����):");
				scanf("%s", Head_1->next->name);
				break;
			case 2:
				printf("�����޸�����(�Ա� -0-�� -1-Ů):");
				scanf("%u", &Head_1->next->sex);
				break;
			case 3:
				printf("�����޸�����(רҵ):");
				scanf("%s", Head_1->next->major);
				break;
			case 4:
				printf("�����޸�����(�༶ xxx��):");
				scanf("%s", Head_1->next->banji);
				break;
			case 0:
			default:
				break;
			}
			k = 1;
			j = 1;
			break;
		}
		Head_1 = Head_1->next;
	}
	//�޸��о�������Ϣ
	if (k == 0) {
		if (j == 0) {
			while (Head_2->next != NULL) {
				if (Head_2->next->num == num1) {
					printf("���������޸ĵ����ݵı��(-1-���� -2-�Ա� -3-רҵ -4-�༶ -5-�о����� -6-��ʦ���� -0-�˳�):");
					scanf("%d", &i);
					switch (i) {
					case 1:
						printf("�����޸�����(����):");
						scanf("%s", Head_2->next->name);
						break;
					case 2:
						printf("�����޸�����(�Ա� -0-�� -1-Ů):");
						scanf("%u", &Head_2->next->sex);
						break;
					case 3:
						printf("�����޸�����(רҵ):");
						scanf("%s", Head_2->next->major);
						break;
					case 4:
						printf("�����޸�����(�༶ Ϊ������):");
						scanf("%d", &Head_2->next->Class);
						break;
					case 5:
						printf("�����޸�����(�о�����):");
						scanf("%s", Head_2->next->research);
						break;
					case 6:
						printf("�����޸�����(��ʦ����):");
						scanf("%s", Head_2->next->turtor);
						break;
					case 0:
					default:
						break;
					}
					k = 1;
					j = 1;
					break;
				}
				Head_2 = Head_2->next;
			}
		}
		if (k == 0) {
			if (j == 0) {
				printf("���޴�ѧ��!\n");
			}
			printf("�޸�����ɣ�\n");
			system("pause");
			system("cls");
		}
	}
}

//�޸�ѧ����������
void modifyScore() {
	UND* Head_1 = Head1;
	UND* Head__1 = Head1;
	Gra* Head_2 = Head2;
	Gra* Head__2 = Head2;
	int num1 = 0;
	char num_1[20];
	int k = 0;
	int i = 0;
	int j = 0, l = 0;
	printf("********************ѧ���ɼ�����ϵͳ********************\n");
	printf("���������޸�ѧ����ѧ�ţ�����0���أ�:");
	scanf("%d", &num1);
	if (num1 == 0) {
		scanf("%s", num_1);
		if (strcmp(num_1, "0") == 0) {
			system("cls");
			return;
		}
		while (Head_1->next != NULL) {
			if (Head_1->next->num == num1) {
				printf("�Ѳ��ҵ�ѧ��Ϊ%d��ѧ����Ϣ!\n", num1);
				displayData_1(*Head_1->next);
				k = 1;
				break;
			}
			Head_1 = Head_1->next;
		}
		if (k == 0) {
			while (Head_2->next != NULL) {
				if (Head_2->next->num == num1) {
					printf("�Ѳ��ҵ�ѧ��Ϊ%d��ѧ����Ϣ!\n", num1);
					displayData_2(*Head_2->next);
					k = 1;
					break;
				}
				Head_2 = Head_2->next;
			}
		}
		while (Head__1->next != NULL) {
			if (Head__1->next->num == num1) {
				printf("���������޸ĵ����ݵı��(-1-�����ɼ� -2-c���Գɼ� -3-Ӣ��ɼ� -4-�����ɼ���c���Գɼ���Ӣ��ɼ� -0-�˳�):");
				scanf("%d", &i);
				switch (i) {
				case 1:
					printf("�����޸�����(�����ɼ�):");
					scanf("%d", &Head__1->next->score[0]);
					break;
				case 2:
					printf("�����޸�����(c���Գɼ�):");
					scanf("%d", &Head__1->next->score[1]);
					break;
				case 3:
					printf("�����޸�����(Ӣ��ɼ�):");
					scanf("%d", &Head__1->next->score[2]);
					break;
				case 4:
					printf("�����޸�����(Ӣ��ɼ�):");
					scanf("%d%d%d", &Head__1->next->score[0], &Head__1->next->score[1], &Head__1->next->score[2]);
					break;
				case 0:
				default:
					break;
				}
				k = 1;
				break;
			}
			Head__1 = Head__1->next;
		}
		gradesCompute_1(Head__1->next);
		if (k == 0) {
			while (Head__2->next != NULL) {
				if (Head__2->next->num == num1) {
					printf("���������޸ĵ����ݵı��(-1-�ۺϳɼ� -2-���ĳɼ� -3-�ۺϳɼ������ĳɼ� -0-�˳�):");
					scanf("%d", &i);
					switch (i) {
					case 1:
						printf("�����޸�����(�ۺϳɼ�):");
						scanf("%d", &Head__2->next->score[0]);
						break;
					case 2:
						printf("�����޸�����(���ĳɼ�):");
						scanf("%d", &Head__2->next->score[1]);
						break;
					case 3:
						printf("�����޸�����(�ۺϳɼ������ĳɼ�):");
						scanf("%d%d", &Head__2->next->score[0], &Head__2->next->score[1]);
						break;
					case 0:
					default:
						break;
					}
					gradesCompute_2(Head__2->next);
					k = 1;
					break;
				}
				Head__2 = Head__2->next;
			}
		}
	}	
	if (k == 0) {
		printf("���޴�ѧ��!\n");
	}
	else {
		printf("�޸�����ɣ�\n");
	}
	printf("�޸�����ɣ�\n");
	system("pause");
	system("cls");
}


//ɾ����Ӧѧ�ŵ�ѧ����Ϣ
void deleteStudentByild(int num1) {
	UND* Head_1 = Head1;
	Gra* Head_2 = Head2;
	int k = 0;
	while (Head_1->next != NULL) {
		if (Head_1->next->num == num1) {
			Head_1->next->num = -1;
			printf("��ɾ��ѧ��Ϊ%d��ѧ��!\n", num1);
			k = 1;
			break;
		}
		Head_1 = Head_1->next;
	}
	if (k == 0) {
		while (Head_2->next != NULL) {
			if (Head_2->next->num == num1) {
				Head_2->next->num = -1;
				printf("��ɾ��ѧ��Ϊ%d��ѧ��!\n", num1);
				k = 1;
				break;
			}
			Head_2 = Head_2->next;
		}
	}
	if (k == 0) {
		printf("���޴�ѧ��!\n");
	}
}


//��ӡ���б���������Ϣ
void getstu_1(UND* Head) {
	while (Head->next != NULL) {
		//û����β��ֹͣ��ѧ��Ϊ0������ӡ��
		if (Head->next->num != -1) {
			if (Head->next != NULL && Head->next->num != 0) {
				displayData_1(*Head->next);
			}
		}
		Head = Head->next;
	}
}

//��ӡ�����о�������Ϣ
void getstu_2(Gra* Head) {
	while (Head->next != NULL) {
		if (Head->next->num != -1) {
			if (Head->next != NULL && Head->next->num != 0) {
				displayData_2(*Head->next);
			}
		}
		Head = Head->next;
	}
}

//��ӡ��iҳ�ı�����������
void printften_1(int i)
{
	int stunum = 0;
	int cnt = 1;
	UND* pstu;
	pstu = Head1;
	//��ӡһҳ��10��������������Ϣ����������β�����ʮ��ֹͣ
	while (pstu->next != NULL && stunum < 10)
	{
		//��λ����Ӧ(i-1)*10+1��ѧ��
		if (cnt >= (i - 1) * 10 + 1)
		{
			displayData_1(*pstu->next);
			pstu = pstu->next;
			stunum++;
		}
		else pstu = pstu->next;
		cnt++;
	}
}

//��ӡ��iҳ�о�������Ϣ
void printften_2(int i)
{
	int stunum = 0;
	int cnt = 1;
	Gra* pstu;
	pstu = Head2;
	while (pstu->next != NULL && stunum < 10)
	{
		if (cnt >= (i - 1) * 10 + 1)
		{
			displayData_2(*pstu->next);
			pstu = pstu->next;
			stunum++;
		}
		else pstu = pstu->next;
		cnt++;
	}
}


//����ѧ�Ÿ�����������
void sortAllById_1() {
	UND* Head_1 = Head1;
	int count = numberPeople_1(Head_1), i = 0, j = 0, k = count;
	for (; i < count - 1; i++) {
		for (; j < k - 1; j++) {
			if (Head_1->next->num > Head_1->next->next->num) {
				UND* cur = Head_1->next, * p;
				p = cur->next;
				//swap,ǰn-1�������������Ľ�����ð������
				cur->next = cur->next->next;
				p->next = cur;
				Head_1->next = p;
				Head_1 = Head_1->next;
			}
		}
		k--;    //Ϊ��ʹÿ���������k-1��
	}
}

//����ѧ�Ÿ��о�������
void sortAllById_2() {
	Gra* Head_2 = Head2;
	int count = numberPeople_2(Head_2), i = 0, j = 0, k = count;
	for (; i < count - 1; i++) {
		for (; j < k - 1; j++) {
			if (Head_2->next->num > Head_2->next->next->num) {
				Gra* cur = Head_2->next;
				Gra* p;
				p = cur->next;//ÿ�ζ�Ҫ����p��ָ���
				//swap,ǰn-1�������������Ľ���,ѧ�ŵ͵�һ���ỻ�����һ�����
				cur->next = cur->next->next;
				p->next = cur;
				Head_2->next = p;
				Head_2 = Head_2->next;
			}
		}
		k--;
	}
}

//��ҳ��ʾ����������Ϣ�����ò˵���
void getPage_1() {
	sortAllById_1(); //����ѧ������
	int totalstu = 0;   //����
	char choice[2];
	int allpage;   //��ҳ��
	int page = 1;  //��ǰҳ��
	UND* cnt;
	cnt = Head1;
	while (cnt->next != NULL)
	{
		totalstu++;
		cnt = cnt->next;
	}
	if (totalstu % 10 != 0)
	{
		allpage = totalstu / 10 + 1;
	}
	else allpage = totalstu / 10;
	while (1) {
		system("cls");
		printf("********************************�������ɼ�����ϵͳ*********************************\n");
		infoPrint_1();
		printften_1(page);
		printf("-------------------------------��ǰΪ��%dҳ,��%dҳ--------------------------------\n", page, allpage);
		printf("��ҳ�밴��a���� ��һҳ�밴��w���� ��һҳ�밴��s���� βҳ�밴��d���� �˳��밴��0������");
		scanf("%c", &choice[0]);
		scanf("%c", &choice[1]);
		switch (choice[1]) {
		case 'a':
			if (page == 1) {
				printf("�Ѿ�����ҳ!\n");
				system("pause");
			}
			else {
				page = 1;
			}
			break;
		case 'w':
			if (page == 1) {
				printf("�Ѿ�����ҳ!\n");
				system("pause");
			}
			else if (page > 1) {
				page--;
			}
			break;
		case 's':
			if (page == allpage) {
				printf("�Ѿ���βҳ!\n");
				system("pause");
			}
			else if (page < allpage) {
				page++;
			}
			break;
		case 'd':
			if (page == allpage) {
				printf("�Ѿ���βҳ!\n");
				system("pause");
			}
			else {
				page = allpage;
			}
			break;
		case '0':
			system("cls");
			return;
		default:
			printf("����������������룡\n");
			system("pause");
			system("cls");
			break;
		}
	}
}


//��ҳ��ʾ�о�������Ϣ�����ò˵���
void getPage_2() {
	sortAllById_2(); //����ѧ������
	int totalstu = 0;   //����
	char choice[2];
	int allpage;   //��ҳ��
	int page = 1;  //��ǰҳ��
	Gra* cnt;
	cnt = Head2;
	while (cnt->next != NULL)
	{
		totalstu++;
		cnt = cnt->next;
	}
	if (totalstu % 10 != 0)
	{
		allpage = totalstu / 10 + 1;
	}
	else allpage = totalstu / 10;
	while (1) {
		system("cls");
		printf("********************************�о����ɼ�����ϵͳ*********************************\n");
		infoPrint_2();
		printften_2(page);
		printf("-------------------------------��ǰΪ��%dҳ,��%dҳ--------------------------------\n", page, allpage);
		printf("��ҳ�밴��a���� ��һҳ�밴��w���� ��һҳ�밴��s���� βҳ�밴��d���� �˳��밴��0������");
		scanf("%c", &choice[0]);
		scanf("%c", &choice[1]);
		switch (choice[1]) {
		case 'a':
			if (page == 1) {
				printf("�Ѿ�����ҳ!\n");
				system("pause");
			}
			else {
				page = 1;
			}
			break;
		case 'w':
			if (page == 1) {
				printf("�Ѿ�����ҳ!\n");
				system("pause");
			}
			else if (page > 1) {
				page--;
			}
			break;
		case 's':
			if (page == allpage) {
				printf("�Ѿ���βҳ!\n");
				system("pause");
			}
			else if (page < allpage) {
				page++;
			}
			break;
		case 'd':
			if (page == allpage) {
				printf("�Ѿ���βҳ!\n");
				system("pause");
			}
			else {
				page = allpage;
			}
			break;
		case '0':
			system("cls");
			return;
		default:
			printf("����������������룡\n");
			system("pause");
			system("cls");
			break;
		}
	}
}

//���༶Ѱ�����а༶�б�����
void searchByClass_1(char* banji) {
	UND* Head_1 = Head1;
	int k = 0;
	while (Head_1->next != NULL) {
		if (strcmp(Head_1->next->banji, banji) == 0) {
			displayData_1(*Head_1->next);
			k = 1;
		}
		Head_1 = Head_1->next;
	}
	if (k == 0)printf("�޴˰༶\n");
}

//��ӡ���ж�Ӧ�༶���о���
void searchByClass_2(char* major,int Class) {
	Gra* Head_2 = Head2;
	int k = 0;
	while (Head_2->next != NULL) {
		if (Head_2->next->Class == Class && strcmp(Head_2->next->major, major) == 0) {
			displayData_2(*Head_2->next);
			k = 1;
		}
		Head_2 = Head_2->next;
	}
	if (k == 0)printf("�޴˰༶\n");
}

//�����ֲ���ѧ��
void searchByName(char* name) {
	UND* Head_1 = Head1;
	Gra* Head_2 = Head2;
	int k = 0;
	while (Head_1->next != NULL) {
		if (strcmp(Head_1->next->name, name) == 0) {
			displayData_1(*Head_1->next);
			k = 1;
		}
		Head_1 = Head_1->next;
	}
	while (Head_2->next != NULL) {
		if (strcmp(Head_2->next->name, name) == 0) {
			displayData_2(*Head_2->next);
			k = 1;
		}
		Head_2 = Head_2->next;
	}
	if (k == 0)printf("û������Ϊ%s��ѧ��\n", name);
}

//���Ұ༶���пγ̲������ѧ��
void searnraiidyClassCourse_1(char* banji, char* course) {
	UND* Head_1 = Head1;
	int k = 0, i;
	char gaoshu[10] = "����";
	char c[10] = "C����";
	char yingyu[10] = "Ӣ��";
	if (strcmp(course, gaoshu) == 0) {
		i = 0;
	}
	else if (strcmp(course, c) == 0) {
		i = 1;
	}
	else if (strcmp(course, yingyu) == 0) {
		i = 2;
	}
	else {
		printf("����������������룡\n");
		printf("�������������\n");
		system("pause");
		system("cls");
		return;
	}
	while (Head_1->next != NULL) {
		if (strcmp(Head_1->next->banji, banji) == 0) {
			if (Head_1->next->score[i] < 60) {
				displayData_1(*Head_1->next);
				k = 1;
			}
		}
		Head_1 = Head_1->next;
	}
	if (k == 0)printf("�ð༶�еĸÿγ���ѧ��������\n");
	printf("��ѯ���\n");
	system("pause");
	system("cls");
}

//���Ұ༶���пγ̲������ѧ��
void searnraiidyClassCourse_2(int Class, char* major, char* course) {
	Gra* Head_2 = Head2;
	int k = 0, i = -1;
	char zonghe[20] = "�ۺϳɼ�";
	char lunwen[20] = "���ĳɼ�";
	if (strcmp(course, zonghe) == 0) {
		i = 0;
	}
	else if (strcmp(course, lunwen) == 0) {
		i = 1;
	}
	while (Head_2->next != NULL) {
		if (Head_2->next->Class == Class && !strcmp(Head_2->next->major, major)) {
			if (Head_2->next->score[i] < 60) {
				displayData_2(*Head_2->next);
				k = 1;
			}
		}
		Head_2 = Head_2->next;
	}
	if (k == 0)printf("�ð༶�еĸÿγ���ѧ��������\n");
	printf("��ѯ���\n");
	system("pause");
	system("cls");
}


//���������ܳɼ����򱾿�������
void sortAllBygrade_1() {
	UND* cur, * tail;
	UND* Head_1 = Head1;
	UND* Head_2 = Head_1;
	infoPrint_1();
	cur = Head_2;  //ָͷ���
	tail = NULL;
	//��curû������n-1��ʱ������ð�����򣨲�һ������
	while (cur != tail) {
		while (cur->next != tail) {
			if (cur->score[3] < cur->next->score[3]) {
				UND* p;
				p = cur->next;
				//swap,ǰn-1�������������Ľ���,�ɼ���͵�һ���ỻ�����һ�����
				cur->next = cur->next->next;
				p->next = cur;
				Head_1->next = p;
				Head_1 = Head_1->next;
			}
			cur = cur->next;
		}
		tail = cur;//����β��㣨�������������β��㣬ֻ��Ϊ��һ��ð�����������
		cur = Head_2;//��ͷ��ʼ
	}
	//----------------��������----------------
	int ranking = 1;  //����
	int const1 = 1;   //����ѧ��������
	Head_1->next->score[5] = ranking;
	//Ĭ�ϵ�һ�����Ϊ��һ��
	while (Head_1->next->next != NULL)
	//��������ʣ��ֹһ�����
	{
		if (Head_1->next->score[3] != Head_1->next->next->score[3])
		//���ɼ����ǲ��У������������������
		{
			Head_1->next->next->score[5] = Head_1->next->score[5] + const1;
			const1 = 1;
		}
		else {
			const1++;
			Head_1->next->next->score[5] = Head_1->next->score[5];
		}
		Head_1 = Head_1->next;
	}
}


//���о����������а��ɼ�����
void sortAllBygrade_2() {
	Gra* cur, * tail;
	Gra* Head_2 = Head2;
	Gra* Head_3 = Head_2;
	infoPrint_2();
	cur = Head_3;
	tail = NULL;
	while (cur != tail) {
		while (cur->next != tail) {
			if (cur->score[2] < cur->next->score[2]) {
				Gra* p;
				p = cur->next;//ÿ�ζ�Ҫ����p��ָ���
				//swap,ǰn-1�������������Ľ���,�ɼ��͵�һ���ỻ�����һ�����
				cur->next = cur->next->next;
				p->next = cur;
				Head_2->next = p;
				Head_2 = Head_2->next;
			}
			cur = cur->next;
		}
		tail = cur;
		cur = Head_3;
	}
	//----------------��������----------------
	int ranking = 1;  //����
	int const1 = 1;   //������
	Head_2->next->sch_rank = ranking;
	while (Head_2->next->next != NULL) {
		if (Head_2->next->score[2] != Head_2->next->next->score[2]) {
			Head_2->next->next->sch_rank = Head_2->next->sch_rank + const1;
			const1 = 1;
		}
		else {
			const1++;
			Head_2->next->next->sch_rank = Head_2->next->sch_rank;
		}
		Head_2 = Head_2->next;
	}
}

//���򰴳ɼ�����ʾ���б�������Ϣ
void sortAllAndShow_1() {
	sortAllBygrade_1();
	getstu_1(Head1);
	sortAllById_1();//��ʾ����ѧ�������ȥ
	printf("��ѯ��ϣ���������������˵���\n");
	system("pause");
	system("cls");
}

//�Գɼ��ߵ��������ʾ�������о�����Ϣ
void sortAllAndShow_2() {
	sortAllBygrade_2();//�Գɼ�����
	getstu_2(Head2);
	sortAllById_2();
	printf("��ѯ��ϣ���������������˵���\n");
	system("pause");
	system("cls");
}

//���ر������༶�������´�������ͷָ��
UND* returnsClassHead_1(char* banji) {
	UND* Head_1 = Head1;
	UND* Head_2 = (UND*)malloc(sizeof(UND));
	UND* Head_3 = Head_2;   //��ֹHead_2��ʧ
	while (Head_1->next != NULL) {
		if (strcmp(Head_1->next->banji, banji) == 0) {
			Head_2->next = (UND*)malloc(sizeof(UND));  //���ٿռ��������Head_2
			*Head_2->next = *Head_1->next;
			Head_2->next->next = NULL;
			Head_2 = Head_2->next;
		}
		Head_1 = Head_1->next;
	}
	Head_2->next = NULL;
	return Head_3;
}

//�����о����༶������ͷָ��
Gra* returnsClassHead_2(char* major, int Class) {
	Gra* Head_1 = Head2;
	Gra* Head_2 = (Gra*)malloc(sizeof(Gra));//�µİ༶��
	Gra* Head_3 = Head_2;   //��ֹHead_2��ʧ
	while (Head_1->next != NULL) {
		if (Head_1->next->Class == Class) 
		//�༶��ͬʱ���Ƚ�רҵ
		{
			if (strcmp(Head_1->next->major, major) == 0)
			//רҵҲ��ͬʱ����ѧ��������༶����
			{
				Head_2->next = (Gra*)malloc(sizeof(Gra));
				*Head_2->next = *Head_1->next;
				Head_2->next->next = NULL;
				Head_2 = Head_2->next;
			}
		}
		Head_1 = Head_1->next;
	}
	Head_2->next = NULL;
	return Head_3;
}


//�������༶�������ɼ��ߵ�������ʾ
void sortAllByClass_1(char* banji) {
	UND* Head_1 = returnsClassHead_1(banji), * Head___3 = Head_1;//�����Head_1�Ǿֲ�����
	UND* cur, * tail;
	cur = Head_1;
	tail = NULL;
	while (cur != tail) {
		while (cur->next != tail) {
			if (cur->score[3] < cur->next->score[3]) {
				UND* p;
				p = cur->next;
				//swap,ǰn-1�������������Ľ���,�ɼ���͵�һ���ỻ�����һ�����
				cur->next = cur->next->next;
				p->next = cur;
				Head_1->next = p;
				Head_1 = Head_1->next;
			}
			cur = cur->next;
		}
		tail = cur;
		cur = Head_1;
	}
	getstu_1(Head___3);

}


//���о����༶���ճɼ��ߵ�����
void sortAllByClass_2(char* major, int Class) {
	Gra* Head_1 = returnsClassHead_2(major, Class), * Head___3 = Head_1;
	Gra* cur, * tail;
	cur = Head_1;
	Gra* Head_2 = Head_1;
	tail = NULL;
	while (cur != tail) {
		while (cur->next != tail) {
			if (cur->score[2] < cur->next->score[2]) {
				Gra* p;
				p = cur->next;//ÿ�ζ�Ҫ����p��ָ���
				//swap,ǰn-1�������������Ľ���,�ɼ��͵�һ���ỻ�����һ�����
				cur->next = cur->next->next;
				p->next = cur;
				Head_2->next = p;
				Head_2 = Head_2->next;
			}
			cur = cur->next;
		}
		tail = cur;
		cur = Head_1;
	}
	getstu_2(Head___3);
}


//ͳ��ĳ�Ƴɼ�ƽ����
void countAverScore() {
	typedef struct Class1 {
		char banji[LEN];      //�༶��
		double totalScore;   //�ܷ�
		double averScore;    //ƽ����
		int numStudent;      //����
	}Class_1;
typedef	struct Class2 {         //�о��������ṹ
		char major[10];
		int Class;
		double totalScore;   //�ܷ�
		double averScore;    //ƽ����
		int numStudent;   //����
	}Class_2;
	UND* Head_1 = Head1;     //ʹ�þֲ�����������Head1,2�ı�
	Gra* Head_2 = Head2;
	int Number_1 = numberPeople_1(Head_1);//������������о���������
	int Number_2 = numberPeople_2(Head_2);
	Class_1 *class1;//�ṹ����,ʹ�ö�̬����
	Class_2 *class2;
	//���ݰ༶������ռ䲢�жϷ������
	
	//����ĳ�Ƴɼ�
	char gaoshu[] = "����";
	char c[] = "C����";
	char yingyu[] = "Ӣ��";
	char zonghe[] = "�ۺϳɼ�";
	char lunwen[] = "���ĳɼ�";
	char course[10];//�γ���
	int i;//�γ̴���
	int j = 0;//CLass����ʹ�ü�����
	printf("������γ̲�ѯ(����0������һ���˵�):");
	scanf("%s", course);
	if (course[0] == '0') {
		system("cls");
		return;
	}
	if (strcmp(course, gaoshu) == 0 || strcmp(course, c) == 0 || strcmp(course, yingyu) == 0)
	//��·ԭ��
	{
		class1 = (Class_1*)malloc(sizeof(Class_1) * Size);
		if (class1 == NULL) {
			printf("Can't alloc!");
			return;
		}
		if (strcmp(course, gaoshu) == 0) {
			i = 0;
		}
		else if (strcmp(course, c) == 0) {
			i = 1;
		}
		else {
			i = 2;
		}
		//��̬����¼��������Ϣ
		while (Head_1->next != NULL) {
			for (int l = 0; l <= j;) {
				//�жϰ༶,���༶�����ϣ��������i�ɼ�����
				if (strcmp(Head_1->next->banji, class1[l].banji) == 0) {
					class1[l].totalScore += Head_1->next->score[i];
					class1[l].numStudent++;
					Head_1 = Head_1->next;
					break;
					//ͳ����һ���ð�ѧ�����˳�����forѭ��
				}
				//�༶����ʱ�����������ж�
				else {
					if (l == j) 
						//���༶����j��ȣ���һ�������ð༶�����������µİ༶,�������ѧ��
					{
						strcpy(class1[j].banji, Head_1->next->banji);
						class1[j].totalScore = Head_1->next->score[i];
						class1[j].numStudent = 1;
						j++;
						Head_1 = Head_1->next;
						break;//ͳ����һ���ð�ѧ�����˳�����forѭ��
					}
					//�༶��ͬ����l++���༶��ͬ
					else {
						l++;
					}
				}
			}
		}
		//ͳ�ƺ����ƽ����
		for (int x = 0; x < j; x++) {
			class1[x].averScore = class1[x].totalScore / class1[x].numStudent;
		}
		//��ʾ�󽫷�����ڴ��ͷ�
		switch (i) {
		case 0:
			printf("��������ƽ���ɼ����£�\n");
			for (int x = 0; x < j; x++) {
				printf("%s\t��%.2lf\n", class1[x].banji, class1[x].averScore);
			}
			free(class1);
			break;
		case 1:
			printf("C���Ը���ƽ���ɼ����£�\n");
			for (int x = 0; x < j; x++) {
				printf("%s\t��%.2lf\n", class1[x].banji, class1[x].averScore);
			}
			free(class1);
			break;
		case 2:
			printf("Ӣ�����ƽ���ɼ����£�\n");
			for (int x = 0; x < j; x++) {
				printf("%s\t��%.2lf\n", class1[x].banji, class1[x].averScore);
			}
			free(class1);
			break;
		}
	}
	//�о����İ༶ƽ���ɼ�ͳ��
	else if (strcmp(course, zonghe) == 0 || strcmp(course, lunwen) == 0) {
		class2 = (Class_2*)malloc(sizeof(Class_2) * LEN);
		if (class2 == NULL) {
			printf("Can't alloc!Error!");
			return;
		}

		if (strcmp(course, zonghe) == 0) {
			i = 0;
		}
		else {
			i = 1;
		}
		while (Head_2->next != NULL) {
			for (int l = 0; l <= j; ) {

				if (strcmp(Head_2->next->major, class2[l].major) == 0 && Head_2->next->Class == class2[l].Class) {
					class2[l].totalScore += Head_2->next->score[i];
					class2[l].numStudent++;
					Head_2 = Head_2->next;
					break;//ͳ����һ���ð�ѧ�����˳�����forѭ��
				}
				else {
					if (l == j)
						//���༶����j��ȣ���һ�������ð༶�����������µİ༶,�������ѧ��
					{
						class2[j].Class = Head_2->next->Class;
						strcpy(class2[j].major, Head_2->next->major);
						class2[j].totalScore = Head_2->next->score[i];
						class2[j].numStudent = 1;
						j++;
						Head_2 = Head_2->next;
						break;//ͳ����һ���ð�ѧ�����˳�����forѭ��
					}
					else {
						l++;
					}
				}
			}
		}
		for (int x = 0; x < j; x++) {
			class2[x].averScore = class2[x].totalScore / class2[x].numStudent;
		}
		switch (i) {
		case 0:
			printf("�ۺϳɼ�����ƽ���ɼ����£�\n");
			for (int x = 0; x < j; x++) {
				printf("%sרҵ%d�ࣺ%.2lf\n", class2[x].major, class2[x].Class, class2[x].averScore);
			}
			free(class2);
			break;
		case 1:
			printf("���ĳɼ�����ƽ���ɼ����£�\n");
			for (int x = 0; x < j; x++) {
				printf("%sרҵ%d�ࣺ%.2lf\n", class2[x].major, class2[x].Class, class2[x].averScore);
			}
			free(class2);
			break;
		}
	}
	else {
		printf("�����������������룡\n");
		system("pause");
		system("cls");
		return;
	}
	printf("-----------------------------------------------------\n");
	printf("��ѯ��ϣ�������������ϼ��˵���\n");
	system("pause");
	system("cls");
}



//�󱾿�������༶��ѧ��ĳ�Ƴɼ��������������ʾ
void countByClassScore_1(char* banji, char* course) {
	UND* Head_1 = Head1;//�ֲ�����Head_1
	int i, k = 0;
	char gaoshu[10] = "����";
	char c[10] = "C����";
	char yingyu[10] = "Ӣ��";
	if (strcmp(course, gaoshu) == 0) {
		i = 0;
	}
	else if (strcmp(course, c) == 0) {
		i = 1;
	}
	else if (strcmp(course, yingyu) == 0) {
		i = 2;
	}
	else {
		printf("����������������룡\n");
		printf("�������������\n");
		system("pause");
		system("cls");
		return;
	}
	printf("%s�༶%s�ɼ��ֲ����£�\n", banji, course);

	printf("������");
	infoPrint_1();
	while (Head_1->next != NULL) {
		if (strcmp(Head_1->next->banji, banji) == 0)
		//�ԱȰ༶������ͬ���ͬѧ�Ķ�Ӧ�ɼ��ּ�
		{
			if (Head_1->next->score[i] < 60) {
				displayData_1(*Head_1->next);
				k++;
			}
		}
		Head_1 = Head_1->next;
	}
	if (k == 0) {
		printf("��\n");
	}
	else {
		k = 0;
	}
	printf("-----------------------------------------------------\n");
	printf("����");
	infoPrint_1();
	Head_1 = Head1;
	while (Head_1->next != NULL) {
		if (strcmp(Head_1->next->banji, banji) == 0) {
			if (Head_1->next->score[i] >= 60 && Head_1->next->score[i] < 70) {
				displayData_1(*Head_1->next);
				k++;
			}
		}
		Head_1 = Head_1->next;
	}
	if (k == 0) {
		printf("��\n");
	}
	else {
		k = 0;
	}
	printf("-----------------------------------------------------\n");
	printf("�еȣ�");
	infoPrint_1();
	Head_1 = Head1;
	while (Head_1->next != NULL) {
		if (strcmp(Head_1->next->banji, banji) == 0) {
			if (Head_1->next->score[i] >= 70 && Head_1->next->score[i] < 80) {
				displayData_1(*Head_1->next);
				k++;
			}
		}
		Head_1 = Head_1->next;
	}
	if (k == 0) {
		printf("��\n");
	}
	else {
		k = 0;
	}
	printf("-----------------------------------------------------\n");
	printf("���ã�");
	infoPrint_1();
	Head_1 = Head1;
	while (Head_1->next != NULL) {
		if (strcmp(Head_1->next->banji, banji) == 0) {
			if (Head_1->next->score[i] >= 80 && Head_1->next->score[i] < 90) {
				displayData_1(*Head_1->next);
				k++;
			}
		}
		Head_1 = Head_1->next;
	}
	if (k == 0) {
		printf("��\n");
	}
	else {
		k = 0;
	}
	printf("-----------------------------------------------------\n");
	printf("���㣺");
	infoPrint_1();
	Head_1 = Head1;
	while (Head_1->next != NULL) {
		if (strcmp(Head_1->next->banji, banji) == 0) {
			if (Head_1->next->score[i] >= 90) {
				displayData_1(*Head_1->next);
				k++;
			}
		}
		Head_1 = Head_1->next;
	}
	if (k == 0) {
		printf("��\n");
	}
	printf("-----------------------------------------------------\n");
	printf("��ѯ���\n");
	system("pause");
	system("cls");
}


//���о�������༶��ѧ��ĳ�Ƴɼ��������ʾ����
void countByClassScore_2(char* major, char* course, int Class) {
	Gra* Head_2 = Head2;
	int k = 0, i;
	char zonghe[20] = "�ۺϳɼ�";
	char lunwen[20] = "���ĳɼ�";
	if (strcmp(course, zonghe) == 0) {
		i = 0;
	}
	else if (strcmp(course, lunwen) == 0) {
		i = 1;
	}
	else {
		printf("�����������������룡\n");
		system("pause");
		system("cls");
		return;
	}
	printf("%sרҵ%d��%s�ɼ��ֲ����£�\n", major, Class, course);
	printf("������");
	infoPrint_2();
	while (Head_2->next != NULL) {
		if (Head_2->next->Class == Class && !strcmp(Head_2->next->major, major)) {
			if (Head_2->next->score[i] < 60) {
				displayData_2(*Head_2->next);
				k = 1;
			}
		}
		Head_2 = Head_2->next;
	}
	if (k == 0) {
		printf("��\n");
	}
	else {
		k = 0;
	}
	printf("-----------------------------------------------------\n");
	printf("����");
	infoPrint_2();
	Head_2 = Head2;
	while (Head_2->next != NULL) {
		if (Head_2->next->Class == Class && !strcmp(Head_2->next->major, major)) {
			if (Head_2->next->score[i] >= 60 && Head_2->next->score[i] < 70) {
				displayData_2(*Head_2->next);
				k = 1;
			}
		}
		Head_2 = Head_2->next;
	}
	if (k == 0) {
		printf("��\n");
	}
	else {
		k = 0;
	}
	printf("-----------------------------------------------------\n");
	printf("�еȣ�");
	infoPrint_2();
	Head_2 = Head2;
	while (Head_2->next != NULL) {
		if (Head_2->next->Class == Class && !strcmp(Head_2->next->major, major)) {
			if (Head_2->next->score[i] >= 70 && Head_2->next->score[i] < 80) {
				displayData_2(*Head_2->next);
				k = 1;
			}
		}
		Head_2 = Head_2->next;
	}
	if (k == 0) {
		printf("��\n");
	}
	else {
		k = 0;
	}
	printf("-----------------------------------------------------\n");
	printf("���ã�");
	infoPrint_2();
	Head_2 = Head2;
	while (Head_2->next != NULL) {
		if (Head_2->next->Class == Class && !strcmp(Head_2->next->major, major)) {
			if (Head_2->next->score[i] >= 80 && Head_2->next->score[i] < 90) {
				displayData_2(*Head_2->next);
				k = 1;
			}
		}
		Head_2 = Head_2->next;
	}
	if (k == 0) {
		printf("��\n");
	}
	else {
		k = 0;
	}
	printf("-----------------------------------------------------\n");
	printf("���㣺");
	infoPrint_2();
	Head_2 = Head2;
	while (Head_2->next != NULL) {
		if (Head_2->next->Class == Class && !strcmp(Head_2->next->major, major)) {
			if (Head_2->next->score[i] >= 90) {
				displayData_2(*Head_2->next);
				k = 1;
			}
		}
		Head_2 = Head_2->next;
	}
	if (k == 0) {
		printf("��\n");
	}
	printf("-----------------------------------------------------\n");
	printf("��ѯ���\n");
	system("pause");
	system("cls");
}


