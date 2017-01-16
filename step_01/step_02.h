#pragma once
namespace University
{
	struct Student
	{
		int id;
		float grade;
	};
}
namespace Student
{
	struct Student
	{
		int id;
		float grade;
	};
}

int I = 100;
void USEnamespace()//각각다른 네임스페이스에서 정의한 구조체 확인
{
	University::Student a;//University 에서 정의한 Student
	Student::Student b;//Student에서 정의한 Student
	int I = 10;

	cout << I <<endl;//지역 접근
	cout << ::I << endl;//전역값에 접근
}

struct S_Rect 
{
	float width;
	float height;
};
void rect()//정사각형 예제
{
	S_Rect rect;
	cout << "가로길이를 입력하세요\n";
	cin >> rect.width;
	cout << "세로길이를 입력하세요\n";
	cin >> rect.height;
	cout << "이것은 정사각형이 " << (rect.width == rect.height ? "맞습니다\n" : "아닙니다\n");
	
}
int Factoral(int i)//팩토리얼 재귀예제
{
	if (i == 1)
		return 1;
	else
		return i *= Factoral(i - 1);
}
void hop()//n까지 홀수 더하는 함수
{
	int j = 0, sum = 0;
	cin >> j;
	for (int i = 0; i <= j; i++)
	{
		if (i % 2)
			sum += i;
		else continue;
	}
	cout << sum;
}
////////////////////////////////////////////////
				//상속 예제
////////////////////////////////////////////////
class NPC //NPC클래스
{
	int defence;
public :
	void SetDefense(int n)
	{
		defence = n;
	}
	int GetDefense()
	{
		return defence;
	}
};
class Grunt:public NPC {//NPC 클래스 상속됨
	int armor;
public:
	void SetArmor(int n)
	{
		armor = n;
	}
	int GetArmor() {
		return armor+GetDefense();//defense값을 가져옴 
	}
};
/*
//메인함수
Grunt unit;
Grunt *unit2 = new Grunt;
unit.SetArmor(10);
unit.SetDefense(20);
cout << unit.GetArmor()<<endl;

unit2->SetArmor(10);
unit2->SetDefense(20);
cout << unit2->GetArmor() << endl;
*/
////////////////////////////////////////////////
			//얕은 복사 깊은 복사
////////////////////////////////////////////////

//얕은 복사

/*
이유: 먼저 A를 생성하면 문자를 담을 str이라는 변수를 선언하고 그 변수를 위한 메모리 공간을 할당하였다.
그리고 default 복사생성자로 B를 생성하면서 이미 A가 만들어 놓은 메모리의 주소만을 참조하게끔 주소만 복사하기 때문에 이런일이 발생한것이다.
이를 얕은 복사라고 한다.
해결방법은 깊은 복사를 하는 것 이다.
*/
class Unit_short {
	char *str;
public:
	Unit_short() { cout << "생성자" << endl; str = NULL; }
	~Unit_short(){}
	Unit_short(char* agStr)
	{
		cout << "매개변수 생성자" << endl;
		int strLength = strlen(agStr);
		str = new char[strLength + 1];
		strcpy(str, agStr);

	}
	void setstr(char* agStr)
	{
		strcpy(str, agStr);
	}
	void show()
	{
		cout << str << endl;
	}
};
//메인함수

//Unit_short a("어쩌구저쩌구");
//Unit_short b = a;//b를 생성하는데 복사생성자가 사용되었다
//a.setstr("TEST2");
//a.show();
//b.show();

//둘다 TEST2가 된다.


//깊은 복사


/*
메모리를 따로 할당하여 치환이 일어나도 메모리를 공유하지 않도록 하였다. 
*/
class Unit_long {
	char *str;

public:
	Unit_long() { cout << "생성자" << endl; str = NULL; }
	~Unit_long() {if (str != NULL) { delete[] str; str = NULL; }}
	Unit_long(Unit_long& agUnit)//복사 생성자 정의
	{
		cout << "복사 생성자" << endl;
		str = new char[strlen(agUnit.str) + 1];//깊은 복사를 위해 메모리를 새로 할당
		strcpy(str, agUnit.str);//문자열 복사
	}
	Unit_long(char* agStr)
	{
		cout << "매개변수 생성자" << endl;
		int strLength = strlen(agStr);
		str = new char[strLength + 1];
		strcpy(str, agStr);

	}
	void setstr(char* agStr)
	{
		strcpy(str, agStr);
	}
	void show()
	{
		cout << str << endl;
	}

};

//Unit_long a("어쩌구저쩌구");
//Unit_long b = a;//b를 생성하는데 복사생성자가 사용되었다
//a.setstr("TEST2");
//a.show();
//b.show();


class Unit_call
{
	int defaultArmor;
public :
	Unit_call(int armor) { defaultArmor = armor; }
	int GetDefaultArmor() { return defaultArmor; }
	void setArrmor(int armmor) { defaultArmor = armmor; }

};
class Unit_friend
{
	int x, y;
public:
	Unit_friend(int i, int j) {
		x = i; y = j;
	}
	friend bool isSame(Unit_friend a)//프렌드함수를 사용해서 비공개 맴버변수인 x,y에 접근 했다.
	{
		if (a.x == a.y)return true;
		else return false;
	}
	
};

class Unit_this//this포인터
{
	int x, y;
public:
	Unit_this(int x, int y) {
		this->x = x; this->y = y;
	}
	~Unit_this(){}
	void show()
	{
		cout << x<<","<< y << endl;
	}
};
void my_swap_copy(int &x, int &y)//참조에 의한 인자 전달 복사된 x,y값이 아닌
							//main함수의 값을 서로 바꾼다.
{
	int t;
	t = x;
	x = y;
	y = t;
	//my_swap_copy(x, y);//사용법

}
void my_swap_point(int *x, int *y)//포인터에 의한 인자 전달 복사된 x,y값이 아닌
							//main함수의 값을 서로 바꾼다.
{
	int t;
	t = *x;
	*x = *y;
	*y = t;
	//my_swap_point(&x, &y);//사용법
}
void USErefandpoint()//참조와 포인터 혼용 최종정리
{
	int value = 100;
	int value2 = value;//이런대입은 서로 다른 저장소를 가진다
	int &ref1 = value;//이러한 대입은 같은 저장소를 가진다
	int *ref2 = &value;
	int **ref3 = &ref2;
	//정리
	//ref3->ref2->value->100
	//ref1->100
	//ref3->ref2->value->100
	cout << "Adress of value=" << &value << endl;
	cout << "Adress of value2=" << &value2 << endl;
	cout << "Adress of ref=" << &ref1 << endl;
	cout << "Adress of ref2=" << &ref2 << endl;
	cout << "value of ref2=" << ref2 << endl;

	cout << value << ',' << value2 << ',' << ref1 << ',' << *ref2 << endl;
	*ref3 = &value2;
	value2 = 200;
	//ref3->ref2->value->200
	cout << value << ',' << value2 << ',' << ref1 << ',' << *ref2 << endl;

}

#define MAX_LEN 255

class USEcopy {//복사 생성자
	char *pszName;
public:
	USEcopy()
	{
		pszName = new char[MAX_LEN];
		cout << "생성자\n";
	}
	~USEcopy()
	{
		if (!pszName) {//복사시 참조하는 메모리가 두개임으로 소멸자가 두번 생성되는 경우의 오류때문에 수정
			delete[] pszName;
			pszName = NULL;
		}
	}
	USEcopy(const USEcopy &unit)//복사 생성자
	{
		pszName = new char[MAX_LEN];
		strcpy(pszName, "Untitled");
		cout << "복사 생성자\n";
	}
	void print() {
		cout << pszName << endl;

	}
	void Set(char *pszIn)//이름을 저장한다
	{
		strcpy(pszName, pszIn);
	}

};
//main
/*
USEcopy copy;
copy.Set("Zerg");
copy.print();
USEcopy copy2 = copy;
copy2.print();*/

class Unit_operator {//연산자 예제
	int hp;
public:
	Unit_operator() :hp(0){}
	Unit_operator(int i) { hp = i; }
	int Gehp() { return hp; }
	Unit_operator operator+(Unit_operator right)
	{
		Unit_operator temp;
		if (right.hp > hp)
			temp.hp = right.hp;
		else temp.hp = hp;
		return temp;
	}
};
class Unit_friend_operator {//프렌드 함수를 이용한 연산자 예제
	int hp;
public:
	
	Unit_friend_operator(int i=0) { hp = i; }
	int Gehp() { return hp; }
	friend Unit_friend_operator operator+(Unit_friend_operator left,Unit_friend_operator right)
		//friend 함수는 this 포인터를 가지고 있지 않으므로 이항연산 할 경우 두개의 피연산자를 모두 전달 받아야한다.
		//friend 함수를 선언 즉 다른객체에서 이함수로 접근할 수 있다는 의미
	{
		Unit_friend_operator temp;
		temp.hp = left.hp + right.hp;
		cout << "left hp=" << left.hp << endl;
		cout << "right hp=" << right.hp << endl;
		cout << "reslut hp=" << temp.hp << endl;
		return temp;
	}
};
class Unit_equal_operator {//치환연산자를 이용한 연산자 중복
	char *psznName;
public:
	Unit_equal_operator()//매모리 확보
	{
		psznName = new char[100];
		cout << "생성자" << endl;
	}
	~Unit_equal_operator()
	{
		if (!psznName) {//소멸자를 두번 생성을 막으려고
			delete[] psznName;
			psznName = NULL;
		}
	}
	void print()
	{
		cout << psznName << endl;
	}
	void set(char *str)
	{
		strcpy(psznName, str);
	}
	Unit_equal_operator &operator=(Unit_equal_operator &right)//치환 연산자 중복수행
	{
		cout << "operator called" << endl;
		strcpy(psznName, right.psznName);
		return *this;
	}
	//spawn = Zerg;
};

class USEPrint_operator {//<<을 중복해서 따로 cout 에 추가함수가 없어도 "Student ID=" << stu.stuID;가 나오게 하는 예제
	int stuID;
public:
	USEPrint_operator(int agID):stuID(agID){}
	~USEPrint_operator() {}
	friend ostream& operator<<(ostream & os, USEPrint_operator& stu)
	{
		os << "Student ID=" << stu.stuID;
		return os;
	}
};


////////////////////////////////////////////////
		//c++ 입출력 함수 사용
/////////////////////////////////////////////////
void USE_cout_01()//cout의 포멧 입출력
{
	cout << 123.23 << "hello" << 100 << endl;
	cout.setf(ios::hex, ios::basefield);
	cout << 123.23 << "hello" << 100 << endl;
	cout.setf(ios::scientific, ios::basefield);
	cout << 123.23 << "hello" << 100 << endl;
	cout.setf(ios::uppercase, ios::basefield);
	cout << 123.23 << "hello" << 100 << endl;
}

void USE_cout_02() {//cout의 맴버 함수
	cout.width(10);//넓이 설정
	cout << "...test..." << endl;

	cout.fill('-');//너비보다 작은길이의 값이 출력되고 나머지는 -로 채운다
	cout.width(20);
	cout << "...test..." << endl;

	cout.setf(ios::left);//왼쪽정렬
	cout.width(20);
	cout << "...test..." << endl;

	cout.precision(10);//precision(p) p의 자리수 만큼 출력
	cout.width(20);
	cout << 3.14159265 << endl;

	cout.precision(5);
	cout.width(20);
	cout << 123.234567 << endl;
}
void USE_cout_03() {//cout의 조작자
	//endl	뉴라인(엔터) 문자를 출력하여 스트림을 비운다
	//ends	NULL 출력
	//flush	스트림을 비운다.
	//dec,hex,oct	10,16,8진수 출력
	//setbase(int base) base에 해당하는 진수로 출력
	//setw(int width)	너비를 width로 설정한다.
	//setposition(int pos)	pos에 해당하는 자리수로 설정한다.
	//setfill(char c)	C에 해당하는 문자로 빈자리를 채우도록 설정한다.
	cout << hex << 100 << endl;
	cout << oct << 100 << endl;
	std::cout<< setfill('-') << setw(10);//#include<iomanip> 를 해야됨
	cout << "hello" << endl;
}

class Unit_operator_cout_cin {//입출력 연산자 중복
	int x, y;
public:
	Unit_operator_cout_cin() { x = 0; y = 0; }
	Unit_operator_cout_cin(int x, int y) { this->x = x; this->y = y; }
	~Unit_operator_cout_cin(){}
	friend ostream &operator<<(ostream &stream, Unit_operator_cout_cin unit)
	{
		stream << unit.x << "," << unit.y << endl;
		return stream;
	}

	friend istream &operator>>(istream &stream, Unit_operator_cout_cin& unit)//&
	{
		cout << "enter xy: ";
		stream >> unit.x;
		stream >> unit.y;
		return stream;
	}

};
//main
/*
Unit_operator_cout_cin a(5, 5), b(4, 4),c;
cout << a << b;
cin >> c;
cout << c;
*/

ostream &mysetup(ostream &stream)//조작자 생성 조작자를 설정하여 사용할 수 있다
//main 
//cout << mysetup << 123.123456;
{
	stream.width(10);
	stream.precision(4);
	stream.fill('*');
	return stream;
}

//////////////////////////////////////////////////////
//c++ 파일 입출력 방식
//////////////////////////////////////////////////////

/*	기본 속성
	ios::in		읽기 가능한 형태로 파일을 연다.
	ios::out	쓰기 **
	ios::ate	파일을 열 때, File pointer(커서)의 위치를 끝부분으로 이동
	ios::app	쓸 때, 씉부분에 쓰게 한다.
	ios::trunc	파일의 내용을 지우고 연다
	ios::binary	파일을 이진모드로 연다
*/
void USE_ofstream()//파일 출력(쓰기)
{
	ofstream file1("log1.txt");
	file1 << "this is a log file 1.";
	file1.close();
}
void USE_ofstream_copy()//파일 복사
{
	ifstream file1;//읽기 전용
	ofstream file2;//쓰기 전용
	char data;
	file1.open("before.txt",ios::binary);
	file2.open("after.txt", ios::binary);

	while(file1.get(data))
	{
		file2.put(data);
	}
	file1.close();
	file2.close();
}
////////////////////////////////////////////////////////
//가상 함수
////////////////////////////////////////////////////////
class B_Unit {
protected:
	int m_x, m_y;
public:
	B_Unit(int x, int y)
	{
		m_x = x;
		m_y = y;
	}
	virtual void Move()
	{
		cout << "Executing Move" << endl;
	}
};
class Zergling :public B_Unit
{
public:
	Zergling(int x, int y) :B_Unit(x,y){}
	void Move()
	{
		cout << "저글링 움직임\n";
	}
};
class mutalisk :public B_Unit
{
public:
	mutalisk(int x, int y) :B_Unit(x, y) {}
	void Move()
	{
		cout << "뮤탈 움직임\n";
	}
};

//어떤 객체를 가르키냐의 따라서 값이 달라지는 것을 알 수 있다.
//main
/*
B_Unit *pUnit;
B_Unit BaseUnit(10, 10);
Zergling Unit1(1, 2);
mutalisk Unit2(2, 3);
pUnit = &BaseUnit;
pUnit->Move();

pUnit = &Unit1;
pUnit->Move();

pUnit = &Unit2;
pUnit->Move();
*/
/////////////////////////////////////////////////
/////////////////////////////////////////////////
////////////////////////////////////////////////

//가상 소멸자
class BaseClass
{
	char* m_className;//클래스명을 저장할 변수
public:
	BaseClass()//기본생성자
	{
		cout << "BaseClass is Create...\n";
		m_className = NULL;
	}
	virtual ~BaseClass()
		//자식 클래스에서 할당된 메모리가 해체되지 않고 베이스 클래스의 메모리만 해체되는 것을 방지하고자
		//소멸자를 가상함수로 넣는다 생성순서의 역순으로 소멸자를 호출시켜
		//자식클래스의 할당된 메모리도 반환받을 수 있게 된다.
	{
		cout << "BaseClass is destoryed...\n";
		if (m_className != NULL)//잘못된 메모리 접근을 막기 위함
			delete m_className;//메모리 해체
	}
	virtual void Useit()
	{
		m_className = new char[20];
		strcpy(m_className, "BaseClass");
		cout << "Class Name is=" << m_className<<endl;//호출여부 확인
	}
};

class UsingClass:public BaseClass{
	char* m_Alias;
public:
	UsingClass()
	{
		cout << "UsingClass is create...\n";//호출여부 확인
		m_Alias = NULL;
	}
	~UsingClass()
	{
		cout << "UsingClass is destoryed...\n";
		if (m_Alias != NULL)
			delete m_Alias;
	}
	void Useit()
	{
		BaseClass::Useit();//부모클래스의 함수를 호출
		//그 뒤에 재정의
		m_Alias = new char[10];//메모리누수 발생
		strcpy(m_Alias, "DELTA");
		cout << "Alias is" << m_Alias << endl;
	}
};
//main
/*
BaseClass *bc = new UsingClass();
bc->Useit();
delete bc
*/


//순수가상함수
//순수가상함수는 반드시 재정의를 해야한다.

class V_Unit {//순수가상함수 베이스
protected:
	int m_x, m_y;
public:
	V_Unit(int x,int y):m_x(x),m_y(y)
	{}
	virtual void Move() = 0;
};
class V_Zergling :public V_Unit
{
public:
	V_Zergling(int x, int y) :V_Unit(x, y) {};
	void Move()
	{
		cout << "Zergling is Moving to (" << m_x << "," << m_y << ")" << endl;
	}
};
class V_Mutalisk :public V_Unit
{
public:
	V_Mutalisk(int x, int y) :V_Unit(x, y) {};
	void Move()
	{
		cout << "Mutalisk is Moving to (" << m_x << "," << m_y << ")" << endl;
	}
};

/////////////////////////////////////////////////////////
//일반화(템플릿)
////////////////////////////////////////////////////////

//일반 함수
template <typename X>X generic_abs(X a)//절대값 구함
//사용 방식
//generic_abs(int a);
//generic_abs(float a);
{
	X ret;
	ret = a < 0 ? -a : a;
	cout << "절대값 :" << ret << endl;
	return ret;
}
template <typename T, typename Y>T avg(T a,Y b)//평균값 구함
{
	T ret;
	ret = (a+b)/2;
	cout << "평균값 :" << ret << endl;
	return ret;
}
//일반 클래스
template <class TYPE> class stack 
//선언 방식
//stack<int> stack1;
//stack<float> stack2;
{
	TYPE data[50];
	int nCount;
public:
	stack():nCount(0){}
	void add(TYPE in)
	{
		
		if (nCount == 50) { cout << "다 참" << endl; }
		data[nCount++] = in;
	}
	TYPE pop(void) {
		if (nCount <= 0)
		{
			cout << "empty" << endl;
			return data[0];
		}
		else return data[--nCount];
	}

	
};

//////////////////////////////////////////////////////////
//예외처리
//////////////////////////////////////////////////////////

class my_exception_01 {//예외 클래스1
public:
	void printout()
	{
		cout << "1번예외" << endl;
	}
};
class my_exception_02 {//예외 클래스2
public:
	void printout()
	{
		cout << "2번예외" << endl;
	}
};
void throw_ex(int a)//실행 함수
{
	if (a == 0)
		throw my_exception_01();//예외 보내기
	else if (a == 1)
		throw my_exception_02();
	else if(a==3)
		throw "?";//알수없는 에러
	else cout << a<<endl;//에러가 아닐때
}
void reciprocal(int a)//main에서 사용하는 최종 함수
{
	try
	{
		throw_ex(a);//이미 정의한 실행함수
	}
	catch (my_exception_01 e)//예외들
	{
		e.printout();
	}
	catch (my_exception_02 e)//예외들
	{
		e.printout();
	}
	catch (...)
	{
		cout << "그외의 에러입니다." << endl;
	}
}

//예외 중첩
void reciprocal_(int a)//위의 예제와 기본적으로 동일하다
//다만 try,catch를 중첩되게 수정했을 뿐이다.
{
	try
	{
		try
		{
			try 
			{
				throw_ex(a);
			}
			catch (my_exception_01 e)
			{
				e.printout();
			}
		}
		catch (my_exception_02 e)
		{
			e.printout();
		}
	}
	catch (...)
	{
		cout << "모르는 오류\n";
	}
}

/////////////////////////////////////////////////////////////////
//STL
/////////////////////////////////////////////////////////////////

void STL_string()
{
	string str1, str2,str3;
	str1 = "ABC";
	str2 = "DEF";
	str3 = str1 + str2;
	cout << str1.c_str() << "+" << str2.c_str() << "=" << str3.c_str() << endl;
}
void STL_list()
{
	list<string> stringlist;		//string 객체를 원소로 가지는 list 선언
	list<string>::iterator iter;	//list의 원소들을 참조하기 위한 iterator를 선언

	stringlist.push_back("푸시백_01");//삽입
	stringlist.push_back("푸시백_02");
	int i = 1;
	cout << "원래 리스트:" << endl;
	for (iter = stringlist.begin(); iter != stringlist.end(); iter++)
		cout << "[" <<i++<< "]" << (*iter).c_str() << endl;

	i = 1;
	stringlist.reverse();
	cout << "뒤집힌 리스트:" << endl;
	for (iter = stringlist.begin(); iter != stringlist.end(); iter++)
		cout << "[" << i++ << "]" << (*iter).c_str() << endl;
}

void STL_vector()
{
	vector<int> intVector;//선언
	vector<int>::iterator iter;//참조를 위한 선언

	intVector.push_back(1);
	intVector.push_back(4);

	intVector.insert(intVector.begin() + 1, 2);//1과 4사이에  2를 입력

	//iter로 접근
	for (iter = intVector.begin(); iter != intVector.end(); iter++)
		cout << " " << *iter;
	cout << endl;

	intVector[2] = 3;

	//vector.size()로 접근
	//배열을 참조하듯 index값을 이용한 임의적인 접근이 가능하다
	for (int i = 0; i < intVector.size(); i++)
		cout << " " << intVector[i];
	cout << endl;	
}

void STL_map()
{
	//map은 key와 value값이 하나의 쌍으로 저장된다.

	map<string, int> stringMap;		//string형 key와 int형 valueㄹ를 가지는 map을 선언한다.
	map<string, int>::iterator iter;//map에 접근하기 위한 iterator를 선언하다.

	typedef pair<string, int>STR_INT;//타입을 정의함

	stringMap.insert(STR_INT("one", 1));//삽입
	stringMap.insert(STR_INT("two", 2));

	for (iter = stringMap.begin(); iter != stringMap.end(); iter++)
		cout << "Key=" << (iter->first).c_str() << ",value=" << iter->second << endl;

	stringMap["three"] = 3;//string의 알파벳순으로 정렬된다

	for (iter = stringMap.begin(); iter != stringMap.end(); iter++)
		cout << "Key=" << (iter->first).c_str() << ",value=" << iter->second << endl;

	cout << "stringMap[three]=" << stringMap["three"] << endl;
	
}
void STL_stack_queue()//스택과 큐의 사용법
{
	std::stack<int> S1;
	queue<int> Q1;
	
	S1.push(1);
	S1.push(2);
	S1.push(3);

	Q1.push(1);
	Q1.push(2);
	Q1.push(3);

	while (Q1.size())
	{
		cout << Q1.front() << endl;
		Q1.pop();
	}

	while (S1.size())
	{
		cout << S1.top() << endl;
		S1.pop();
	}
}