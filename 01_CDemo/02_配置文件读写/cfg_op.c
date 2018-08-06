#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

#define MaxLine 2048

int GetCfgItem(char *pFileName/*in*/, char *pKey/*in*/, char *pValue/*in*/, int *pValueLen/*out*/) {
	int		ret = 0;
	if (pFileName == NULL)
	{
		ret = -1;
		printf("Func GetCfgItem errr: pFileName is NULL\n");
		goto End;
	}

	FILE	*fp = NULL;
	char	*pTmp = NULL;
	char	*pkeyTmp = NULL;

	char lineBuf[MaxLine];

	fp = fopen(pFileName, "r");
	if (fp == NULL)
	{
		printf("Func GetCfgItem errr: fopen err\n");
		ret = -1;
		goto End;
	}

	while (!feof(fp))
	{
		memset(lineBuf, 0, sizeof(lineBuf));
		fgets(lineBuf, MaxLine, fp);

		pTmp = strchr(lineBuf, '=');//�ж� = 
		if (pTmp == NULL)
		{
			continue;
		}

		pTmp = strstr(lineBuf, pKey);//�ж� ���Ƿ���� 
		if (pTmp == NULL)
		{
			continue;
		}
		pTmp = pTmp + strlen(pKey);

		pTmp = strchr(pTmp, '=');//��λ��=�����Ƶ�����
		if (pTmp == NULL)
		{
			continue;
		}
		pTmp = pTmp + 1;

		ret = trimStr(&pTmp);
		if (ret != 0)
		{
			goto End;
		}
		strcpy(pValue, pTmp);
		*pValueLen = strlen(pTmp);
	}

End:
	if (fp != NULL)
	{
		fclose(fp);
	}
	return ret;
}

//д������
//ʵ������
//ѭ����ÿһ�У����key�������Ƿ���ڣ��������޸Ķ�Ӧvalueֵ���������ڣ��ļ�ĩβ��� "key = value"
//�ѵ㣺����޸��ļ����е�ֵ
int WriteCfgItem(char *pFileName/*in*/, char *pKey/*in*/, char *pValue/*in*/, int itemValueLen/*out*/) {
	int		ret = 0, iTag = 0, length = 0;
	FILE	*fp = NULL;
	char	lineBuf[MaxLine];
	char	*pTmp = NULL, *pBegin = NULL, *pEnd = NULL;
	char	filebuf[1024 * 8] = { 0 };

	if (pFileName == NULL || pKey == NULL || pValue == NULL)
	{
		ret = -1;
		printf("Func SetCfgItem() err: param err \n");
		goto End;
	}

	fp = fopen(pFileName, "r+");
	if (fp == NULL)
	{
		fp = fopen(pFileName, "w+t");
		if (fp == NULL)
		{
			ret = -2;
			printf("fopen() err\n");
			goto End;
		}
	}

	fseek(fp, 0L, SEEK_END);//���ļ�ָ���0λ�ÿ�ʼ���ƶ����ļ�ĩβ
	//��ȡ�ļ�����
	length = ftell(fp);

	fseek(fp, 0, SEEK_SET);

	if (length > 1024 * 8)
	{
		ret = -3;
		printf("�ļ�����1024*8, unsupport\n");
		goto End;
	}

	while (!feof(fp))
	{
		//��ÿһ��
		memset(lineBuf, 0, sizeof(lineBuf));
		pTmp = fgets(lineBuf, MaxLine, fp);
		if (pTmp == NULL)
		{
			break;
		}
		//key�ؼ����Ƿ��ڱ���
		pTmp = strstr(lineBuf, pKey);
		if (pTmp == NULL)//������ڣ�ֱ��copy��filebuf��
		{
			strcat(filebuf, lineBuf);
			continue;
		}
		else
		{
			sprintf(lineBuf, "%s=%s\n", pKey, pValue);
			strcat(filebuf, lineBuf);
			//������key
			iTag = 1;
		}
	}
	if (iTag == 0)//key�����ڣ����ļ���׷��
	{
		fprintf(fp, "%s = %s\n", pKey, pValue);//��򿪵��ļ���׷������
	}
	else//��key�ؼ��ִ��ڣ������´����ļ�
	{
		if (fp!=NULL)
		{
			fclose(fp);
			fp = NULL;
		}
		fp = fopen(pFileName, "w+t");//��'w'���Ѵ��ڵ��ļ�д��ͻ����ԭ�е��ļ�����
		if (fp==NULL)
		{
			ret = -4;
			printf("fopen() err. \n");
			goto End;
		}
		fputs(filebuf, fp);
	}

End:
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
	return 0;
}


int trimStr(char **buffer) {
	if (buffer == NULL)
	{
		printf("func trimStr");
		return -1;
	}

	char *tmp = *buffer;
	char *pBegin = NULL, *pEnd = NULL;
	while (1)
	{
		if (*tmp == ' ')
		{
			tmp++;
		}
		else
		{
			break;
		}
	}
	pBegin = tmp;

	while (1)
	{
		if ((*tmp == ' ' || *tmp == '\n'))
		{
			break;
		}
		else
		{
			tmp++;
		}
	}
	pEnd = tmp;
	char pValue[1024] = { 0 };
	memcpy(pValue, pBegin, pEnd - pBegin);
	*buffer = pValue;

	return 0;
}