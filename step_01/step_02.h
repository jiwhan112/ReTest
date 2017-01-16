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
void USEnamespace()//�����ٸ� ���ӽ����̽����� ������ ����ü Ȯ��
{
	University::Student a;//University ���� ������ Student
	Student::Student b;//Student���� ������ Student
	int I = 10;

	cout << I <<endl;//���� ����
	cout << ::I << endl;//�������� ����
}

struct S_Rect 
{
	float width;
	float height;
};
void rect()//���簢�� ����
{
	S_Rect rect;
	cout << "���α��̸� �Է��ϼ���\n";
	cin >> rect.width;
	cout << "���α��̸� �Է��ϼ���\n";
	cin >> rect.height;
	cout << "�̰��� ���簢���� " << (rect.width == rect.height ? "�½��ϴ�\n" : "�ƴմϴ�\n");
	
}
int Factoral(int i)//���丮�� ��Ϳ���
{
	if (i == 1)
		return 1;
	else
		return i *= Factoral(i - 1);
}
void hop()//n���� Ȧ�� ���ϴ� �Լ�
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
				//��� ����
////////////////////////////////////////////////
class NPC //NPCŬ����
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
class Grunt:public NPC {//NPC Ŭ���� ��ӵ�
	int armor;
public:
	void SetArmor(int n)
	{
		armor = n;
	}
	int GetArmor() {
		return armor+GetDefense();//defense���� ������ 
	}
};
/*
//�����Լ�
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
			//���� ���� ���� ����
////////////////////////////////////////////////

//���� ����

/*
����: ���� A�� �����ϸ� ���ڸ� ���� str�̶�� ������ �����ϰ� �� ������ ���� �޸� ������ �Ҵ��Ͽ���.
�׸��� default ��������ڷ� B�� �����ϸ鼭 �̹� A�� ����� ���� �޸��� �ּҸ��� �����ϰԲ� �ּҸ� �����ϱ� ������ �̷����� �߻��Ѱ��̴�.
�̸� ���� ������ �Ѵ�.
�ذ����� ���� ���縦 �ϴ� �� �̴�.
*/
class Unit_short {
	char *str;
public:
	Unit_short() { cout << "������" << endl; str = NULL; }
	~Unit_short(){}
	Unit_short(char* agStr)
	{
		cout << "�Ű����� ������" << endl;
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
//�����Լ�

//Unit_short a("��¼����¼��");
//Unit_short b = a;//b�� �����ϴµ� ��������ڰ� ���Ǿ���
//a.setstr("TEST2");
//a.show();
//b.show();

//�Ѵ� TEST2�� �ȴ�.


//���� ����


/*
�޸𸮸� ���� �Ҵ��Ͽ� ġȯ�� �Ͼ�� �޸𸮸� �������� �ʵ��� �Ͽ���. 
*/
class Unit_long {
	char *str;

public:
	Unit_long() { cout << "������" << endl; str = NULL; }
	~Unit_long() {if (str != NULL) { delete[] str; str = NULL; }}
	Unit_long(Unit_long& agUnit)//���� ������ ����
	{
		cout << "���� ������" << endl;
		str = new char[strlen(agUnit.str) + 1];//���� ���縦 ���� �޸𸮸� ���� �Ҵ�
		strcpy(str, agUnit.str);//���ڿ� ����
	}
	Unit_long(char* agStr)
	{
		cout << "�Ű����� ������" << endl;
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

//Unit_long a("��¼����¼��");
//Unit_long b = a;//b�� �����ϴµ� ��������ڰ� ���Ǿ���
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
	friend bool isSame(Unit_friend a)//�������Լ��� ����ؼ� ����� �ɹ������� x,y�� ���� �ߴ�.
	{
		if (a.x == a.y)return true;
		else return false;
	}
	
};

class Unit_this//this������
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
void my_swap_copy(int &x, int &y)//������ ���� ���� ���� ����� x,y���� �ƴ�
							//main�Լ��� ���� ���� �ٲ۴�.
{
	int t;
	t = x;
	x = y;
	y = t;
	//my_swap_copy(x, y);//����

}
void my_swap_point(int *x, int *y)//�����Ϳ� ���� ���� ���� ����� x,y���� �ƴ�
							//main�Լ��� ���� ���� �ٲ۴�.
{
	int t;
	t = *x;
	*x = *y;
	*y = t;
	//my_swap_point(&x, &y);//����
}
void USErefandpoint()//������ ������ ȥ�� ��������
{
	int value = 100;
	int value2 = value;//�̷������� ���� �ٸ� ����Ҹ� ������
	int &ref1 = value;//�̷��� ������ ���� ����Ҹ� ������
	int *ref2 = &value;
	int **ref3 = &ref2;
	//����
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

class USEcopy {//���� ������
	char *pszName;
public:
	USEcopy()
	{
		pszName = new char[MAX_LEN];
		cout << "������\n";
	}
	~USEcopy()
	{
		if (!pszName) {//����� �����ϴ� �޸𸮰� �ΰ������� �Ҹ��ڰ� �ι� �����Ǵ� ����� ���������� ����
			delete[] pszName;
			pszName = NULL;
		}
	}
	USEcopy(const USEcopy &unit)//���� ������
	{
		pszName = new char[MAX_LEN];
		strcpy(pszName, "Untitled");
		cout << "���� ������\n";
	}
	void print() {
		cout << pszName << endl;

	}
	void Set(char *pszIn)//�̸��� �����Ѵ�
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

class Unit_operator {//������ ����
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
class Unit_friend_operator {//������ �Լ��� �̿��� ������ ����
	int hp;
public:
	
	Unit_friend_operator(int i=0) { hp = i; }
	int Gehp() { return hp; }
	friend Unit_friend_operator operator+(Unit_friend_operator left,Unit_friend_operator right)
		//friend �Լ��� this �����͸� ������ ���� �����Ƿ� ���׿��� �� ��� �ΰ��� �ǿ����ڸ� ��� ���� �޾ƾ��Ѵ�.
		//friend �Լ��� ���� �� �ٸ���ü���� ���Լ��� ������ �� �ִٴ� �ǹ�
	{
		Unit_friend_operator temp;
		temp.hp = left.hp + right.hp;
		cout << "left hp=" << left.hp << endl;
		cout << "right hp=" << right.hp << endl;
		cout << "reslut hp=" << temp.hp << endl;
		return temp;
	}
};
class Unit_equal_operator {//ġȯ�����ڸ� �̿��� ������ �ߺ�
	char *psznName;
public:
	Unit_equal_operator()//�Ÿ� Ȯ��
	{
		psznName = new char[100];
		cout << "������" << endl;
	}
	~Unit_equal_operator()
	{
		if (!psznName) {//�Ҹ��ڸ� �ι� ������ ��������
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
	Unit_equal_operator &operator=(Unit_equal_operator &right)//ġȯ ������ �ߺ�����
	{
		cout << "operator called" << endl;
		strcpy(psznName, right.psznName);
		return *this;
	}
	//spawn = Zerg;
};

class USEPrint_operator {//<<�� �ߺ��ؼ� ���� cout �� �߰��Լ��� ��� "Student ID=" << stu.stuID;�� ������ �ϴ� ����
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
		//c++ ����� �Լ� ���
/////////////////////////////////////////////////
void USE_cout_01()//cout�� ���� �����
{
	cout << 123.23 << "hello" << 100 << endl;
	cout.setf(ios::hex, ios::basefield);
	cout << 123.23 << "hello" << 100 << endl;
	cout.setf(ios::scientific, ios::basefield);
	cout << 123.23 << "hello" << 100 << endl;
	cout.setf(ios::uppercase, ios::basefield);
	cout << 123.23 << "hello" << 100 << endl;
}

void USE_cout_02() {//cout�� �ɹ� �Լ�
	cout.width(10);//���� ����
	cout << "...test..." << endl;

	cout.fill('-');//�ʺ񺸴� ���������� ���� ��µǰ� �������� -�� ä���
	cout.width(20);
	cout << "...test..." << endl;

	cout.setf(ios::left);//��������
	cout.width(20);
	cout << "...test..." << endl;

	cout.precision(10);//precision(p) p�� �ڸ��� ��ŭ ���
	cout.width(20);
	cout << 3.14159265 << endl;

	cout.precision(5);
	cout.width(20);
	cout << 123.234567 << endl;
}
void USE_cout_03() {//cout�� ������
	//endl	������(����) ���ڸ� ����Ͽ� ��Ʈ���� ����
	//ends	NULL ���
	//flush	��Ʈ���� ����.
	//dec,hex,oct	10,16,8���� ���
	//setbase(int base) base�� �ش��ϴ� ������ ���
	//setw(int width)	�ʺ� width�� �����Ѵ�.
	//setposition(int pos)	pos�� �ش��ϴ� �ڸ����� �����Ѵ�.
	//setfill(char c)	C�� �ش��ϴ� ���ڷ� ���ڸ��� ä�쵵�� �����Ѵ�.
	cout << hex << 100 << endl;
	cout << oct << 100 << endl;
	std::cout<< setfill('-') << setw(10);//#include<iomanip> �� �ؾߵ�
	cout << "hello" << endl;
}

class Unit_operator_cout_cin {//����� ������ �ߺ�
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

ostream &mysetup(ostream &stream)//������ ���� �����ڸ� �����Ͽ� ����� �� �ִ�
//main 
//cout << mysetup << 123.123456;
{
	stream.width(10);
	stream.precision(4);
	stream.fill('*');
	return stream;
}

//////////////////////////////////////////////////////
//c++ ���� ����� ���
//////////////////////////////////////////////////////

/*	�⺻ �Ӽ�
	ios::in		�б� ������ ���·� ������ ����.
	ios::out	���� **
	ios::ate	������ �� ��, File pointer(Ŀ��)�� ��ġ�� ���κ����� �̵�
	ios::app	�� ��, ���κп� ���� �Ѵ�.
	ios::trunc	������ ������ ����� ����
	ios::binary	������ �������� ����
*/
void USE_ofstream()//���� ���(����)
{
	ofstream file1("log1.txt");
	file1 << "this is a log file 1.";
	file1.close();
}
void USE_ofstream_copy()//���� ����
{
	ifstream file1;//�б� ����
	ofstream file2;//���� ����
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
//���� �Լ�
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
		cout << "���۸� ������\n";
	}
};
class mutalisk :public B_Unit
{
public:
	mutalisk(int x, int y) :B_Unit(x, y) {}
	void Move()
	{
		cout << "��Ż ������\n";
	}
};

//� ��ü�� ����Ű���� ���� ���� �޶����� ���� �� �� �ִ�.
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

//���� �Ҹ���
class BaseClass
{
	char* m_className;//Ŭ�������� ������ ����
public:
	BaseClass()//�⺻������
	{
		cout << "BaseClass is Create...\n";
		m_className = NULL;
	}
	virtual ~BaseClass()
		//�ڽ� Ŭ�������� �Ҵ�� �޸𸮰� ��ü���� �ʰ� ���̽� Ŭ������ �޸𸮸� ��ü�Ǵ� ���� �����ϰ���
		//�Ҹ��ڸ� �����Լ��� �ִ´� ���������� �������� �Ҹ��ڸ� ȣ�����
		//�ڽ�Ŭ������ �Ҵ�� �޸𸮵� ��ȯ���� �� �ְ� �ȴ�.
	{
		cout << "BaseClass is destoryed...\n";
		if (m_className != NULL)//�߸��� �޸� ������ ���� ����
			delete m_className;//�޸� ��ü
	}
	virtual void Useit()
	{
		m_className = new char[20];
		strcpy(m_className, "BaseClass");
		cout << "Class Name is=" << m_className<<endl;//ȣ�⿩�� Ȯ��
	}
};

class UsingClass:public BaseClass{
	char* m_Alias;
public:
	UsingClass()
	{
		cout << "UsingClass is create...\n";//ȣ�⿩�� Ȯ��
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
		BaseClass::Useit();//�θ�Ŭ������ �Լ��� ȣ��
		//�� �ڿ� ������
		m_Alias = new char[10];//�޸𸮴��� �߻�
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


//���������Լ�
//���������Լ��� �ݵ�� �����Ǹ� �ؾ��Ѵ�.

class V_Unit {//���������Լ� ���̽�
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
//�Ϲ�ȭ(���ø�)
////////////////////////////////////////////////////////

//�Ϲ� �Լ�
template <typename X>X generic_abs(X a)//���밪 ����
//��� ���
//generic_abs(int a);
//generic_abs(float a);
{
	X ret;
	ret = a < 0 ? -a : a;
	cout << "���밪 :" << ret << endl;
	return ret;
}
template <typename T, typename Y>T avg(T a,Y b)//��հ� ����
{
	T ret;
	ret = (a+b)/2;
	cout << "��հ� :" << ret << endl;
	return ret;
}
//�Ϲ� Ŭ����
template <class TYPE> class stack 
//���� ���
//stack<int> stack1;
//stack<float> stack2;
{
	TYPE data[50];
	int nCount;
public:
	stack():nCount(0){}
	void add(TYPE in)
	{
		
		if (nCount == 50) { cout << "�� ��" << endl; }
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
//����ó��
//////////////////////////////////////////////////////////

class my_exception_01 {//���� Ŭ����1
public:
	void printout()
	{
		cout << "1������" << endl;
	}
};
class my_exception_02 {//���� Ŭ����2
public:
	void printout()
	{
		cout << "2������" << endl;
	}
};
void throw_ex(int a)//���� �Լ�
{
	if (a == 0)
		throw my_exception_01();//���� ������
	else if (a == 1)
		throw my_exception_02();
	else if(a==3)
		throw "?";//�˼����� ����
	else cout << a<<endl;//������ �ƴҶ�
}
void reciprocal(int a)//main���� ����ϴ� ���� �Լ�
{
	try
	{
		throw_ex(a);//�̹� ������ �����Լ�
	}
	catch (my_exception_01 e)//���ܵ�
	{
		e.printout();
	}
	catch (my_exception_02 e)//���ܵ�
	{
		e.printout();
	}
	catch (...)
	{
		cout << "�׿��� �����Դϴ�." << endl;
	}
}

//���� ��ø
void reciprocal_(int a)//���� ������ �⺻������ �����ϴ�
//�ٸ� try,catch�� ��ø�ǰ� �������� ���̴�.
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
		cout << "�𸣴� ����\n";
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
	list<string> stringlist;		//string ��ü�� ���ҷ� ������ list ����
	list<string>::iterator iter;	//list�� ���ҵ��� �����ϱ� ���� iterator�� ����

	stringlist.push_back("Ǫ�ù�_01");//����
	stringlist.push_back("Ǫ�ù�_02");
	int i = 1;
	cout << "���� ����Ʈ:" << endl;
	for (iter = stringlist.begin(); iter != stringlist.end(); iter++)
		cout << "[" <<i++<< "]" << (*iter).c_str() << endl;

	i = 1;
	stringlist.reverse();
	cout << "������ ����Ʈ:" << endl;
	for (iter = stringlist.begin(); iter != stringlist.end(); iter++)
		cout << "[" << i++ << "]" << (*iter).c_str() << endl;
}

void STL_vector()
{
	vector<int> intVector;//����
	vector<int>::iterator iter;//������ ���� ����

	intVector.push_back(1);
	intVector.push_back(4);

	intVector.insert(intVector.begin() + 1, 2);//1�� 4���̿�  2�� �Է�

	//iter�� ����
	for (iter = intVector.begin(); iter != intVector.end(); iter++)
		cout << " " << *iter;
	cout << endl;

	intVector[2] = 3;

	//vector.size()�� ����
	//�迭�� �����ϵ� index���� �̿��� �������� ������ �����ϴ�
	for (int i = 0; i < intVector.size(); i++)
		cout << " " << intVector[i];
	cout << endl;	
}

void STL_map()
{
	//map�� key�� value���� �ϳ��� ������ ����ȴ�.

	map<string, int> stringMap;		//string�� key�� int�� value���� ������ map�� �����Ѵ�.
	map<string, int>::iterator iter;//map�� �����ϱ� ���� iterator�� �����ϴ�.

	typedef pair<string, int>STR_INT;//Ÿ���� ������

	stringMap.insert(STR_INT("one", 1));//����
	stringMap.insert(STR_INT("two", 2));

	for (iter = stringMap.begin(); iter != stringMap.end(); iter++)
		cout << "Key=" << (iter->first).c_str() << ",value=" << iter->second << endl;

	stringMap["three"] = 3;//string�� ���ĺ������� ���ĵȴ�

	for (iter = stringMap.begin(); iter != stringMap.end(); iter++)
		cout << "Key=" << (iter->first).c_str() << ",value=" << iter->second << endl;

	cout << "stringMap[three]=" << stringMap["three"] << endl;
	
}
void STL_stack_queue()//���ð� ť�� ����
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