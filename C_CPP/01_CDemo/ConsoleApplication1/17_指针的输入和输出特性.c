#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

//ָ������� -> �����ú��������ڴ�
//ָ�������� -> �����ú��������ڴ�
//���ļ��е����λ��ĳ���
int getMem17(char **myp1, int *mylen1, char **myp2, int *mylen2) {
	char *tmp1 = NULL;
	char *tmp2 = NULL;
	tmp1 = (char *)malloc(100);
	if (tmp1 == NULL)
	{
		return -1;
	}
	strcpy(tmp1, "abcdefg");
	*mylen1 = strlen(tmp1);

	*myp1 = tmp1;//����޸�ʵ��p1��ֵ

	tmp2 = (char *)malloc(100);
	if (tmp2 == NULL)
	{
		return -1;
	}
	strcpy(tmp2, "12343423");
	*mylen2 = strlen(tmp2);

	*myp2 = tmp2;//����޸�ʵ��p1��ֵ

	return 0;
}

//��ʵ�θ�ֵ������ָ�룬���Ա���ʵ��һ��ָ��ĵ�ַ�����ͷŵ�ʵ��ָ����ڴ�ռ�󻹿����ͷ�ʵ��
int getMem_Free(char **myp) {
	if (myp == NULL)
	{
		return -1;
	}
	free(*myp);//�ͷ�ָ��������ڴ�ռ�
	*myp = NULL;//��ʵ���޸ĳ�NULL

	return 0;
}
//һ��ָ���ͷ�ʵ�Σ�ͨ��һ��ָ�룬ֻ�ܽ��ڴ�ռ�ĵ�ַͨ��ʵ�δ��ݸ��βΣ������βκ�ʵ��û���κ���ϵ��
int getMem_Free0(char *myp) {
	if (myp==NULL)
	{
		return -1;
	}
	free(myp);//�ͷ�ָ��ָ����ڴ�ռ�
	//myp == NULL;//�ͷŵ�����ջ�Ϸ�����β�ָ�룬����ʵ��ָ�벻�ᱻ�ͷš�

	return 0;
}

void main17()
{
	char *p1 = NULL;
	int len1 = 0;

	char *p2 = NULL;
	int len2 = 0;

	int ret = 0;
	ret = getMem17(&p1, &len1, &p2, &len2);
	printf("p1: %s\n", p1);
	printf("p2: %s\n", p2);

	/*getMem_Free(&p1);
	getMem_Free(&p2);*/

	getMem_Free0(p1);
	getMem_Free0(p2);

	printf("hello....\n");
	system("pause");
	return;
}