#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <math.h>

//struct������֮��Ͳ�Ӧ�ö�Ԫ�ص��޸ģ�Ԫ�ص����������������͵ı仯�������ƫ�����ı仯
typedef struct AdTeacher {
	char name[64];
	int age;
	int p;
	char *pname2;
} AdTeacher;

int main254() {
	int i = 0;
	AdTeacher t1;
	AdTeacher *p = NULL;
	p = &t1;
	//p = p + 100;

	{
		//int offsize1 = (int)&(p->age);//age�ĵ�ַ=p+ageƫ����
		int offsize1= (int)&(p->age)-(int)p;//����age��ƫ����
		int offsize2 = (int)&(((AdTeacher*)0)->age);
		printf("offsized1:%d \n", offsize1);
		printf("offsized2:%d \n", offsize2);
	}

	printf("hello..../n");
	system("pause");
	return;
}