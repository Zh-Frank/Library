#include <iostream>
#include "menu.h"
using namespace std;
void menu()
{
	cout << "┏━━━━━━━━━━━━━━━━━━━━━┓" << endl
		 << "┃              图书馆管理系统              ┃" << endl
		 << "┠──────────┬──────────┨" << endl
		 << "┃     1-添加信息     │     2-查询信息     ┃" << endl
		 << "┠──────────┼──────────┨" << endl
		 << "┃     3-修改信息     │     4-删除信息     ┃" << endl
		 << "┠──────────┼──────────┨" << endl
		 << "┃     5-借阅归还     │     0-退出系统     ┃" << endl
		 << "┗━━━━━━━━━━┷━━━━━━━━━━┛" << endl;
	cout << "请选择操作 :"; 
}
void menu_add(CLibrary &lib)
{
	system("cls");
	cout << "┏━━━━━━━━━━━━━━━━━━━━━┓" << endl
		 << "┃                 添加信息                 ┃" << endl
		 << "┠──────────┬──────────┨" << endl
		 << "┃ 1-添加图书信息     │ 2-添加用户信息     ┃" << endl
		 << "┠──────────┴──────────┨" << endl
		 << "┃ 0-返回上级菜单                           ┃" << endl
		 << "┗━━━━━━━━━━━━━━━━━━━━━┛" << endl;
	int sel;
	do
	{
		cout << "请选择 : ";
		cin >> sel;
		if(1 == sel)
		{
			string isbn, name;
			cout << "图书编号 : ";
			cin >> isbn;
			cout << "图书名称 : ";
			cin >> name;
			unsigned int num;
			cout << "收藏数量 : ";
			cin >> num;
			lib.AddBook(CBook(isbn, name, num));
		}
		else if(2 == sel)
		{
			unsigned int id, num;
			string name;
			cout << "学生编号 : ";
			cin >> id;
			cout << "学生姓名 : ";
			cin >> name;
			cout << "可借册数 : ";
			cin >> num;
			lib.AddStudent(CStudent(id, name, num));
		}
		else if(0 == sel)
		{
			system("cls");
			menu();
		}
		else
			cout << "选择错误，请重新输入" << endl; 
	}while(sel != 0);
} 
void menu_find(const CLibrary &lib)
{
	system("cls");
	cout << "┏━━━━━━━━━━━━━━━━━━━━━┓" << endl
		 << "┃                 查询信息                 ┃" << endl
		 << "┠──────────┬──────────┨" << endl
		 << "┃ 1-查询全部图书信息 │ 3-查询全部学生信息 ┃" << endl
		 << "┠──────────┼──────────┨" << endl
		 << "┃ 2-查询单册图书信息 │ 4-查询单个学生信息 ┃" << endl
		 << "┠──────────┴──────────┨" << endl
		 << "┃ 0-返回上级菜单                           ┃" << endl
		 << "┗━━━━━━━━━━━━━━━━━━━━━┛" << endl;
	
	int sel;
	do
	{
		cout << "请选择查询操作 : ";
		cin >> sel;
		if(1 == sel)
		{
			lib.show_allbook();
		}
		else if(3 == sel)
		{
			lib.show_allstu();
		}
		else if(2 == sel)
		{
			cout << "请输入要查询的图书编号 : ";
			string isbn;
			cin >> isbn;
			lib.findBook(isbn);
		}
		else if(4 == sel)
		{
			cout << "请输入要查询的学生编号 : ";
			unsigned int id;
			cin >> id;
			lib.findStudent(id);
		}
		else if(0 == sel)
		{
			system("cls");
			menu();
		}
		else
			cout << "选择错误，请重新输入" << endl; 
	}while(sel != 0);
}
void menu_edit(CLibrary &lib)
{
	system("cls");
	cout << "┏━━━━━━━━━━━━━━━━━━━━━┓" << endl
		 << "┃                 修改信息                 ┃" << endl
		 << "┠──────────┬──────────┨" << endl
		 << "┃ 1-修改图书信息     │ 2-修改用户信息     ┃" << endl
		 << "┠──────────┴──────────┨" << endl
		 << "┃ 0-返回上级菜单                           ┃" << endl
		 << "┗━━━━━━━━━━━━━━━━━━━━━┛" << endl;
	int sel;
	do
	{
		cout << "请选择 : ";
		cin >> sel;
		if(1 == sel)
		{
			cout << "请输入要修改的图书编号: ";
			string isbn;
			cin >> isbn;
			if(lib.editBook(isbn)) 
				cout << "修改信息成功" << endl;
			else
				cout << "指定编号图书不存在，修改失败" << endl;
		}
		else if(2 == sel)
		{
			cout << "请输入要修改的学生编号: ";
			unsigned int id;
			cin >> id;
			if(lib.editStudent(id)) 
				cout << "修改信息成功" << endl;
			else
				cout << "指定编号学生不存在，修改失败" << endl;
		}
		else if(0 == sel)
		{
			system("cls");
			menu();
		}
		else
			cout << "选择错误，请重新输入" << endl; 
	}while(sel != 0);
}
void menu_delete(CLibrary &lib)
{
	system("cls");
	cout << "┏━━━━━━━━━━━━━━━━━━━━━┓" << endl
		 << "┃                 删除信息                 ┃" << endl
		 << "┠──────────┬──────────┨" << endl
		 << "┃ 1-删除图书信息     │ 2-删除用户信息     ┃" << endl
		 << "┠──────────┴──────────┨" << endl
		 << "┃ 0-返回上级菜单                           ┃" << endl
		 << "┗━━━━━━━━━━━━━━━━━━━━━┛" << endl;
	
	int sel;
	do
	{
		cout << "请选择 : ";
		cin >> sel;
		if(1 == sel)
		{
			string isbn;
			cout << "要删除的图书编号 : ";
			cin >> isbn;
			if(lib.deleteBook(isbn))
				cout << "删除成功" << endl;
			else
				cout << "未找到指定编号图书，删除失败" << endl;
		}
		else if(2 == sel)
		{
			unsigned int id;
			cout << "要删除的学生编号 : ";
			cin >> id;
			if(lib.deleteStu(id))
				cout << "删除成功" << endl;
			else
				cout << "未找到指定编号学生，删除失败" << endl;
		}
		else if(0 == sel)
		{
			system("cls");
			menu();
		}
		else
			cout << "选择错误，请重新输入" << endl; 
	}while(sel != 0);
}
void menu_bor_re(CLibrary &lib)
{
	system("cls");
	
	cout << "┏━━━━━━━━━━━━━━━━━━━━━┓" << endl
		 << "┃               借阅归还图书               ┃" << endl
		 << "┠──────────┬──────────┨" << endl
		 << "┃  1-借阅图书        │  2-归还图书        ┃" << endl
		 << "┠──────────┴──────────┨" << endl
		 << "┃  0-返回上级菜单                          ┃" << endl
		 << "┗━━━━━━━━━━━━━━━━━━━━━┛" << endl;
	
	
	int sel;
	do
	{
		cout << "请选择 : ";
		cin >> sel;
		if(1 == sel)
		{
			string isbn;
			cout << "借阅图书编号 : ";
			cin >> isbn;
			unsigned int id;
			cout << "借阅学生编号 : ";
			cin >> id;
			if(lib.borrowbook(isbn, id))
				cout << "借阅成功" << endl;
		}
		else if(2 == sel)
		{
			string isbn;
			cout << "归还图书编号 : ";
			cin >> isbn;
			unsigned int id;
			cout << "归还学生编号 : ";
			cin >> id;
			if(lib.returnbook(isbn, id))
				cout << "还书成功" << endl;
		}
		else if(0 == sel)
		{
			system("cls");
			menu();
		}
		else
			cout << "选择错误，请重新输入" << endl; 
	}while(sel != 0);
}
