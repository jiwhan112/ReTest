#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#define _SWAP(x,y,t) t=x,x=y,y=t;
typedef unsigned int uint;
#include <iostream>
#include <stdio.h>
//cout ������
#include <iomanip>
//���� �����
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


//�Լ��� Ŭ������ �������

//int GetEnhanArmor(Unit_call abc);
//Unit_call GetUnit_call();
//void main(int argc, char *argv[])
//{
//	Unit_call armmors(0);
//	armmors = GetUnit_call();//Ŭ���� ���� ��ȯ
//	cout << GetEnhanArmor(armmors);//Ŭ���� ��ü�� ���ڷ� �־���
//
//
//}
//int GetEnhanArmor(Unit_call abc) {//Ŭ���� ��ä�� ���ڷ� �޴� �Լ��� ��
//	return abc.GetDefaultArmor() * 2;
//}
//Unit_call GetUnit_call()
//{
//	int arrmor=0;
//	Unit_call temp(0);
//	cout << "�Ƹ� �Է�:";
//	cin >> arrmor;
//	temp.setArrmor(arrmor);
//	return temp;//Ŭ���� ���� ��ȯ�Ѵ�.
//}

//����ü�迭�� �̿��� ���� ���α׷�
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

//���� �ٸ����� �迭���� �������� �Լ�
//int�� ���� char�� ���ڿ� ������ ���� �� �ְ� index���� �Է¹޾� index���� �ش��° ���ڳ� ���ڸ� �����Ѵ�.
//������ ù��°���ڸ� ����
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
	cout << "3��°:" << number << "=" << Getitem(number,3) << endl;
	cout << "5��°:" << str << "=" << Getitem(str, 5) << endl;
	cout << "1��°:" << str << "=" << Getitem(str) << endl;
}*/

void main()
{	
	USEfopen();
}