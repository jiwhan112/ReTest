#pragma once
//////////////////////////////////////////////////////////////////////
								//문자열//
/////////////////////////////////////////////////////////////////////
int print(char *str);
int SerachA(char *ret);
void Gets();
char *My_strcpy(char*dest, const char*src);
//문자출력하기 (putchar)
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

void Gets() //문자입력받음(gets_s)
{

	char str[100];
	char *ret;

	ret = gets_s(str);

	if (ret != NULL)
	{
		cout << SerachA(ret) << endl;
	}
}

int SerachA(char *ret)//a찾음
{

	int len = 0;
	while (*ret != NULL)
	{
		if (*ret++ == 'a')
			len++;
	}

	return len;
}

char *My_strcpy(char*dest, const char*src)//문자열 복사함수
{
	char *ret = dest;
	//예외처리 
	//둘중하나가 NULL이면 
	if (dest == (int)NULL && src == (int)NULL)
	{
		//dest가 NULL이 아니면
		if (*dest != (int)NULL)
			//NULL을 집어넣은다
			*dest = (int)NULL;
		//NULL을 리턴
		return NULL;
	}

	//복사
	do
	{
		*dest++ = *src;
		
	} 
	while (*src++ != (int)NULL);
	return ret;
}

//첫번째 입력한 문자열과 두번째 입력한 문자열을 같은지 비교하는 함수
void USE_strcmpi()
{
	char str1[100];//문자열1
	char str2[100];//문자열2
	cin >> str1>>str2;
	int i = _strcmpi(str1, str2);
	if (i == 0)
		cout << "O";
	else
		cout << "X";
}
#define TOKEN " "
void USEstrtok()//토큰 " "에 따라 문자열을 구분자로 분리하는 함수
{
	char str[100];
	char *token;
	puts("문자열을 입력한후 Enter키를 치세요");
	cin.getline(str, strlen(str));

	token = strtok(str, TOKEN);

	while (token != NULL)
	{
		cout << token << endl;
		token = strtok(NULL, TOKEN);//검색한 다음위치보터 탐색하기 위해 NULL을 넣어준다
	}
	//token = strpbrk(str, TOKEN);
	//while (token != NULL) 
	//{
	//	puts(token);
	//	token = strpbrk(str, TOKEN);
	//}
	
	
}

void USEstrset(char* a)//_strset으로 입력한 문자열을 특정문자로 전부 채우기
{
	char str[100];

	puts("문자열 입력");
	do
	{
		cin.getline(str, strlen(str));
		if (strlen(str) == 0)break;

		strset(str,*a);
		puts(str);
	} while (1);
}


void USEstrnset(char* a,int b)//_strnset으로 입력한 문자열을 특정문자로 일부분채우기 0~b까지 a를 채움
//a문자열 b자리수
{
	char str[100];
	puts("문자열 입력");
	while (1)
	{
		cin.getline(str, strlen(str));
		if (strlen(str) == 0)break;

		strnset(str, *a,b);
		puts(str);
	} 
}

void USEstrupr()//입력받은 소문자영어를 대문자로 바꿔 줌
{
	char str[100];
	puts("문자열 입력");
	while (1)
	{
		cin.getline(str, strlen(str));
		if (strlen(str) == 0)break;
		strupr(str);
		cout << str;
	} 
}

void USEstrlwr()//입력받은 대문자영어를 소문자로 바꿔 줌
{
	char str[100];
	puts("문자열 입력");
	while (1)
	{
		cin.getline(str, strlen(str));
		if (strlen(str) == 0)break;
		strlwr(str);
		cout << str;
	} 
}
void USEstrrev()//입력문자열을 뒤집음
{
	char str[100];
	puts("문자열 입력");
	while (1)
	{
		cin.getline(str, strlen(str));
		if (strlen(str) == 0)break;
		strrev(str);
		cout << str;
	} 
}
void USEstrdup()//메모리할당시켜 문자열을 중복생성한다.
{
	char str[100];
	char *pstr;

	puts("문자열 입력");
	while (1)
	{
		cin.getline(str, strlen(str));
		if (strlen(str) == 0)break;
		pstr=strdup(str);//할당시킴
		cout << str << endl;
		cout << pstr << endl;

		free(pstr);//해체
	}
}

void USEsprintf()//sprintf는 바로 출력하지 않고 문자열 버퍼에 생성하고 저장시켜놓는다.
{
	char *str="Korea";
	char buf[100];//그때그때 출력하거나 저장할 버퍼
	sprintf(buf, "aaaaaa\n");
	
	sprintf(buf, "bbbbbb\n");

	sprintf(buf, "cccccccccccccc\n");
	cout << buf;
	sprintf(buf, str);
	cout << buf;

}
void USEatoi(int n)//n개의 숫자로된 문자열을 정수로 변환해 합산하여 출력하는 프로그램
//atoi= int
//atol= long
//atof= double

{
	
	int total = 0;
	char str[100];

	for (int i = 1; i <= n; i++)
	{
		cout << i << "번째 문자열을 입력\n";
		cin >> str;
		total += atoi(str);//받은 문자열을 정수로만 추려낸다
	}
	cout << "총합은 :" << total;
}

void USEstrtol()//문자열 진수변경
//strtol=long
//strtoul=unsigned long
{
	char *str = "1111111";
	char *stop;
	int radix;
	int value;

	radix = 2;//진수설정
	value = strtol(str, &stop, radix);

	cout << stop - str<<endl;
	cout << str <<"\n"<< value;
	//str은 변환된문자
	//value는 변환된값
}
void USEstrtod()//지수가 포함된 문자열 실수전환
{
	char *str = "1.2345E-10";
	char *stop;
	double value;

	value = strtod(str, &stop);
	cout << stop - str << endl << value;
}
//정수->문자열 itoa,ltoa,ultoa
//실수->문자열 fcvt,ecvt,gcvt

void USEisalpha()//문자여에 알파벳 판단하는 함수
//isalpha 알파벳
//isdigit 숫자
//isalnum 알파벳,숫자
//isupper 대문자
//islower 소문자
//isspace 공백 탭 개행인지 검사
{
	char *str = "cat1car2caw3";
	char buffer[100] = { 0, };//판단 문자열 저장
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

void USEswap()//문자열에서 앞뒤2바이트씩 교환
{
	char str1[] = "1a2b3c4d5f6g";
	char str2[]="1a2b3c4d5f6g";
	cout << str1 << endl;

	swab(str1, str2, sizeof(str1) - 1);
	cout << str1 << endl;
	cout << str2 << endl;
}

//////////////////////////////////////////////////////////////////////
					//메모리
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
			cout << "메모리노할당\n";
		else
		{
			puts("메모리 1MB 할당");
			delete pmem;
			puts("메모리 해체");

		}
	}

}

void USEmemcpy()
{
	M1 x1, x2;
	x1.x = 5; x1.y = 10;
	strcpy(x1.buf, "memoy copy");

	memcpy(&x2, &x1, sizeof(x1));
	//memcmp(x1, x2, sizeof(x1));//메모리 비교
	puts(x2.buf);

}
void USEmemmove()//memcpy와 비슷한기능 더 안전함
{
	char s1[20] = "1234567890";

	puts(s1);
	memmove(s1 + 4, s1 + 2, 5);
	puts(s1);

}
void USEmemset()//메모리채우기
{
	char str[50]="공지사항은 없다";
	puts(str);
	memset(str, (int)NULL, sizeof(str));
	memset(str, '*', sizeof(str) - 1);
	puts(str);
}

//////////////////////////////////////////////////////////////////////
					//포인터
/////////////////////////////////////////////////////////////////////
void change_X2(int *x2)//포인터를 사용하면 메인에서 실제값을 바꿔줄 수 있음
{
	*x2 = 100;
}
void change_array(int x1[],int size)//배열은 애초에 포인터라서 *를 쓸ㄴ필요가 업었다.
{
	for (int i = 0; i <size; i++)
		x1[i] = 5;
}
void print_one(char one[], char *one2)//배열을 인자로 받는 방법은 두가지
{
	puts(one);
	puts(one2);
}
//////////////////////////////////////////////////////////////////////
					//파일
/////////////////////////////////////////////////////////////////////

void USEfopen()//파일생성
{
	FILE *file;
	file = fopen("file.bin", "w");//생성은 w,읽을땐 r
	if (file == NULL)
	{
		perror("파일 개방 에러");//파일처리시 발생된 에러 표시
	}
	else
	{
		puts("파일생성");
		fclose(file);
	}
}
#define FPATH "I:\\file.txt"//파일위치
#define MPATH "I:\\test\\file.txt"

void USEfputs()//문자열 쓰기
//한개문자는 fputc
{
	FILE *file;
	file = fopen(FPATH, "w");
	if (file == NULL)
	{
		puts("파일을 생성할 수 없습니다.");
	}
	else
	{
		fputs("이것은 말이여", file);
		fclose(file);
	}
}
void USEfgets()//문자열 읽기
//한개문자는 fgetc
{
	FILE *file;
	char Buffer[100];
	file = fopen(FPATH, "r");
	if (file == NULL)
	{
		puts("파일을 생성할 수 없습니다.");
	}
	else
	{
		fgets(Buffer,strlen(Buffer),file);
		cout << Buffer;
		fclose(file);
	}
}
void USEfprinf()//형식화된 문자열 쓰기
{
	FILE *file;
	char *strnum_001 = "일번 스트링입니다.\n";
	char *strnum_002 = "이번 스트링입니다.\n";

	file = fopen(FPATH, "w");
	if (file == NULL)
	{
		puts("파일을 생성할 수 없습니다.");
	}
	else
	{
		fprintf(file, strnum_001);
		fprintf(file, strnum_002);
		fclose(file);
	}
}
void USEfscanf()//형식화된 문자열 읽기
{
	FILE *file;
	char strnum_001[100];
	char strnum_002[100];

	file = fopen(FPATH, "r");
	if (file == NULL)
	{
		puts("파일을 생성할 수 없습니다.");
	}
	else
	{
		fscanf(file, "%s %s",strnum_001, strnum_002);//space던위로 읽음
		cout << strnum_001 << strnum_002;
		fclose(file);
	}
}
void USEfflush()//파일의 버퍼비우기
{
	FILE *file;
	file = fopen(FPATH, "w");
	if (file == NULL)
	{
		puts("파일을 생성할 수 없습니다.");
	}
	else
	{
		fputs("asd", file);
		fflush(file);
		fclose(file);
	}
}
void USEftell()//파일 포인터의 현재위치 구하기
//fpos_t pos;//저장변수
//fgetpos(file,&pos);//함수
{
	FILE *file;
	file = fopen(FPATH, "w");
	if (file == NULL)
	{
		puts("파일을 생성할 수 없습니다.");
	}
	else
	{
		cout << "파일포인터 위치 :" << ftell(file) << endl;
		fputs("abcde", file);
		cout << "파일포인터 위치 :" << ftell(file) << endl;
		fclose(file);
	}
}
void USEfseek()//파일 포인터를 처음으로 이동하기1
{

	FILE *file;
	file = fopen(FPATH, "w");
	if (file == NULL)
	{
		puts("파일을 생성할 수 없습니다.");
	}
	else
	{
		cout << "파일포인터 위치 :" << ftell(file) << endl;
		fputs("abcde", file);
		cout << "파일포인터 위치 :" << ftell(file) << endl;
		fseek(file, 0L, SEEK_SET);
		//SEEK_SET,SEEK_CUR,SEEK_END
		cout << "파일포인터 위치 :" << ftell(file) << endl;
		fclose(file);
	}
}
void USErewind()//파일 포인터를 처음으로 이동하기2
{

	FILE *file;
	file = fopen(FPATH, "w");
	if (file == NULL)
	{
		puts("파일을 생성할 수 없습니다.");
	}
	else
	{
		cout << "파일포인터 위치 :" << ftell(file) << endl;
		fputs("abcde", file);
		cout << "파일포인터 위치 :" << ftell(file) << endl;
		rewind(file);
		cout << "파일포인터 위치 :" << ftell(file) << endl;
		fclose(file);
	}
}

void USEfseekcur()//파일 포인터를 임의의 위치로 이동하기
{
	FILE *file;
	file = fopen(FPATH, "w");
	if (file == NULL)
	{
		puts("파일을 생성할 수 없습니다.");
	}
	else
	{
		cout << "파일포인터 위치 :" << ftell(file) << endl;
		fputs("abcde", file);
		cout << "파일포인터 위치 :" << ftell(file) << endl;
		fseek(file, -2L, SEEK_CUR);//현재위치에서 -2
		//SEEK_SET,SEEK_CUR,SEEK_END
		fputs("abcde", file);
		cout << "파일포인터 위치 :" << ftell(file) << endl;
		fclose(file);
	}
}

void USEfeof()//파일의 끝에 도달했는지 검사
{
	FILE *file;
	char ch;
	file = fopen(FPATH, "r");
	if (file == NULL)
	{
		puts("파일을 생성할 수 없습니다.");
	}
	else
	{
		while (!feof(file))
		{
			ch = fgetc(file);
			if (ferror(file))//파일에러 체크
			{
				puts("에러 발생");
			}
			
			cout << ch<<endl;
		}
		fclose(file);
	}
}

void USEtmpnam() //임시 파일 이름만들기
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
	if (_access(path, 0) == 0)//반환값이 0이 아니면 파일존재 무
		//0:파일 및 디렉터리가 존재하는지 검사하는 경우
		//2:파일을 쓰기 위해 개방할 수 있는지 검사하는 경우
		//4:파일을 읽기 위해 개방할 수 있는지 검사하는 경우
		//6:파일을 읽기 및 쓰기 위해 개방할 수 있는지 검사하는 경우
	{
		puts("파일존재");
	}
}
#define NPATH "K:\\file_1.txt"//파일위치
void USE_rename()//이름변경
{
	char *oldname = FPATH;
	char *newname = NPATH;

	if (rename(oldname, newname) != 0)
	{
		perror("변경에러");
	}
	else
	{
		puts("변경완료");
	}
}

void USE_chmod()//파일 속성 변경하기
{
	//_S_IREAD : 읽기 전용
	//_S_IWRITE : 일반 파일
	char *file = FPATH;
	if (_chmod(file, _S_IREAD))
	{
		perror("파일속성 에러");
	}
	else
	{
		puts("성공");
	}
}
void USEremove()//삭제
{
	char *file = FPATH;
	if (remove(file))
	{
		perror("파일삭제 에러");
	}
	else
	{
		puts("성공");
	}
}


//////////////////////////////////////////////////////////////////////
						//디렉토리
/////////////////////////////////////////////////////////////////////
#include<direct.h>
void USE_mkdir()//디렉터리 생성
{
	char *path = "k:\\test";
	if (_mkdir(path) == -1)
	{
		perror("디렉터리 생성 에러");
	}
	else
		puts("생성완료");
}
void USE_rmdir()//디렉터리 삭제
{
	char *path = "k:\\test";
	if (_rmdir(path) == -1)
	{
		perror("디렉터리 생성 에러");
	}
	else
		puts("삭제완료");
}

void USE_getcwd()//현재 작업중인 디렉터리 구하기
//_getdrive 드라이브 구하기
{
	char pathname[_MAX_PATH];
	_getcwd(pathname, _MAX_PATH);
	puts(pathname);
}

void USE_chdir()//현재 작업중인 디렉터리 변경하기
//_chdrive 드라이브 변경하기
{
	char pathname[_MAX_PATH] = "k:\\";
	if (_chdir(pathname) == 0)//error=-1
	{

		_getcwd(pathname, _MAX_PATH);
		puts(pathname);
	}
}
//////////////////////////////////////////////////////////////////////
					//수학
/////////////////////////////////////////////////////////////////////
#include<time.h>
void USE_math()//여러 수학 함수
{

	float i;
	i = sin(1);
	cout << "sin1="<<i<<endl;
	i = asin(0.5);
	cout << "asin0.5=" << i << endl;
	i = exp(1.0);
	cout << "exp(1.0)=" << i << endl;//지수함수 지수값
	i = log(2.0);
	cout << "log(2.0)=" << i << endl;//로그함수 자연 로그값
	i = log10(2.0);
	cout << "log10(2.0)=" << i << endl;//로그10함수 자연 로그값
	i = sqrt(4);
	cout << "sqrt(4)=" << i << endl;//제곱근 구하기
	//절대값은 abs
	//주어진 값보다 작지않은 최소 정수값 구하기 (ceil)
	//주어진 값보다 크지않은 최대의 정수값 구하기 (floor)
	//주어진 값의 정수와 소수 구분 (modf)
	//x의 y승 구하기 (pow)
	srand((unsigned)time(NULL));
	i = rand()%500+1500;//1500~1999
	cout <<"난수 :"<< i << endl;
}
//////////////////////////////////////////////////////////////////////
					//응용문제
/////////////////////////////////////////////////////////////////////
void triangle()//삼각형 
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

void USEbit_1()//비트연산을 사용해 소문자를 대문자로 만들기 
			   //&사용
{
	char str[] = "abcdefghijklmnopqrstuvwxyz";
	char str2[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


	puts(str);

	for (int i = 0; i < strlen(str); i++)
	{
		str[i] = str[i] & 0xDF;//0xDF는 2잔수로 1101 1111
		
		//소문자 a는 0110 0001
		//대문자 A는 0100 0001
		//따라서 3번째 비트를 마스트해주면 대문자 A로 변환됩니다.
		//0x20은 |해주면 대문자->소문자로 바뀜
	}

	puts(str);
}

void USEbit_2()//두개는 서로 같음으로 XOR연산시 0으로 수렴
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

void USEfputs_one()//텍스트 파일을 한줄씩 쓰기
{
	FILE *file;
	file = fopen(FPATH, "w");//생성은 w,읽을땐 r
	if (file == NULL)
	{
		perror("파일 개방 에러");//파일처리시 발생된 에러 표시
	}
	else
	{
		fputs("대한민국\n", file);
		fputs("대한민국\n", file);
		fputs("대한민국\n", file);
		fputs("대한민국\n", file);
		fputs("대한민국\n", file);
		fclose(file);
	}
}

void USEfgets_one()//텍스트 파일을 한줄씩 읽기
{
	FILE *file;
	char buf[100];
	file = fopen(FPATH, "r");//생성은 w,읽을땐 r
	if (file == NULL)
	{
		perror("파일 개방 에러");//파일처리시 발생된 에러 표시
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
void USEfwrite()//텍스트 파일 쓰기
{
	FILE *file;
	char *str = "우리강산\n";
	file = fopen(FPATH, "w");//생성은 w,읽을땐 r
	if (file == NULL)
	{
		perror("파일 개방 에러");//파일처리시 발생된 에러 표시
	}
	else
	{
		fwrite(str, 1, strlen(str), file);
		fwrite(str, 1, strlen(str), file);
		fwrite(str, 1, strlen(str), file);
		fclose(file);
	}
}
void USEfread()//텍스트 파일 읽기
{
	FILE *file;
	char buf[100] = { 0, };
	int len;
	file = fopen(FPATH, "r");//생성은 w,읽을땐 r
	if (file == NULL)
	{
		perror("파일 개방 에러");//파일처리시 발생된 에러 표시
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

void USEfwrite_wb()//이진 파일 쓰기
{
	FILE *file;
	char buf[5];
	file = fopen(FPATH, "wb");//이진파일은 wb,rb

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
void USEfread_rb()//이진 파일 쓰기
{
	FILE *file;
	char buf;
	file = fopen(FPATH, "rb");//이진파일은 wb,rb

	{
		while (!feof(file))
		{
			fread(&buf, 1, 1, file);
			if (!feof(file))
				cout << buf;
		}
	}
}
void USE_filemove()//파일이동
{
	if (rename(FPATH, MPATH) != 0)
	{
		perror("파일이동에러");
	}
	else
	{
		puts("이동성공");
	}
}

#define SECRETKEY "!@#$%^&*()_+=-"
void MessageSecret()//메시지 암호화 및 복호화
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


int encryption(char *filename)//파일 암호화
{
	char data[1024];
	char secret[16] = { "!@#$%^&*()_><,." };
	FILE *fp;
	unsigned int read_size, i;
	long frpos, fwpos;

	fp = fopen(filename, "r+b");

	if (fp == NULL)
	{
		perror("파일 개방 에러");
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
