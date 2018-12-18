#include "CLibrary.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
void CLibrary::show_allstu() const
{
	cout << setiosflags(ios::left) << setw(10)<< "���" << setw(12) << "����" 
		 << setw(10)<< "�ɽ���" << setw(10)<< "�ѽ���" << endl; 
	for(const auto &i : m_stus)
	{
		cout << setw(10) << i.getID() << setw(12) << i.getName() << setw(10) 
			 << i.getCanLend()  << setw(10) << i.getHaveLend() << endl;
	}
	cout << resetiosflags(ios::left);
}
void CLibrary::show_allbook() const
{
	cout << setiosflags(ios::left) << setw(12)<< "���" << setw(18) << "����" 
		 << setw(10)<< "�ղ���" << setw(10)<< "�ѽ���" << setw(10) << "�ɽ���"<< endl; 
	for(const auto &i : m_books)
	{
		cout << setw(12) << i.getISBN() << setw(18) << i.getName() << setw(10)
			 << i.getNum() << setw(10) << i.getLendNum() << setw(10)
			 << i.getNum() - i.getLendNum() << endl;
	}
	cout << resetiosflags(ios::left);
}
bool CLibrary::borrowbook(const std::string &ISBN, unsigned int ID)
{
	auto book_it =m_books.begin();
	auto stu_it = m_stus.begin();
	while(book_it != m_books.end())
	{
		if(book_it->getISBN() == ISBN)
			break;
		++book_it;
	}
	while(stu_it != m_stus.end())
	{
		if(stu_it->getID() == ID)
			break;
		++stu_it;
	}
	if(book_it == m_books.end())
	{
		cout << "Ҫ�����鱾�����ղأ�����ʧ��" << endl;
		return false;	
	}
	if(stu_it == m_stus.end())
	{
		cout << "ѧ����Ϣ�����ڣ�����ʧ��" << endl;
		return false; 
	}
	if(book_it->getNum() == book_it->getLendNum())
	{
		cout << "Ҫ����ͼ���Ѿ�ȫ�����������ʧ��!" << endl;
		return false;
	}
	if(stu_it->getHaveLend() == stu_it->getCanLend())
	{
		cout << "ѧ���ɽ��������Ѿ����꣬����ʧ�ܣ�"<< endl;
		return false;
	}
	book_it->borrowbook(ID);
	stu_it->borrowbook(ISBN);
	return true;
}

bool CLibrary::returnbook(const std::string &ISBN, unsigned int ID)
{
	auto book_it =m_books.begin();
	auto stu_it = m_stus.begin();
	while(book_it != m_books.end())
	{
		if(book_it->getISBN() == ISBN)
			break;
		++book_it;
	}
	while(stu_it != m_stus.end())
	{
		if(stu_it->getID() == ID)
			break;
		++stu_it;
	}
	if(book_it == m_books.end())
	{
		cout << "Ҫ���鱾�����ղأ�����ʧ��" << endl;
		return false;	
	}
	if(stu_it == m_stus.end())
	{
		cout << "ѧ����Ϣ�����ڣ�����ʧ��" << endl;
		return false; 
	}
	if(book_it->returnbook(ID))
	{
		stu_it->returnbook(ISBN);
		return true;
	}
	else
	{
		cout << "ѧ��û�н���Ҫ���鱾������ʧ��" << endl;
		return false;
	}
}
bool CLibrary::deleteBook(const std::string &isbn)
{
	auto it = m_books.begin();
	while(it != m_books.end())
	{
		if(it->getISBN() == isbn)	//�ҵ��鱾��Ϣ 
		{
			if(it->getLendNum() != 0)	//����鱾�н��ļ�¼ 
			{
				list<unsigned int> stuid = it->getIDList();	//��ȡ���ļ�¼ 
				for(const auto &i : stuid)	//���ü�¼����Ӧѧ���黹�鱾 
				{
					auto sit = m_stus.begin();
					while(sit != m_stus.end())	 
					{
						if(sit->getID() == i)	//��ѧ�����ҵ���¼��ѧ��
						{
							sit->returnbook(isbn);
							break;
						}
						++sit;
					}
				}
			}
			m_books.erase(it);
			return true;
		}
		++it;
	}
	return false;
}
bool CLibrary::deleteStu(unsigned int id)
{
	auto it = m_stus.begin();
	while(it != m_stus.end())
	{
		if(it->getID() == id)	//�ҵ�ѧ����Ϣ 
		{
			if(it->getHaveLend() != 0)	//���ѧ���н��ļ�¼ 
			{
				list<string> books = it->getBookList();	//��ȡ���ļ�¼ 
				for(const auto &i : books)	//�黹��Ӧ��ͼ�� 
				{
					auto bit = m_books.begin();
					while(bit != m_books.end())	 
					{
						if(bit->getISBN() == i)	//��ѧ���ļ�¼���ҵ���Ӧ���鱾 
						{
							bit->returnbook(id);
							break;
						}
						++bit;
					}
				}
			}
			m_stus.erase(it);
			return true;
		}
		++it;
	}
	return false;
}
void CLibrary::findStudent(unsigned int id) const
{
	auto it = m_stus.cbegin();
	while(it != m_stus.cend())
	{
		if(it->getID() == id)	//�ҵ�ѧ����Ϣ 
		{
			cout << setiosflags(ios::left)
				<< "���: " << setw(10) << it->getID() 
				<< "����: " << setw(10) << it->getName() 
				<< "�ɽ���: " << setw(5) << it->getCanLend() 
				<< "�ѽ���: " << setw(5) << it->getHaveLend() << endl; 
			 if(it->getHaveLend() != 0)	//����н��ļ�¼ 
			 {
			 	cout << "������Ϣ" << endl
				 	 << setw(18) << "ͼ��ISBN���" << "ͼ������" << endl;
			 	list<string> books = it->getBookList();
			 	for(const auto &i : books)
			 	{
			 		auto bit = m_books.cbegin();
					while(bit != m_books.cend())
					{
						if(bit->getISBN() == i)
						{
							cout << setw(18) << bit->getISBN()
								 << bit->getName() << endl;
							break;
						}
						++bit;	
					}	
				}	
			}
			cout << resetiosflags(ios::left);
			break;
		}
		++it;
	}
	if(it == m_stus.cend())
		cout << "δ�ҵ�ѧ����Ϣ" << endl; 
}
void CLibrary::findBook(const std::string &isbn) const
{
	auto it = m_books.cbegin();
	while(it != m_books.cend())
	{
		if(it->getISBN() == isbn)
		{
			cout << setiosflags(ios::left)
				 << "���: " << setw(12) << it->getISBN()
				 << "����: " << setw(18) <<it->getName() << endl
				 << "�ղ���: " << setw(5) << it->getNum()
				 << "�����: " << setw(5) << it->getLendNum()
				 << "�ɽ���: " << setw(5) << it->getNum() - it->getLendNum()<< endl;
			if(it->getLendNum() != 0)	//����鱾�н����Ϣ 
			{
			 	cout << "����ѧ����Ϣ" << endl
			 		 << setw(10) << "ѧ�����" << "ѧ������" << endl; 
			 	list<unsigned int> stus = it->getIDList();
			 	for(const auto &i : stus)
			 	{
			 		auto sit = m_stus.cbegin();
					while(sit != m_stus.cend())
					{
						if(sit->getID() == i)
						{
							cout << setw(10) << sit->getID() << sit->getName() << endl;
							break;
						}
						++sit;	
					}
				}	
			}
			cout << resetiosflags(ios::left);
			break;
		}	
		++it;
	}
	if(it == m_books.cend())
		cout << "δ�ҵ�ͼ����Ϣ" << endl; 
}
bool CLibrary::editBook(const std::string &isbn)
{
	auto it = m_books.begin();
	while(it != m_books.end())
	{
		if(it->getISBN() == isbn)
		{
			char c;
			cout << "�Ƿ��޸�ͼ����(Y/N) : ";
			cin >> c;
			if('Y' == c || 'y' == c)
			{
				cout << "�������µı�� : ";
				string newisbn;
				cin >> newisbn;
				it->setISBN(newisbn);
			}
			cout << "�Ƿ��޸�ͼ������(Y/N) : ";
			cin >> c;
			if('Y' == c || 'y' == c)
			{
				cout << "�������µ����� : ";
				string newname;
				cin >> newname;
				it->setName(newname);
			}
			cout << "�Ƿ��޸�ͼ���ղز���(Y/N) : ";
			cin >> c;
			if('Y' == c || 'y' == c)
			{
				cout << "�������µ����� : ";
				unsigned int newnum;
				cin >> newnum;
				while(newnum < it->getLendNum())
				{
					cout << "���������С���ѽ������������������ :";
					cin >> newnum;
				}
				it->setNum(newnum);
			}
			return true;
		}
		++it;
	}
	return false;
}
bool CLibrary::editStudent(unsigned int ID)
{
	auto it = m_stus.begin();
	while(it != m_stus.end())
	{
		if(it->getID() == ID)
		{
			char c;
			cout << "�Ƿ��޸�ѧ�����(Y/N) : ";
			cin >> c;
			if('Y' == c || 'y' == c)
			{
				cout << "�������µı�� : ";
				unsigned int newID;
				cin >> newID;
				it->setID(newID);
			}
			cout << "�Ƿ��޸�ѧ������(Y/N) : ";
			cin >> c;
			if('Y' == c || 'y' == c)
			{
				cout << "�������µ����� : ";
				string newname;
				cin >> newname;
				it->setName(newname);
			}
			cout << "�Ƿ��޸Ŀɽ�ͼ������(Y/N) : ";
			cin >> c;
			if('Y' == c || 'y' == c)
			{
				cout << "�������µĿɽ��� : ";
				unsigned int newnum;
				cin >> newnum;
				while(newnum < it->getHaveLend())
				{
					cout << "���������С�ڸ�ѧ���ѽ����������������� :";
					cin >> newnum;
				}
				it->setCanLend(newnum);
			}
			return true;
		}
		++it;
	}
	return false;
}
bool CLibrary::readFile(const std::string &bookfile, const std::string &stufile)
{
	m_books.clear();
	m_stus.clear();
	ifstream inFile(bookfile, ios::in);
	if(!inFile.is_open())
		return false;
	CBook book("", "", 0);
	while(inFile >> book)
		m_books.push_back(book);
	inFile.close();
	inFile.open(stufile, ios::in);
	if(!inFile.is_open())
	{
		m_books.clear();
		return false;
	}
	CStudent stu(0, "");
	while(inFile >> stu)
		m_stus.push_back(stu);
	inFile.close();
	return true;
}
void CLibrary::saveFile(const std::string &bookfile, const std::string &stufile)
{
	ofstream outFile(bookfile, ios::out);
	for(const auto &i : m_books)
		outFile << i << endl;
	outFile.close();
	outFile.open(stufile, ios::out);
	for(const auto &i : m_stus)
		outFile << i << endl;
	outFile.close();
}
