#include <iostream>
#include "menu.h"
using namespace std;
void menu()
{
	cout << "����������������������������������������������" << endl
		 << "��              ͼ��ݹ���ϵͳ              ��" << endl
		 << "�ĩ��������������������Щ���������������������" << endl
		 << "��     1-�����Ϣ     ��     2-��ѯ��Ϣ     ��" << endl
		 << "�ĩ��������������������੤��������������������" << endl
		 << "��     3-�޸���Ϣ     ��     4-ɾ����Ϣ     ��" << endl
		 << "�ĩ��������������������੤��������������������" << endl
		 << "��     5-���Ĺ黹     ��     0-�˳�ϵͳ     ��" << endl
		 << "�����������������������۩���������������������" << endl;
	cout << "��ѡ����� :"; 
}
void menu_add(CLibrary &lib)
{
	system("cls");
	cout << "����������������������������������������������" << endl
		 << "��                 �����Ϣ                 ��" << endl
		 << "�ĩ��������������������Щ���������������������" << endl
		 << "�� 1-���ͼ����Ϣ     �� 2-����û���Ϣ     ��" << endl
		 << "�ĩ��������������������ة���������������������" << endl
		 << "�� 0-�����ϼ��˵�                           ��" << endl
		 << "����������������������������������������������" << endl;
	int sel;
	do
	{
		cout << "��ѡ�� : ";
		cin >> sel;
		if(1 == sel)
		{
			string isbn, name;
			cout << "ͼ���� : ";
			cin >> isbn;
			cout << "ͼ������ : ";
			cin >> name;
			unsigned int num;
			cout << "�ղ����� : ";
			cin >> num;
			lib.AddBook(CBook(isbn, name, num));
		}
		else if(2 == sel)
		{
			unsigned int id, num;
			string name;
			cout << "ѧ����� : ";
			cin >> id;
			cout << "ѧ������ : ";
			cin >> name;
			cout << "�ɽ���� : ";
			cin >> num;
			lib.AddStudent(CStudent(id, name, num));
		}
		else if(0 == sel)
		{
			system("cls");
			menu();
		}
		else
			cout << "ѡ���������������" << endl; 
	}while(sel != 0);
} 
void menu_find(const CLibrary &lib)
{
	system("cls");
	cout << "����������������������������������������������" << endl
		 << "��                 ��ѯ��Ϣ                 ��" << endl
		 << "�ĩ��������������������Щ���������������������" << endl
		 << "�� 1-��ѯȫ��ͼ����Ϣ �� 3-��ѯȫ��ѧ����Ϣ ��" << endl
		 << "�ĩ��������������������੤��������������������" << endl
		 << "�� 2-��ѯ����ͼ����Ϣ �� 4-��ѯ����ѧ����Ϣ ��" << endl
		 << "�ĩ��������������������ة���������������������" << endl
		 << "�� 0-�����ϼ��˵�                           ��" << endl
		 << "����������������������������������������������" << endl;
	
	int sel;
	do
	{
		cout << "��ѡ���ѯ���� : ";
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
			cout << "������Ҫ��ѯ��ͼ���� : ";
			string isbn;
			cin >> isbn;
			lib.findBook(isbn);
		}
		else if(4 == sel)
		{
			cout << "������Ҫ��ѯ��ѧ����� : ";
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
			cout << "ѡ���������������" << endl; 
	}while(sel != 0);
}
void menu_edit(CLibrary &lib)
{
	system("cls");
	cout << "����������������������������������������������" << endl
		 << "��                 �޸���Ϣ                 ��" << endl
		 << "�ĩ��������������������Щ���������������������" << endl
		 << "�� 1-�޸�ͼ����Ϣ     �� 2-�޸��û���Ϣ     ��" << endl
		 << "�ĩ��������������������ة���������������������" << endl
		 << "�� 0-�����ϼ��˵�                           ��" << endl
		 << "����������������������������������������������" << endl;
	int sel;
	do
	{
		cout << "��ѡ�� : ";
		cin >> sel;
		if(1 == sel)
		{
			cout << "������Ҫ�޸ĵ�ͼ����: ";
			string isbn;
			cin >> isbn;
			if(lib.editBook(isbn)) 
				cout << "�޸���Ϣ�ɹ�" << endl;
			else
				cout << "ָ�����ͼ�鲻���ڣ��޸�ʧ��" << endl;
		}
		else if(2 == sel)
		{
			cout << "������Ҫ�޸ĵ�ѧ�����: ";
			unsigned int id;
			cin >> id;
			if(lib.editStudent(id)) 
				cout << "�޸���Ϣ�ɹ�" << endl;
			else
				cout << "ָ�����ѧ�������ڣ��޸�ʧ��" << endl;
		}
		else if(0 == sel)
		{
			system("cls");
			menu();
		}
		else
			cout << "ѡ���������������" << endl; 
	}while(sel != 0);
}
void menu_delete(CLibrary &lib)
{
	system("cls");
	cout << "����������������������������������������������" << endl
		 << "��                 ɾ����Ϣ                 ��" << endl
		 << "�ĩ��������������������Щ���������������������" << endl
		 << "�� 1-ɾ��ͼ����Ϣ     �� 2-ɾ���û���Ϣ     ��" << endl
		 << "�ĩ��������������������ة���������������������" << endl
		 << "�� 0-�����ϼ��˵�                           ��" << endl
		 << "����������������������������������������������" << endl;
	
	int sel;
	do
	{
		cout << "��ѡ�� : ";
		cin >> sel;
		if(1 == sel)
		{
			string isbn;
			cout << "Ҫɾ����ͼ���� : ";
			cin >> isbn;
			if(lib.deleteBook(isbn))
				cout << "ɾ���ɹ�" << endl;
			else
				cout << "δ�ҵ�ָ�����ͼ�飬ɾ��ʧ��" << endl;
		}
		else if(2 == sel)
		{
			unsigned int id;
			cout << "Ҫɾ����ѧ����� : ";
			cin >> id;
			if(lib.deleteStu(id))
				cout << "ɾ���ɹ�" << endl;
			else
				cout << "δ�ҵ�ָ�����ѧ����ɾ��ʧ��" << endl;
		}
		else if(0 == sel)
		{
			system("cls");
			menu();
		}
		else
			cout << "ѡ���������������" << endl; 
	}while(sel != 0);
}
void menu_bor_re(CLibrary &lib)
{
	system("cls");
	
	cout << "����������������������������������������������" << endl
		 << "��               ���Ĺ黹ͼ��               ��" << endl
		 << "�ĩ��������������������Щ���������������������" << endl
		 << "��  1-����ͼ��        ��  2-�黹ͼ��        ��" << endl
		 << "�ĩ��������������������ة���������������������" << endl
		 << "��  0-�����ϼ��˵�                          ��" << endl
		 << "����������������������������������������������" << endl;
	
	
	int sel;
	do
	{
		cout << "��ѡ�� : ";
		cin >> sel;
		if(1 == sel)
		{
			string isbn;
			cout << "����ͼ���� : ";
			cin >> isbn;
			unsigned int id;
			cout << "����ѧ����� : ";
			cin >> id;
			if(lib.borrowbook(isbn, id))
				cout << "���ĳɹ�" << endl;
		}
		else if(2 == sel)
		{
			string isbn;
			cout << "�黹ͼ���� : ";
			cin >> isbn;
			unsigned int id;
			cout << "�黹ѧ����� : ";
			cin >> id;
			if(lib.returnbook(isbn, id))
				cout << "����ɹ�" << endl;
		}
		else if(0 == sel)
		{
			system("cls");
			menu();
		}
		else
			cout << "ѡ���������������" << endl; 
	}while(sel != 0);
}
