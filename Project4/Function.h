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
	int score[3];//综合，论文，总成绩
	int class_rank;
	int sch_rank;
	struct graduate* next;
}Gra;
typedef struct undergraduate
{
	int num;           //学号
	char name[15];     //姓名
	enum Sex sex;      //性别  //enum Sex { male, female };
	char major[30];    //专业
	char banji[10];    //班级
	/*成绩*/
	int score[12];//高数成绩、C语言成绩、英语成绩、总成绩、班级排名、校级排名
	struct undergraduate* next;
} UND;
UND* Head1 = { NULL };
Gra *Head2={NULL};
FILE* fp1 = NULL;
FILE* fp2 = NULL;

//读取文件
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
	//	//读取fp2中一个gra大小的数据块，复制给graduate2
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
	UND* Head_1 = Head1;   //Head_1和Head_2暂存头指针,防止头指针丢失
	Gra* Head_2 = Head2;
	UND* graduate1 = (UND*)malloc(sizeof(UND));   //graduate1和graduate2暂存学生数据
	Gra* graduate2 = (Gra*)malloc(sizeof(Gra));
	if ((fp1 = fopen("undergraduate.dat", "rb+")) == NULL) {
		printf("文件打开失败!");
		exit(1);
	}
	if ((fp2 = fopen("graduate.dat", "rb+")) == NULL) {
		printf("文件打开失败!");
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
//保存链表中学生的所有数据到文件后再关闭文件
void saveToFile() {
	rewind(fp2);
	Gra* Head_2= Head2;
	//用head_2暂存头指针
	while ((fwrite(Head_2->next, sizeof(Gra), 1, fp2)) == 1) {
		Head_2 = Head_2->next;
	}
	fclose(fp2);
	exit(0);
}

//从键盘读取一个本科生的信息
UND* scanf_1() {
	UND* stu;
	if ((stu = (UND*)malloc(sizeof(UND))) == NULL) {
		printf("未为stu分配内存成功");
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


//从键盘读取一个研究生的信息
Gra* scanf_2() {
	Gra* stu;
	int i;
	if ((stu = (Gra*)malloc(sizeof(Gra))) == NULL) {
		printf("未为stu分配内存成功");
		exit(0);
	}
	stu->num = 0;
	for (i = 0; i < 3; ++i) {
		stu->score[i] = 0;
	}
	stu->class_rank = 0;
	stu->sch_rank = 0;
	printf("按顺序输入：姓名  性别 专业 班级 研究方向 导师 综合成绩 论文分数 \n");
	scanf("%s%u%s%d%s%s%d%d", stu->num, &stu->sex, stu->major, &stu->Class,
		stu->research, stu->turtor, &stu->score[0], &stu->score[1]);
	return stu;
}

//总分自动统计
void gradesCompute_1(UND* stu){
    stu->score[3]=stu->score[0]+stu->score[1]+stu->score[2];
}

//总分自动统计
void gradesCompute_2(Gra* stu) {
	stu->score[2] = stu->score[1] + stu->score[0];
}

void addNode_1(UND*stu) {
	UND* Head_1 = Head1;
	Gra* Head_2 = Head2;   //Head_2暂存头指针,防止头指针丢失
	int count = 0;
	int num1 = 0;
	int num2 = 0;
	if (Head_1->next == NULL && Head_2->next == NULL) {
		stu->num = 1;
		count = 1;
	}
	//学号生成：对比研究生和本科生的学号
	while (Head_1->next != NULL) {
		if (Head_1->next->num != -1) {
			num1 = Head_1->next->num;
		}
		Head_1 = Head_1->next;
	}  //链表尾的学号
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


//添加一个研究生的信息
void addNode_2(Gra* stu) {
	UND* Head_1 = Head1;
	Gra* Head_2 = Head2;   //Head_2暂存头指针,防止头指针丢失
	int count = 0;
	int num1 = 0;
	int num2 = 0;
	if (Head_1->next == NULL && Head_2->next == NULL) {
		stu->num = 1;
		count = 1;
	}
	//学号生成：对比研究生和本科生的学号
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
		//将大的学号+1，赋值给新学号
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

//统计本科生人数
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

//统计研究生人数
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


//打印一个本科生的所有信息
void displayData_1(UND stu) {
	if (stu.num != -1) {
		switch (stu.sex) {
		case 0:
			printf("%-4d %-4s   男   %-3s  %-9s  %-4d  %-5d  %-4d  %-3d    %-5d    %-3d\n", stu.num, stu.name, stu.major,
				stu.banji, stu.score[0],
				stu.score[1], stu.score[2], stu.score[3], stu.score[4], stu.score[5]);
			break;
		case 1:
			printf("%-4d %-4s   女   %-3s  %-9s  %-5d  %-4d  %-4d  %-3d    %-5d    %-3d\n", stu.num, stu.name, stu.major,
				stu.banji, stu.score[0],
				stu.score[1], stu.score[2], stu.score[3], stu.score[4], stu.score[5]);
			break;
		}
	}
}

//打印一个研究生的所有信息
void displayData_2(Gra stu) {
	if (stu.num != -1) {
		switch (stu.sex) {
		case 0:
			printf("%-4d  %-4s  男   %-3s  %-3d  %-12s  %-5s  %-7d  %-7d  %-4d   %-6d   %-3d\n", stu.num, stu.name, stu.major,
				stu.Class,
				stu.research, stu.turtor, stu.score[0], stu.score[1], stu.score[2], stu.class_rank, stu.sch_rank);
			break;
		case 1:
			printf("%-4d  %-4s  女   %-3s  %-3d  %-12s  %-5s  %-7d  %-7d  %-4d   %-6d   %-3d\n", stu.num, stu.name, stu.major,
				stu.Class,
				stu.research, stu.turtor, stu.score[0], stu.score[1], stu.score[2], stu.class_rank, stu.sch_rank);
			break;
		}
	}
}


void infoPrint_1() {
	printf("\n学号  姓名 性别  专业  班级      高数  C语言  英语 总成绩  班级排名 校级排名\n");
}

void infoPrint_2() {
	printf("\n学号  姓名 性别  专业  班级 研究方向    导师名字 综合成绩 论文成绩 总成绩 班级排名 校级排名\n");
}


//对比两个链表中的学号或者姓名，查找对应学生
void searchstu(char* num_Name) {
	UND* Head_1 = Head1;
	Gra* Head_2 = Head2;
	int num1 = 0;
	int i, j, k = 0, h = 0;
	printf("********************学生数据查询********************\n");
	if ('0' <= num_Name[0] && num_Name[0] <= '9') {    //判断num_Name是否是学号
		for (i = 0; i < strlen(num_Name); i++) {     //得到int类型的学号
			j = num_Name[i] - '0';
			num1 = 10 * num1 + j;
		}
		//先查找本科学生中是否有num1
		while (Head_1->next != NULL) {
			if (Head_1->next->num == num1) {
				printf("已查找到学号为%d的学生信息!\n\n", num1);
				printf("已查找到学号为%d的学生信息!\n", num1);
				infoPrint_1();
				displayData_1(*Head_1->next);
				printf("\n");
				k = 1;
				break;
			}
			Head_1 = Head_1->next;
		}
		//当本科生中没有找到，在研究生中找
		if (k == 0) {
			while (Head_2->next != NULL) {
				if (Head_2->next->num == num1) {
					printf("已查找到学号为%d的学生信息!\n\n", num1);
					printf("已查找到学号为%d的学生信息!\n", num1);
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
	//以姓名查找学生
	else {
		while (Head_1->next != NULL) {
			if (strcmp(num_Name, Head_1->next->name) == 0) {
				printf("已查找到姓名为%s的学生信息!\n\n", num_Name);
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
				printf("已查找到姓名为%s的学生信息!\n\n", num_Name);
				printf("已查找到姓名为%s的学生信息!\n", num_Name);
				infoPrint_2();
				displayData_2(*Head_2->next);
				printf("\n");
				k = 1;
				h++;
			}
			Head_2 = Head_2->next;
		}
		if (h > 1) {
			printf("共查找到姓名为%s的学生信息%d组\n", num_Name, h);
		}
	}
	if (k == 0) {
		printf("查无此学生!\n");
	}
}


//修改学生基本信息函数
void modifyStudent() {
	UND* Head_1 = Head1;
	UND* Head__1 = Head1;
	Gra* Head_2 = Head2;
	Gra* Head__2 = Head2;
	int num1 = 0;
	int k = 0;
	int j = 0;
	int i = 0;
	printf("********************学生成绩管理系统********************\n");
	printf("请输入需修改学生的学号（输入0返回）:");
	scanf("%d", &num1);
	if (num1 == 0) {
		//当学号为0时，保留,清屏小黑窗并返回
		system("cls");
		return;
	}
	//在本科生，后研究生中以学号查找
	while (Head__1->next != NULL) {
		if (Head__1->next->num == num1) {
			printf("已查找到学号为%d的学生信息!\n", num1);
			printf("已查找到学号为%d的学生信息!", num1);
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
				printf("已查找到学号为%d的学生信息!\n", num1);
				printf("已查找到学号为%d的学生信息!", num1);
				infoPrint_2();
				displayData_2(*Head__2->next);
				k = 1;
				break;
			}
			Head__2 = Head__2->next;
		}
	}
	//找到后进行修改选择
	while (Head_1->next != NULL) {
		if (Head_1->next->num == num1) {
			printf("请输入需修改的数据的编号(-1-姓名 -2-性别 -3-专业 -4-班级 -0-退出):");
			scanf("%d", &i);
			switch (i) {
			case 1:
				printf("输入修改数据(姓名):");
				scanf("%s", Head_1->next->name);
				break;
			case 2:
				printf("输入修改数据(性别 -0-男 -1-女):");
				scanf("%u", &Head_1->next->sex);
				break;
			case 3:
				printf("输入修改数据(专业):");
				scanf("%s", Head_1->next->major);
				break;
			case 4:
				printf("输入修改数据(班级 xxx班):");
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
	//修改研究生的信息
	if (k == 0) {
		if (j == 0) {
			while (Head_2->next != NULL) {
				if (Head_2->next->num == num1) {
					printf("请输入需修改的数据的编号(-1-姓名 -2-性别 -3-专业 -4-班级 -5-研究方向 -6-导师名字 -0-退出):");
					scanf("%d", &i);
					switch (i) {
					case 1:
						printf("输入修改数据(姓名):");
						scanf("%s", Head_2->next->name);
						break;
					case 2:
						printf("输入修改数据(性别 -0-男 -1-女):");
						scanf("%u", &Head_2->next->sex);
						break;
					case 3:
						printf("输入修改数据(专业):");
						scanf("%s", Head_2->next->major);
						break;
					case 4:
						printf("输入修改数据(班级 为纯数字):");
						scanf("%d", &Head_2->next->Class);
						break;
					case 5:
						printf("输入修改数据(研究方向):");
						scanf("%s", Head_2->next->research);
						break;
					case 6:
						printf("输入修改数据(导师名字):");
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
				printf("查无此学生!\n");
			}
			printf("修改已完成！\n");
			system("pause");
			system("cls");
		}
	}
}

//修改学生分数函数
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
	printf("********************学生成绩管理系统********************\n");
	printf("请输入需修改学生的学号（输入0返回）:");
	scanf("%d", &num1);
	if (num1 == 0) {
		scanf("%s", num_1);
		if (strcmp(num_1, "0") == 0) {
			system("cls");
			return;
		}
		while (Head_1->next != NULL) {
			if (Head_1->next->num == num1) {
				printf("已查找到学号为%d的学生信息!\n", num1);
				displayData_1(*Head_1->next);
				k = 1;
				break;
			}
			Head_1 = Head_1->next;
		}
		if (k == 0) {
			while (Head_2->next != NULL) {
				if (Head_2->next->num == num1) {
					printf("已查找到学号为%d的学生信息!\n", num1);
					displayData_2(*Head_2->next);
					k = 1;
					break;
				}
				Head_2 = Head_2->next;
			}
		}
		while (Head__1->next != NULL) {
			if (Head__1->next->num == num1) {
				printf("请输入需修改的数据的编号(-1-高数成绩 -2-c语言成绩 -3-英语成绩 -4-高数成绩和c语言成绩和英语成绩 -0-退出):");
				scanf("%d", &i);
				switch (i) {
				case 1:
					printf("输入修改数据(高数成绩):");
					scanf("%d", &Head__1->next->score[0]);
					break;
				case 2:
					printf("输入修改数据(c语言成绩):");
					scanf("%d", &Head__1->next->score[1]);
					break;
				case 3:
					printf("输入修改数据(英语成绩):");
					scanf("%d", &Head__1->next->score[2]);
					break;
				case 4:
					printf("输入修改数据(英语成绩):");
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
					printf("请输入需修改的数据的编号(-1-综合成绩 -2-论文成绩 -3-综合成绩和论文成绩 -0-退出):");
					scanf("%d", &i);
					switch (i) {
					case 1:
						printf("输入修改数据(综合成绩):");
						scanf("%d", &Head__2->next->score[0]);
						break;
					case 2:
						printf("输入修改数据(论文成绩):");
						scanf("%d", &Head__2->next->score[1]);
						break;
					case 3:
						printf("输入修改数据(综合成绩和论文成绩):");
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
		printf("查无此学生!\n");
	}
	else {
		printf("修改已完成！\n");
	}
	printf("修改已完成！\n");
	system("pause");
	system("cls");
}


//删除对应学号的学生信息
void deleteStudentByild(int num1) {
	UND* Head_1 = Head1;
	Gra* Head_2 = Head2;
	int k = 0;
	while (Head_1->next != NULL) {
		if (Head_1->next->num == num1) {
			Head_1->next->num = -1;
			printf("已删除学号为%d的学生!\n", num1);
			k = 1;
			break;
		}
		Head_1 = Head_1->next;
	}
	if (k == 0) {
		while (Head_2->next != NULL) {
			if (Head_2->next->num == num1) {
				Head_2->next->num = -1;
				printf("已删除学号为%d的学生!\n", num1);
				k = 1;
				break;
			}
			Head_2 = Head_2->next;
		}
	}
	if (k == 0) {
		printf("查无此学生!\n");
	}
}


//打印所有本科生的信息
void getstu_1(UND* Head) {
	while (Head->next != NULL) {
		//没到表尾不停止，学号为0（不打印）
		if (Head->next->num != -1) {
			if (Head->next != NULL && Head->next->num != 0) {
				displayData_1(*Head->next);
			}
		}
		Head = Head->next;
	}
}

//打印所有研究生的信息
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

//打印第i页的本科生的数据
void printften_1(int i)
{
	int stunum = 0;
	int cnt = 1;
	UND* pstu;
	pstu = Head1;
	//打印一页（10个）本科生的信息，若遇到表尾或打完十个停止
	while (pstu->next != NULL && stunum < 10)
	{
		//定位到对应(i-1)*10+1个学生
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

//打印第i页研究生的信息
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


//按照学号给本科生排序
void sortAllById_1() {
	UND* Head_1 = Head1;
	int count = numberPeople_1(Head_1), i = 0, j = 0, k = count;
	for (; i < count - 1; i++) {
		for (; j < k - 1; j++) {
			if (Head_1->next->num > Head_1->next->next->num) {
				UND* cur = Head_1->next, * p;
				p = cur->next;
				//swap,前n-1个结点符合这样的交换，冒泡排序
				cur->next = cur->next->next;
				p->next = cur;
				Head_1->next = p;
				Head_1 = Head_1->next;
			}
		}
		k--;    //为了使每次排序进行k-1次
	}
}

//按照学号给研究生排序
void sortAllById_2() {
	Gra* Head_2 = Head2;
	int count = numberPeople_2(Head_2), i = 0, j = 0, k = count;
	for (; i < count - 1; i++) {
		for (; j < k - 1; j++) {
			if (Head_2->next->num > Head_2->next->next->num) {
				Gra* cur = Head_2->next;
				Gra* p;
				p = cur->next;//每次都要更新p所指结点
				//swap,前n-1个结点符合这样的交换,学号低的一定会换到最后一个结点
				cur->next = cur->next->next;
				p->next = cur;
				Head_2->next = p;
				Head_2 = Head_2->next;
			}
		}
		k--;
	}
}

//分页显示本科生的信息（内置菜单）
void getPage_1() {
	sortAllById_1(); //按照学号排序
	int totalstu = 0;   //人数
	char choice[2];
	int allpage;   //总页数
	int page = 1;  //当前页数
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
		printf("********************************本科生成绩管理系统*********************************\n");
		infoPrint_1();
		printften_1(page);
		printf("-------------------------------当前为第%d页,共%d页--------------------------------\n", page, allpage);
		printf("首页请按“a”键 上一页请按“w”键 下一页请按“s”键 尾页请按“d”键 退出请按“0”键：");
		scanf("%c", &choice[0]);
		scanf("%c", &choice[1]);
		switch (choice[1]) {
		case 'a':
			if (page == 1) {
				printf("已经是首页!\n");
				system("pause");
			}
			else {
				page = 1;
			}
			break;
		case 'w':
			if (page == 1) {
				printf("已经是首页!\n");
				system("pause");
			}
			else if (page > 1) {
				page--;
			}
			break;
		case 's':
			if (page == allpage) {
				printf("已经是尾页!\n");
				system("pause");
			}
			else if (page < allpage) {
				page++;
			}
			break;
		case 'd':
			if (page == allpage) {
				printf("已经是尾页!\n");
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
			printf("输入错误，请重新输入！\n");
			system("pause");
			system("cls");
			break;
		}
	}
}


//按页显示研究生的信息（内置菜单）
void getPage_2() {
	sortAllById_2(); //按照学号排序
	int totalstu = 0;   //人数
	char choice[2];
	int allpage;   //总页数
	int page = 1;  //当前页数
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
		printf("********************************研究生成绩管理系统*********************************\n");
		infoPrint_2();
		printften_2(page);
		printf("-------------------------------当前为第%d页,共%d页--------------------------------\n", page, allpage);
		printf("首页请按“a”键 上一页请按“w”键 下一页请按“s”键 尾页请按“d”键 退出请按“0”键：");
		scanf("%c", &choice[0]);
		scanf("%c", &choice[1]);
		switch (choice[1]) {
		case 'a':
			if (page == 1) {
				printf("已经是首页!\n");
				system("pause");
			}
			else {
				page = 1;
			}
			break;
		case 'w':
			if (page == 1) {
				printf("已经是首页!\n");
				system("pause");
			}
			else if (page > 1) {
				page--;
			}
			break;
		case 's':
			if (page == allpage) {
				printf("已经是尾页!\n");
				system("pause");
			}
			else if (page < allpage) {
				page++;
			}
			break;
		case 'd':
			if (page == allpage) {
				printf("已经是尾页!\n");
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
			printf("输入错误，请重新输入！\n");
			system("pause");
			system("cls");
			break;
		}
	}
}

//按班级寻找所有班级中本科生
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
	if (k == 0)printf("无此班级\n");
}

//打印所有对应班级的研究生
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
	if (k == 0)printf("无此班级\n");
}

//以名字查找学生
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
	if (k == 0)printf("没有名字为%s的学生\n", name);
}

//查找班级中有课程不及格的学生
void searnraiidyClassCourse_1(char* banji, char* course) {
	UND* Head_1 = Head1;
	int k = 0, i;
	char gaoshu[10] = "高数";
	char c[10] = "C语言";
	char yingyu[10] = "英语";
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
		printf("输入错误，请重新输入！\n");
		printf("输入任意键继续\n");
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
	if (k == 0)printf("该班级中的该课程无学生不及格\n");
	printf("查询完毕\n");
	system("pause");
	system("cls");
}

//查找班级中有课程不及格的学生
void searnraiidyClassCourse_2(int Class, char* major, char* course) {
	Gra* Head_2 = Head2;
	int k = 0, i = -1;
	char zonghe[20] = "综合成绩";
	char lunwen[20] = "论文成绩";
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
	if (k == 0)printf("该班级中的该课程无学生不及格\n");
	printf("查询完毕\n");
	system("pause");
	system("cls");
}


//单独按照总成绩排序本科生链表
void sortAllBygrade_1() {
	UND* cur, * tail;
	UND* Head_1 = Head1;
	UND* Head_2 = Head_1;
	infoPrint_1();
	cur = Head_2;  //指头结点
	tail = NULL;
	//当cur没遍历到n-1个时，进行冒泡排序（不一定换）
	while (cur != tail) {
		while (cur->next != tail) {
			if (cur->score[3] < cur->next->score[3]) {
				UND* p;
				p = cur->next;
				//swap,前n-1个结点符合这样的交换,成绩最低的一定会换到最后一个结点
				cur->next = cur->next->next;
				p->next = cur;
				Head_1->next = p;
				Head_1 = Head_1->next;
			}
			cur = cur->next;
		}
		tail = cur;//更新尾结点（不是真正意义的尾结点，只是为了一次冒泡排序结束）
		cur = Head_2;//从头开始
	}
	//----------------计算排名----------------
	int ranking = 1;  //排名
	int const1 = 1;   //并列学生计数器
	Head_1->next->score[5] = ranking;
	//默认第一个结点为第一名
	while (Head_1->next->next != NULL)
	//当链表还剩不止一个结点
	{
		if (Head_1->next->score[3] != Head_1->next->next->score[3])
		//当成绩不是并列，排名递增，是则递增
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


//对研究生链表进行按成绩排序
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
				p = cur->next;//每次都要更新p所指结点
				//swap,前n-1个结点符合这样的交换,成绩低的一定会换到最后一个结点
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
	//----------------计算排名----------------
	int ranking = 1;  //排名
	int const1 = 1;   //计数器
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

//排序按成绩并显示所有本科生信息
void sortAllAndShow_1() {
	sortAllBygrade_1();
	getstu_1(Head1);
	sortAllById_1();//显示后以学号排序回去
	printf("查询完毕！按任意键返回主菜单！\n");
	system("pause");
	system("cls");
}

//以成绩高低排序和显示将所有研究生信息
void sortAllAndShow_2() {
	sortAllBygrade_2();//以成绩排序
	getstu_2(Head2);
	sortAllById_2();
	printf("查询完毕！按任意键返回主菜单！\n");
	system("pause");
	system("cls");
}

//返回本科生班级链表（新创建）的头指针
UND* returnsClassHead_1(char* banji) {
	UND* Head_1 = Head1;
	UND* Head_2 = (UND*)malloc(sizeof(UND));
	UND* Head_3 = Head_2;   //防止Head_2丢失
	while (Head_1->next != NULL) {
		if (strcmp(Head_1->next->banji, banji) == 0) {
			Head_2->next = (UND*)malloc(sizeof(UND));  //开辟空间接入链表Head_2
			*Head_2->next = *Head_1->next;
			Head_2->next->next = NULL;
			Head_2 = Head_2->next;
		}
		Head_1 = Head_1->next;
	}
	Head_2->next = NULL;
	return Head_3;
}

//返回研究生班级链表的头指针
Gra* returnsClassHead_2(char* major, int Class) {
	Gra* Head_1 = Head2;
	Gra* Head_2 = (Gra*)malloc(sizeof(Gra));//新的班级链
	Gra* Head_3 = Head_2;   //防止Head_2丢失
	while (Head_1->next != NULL) {
		if (Head_1->next->Class == Class) 
		//班级相同时，比较专业
		{
			if (strcmp(Head_1->next->major, major) == 0)
			//专业也相同时，将学生结点接入班级链表
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


//本科生班级链表按成绩高低排序并显示
void sortAllByClass_1(char* banji) {
	UND* Head_1 = returnsClassHead_1(banji), * Head___3 = Head_1;//这里的Head_1是局部变量
	UND* cur, * tail;
	cur = Head_1;
	tail = NULL;
	while (cur != tail) {
		while (cur->next != tail) {
			if (cur->score[3] < cur->next->score[3]) {
				UND* p;
				p = cur->next;
				//swap,前n-1个结点符合这样的交换,成绩最低的一定会换到最后一个结点
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


//对研究生班级按照成绩高低排序
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
				p = cur->next;//每次都要更新p所指结点
				//swap,前n-1个结点符合这样的交换,成绩低的一定会换到最后一个结点
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


//统计某科成绩平均分
void countAverScore() {
	typedef struct Class1 {
		char banji[LEN];      //班级名
		double totalScore;   //总分
		double averScore;    //平均分
		int numStudent;      //人数
	}Class_1;
typedef	struct Class2 {         //研究生分数结构
		char major[10];
		int Class;
		double totalScore;   //总分
		double averScore;    //平均分
		int numStudent;   //人数
	}Class_2;
	UND* Head_1 = Head1;     //使用局部变量，避免Head1,2改变
	Gra* Head_2 = Head2;
	int Number_1 = numberPeople_1(Head_1);//求出本科生，研究生的人数
	int Number_2 = numberPeople_2(Head_2);
	Class_1 *class1;//结构数组,使用动态数组
	Class_2 *class2;
	//根据班级数分配空间并判断分配情况
	
	//查找某科成绩
	char gaoshu[] = "高数";
	char c[] = "C语言";
	char yingyu[] = "英语";
	char zonghe[] = "综合成绩";
	char lunwen[] = "论文成绩";
	char course[10];//课程名
	int i;//课程代码
	int j = 0;//CLass数组使用计数器
	printf("请输入课程查询(输入0返回上一级菜单):");
	scanf("%s", course);
	if (course[0] == '0') {
		system("cls");
		return;
	}
	if (strcmp(course, gaoshu) == 0 || strcmp(course, c) == 0 || strcmp(course, yingyu) == 0)
	//短路原则
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
		//动态数组录入链表信息
		while (Head_1->next != NULL) {
			for (int l = 0; l <= j;) {
				//判断班级,当班级名符合，将其相关i成绩计入
				if (strcmp(Head_1->next->banji, class1[l].banji) == 0) {
					class1[l].totalScore += Head_1->next->score[i];
					class1[l].numStudent++;
					Head_1 = Head_1->next;
					break;
					//统计完一个该班学生则退出本次for循环
				}
				//班级不符时，继续将其判断
				else {
					if (l == j) 
						//当班级数与j相等（第一次遇到该班级），将开辟新的班级,并计入该学生
					{
						strcpy(class1[j].banji, Head_1->next->banji);
						class1[j].totalScore = Head_1->next->score[i];
						class1[j].numStudent = 1;
						j++;
						Head_1 = Head_1->next;
						break;//统计完一个该班学生则退出本次for循环
					}
					//班级不同，将l++至班级相同
					else {
						l++;
					}
				}
			}
		}
		//统计后计算平均分
		for (int x = 0; x < j; x++) {
			class1[x].averScore = class1[x].totalScore / class1[x].numStudent;
		}
		//显示后将分配的内存释放
		switch (i) {
		case 0:
			printf("高数各班平均成绩如下：\n");
			for (int x = 0; x < j; x++) {
				printf("%s\t：%.2lf\n", class1[x].banji, class1[x].averScore);
			}
			free(class1);
			break;
		case 1:
			printf("C语言各班平均成绩如下：\n");
			for (int x = 0; x < j; x++) {
				printf("%s\t：%.2lf\n", class1[x].banji, class1[x].averScore);
			}
			free(class1);
			break;
		case 2:
			printf("英语各班平均成绩如下：\n");
			for (int x = 0; x < j; x++) {
				printf("%s\t：%.2lf\n", class1[x].banji, class1[x].averScore);
			}
			free(class1);
			break;
		}
	}
	//研究生的班级平均成绩统计
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
					break;//统计完一个该班学生则退出本次for循环
				}
				else {
					if (l == j)
						//当班级数与j相等（第一次遇到该班级），将开辟新的班级,并计入该学生
					{
						class2[j].Class = Head_2->next->Class;
						strcpy(class2[j].major, Head_2->next->major);
						class2[j].totalScore = Head_2->next->score[i];
						class2[j].numStudent = 1;
						j++;
						Head_2 = Head_2->next;
						break;//统计完一个该班学生则退出本次for循环
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
			printf("综合成绩各班平均成绩如下：\n");
			for (int x = 0; x < j; x++) {
				printf("%s专业%d班：%.2lf\n", class2[x].major, class2[x].Class, class2[x].averScore);
			}
			free(class2);
			break;
		case 1:
			printf("论文成绩各班平均成绩如下：\n");
			for (int x = 0; x < j; x++) {
				printf("%s专业%d班：%.2lf\n", class2[x].major, class2[x].Class, class2[x].averScore);
			}
			free(class2);
			break;
		}
	}
	else {
		printf("输入有误，请重新输入！\n");
		system("pause");
		system("cls");
		return;
	}
	printf("-----------------------------------------------------\n");
	printf("查询完毕，按任意键返回上级菜单！\n");
	system("pause");
	system("cls");
}



//求本科生具体班级的学生某科成绩情况，并排名显示
void countByClassScore_1(char* banji, char* course) {
	UND* Head_1 = Head1;//局部变量Head_1
	int i, k = 0;
	char gaoshu[10] = "高数";
	char c[10] = "C语言";
	char yingyu[10] = "英语";
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
		printf("输入错误，请重新输入！\n");
		printf("输入任意键继续\n");
		system("pause");
		system("cls");
		return;
	}
	printf("%s班级%s成绩分布如下：\n", banji, course);

	printf("不及格：");
	infoPrint_1();
	while (Head_1->next != NULL) {
		if (strcmp(Head_1->next->banji, banji) == 0)
		//对比班级名，将同班的同学的对应成绩分级
		{
			if (Head_1->next->score[i] < 60) {
				displayData_1(*Head_1->next);
				k++;
			}
		}
		Head_1 = Head_1->next;
	}
	if (k == 0) {
		printf("无\n");
	}
	else {
		k = 0;
	}
	printf("-----------------------------------------------------\n");
	printf("及格：");
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
		printf("无\n");
	}
	else {
		k = 0;
	}
	printf("-----------------------------------------------------\n");
	printf("中等：");
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
		printf("无\n");
	}
	else {
		k = 0;
	}
	printf("-----------------------------------------------------\n");
	printf("良好：");
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
		printf("无\n");
	}
	else {
		k = 0;
	}
	printf("-----------------------------------------------------\n");
	printf("优秀：");
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
		printf("无\n");
	}
	printf("-----------------------------------------------------\n");
	printf("查询完毕\n");
	system("pause");
	system("cls");
}


//求研究生具体班级的学生某科成绩情况，显示排名
void countByClassScore_2(char* major, char* course, int Class) {
	Gra* Head_2 = Head2;
	int k = 0, i;
	char zonghe[20] = "综合成绩";
	char lunwen[20] = "论文成绩";
	if (strcmp(course, zonghe) == 0) {
		i = 0;
	}
	else if (strcmp(course, lunwen) == 0) {
		i = 1;
	}
	else {
		printf("输入有误，请重新输入！\n");
		system("pause");
		system("cls");
		return;
	}
	printf("%s专业%d班%s成绩分布如下：\n", major, Class, course);
	printf("不及格：");
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
		printf("无\n");
	}
	else {
		k = 0;
	}
	printf("-----------------------------------------------------\n");
	printf("及格：");
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
		printf("无\n");
	}
	else {
		k = 0;
	}
	printf("-----------------------------------------------------\n");
	printf("中等：");
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
		printf("无\n");
	}
	else {
		k = 0;
	}
	printf("-----------------------------------------------------\n");
	printf("良好：");
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
		printf("无\n");
	}
	else {
		k = 0;
	}
	printf("-----------------------------------------------------\n");
	printf("优秀：");
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
		printf("无\n");
	}
	printf("-----------------------------------------------------\n");
	printf("查询完毕\n");
	system("pause");
	system("cls");
}



