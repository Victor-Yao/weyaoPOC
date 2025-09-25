#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "cfg_op.h"

#define CFGNAME "c:/VDownload/myConfig.ini"

void mymenu() {
	printf("========================\n");
	printf("1:����д�����ļ�\n");
	printf("2:���Զ������ļ�\n");
	printf("0:�˳�\n");
	printf("========================\n");
}

int TGetCfg() {
	char key[1024] = { 0 };
	char value[1024] = { 0 };
	int len = 0;

	printf("\n�����key:");
	scanf("%s", key);

	int ret = GetCfgItem(CFGNAME/*in*/, key/*in*/, value/*in*/, &len/*out*/);
	if (ret != 0)
	{
		printf("func GetCfgItem() err\n");
		return ret;
	}

	printf("value =%s\n", value);
	printf("value length=%d\n", len);
	return ret;
}

int TWriteCfg() {
	char key[1024] = { 0 };
	char value[1024] = { 0 };

	printf("\n�����key:");
	scanf("%s", key);
	printf("\n�����value:");
	scanf("%s", value);

	int ret = WriteCfgItem(CFGNAME/*in*/, key/*in*/, value/*in*/, strlen(value)/*out*/);
	if (ret != 0)
	{
		printf("func WriteCfgItem() err\n");
	}

	printf("���������: %s = %s\n", key, value);
	return ret;
}

void main() {
	int choice;

	for (;;)
	{
		//��ʾһ���˵�
		mymenu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1://д�����ļ�
			TWriteCfg();
			break;
		case 2://�������ļ�
			TGetCfg();
			break;
		case 0:
			exit(0);
			break;
		default:
			exit(0);
			break;
		}
	}

}