#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#define _SWAP(x,y,t) t=x,x=y,y=t;
typedef unsigned int uint;
#include <iostream>
#include <stdio.h>
//cout 조작자
#include <iomanip>
//파일 입출력
#include <fstream>
//stl
#include <string>
#include <list>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;
#include "step_01.h"
#include "step_02.h"


//함수와 클래스의 상관관계

//int GetEnhanArmor(Unit_call abc);
//Unit_call GetUnit_call();
//void main(int argc, char *argv[])
//{
//	Unit_call armmors(0);
//	armmors = GetUnit_call();//클래스 형을 반환
//	cout << GetEnhanArmor(armmors);//클래스 객체를 인자로 넣어줌
//
//
//}
//int GetEnhanArmor(Unit_call abc) {//클래스 갹채를 인자로 받는 함수의 예
//	return abc.GetDefaultArmor() * 2;
//}
//Unit_call GetUnit_call()
//{
//	int arrmor=0;
//	Unit_call temp(0);
//	cout << "아머 입력:";
//	cin >> arrmor;
//	temp.setArrmor(arrmor);
//	return temp;//클래스 형을 반환한다.
//}

//구조체배열을 이용한 성적 프로그램
/*
struct S_student {
	int no;
	int math;
};
S_student bestGrade(S_student *student);
void main()
{
	S_student student[10],temp;
	for (int i = 0; i < 10; i++) {
		student[i].no = i;
		student[i].math = 50 + i;
	}
	temp=bestGrade(student);
	cout << "best math score:" << temp.math << endl;
	cout << "student no:" << temp.no << endl;
}
S_student bestGrade(S_student *student)
{
	S_student Tempstudent=student[0];
	for (int i = 1; i < 10; i++)
	{
		if (Tempstudent.math < student[i].math) {
			Tempstudent.math = student[i].math;
			Tempstudent.no = student[i].no;
		}
	}
		return Tempstudent;
}
*/

//서로 다른형의 배열값을 가져오는 함수
//int형 숫자 char형 문자열 변수를 받을 수 있고 index값을 입력받아 index값의 해당번째 숫자나 문자를 리턴한다.
//생략시 첫번째문자를 리턴
/*
char Getitem(char *agStr, int agIndex = 1)
{
	return agStr[agIndex - 1];
}
int Getitem(int agValue, int agindex = 1)
{
	char buf[11];
	itoa(agValue, buf, 10);
	return Getitem(buf, agindex) - '0';
}
void main()
{
	int number = 1234567890;
	char *str = "abcdefghi";
	cout << "3번째:" << number << "=" << Getitem(number,3) << endl;
	cout << "5번째:" << str << "=" << Getitem(str, 5) << endl;
	cout << "1번째:" << str << "=" << Getitem(str) << endl;
}*/

void main()
{	
	USEfopen();
}