#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <math.h>

//����ṹ������
struct Teacher1 {//����1
	char name[64];
	int age;
	int id;
};

typedef struct Teacher {//����2
	char name[64];
	int age;
	int id;
} Teacher;

//����ṹ�������3�ַ�����
struct Student {
	char name[64];
	int age;
	int id;
} s1, s2 = { "demo",12,001 };//���ͺͱ���ͬʱ����

struct {
	char name[64];
	int age;
	int id;
} s3, s4 = { "demo",12,001 };

//��ʼ��������3�ַ���
void main251() {
	struct Teacher1 t = { "demo",12,001 };
	Teacher s;
	s.age = 31;//s.Ѱַ����������age�����s��ƫ���� ---> ������CPU�н��У�û�в����ڴ�
	{
		Teacher *p = NULL;
		p = &t;
		printf("p->age:%d \n", p->age);//->, Ѱַ��������.��ͬ��Ҳ����cpu�н���
		printf("p->name:%s \n", p->name);
	}

	system("pause");
	return;
}

void copyTeacher(Teacher *to, Teacher *from) {
	*to = *from;
}
void printfTeacherArray(Teacher *t, int num) {
	for (int i = 0; i < num; i++)
	{
		printf("age:%d\n", t[i].age);
	}
}
void sortTeacherArray(Teacher *myArray, int num) {
	int i = 0, j = 0;
	Teacher tmp;
	for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (myArray[i].age > myArray[j].age)
			{
				tmp = myArray[j];
				myArray[j] = myArray[i];
				myArray[i] = tmp;
			}
		}
	}
}

Teacher *createTeacherArr(int num) {
	Teacher *tmp = NULL;
	tmp = (Teacher *)malloc(sizeof(Teacher)*num);//Teacher Array[3]
	if (tmp == NULL)
		return;
}
int *createTeacherArr01(Teacher **p, int num) {
	Teacher *tmp = NULL;
	tmp = (Teacher *)malloc(sizeof(Teacher)*num);//Teacher Array[3]
	if (tmp == NULL)
	{
		return -1;
	}

	*p = tmp;
	return 0;
}

void freeTeacherArr(Teacher *p) {
	if (p != NULL)
	{
		free(p);
	}
}
void freeTeacherArr01(Teacher **p) {
	if (*p != NULL)
	{
		free(*p);
		p == NULL;
	}
}

void main252() {
	Teacher t1 = { "aaaa",32,02 };
	Teacher t2;
	Teacher t3;

	//t2 = t1; //=�Ų������ɱ�����ʵ�ֵļ򵥸�ֵ����
	//printf("t2.name:%s \n", t2.name);
	//printf("t2.age:%d \n", t2.age);

	//copyTeacher(&t3, &t1);

	//printf("t2.name:%s \n", t2.name);
	//printf("t3.name:%s \n", t3.name);
	//printf("t3.age:%d \n", t3.age);

	int ret = 0;
	Teacher *pArray = NULL;
	//Teacher* pArray = createTeacherArr(3);
	ret = createTeacherArr01(&pArray, 3);
	int length = 3;
	for (int i = 0; i < length; i++)
	{
		printf("\n enter the teacher age:");
		scanf("%d", &(pArray[i].age));
	}
	printfTeacherArray(pArray, length);
	sortTeacherArray(pArray, length);
	printf("����֮��\n");
	printfTeacherArray(pArray, length);
	//freeTeacherArr(pArray);
	freeTeacherArr01(&pArray);
	pArray = NULL;

	system("pause");
	return;
}