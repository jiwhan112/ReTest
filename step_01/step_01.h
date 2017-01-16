#pragma once
//////////////////////////////////////////////////////////////////////
								//���ڿ�//
/////////////////////////////////////////////////////////////////////
int print(char *str);
int SerachA(char *ret);
void Gets();
char *My_strcpy(char*dest, const char*src);
//��������ϱ� (putchar)
int print(char *str)
{
	int len = 0;
	while (*str!=(char)NULL)
	{
		putchar(*str);
		str++;
		len++;
	}
	putchar('\r');
	putchar('\n');
	return len;
}

void Gets() //�����Է¹���(gets_s)
{

	char str[100];
	char *ret;

	ret = gets_s(str);

	if (ret != NULL)
	{
		cout << SerachA(ret) << endl;
	}
}

int SerachA(char *ret)//aã��
{

	int len = 0;
	while (*ret != NULL)
	{
		if (*ret++ == 'a')
			len++;
	}

	return len;
}

char *My_strcpy(char*dest, const char*src)//���ڿ� �����Լ�
{
	char *ret = dest;
	//����ó�� 
	//�����ϳ��� NULL�̸� 
	if (dest == (int)NULL && src == (int)NULL)
	{
		//dest�� NULL�� �ƴϸ�
		if (*dest != (int)NULL)
			//NULL�� ���������
			*dest = (int)NULL;
		//NULL�� ����
		return NULL;
	}

	//����
	do
	{
		*dest++ = *src;
		
	} 
	while (*src++ != (int)NULL);
	return ret;
}

//ù��° �Է��� ���ڿ��� �ι�° �Է��� ���ڿ��� ������ ���ϴ� �Լ�
void USE_strcmpi()
{
	char str1[100];//���ڿ�1
	char str2[100];//���ڿ�2
	cin >> str1>>str2;
	int i = _strcmpi(str1, str2);
	if (i == 0)
		cout << "O";
	else
		cout << "X";
}
#define TOKEN " "
void USEstrtok()//��ū " "�� ���� ���ڿ��� �����ڷ� �и��ϴ� �Լ�
{
	char str[100];
	char *token;
	puts("���ڿ��� �Է����� EnterŰ�� ġ����");
	cin.getline(str, strlen(str));

	token = strtok(str, TOKEN);

	while (token != NULL)
	{
		cout << token << endl;
		token = strtok(NULL, TOKEN);//�˻��� ������ġ���� Ž���ϱ� ���� NULL�� �־��ش�
	}
	//token = strpbrk(str, TOKEN);
	//while (token != NULL) 
	//{
	//	puts(token);
	//	token = strpbrk(str, TOKEN);
	//}
	
	
}

void USEstrset(char* a)//_strset���� �Է��� ���ڿ��� Ư�����ڷ� ���� ä���
{
	char str[100];

	puts("���ڿ� �Է�");
	do
	{
		cin.getline(str, strlen(str));
		if (strlen(str) == 0)break;

		strset(str,*a);
		puts(str);
	} while (1);
}


void USEstrnset(char* a,int b)//_strnset���� �Է��� ���ڿ��� Ư�����ڷ� �Ϻκ�ä��� 0~b���� a�� ä��
//a���ڿ� b�ڸ���
{
	char str[100];
	puts("���ڿ� �Է�");
	while (1)
	{
		cin.getline(str, strlen(str));
		if (strlen(str) == 0)break;

		strnset(str, *a,b);
		puts(str);
	} 
}

void USEstrupr()//�Է¹��� �ҹ��ڿ�� �빮�ڷ� �ٲ� ��
{
	char str[100];
	puts("���ڿ� �Է�");
	while (1)
	{
		cin.getline(str, strlen(str));
		if (strlen(str) == 0)break;
		strupr(str);
		cout << str;
	} 
}

void USEstrlwr()//�Է¹��� �빮�ڿ�� �ҹ��ڷ� �ٲ� ��
{
	char str[100];
	puts("���ڿ� �Է�");
	while (1)
	{
		cin.getline(str, strlen(str));
		if (strlen(str) == 0)break;
		strlwr(str);
		cout << str;
	} 
}
void USEstrrev()//�Է¹��ڿ��� ������
{
	char str[100];
	puts("���ڿ� �Է�");
	while (1)
	{
		cin.getline(str, strlen(str));
		if (strlen(str) == 0)break;
		strrev(str);
		cout << str;
	} 
}
void USEstrdup()//�޸��Ҵ���� ���ڿ��� �ߺ������Ѵ�.
{
	char str[100];
	char *pstr;

	puts("���ڿ� �Է�");
	while (1)
	{
		cin.getline(str, strlen(str));
		if (strlen(str) == 0)break;
		pstr=strdup(str);//�Ҵ��Ŵ
		cout << str << endl;
		cout << pstr << endl;

		free(pstr);//��ü
	}
}

void USEsprintf()//sprintf�� �ٷ� ������� �ʰ� ���ڿ� ���ۿ� �����ϰ� ������ѳ��´�.
{
	char *str="Korea";
	char buf[100];//�׶��׶� ����ϰų� ������ ����
	sprintf(buf, "aaaaaa\n");
	
	sprintf(buf, "bbbbbb\n");

	sprintf(buf, "cccccccccccccc\n");
	cout << buf;
	sprintf(buf, str);
	cout << buf;

}
void USEatoi(int n)//n���� ���ڷε� ���ڿ��� ������ ��ȯ�� �ջ��Ͽ� ����ϴ� ���α׷�
//atoi= int
//atol= long
//atof= double

{
	
	int total = 0;
	char str[100];

	for (int i = 1; i <= n; i++)
	{
		cout << i << "��° ���ڿ��� �Է�\n";
		cin >> str;
		total += atoi(str);//���� ���ڿ��� �����θ� �߷�����
	}
	cout << "������ :" << total;
}

void USEstrtol()//���ڿ� ��������
//strtol=long
//strtoul=unsigned long
{
	char *str = "1111111";
	char *stop;
	int radix;
	int value;

	radix = 2;//��������
	value = strtol(str, &stop, radix);

	cout << stop - str<<endl;
	cout << str <<"\n"<< value;
	//str�� ��ȯ�ȹ���
	//value�� ��ȯ�Ȱ�
}
void USEstrtod()//������ ���Ե� ���ڿ� �Ǽ���ȯ
{
	char *str = "1.2345E-10";
	char *stop;
	double value;

	value = strtod(str, &stop);
	cout << stop - str << endl << value;
}
//����->���ڿ� itoa,ltoa,ultoa
//�Ǽ�->���ڿ� fcvt,ecvt,gcvt

void USEisalpha()//���ڿ��� ���ĺ� �Ǵ��ϴ� �Լ�
//isalpha ���ĺ�
//isdigit ����
//isalnum ���ĺ�,����
//isupper �빮��
//islower �ҹ���
//isspace ���� �� �������� �˻�
{
	char *str = "cat1car2caw3";
	char buffer[100] = { 0, };//�Ǵ� ���ڿ� ����
	int cnt = 0;

	while (*str)
	{
		if (isalpha(*str))
		{
			buffer[cnt++] = *str;
		}
		str++;
	}
	puts(buffer);
}

void USEswap()//���ڿ����� �յ�2����Ʈ�� ��ȯ
{
	char str1[] = "1a2b3c4d5f6g";
	char str2[]="1a2b3c4d5f6g";
	cout << str1 << endl;

	swab(str1, str2, sizeof(str1) - 1);
	cout << str1 << endl;
	cout << str2 << endl;
}

//////////////////////////////////////////////////////////////////////
					//�޸�
/////////////////////////////////////////////////////////////////////
#define MEGA 1024 * 1024
struct M1
{
	int x;
	int y;
	char buf[30];
};
void USEnew()
{
	char *pmem;
	
	for (int i = 0; i < 10; i++)
	{
		pmem = new char[MEGA];
		if (pmem==NULL)
			cout << "�޸𸮳��Ҵ�\n";
		else
		{
			puts("�޸� 1MB �Ҵ�");
			delete pmem;
			puts("�޸� ��ü");

		}
	}

}

void USEmemcpy()
{
	M1 x1, x2;
	x1.x = 5; x1.y = 10;
	strcpy(x1.buf, "memoy copy");

	memcpy(&x2, &x1, sizeof(x1));
	//memcmp(x1, x2, sizeof(x1));//�޸� ��
	puts(x2.buf);

}
void USEmemmove()//memcpy�� ����ѱ�� �� ������
{
	char s1[20] = "1234567890";

	puts(s1);
	memmove(s1 + 4, s1 + 2, 5);
	puts(s1);

}
void USEmemset()//�޸�ä���
{
	char str[50]="���������� ����";
	puts(str);
	memset(str, (int)NULL, sizeof(str));
	memset(str, '*', sizeof(str) - 1);
	puts(str);
}

//////////////////////////////////////////////////////////////////////
					//������
/////////////////////////////////////////////////////////////////////
void change_X2(int *x2)//�����͸� ����ϸ� ���ο��� �������� �ٲ��� �� ����
{
	*x2 = 100;
}
void change_array(int x1[],int size)//�迭�� ���ʿ� �����Ͷ� *�� �����ʿ䰡 ������.
{
	for (int i = 0; i <size; i++)
		x1[i] = 5;
}
void print_one(char one[], char *one2)//�迭�� ���ڷ� �޴� ����� �ΰ���
{
	puts(one);
	puts(one2);
}
//////////////////////////////////////////////////////////////////////
					//����
/////////////////////////////////////////////////////////////////////

void USEfopen()//���ϻ���
{
	FILE *file;
	file = fopen("file.bin", "w");//������ w,������ r
	if (file == NULL)
	{
		perror("���� ���� ����");//����ó���� �߻��� ���� ǥ��
	}
	else
	{
		puts("���ϻ���");
		fclose(file);
	}
}
#define FPATH "I:\\file.txt"//������ġ
#define MPATH "I:\\test\\file.txt"

void USEfputs()//���ڿ� ����
//�Ѱ����ڴ� fputc
{
	FILE *file;
	file = fopen(FPATH, "w");
	if (file == NULL)
	{
		puts("������ ������ �� �����ϴ�.");
	}
	else
	{
		fputs("�̰��� ���̿�", file);
		fclose(file);
	}
}
void USEfgets()//���ڿ� �б�
//�Ѱ����ڴ� fgetc
{
	FILE *file;
	char Buffer[100];
	file = fopen(FPATH, "r");
	if (file == NULL)
	{
		puts("������ ������ �� �����ϴ�.");
	}
	else
	{
		fgets(Buffer,strlen(Buffer),file);
		cout << Buffer;
		fclose(file);
	}
}
void USEfprinf()//����ȭ�� ���ڿ� ����
{
	FILE *file;
	char *strnum_001 = "�Ϲ� ��Ʈ���Դϴ�.\n";
	char *strnum_002 = "�̹� ��Ʈ���Դϴ�.\n";

	file = fopen(FPATH, "w");
	if (file == NULL)
	{
		puts("������ ������ �� �����ϴ�.");
	}
	else
	{
		fprintf(file, strnum_001);
		fprintf(file, strnum_002);
		fclose(file);
	}
}
void USEfscanf()//����ȭ�� ���ڿ� �б�
{
	FILE *file;
	char strnum_001[100];
	char strnum_002[100];

	file = fopen(FPATH, "r");
	if (file == NULL)
	{
		puts("������ ������ �� �����ϴ�.");
	}
	else
	{
		fscanf(file, "%s %s",strnum_001, strnum_002);//space������ ����
		cout << strnum_001 << strnum_002;
		fclose(file);
	}
}
void USEfflush()//������ ���ۺ���
{
	FILE *file;
	file = fopen(FPATH, "w");
	if (file == NULL)
	{
		puts("������ ������ �� �����ϴ�.");
	}
	else
	{
		fputs("asd", file);
		fflush(file);
		fclose(file);
	}
}
void USEftell()//���� �������� ������ġ ���ϱ�
//fpos_t pos;//���庯��
//fgetpos(file,&pos);//�Լ�
{
	FILE *file;
	file = fopen(FPATH, "w");
	if (file == NULL)
	{
		puts("������ ������ �� �����ϴ�.");
	}
	else
	{
		cout << "���������� ��ġ :" << ftell(file) << endl;
		fputs("abcde", file);
		cout << "���������� ��ġ :" << ftell(file) << endl;
		fclose(file);
	}
}
void USEfseek()//���� �����͸� ó������ �̵��ϱ�1
{

	FILE *file;
	file = fopen(FPATH, "w");
	if (file == NULL)
	{
		puts("������ ������ �� �����ϴ�.");
	}
	else
	{
		cout << "���������� ��ġ :" << ftell(file) << endl;
		fputs("abcde", file);
		cout << "���������� ��ġ :" << ftell(file) << endl;
		fseek(file, 0L, SEEK_SET);
		//SEEK_SET,SEEK_CUR,SEEK_END
		cout << "���������� ��ġ :" << ftell(file) << endl;
		fclose(file);
	}
}
void USErewind()//���� �����͸� ó������ �̵��ϱ�2
{

	FILE *file;
	file = fopen(FPATH, "w");
	if (file == NULL)
	{
		puts("������ ������ �� �����ϴ�.");
	}
	else
	{
		cout << "���������� ��ġ :" << ftell(file) << endl;
		fputs("abcde", file);
		cout << "���������� ��ġ :" << ftell(file) << endl;
		rewind(file);
		cout << "���������� ��ġ :" << ftell(file) << endl;
		fclose(file);
	}
}

void USEfseekcur()//���� �����͸� ������ ��ġ�� �̵��ϱ�
{
	FILE *file;
	file = fopen(FPATH, "w");
	if (file == NULL)
	{
		puts("������ ������ �� �����ϴ�.");
	}
	else
	{
		cout << "���������� ��ġ :" << ftell(file) << endl;
		fputs("abcde", file);
		cout << "���������� ��ġ :" << ftell(file) << endl;
		fseek(file, -2L, SEEK_CUR);//������ġ���� -2
		//SEEK_SET,SEEK_CUR,SEEK_END
		fputs("abcde", file);
		cout << "���������� ��ġ :" << ftell(file) << endl;
		fclose(file);
	}
}

void USEfeof()//������ ���� �����ߴ��� �˻�
{
	FILE *file;
	char ch;
	file = fopen(FPATH, "r");
	if (file == NULL)
	{
		puts("������ ������ �� �����ϴ�.");
	}
	else
	{
		while (!feof(file))
		{
			ch = fgetc(file);
			if (ferror(file))//���Ͽ��� üũ
			{
				puts("���� �߻�");
			}
			
			cout << ch<<endl;
		}
		fclose(file);
	}
}

void USEtmpnam() //�ӽ� ���� �̸������
{
	char buffer[100];
	char *path;

	for (int i=0; i < 10; i++)
	{
		tmpnam(buffer);
		puts(buffer);
	}
	for (int i = 0; i < 10; i++)
	{
		path = _tempnam("","test");
		puts(path);
	}
}
#include<io.h>
#include<sys/stat.h>
void USE_access()
{
	char *path = FPATH;
	if (_access(path, 0) == 0)//��ȯ���� 0�� �ƴϸ� �������� ��
		//0:���� �� ���͸��� �����ϴ��� �˻��ϴ� ���
		//2:������ ���� ���� ������ �� �ִ��� �˻��ϴ� ���
		//4:������ �б� ���� ������ �� �ִ��� �˻��ϴ� ���
		//6:������ �б� �� ���� ���� ������ �� �ִ��� �˻��ϴ� ���
	{
		puts("��������");
	}
}
#define NPATH "K:\\file_1.txt"//������ġ
void USE_rename()//�̸�����
{
	char *oldname = FPATH;
	char *newname = NPATH;

	if (rename(oldname, newname) != 0)
	{
		perror("���濡��");
	}
	else
	{
		puts("����Ϸ�");
	}
}

void USE_chmod()//���� �Ӽ� �����ϱ�
{
	//_S_IREAD : �б� ����
	//_S_IWRITE : �Ϲ� ����
	char *file = FPATH;
	if (_chmod(file, _S_IREAD))
	{
		perror("���ϼӼ� ����");
	}
	else
	{
		puts("����");
	}
}
void USEremove()//����
{
	char *file = FPATH;
	if (remove(file))
	{
		perror("���ϻ��� ����");
	}
	else
	{
		puts("����");
	}
}


//////////////////////////////////////////////////////////////////////
						//���丮
/////////////////////////////////////////////////////////////////////
#include<direct.h>
void USE_mkdir()//���͸� ����
{
	char *path = "k:\\test";
	if (_mkdir(path) == -1)
	{
		perror("���͸� ���� ����");
	}
	else
		puts("�����Ϸ�");
}
void USE_rmdir()//���͸� ����
{
	char *path = "k:\\test";
	if (_rmdir(path) == -1)
	{
		perror("���͸� ���� ����");
	}
	else
		puts("�����Ϸ�");
}

void USE_getcwd()//���� �۾����� ���͸� ���ϱ�
//_getdrive ����̺� ���ϱ�
{
	char pathname[_MAX_PATH];
	_getcwd(pathname, _MAX_PATH);
	puts(pathname);
}

void USE_chdir()//���� �۾����� ���͸� �����ϱ�
//_chdrive ����̺� �����ϱ�
{
	char pathname[_MAX_PATH] = "k:\\";
	if (_chdir(pathname) == 0)//error=-1
	{

		_getcwd(pathname, _MAX_PATH);
		puts(pathname);
	}
}
//////////////////////////////////////////////////////////////////////
					//����
/////////////////////////////////////////////////////////////////////
#include<time.h>
void USE_math()//���� ���� �Լ�
{

	float i;
	i = sin(1);
	cout << "sin1="<<i<<endl;
	i = asin(0.5);
	cout << "asin0.5=" << i << endl;
	i = exp(1.0);
	cout << "exp(1.0)=" << i << endl;//�����Լ� ������
	i = log(2.0);
	cout << "log(2.0)=" << i << endl;//�α��Լ� �ڿ� �αװ�
	i = log10(2.0);
	cout << "log10(2.0)=" << i << endl;//�α�10�Լ� �ڿ� �αװ�
	i = sqrt(4);
	cout << "sqrt(4)=" << i << endl;//������ ���ϱ�
	//���밪�� abs
	//�־��� ������ �������� �ּ� ������ ���ϱ� (ceil)
	//�־��� ������ ũ������ �ִ��� ������ ���ϱ� (floor)
	//�־��� ���� ������ �Ҽ� ���� (modf)
	//x�� y�� ���ϱ� (pow)
	srand((unsigned)time(NULL));
	i = rand()%500+1500;//1500~1999
	cout <<"���� :"<< i << endl;
}
//////////////////////////////////////////////////////////////////////
					//���빮��
/////////////////////////////////////////////////////////////////////
void triangle()//�ﰢ�� 
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << '*';
		}
		cout << endl;
	}
}

void USEbit_1()//��Ʈ������ ����� �ҹ��ڸ� �빮�ڷ� ����� 
			   //&���
{
	char str[] = "abcdefghijklmnopqrstuvwxyz";
	char str2[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


	puts(str);

	for (int i = 0; i < strlen(str); i++)
	{
		str[i] = str[i] & 0xDF;//0xDF�� 2�ܼ��� 1101 1111
		
		//�ҹ��� a�� 0110 0001
		//�빮�� A�� 0100 0001
		//���� 3��° ��Ʈ�� ����Ʈ���ָ� �빮�� A�� ��ȯ�˴ϴ�.
		//0x20�� |���ָ� �빮��->�ҹ��ڷ� �ٲ�
	}

	puts(str);
}

void USEbit_2()//�ΰ��� ���� �������� XOR����� 0���� ����
{
	int i = -44;
	cout << i << endl;
	i = i^i;
	cout << i << endl;

}
void USEbit_3()
{
	int value = 2;
	int shift1 = value << 1;//2*2
	int shift2 = value >> 1;//2/2
	cout << value<<endl;
	cout << shift1 << endl;
	cout << shift2 << endl;

}

void USEfputs_one()//�ؽ�Ʈ ������ ���پ� ����
{
	FILE *file;
	file = fopen(FPATH, "w");//������ w,������ r
	if (file == NULL)
	{
		perror("���� ���� ����");//����ó���� �߻��� ���� ǥ��
	}
	else
	{
		fputs("���ѹα�\n", file);
		fputs("���ѹα�\n", file);
		fputs("���ѹα�\n", file);
		fputs("���ѹα�\n", file);
		fputs("���ѹα�\n", file);
		fclose(file);
	}
}

void USEfgets_one()//�ؽ�Ʈ ������ ���پ� �б�
{
	FILE *file;
	char buf[100];
	file = fopen(FPATH, "r");//������ w,������ r
	if (file == NULL)
	{
		perror("���� ���� ����");//����ó���� �߻��� ���� ǥ��
	}
	else
	{
		while (!feof(file))
		{
			fgets(buf, 100, file);
			if (feof(file))break;
			cout << buf;
		}
		fclose(file);
	}
}
void USEfwrite()//�ؽ�Ʈ ���� ����
{
	FILE *file;
	char *str = "�츮����\n";
	file = fopen(FPATH, "w");//������ w,������ r
	if (file == NULL)
	{
		perror("���� ���� ����");//����ó���� �߻��� ���� ǥ��
	}
	else
	{
		fwrite(str, 1, strlen(str), file);
		fwrite(str, 1, strlen(str), file);
		fwrite(str, 1, strlen(str), file);
		fclose(file);
	}
}
void USEfread()//�ؽ�Ʈ ���� �б�
{
	FILE *file;
	char buf[100] = { 0, };
	int len;
	file = fopen(FPATH, "r");//������ w,������ r
	if (file == NULL)
	{
		perror("���� ���� ����");//����ó���� �߻��� ���� ǥ��
	}
	else
	{
		while (!feof(file))
		{
			 fread(buf, 1, 100, file);
			// if (ferror(file)||len<9)break;
			 cout << buf;
		}
		fclose(file);
	}
}

void USEfwrite_wb()//���� ���� ����
{
	FILE *file;
	char buf[5];
	file = fopen(FPATH, "wb");//���������� wb,rb

	buf[0] = '@';
	buf[1] = 0;
	buf[2] = 0x01;
	buf[3] = 0x03;
	buf[4] = 0x61;

	if (file != NULL)
	{
		fwrite(buf, 1, 5, file);
		fclose(file);
	}
	

}
void USEfread_rb()//���� ���� ����
{
	FILE *file;
	char buf;
	file = fopen(FPATH, "rb");//���������� wb,rb

	{
		while (!feof(file))
		{
			fread(&buf, 1, 1, file);
			if (!feof(file))
				cout << buf;
		}
	}
}
void USE_filemove()//�����̵�
{
	if (rename(FPATH, MPATH) != 0)
	{
		perror("�����̵�����");
	}
	else
	{
		puts("�̵�����");
	}
}

#define SECRETKEY "!@#$%^&*()_+=-"
void MessageSecret()//�޽��� ��ȣȭ �� ��ȣȭ
{
	char str[] = "1234567890";
	puts(str);

	for (int i = 0; i < strlen(str); i++)
	{
		str[i] ^= SECRETKEY[i];
	}
	puts(str);

	for (int i = 0; i < strlen(str); i++)
	{
		str[i] ^= SECRETKEY[i];
	}
	puts(str);
}


int encryption(char *filename)//���� ��ȣȭ
{
	char data[1024];
	char secret[16] = { "!@#$%^&*()_><,." };
	FILE *fp;
	unsigned int read_size, i;
	long frpos, fwpos;

	fp = fopen(filename, "r+b");

	if (fp == NULL)
	{
		perror("���� ���� ����");
		return -1;
	}

	while (!feof(fp))
	{
		fwpos = ftell(fp);
		read_size = fread(data, 1, 1024, fp);

		if (read_size == 0) break;

		for (i = 0; i<read_size; i++)
		{
			data[i] ^= secret[i % 16];
		}

		frpos = ftell(fp);

		fseek(fp, fwpos, SEEK_SET);
		fwrite(data, 1, read_size, fp);

		fseek(fp, frpos, SEEK_SET);
	}

	fclose(fp);

	return 1;
}
