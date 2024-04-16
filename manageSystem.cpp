#include <iostream>
#include <string>
#define MAX 30
using namespace std;

// ��ϵ�� �ṹ��
struct Person
{
	string name;
	unsigned short int sex;
	unsigned int age;
	string phone;
	string addr;

}typedef Person;

// ͨѶ¼ �ṹ��
struct AddressBooks
{
	// ͨѶ¼�������ϵ������
	Person arr[MAX];

	// ͨѶ¼�е�ǰ��¼��ϵ�˵ĸ���
	int size = 0;

}typedef AddressBooks;

// ��������
extern void showMenu();
extern void addPerson(AddressBooks*);
extern void showPerson(AddressBooks*);
extern int isExist(AddressBooks*, string);
extern void deletePerson(AddressBooks*);
extern void findPerson(AddressBooks*);
extern void modifyPerson(AddressBooks*);
extern void clearAll(AddressBooks*);


// ������
int main()
{
	// ����һ��ͨѶ¼
	AddressBooks book;

	// ��ʼ���û�ѡ��Ĺ���
	int select = 0;

	// ����ѭ��
	while (true)
	{
		// ��ʾ�˵�
		showMenu();

		// ��ȡ�û�����
		cin >> select;

		switch (select)
		{
			case 1:		// �����ϵ��
				addPerson(&book);
				break;
			case 2:		// ��ʾ��ϵ��
				showPerson(&book);
				break;
			case 3:		// ɾ����ϵ��
				deletePerson(&book);
				break;
			case 4:		// ������ϵ��
				findPerson(&book);
				break;
			case 5:		// �޸���ϵ��
				modifyPerson(&book);
				break;
			case 6:		// �����ϵ��
				clearAll(&book);
				break;
			case 0:		// �˳�ͨѶ¼
				cout << "��ӭ�´�ʹ��" << endl;
				return 0;
		}

		// �������������
		system("pause");
		system("cls");
	}
}

// չʾ���ܲ˵�
void showMenu()
{
	cout << "**************************" << endl;
	cout << "****** 1�������ϵ�� *****" << endl;
	cout << "****** 2����ʾ��ϵ�� *****" << endl;
	cout << "****** 3��ɾ����ϵ�� *****" << endl;
	cout << "****** 4��������ϵ�� *****" << endl;
	cout << "****** 5���޸���ϵ�� *****" << endl;
	cout << "****** 6�������ϵ�� *****" << endl;
	cout << "****** 0���˳�ͨѶ¼ *****" << endl;
	cout << "**************************" << endl;
}

// �����ϵ��
void addPerson(AddressBooks* p)
{
	// �жϵ�ǰͨ��¼�Ƿ�����
	if (p->size >= MAX)
	{
		cout << "ͨѶ¼���������ʧ�ܣ�" << endl;
		return;
	}
	// ��Ӿ������ϵ��
	Person& person = p->arr[p->size];

	// - ����
	cout << "������������";
	cin >> person.name;

	// - �Ա�
	cout << "�������Ա�" << endl;
	cout << "1 -> ��" << endl;
	cout << "2 -> Ů" << endl;
	int sexInput;
	while (true)
	{
		cin >> sexInput;
		if (sexInput == 1 || sexInput == 2)
		{
			person.sex = sexInput;
			break;
		}
		cout << "�������\n���������룺";
	}
	// ����
	cout << "���������䣺";
	cin >> person.age;

	// �绰
	cout << "������绰��";
	cin >> person.phone;

	// סַ
	cout << "������סַ��";
	cin >> person.addr;

	// ���� size ������
	p->size++;

	cout << "��ӳɹ�" << endl;
}

// ��ʾ��ϵ��
void showPerson(AddressBooks* p)
{
	int num = p->size;
	Person* arr = p->arr;
	if (num == 0)
	{
		cout << "��ʱδ����κ���ϵ��" << endl;
		return;
	}
	for (int i = 0; i < num; i++)
	{
		Person person = arr[i];
		cout << endl;
		cout << "������" << person.name << "\t";
		cout << "�Ա�" << person.sex << "\t\t";
		cout << "���䣺" << ((person.age == 1) ? "��" : "Ů") << "\t";
		cout << "�绰��" << person.phone << "\t";
		cout << "סַ��" << person.addr << "\t";
	}
	cout << endl;
}

// �Ƿ������ϵ��
int isExist(AddressBooks* p, string name)
{
	Person* arr = p->arr;
	int num = p->size;
	if (num == 0) return -1;
	for (int i = 0; i < num; i++)
	{
		if (name == arr[i].name) return i;
	}
	return -1;
}

// ɾ����ϵ��
void deletePerson(AddressBooks* p)
{
	// ��ȡɾ������ϵ��
	string name;
	cout << "������ɾ����ϵ�˵�������";
	cin >> name;
	// �����ϵ���Ƿ����
	int res = isExist(p, name);
	if (res < 0)
	{
		cout << "��ϵ�˲�����" << endl;
		return;
	}
	// ɾ������
	int num = p->size;
	Person* arr = p->arr;
	for (int i = res; i < num - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	p->size--;
	cout << "ɾ���ɹ���" << endl;
}

// ������ϵ��
void findPerson(AddressBooks* p)
{
	// ��ȡ���ҵ���ϵ��
	string name;
	cout << "�����������ϵ�˵�������";
	cin >> name;
	// �����ϵ���Ƿ����
	int res = isExist(p, name);
	if (res < 0)
	{
		cout << "��ϵ�˲�����" << endl;
		return;
	}
	Person person = p->arr[res];
	cout << "������" << person.name << "\t";
	cout << "�Ա�" << person.sex << "\t\t";
	cout << "���䣺" << ((person.age == 1) ? "��" : "Ů") << "\t";
	cout << "�绰��" << person.phone << "\t";
	cout << "סַ��" << person.addr << "\t";
	cout << endl;
}

// �޸���ϵ��
void modifyPerson(AddressBooks* p)
{
	// ��ȡ���ҵ���ϵ��
	string name;
	cout << "�������޸���ϵ�˵�������";
	cin >> name;
	// �����ϵ���Ƿ����
	int res = isExist(p, name);
	if (res < 0)
	{
		cout << "��ϵ�˲�����" << endl;
		return;
	}
	Person person = p->arr[res];
	cout << "������";
	cin >> person.name;
	cout << "�Ա�(1 -> �� || 2 -> Ů)";
	int sexInput;
	while (true)
	{	
		cin >> sexInput;
		if (sexInput == 1 || sexInput == 2) break;
		cout << "����������������룺";
	}
	cout << "���䣺";
	cin >> person.age;
	cout << "�绰��";
	cin >> person.phone;
	cout << "סַ��";
	cin >> person.addr;
	cout << endl;
}

// �����ϵ��
void clearAll(AddressBooks* p)
{
	p->size = 0;
	cout << "�����ͨѶ¼�е�������ϵ��" << endl;
}
