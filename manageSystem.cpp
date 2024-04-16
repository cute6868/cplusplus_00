#include <iostream>
#include <string>
#define MAX 30
using namespace std;

// 联系人 结构体
struct Person
{
	string name;
	unsigned short int sex;
	unsigned int age;
	string phone;
	string addr;

}typedef Person;

// 通讯录 结构体
struct AddressBooks
{
	// 通讯录保存的联系人数组
	Person arr[MAX];

	// 通讯录中当前记录联系人的个数
	int size = 0;

}typedef AddressBooks;

// 声明函数
extern void showMenu();
extern void addPerson(AddressBooks*);
extern void showPerson(AddressBooks*);
extern int isExist(AddressBooks*, string);
extern void deletePerson(AddressBooks*);
extern void findPerson(AddressBooks*);
extern void modifyPerson(AddressBooks*);
extern void clearAll(AddressBooks*);


// 主函数
int main()
{
	// 创建一个通讯录
	AddressBooks book;

	// 初始化用户选择的功能
	int select = 0;

	// 功能循环
	while (true)
	{
		// 显示菜单
		showMenu();

		// 获取用户输入
		cin >> select;

		switch (select)
		{
			case 1:		// 添加联系人
				addPerson(&book);
				break;
			case 2:		// 显示联系人
				showPerson(&book);
				break;
			case 3:		// 删除联系人
				deletePerson(&book);
				break;
			case 4:		// 查找联系人
				findPerson(&book);
				break;
			case 5:		// 修改联系人
				modifyPerson(&book);
				break;
			case 6:		// 清空联系人
				clearAll(&book);
				break;
			case 0:		// 退出通讯录
				cout << "欢迎下次使用" << endl;
				return 0;
		}

		// 按任意键后清屏
		system("pause");
		system("cls");
	}
}

// 展示功能菜单
void showMenu()
{
	cout << "**************************" << endl;
	cout << "****** 1、添加联系人 *****" << endl;
	cout << "****** 2、显示联系人 *****" << endl;
	cout << "****** 3、删除联系人 *****" << endl;
	cout << "****** 4、查找联系人 *****" << endl;
	cout << "****** 5、修改联系人 *****" << endl;
	cout << "****** 6、清空联系人 *****" << endl;
	cout << "****** 0、退出通讯录 *****" << endl;
	cout << "**************************" << endl;
}

// 添加联系人
void addPerson(AddressBooks* p)
{
	// 判断当前通信录是否满了
	if (p->size >= MAX)
	{
		cout << "通讯录已满，添加失败！" << endl;
		return;
	}
	// 添加具体的联系人
	Person& person = p->arr[p->size];

	// - 姓名
	cout << "请输入姓名：";
	cin >> person.name;

	// - 性别
	cout << "请输入性别：" << endl;
	cout << "1 -> 男" << endl;
	cout << "2 -> 女" << endl;
	int sexInput;
	while (true)
	{
		cin >> sexInput;
		if (sexInput == 1 || sexInput == 2)
		{
			person.sex = sexInput;
			break;
		}
		cout << "输入错误！\n请重新输入：";
	}
	// 年龄
	cout << "请输入年龄：";
	cin >> person.age;

	// 电话
	cout << "请输入电话：";
	cin >> person.phone;

	// 住址
	cout << "请输入住址：";
	cin >> person.addr;

	// 增加 size 计算器
	p->size++;

	cout << "添加成功" << endl;
}

// 显示联系人
void showPerson(AddressBooks* p)
{
	int num = p->size;
	Person* arr = p->arr;
	if (num == 0)
	{
		cout << "暂时未添加任何联系人" << endl;
		return;
	}
	for (int i = 0; i < num; i++)
	{
		Person person = arr[i];
		cout << endl;
		cout << "姓名：" << person.name << "\t";
		cout << "性别：" << person.sex << "\t\t";
		cout << "年龄：" << ((person.age == 1) ? "男" : "女") << "\t";
		cout << "电话：" << person.phone << "\t";
		cout << "住址：" << person.addr << "\t";
	}
	cout << endl;
}

// 是否存在联系人
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

// 删除联系人
void deletePerson(AddressBooks* p)
{
	// 获取删除的联系人
	string name;
	cout << "请输入删除联系人的姓名：";
	cin >> name;
	// 检查联系人是否存在
	int res = isExist(p, name);
	if (res < 0)
	{
		cout << "联系人不存在" << endl;
		return;
	}
	// 删除操作
	int num = p->size;
	Person* arr = p->arr;
	for (int i = res; i < num - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	p->size--;
	cout << "删除成功！" << endl;
}

// 查找联系人
void findPerson(AddressBooks* p)
{
	// 获取查找的联系人
	string name;
	cout << "请输入查找联系人的姓名：";
	cin >> name;
	// 检查联系人是否存在
	int res = isExist(p, name);
	if (res < 0)
	{
		cout << "联系人不存在" << endl;
		return;
	}
	Person person = p->arr[res];
	cout << "姓名：" << person.name << "\t";
	cout << "性别：" << person.sex << "\t\t";
	cout << "年龄：" << ((person.age == 1) ? "男" : "女") << "\t";
	cout << "电话：" << person.phone << "\t";
	cout << "住址：" << person.addr << "\t";
	cout << endl;
}

// 修改联系人
void modifyPerson(AddressBooks* p)
{
	// 获取查找的联系人
	string name;
	cout << "请输入修改联系人的姓名：";
	cin >> name;
	// 检查联系人是否存在
	int res = isExist(p, name);
	if (res < 0)
	{
		cout << "联系人不存在" << endl;
		return;
	}
	Person person = p->arr[res];
	cout << "姓名：";
	cin >> person.name;
	cout << "性别：(1 -> 男 || 2 -> 女)";
	int sexInput;
	while (true)
	{	
		cin >> sexInput;
		if (sexInput == 1 || sexInput == 2) break;
		cout << "输入错误，请重新输入：";
	}
	cout << "年龄：";
	cin >> person.age;
	cout << "电话：";
	cin >> person.phone;
	cout << "住址：";
	cin >> person.addr;
	cout << endl;
}

// 清空联系人
void clearAll(AddressBooks* p)
{
	p->size = 0;
	cout << "已清空通讯录中的所有联系人" << endl;
}
