#include "CLibrary.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
void CLibrary::show_allstu() const
{
	cout << setiosflags(ios::left) << setw(10)<< "编号" << setw(12) << "姓名" 
		 << setw(10)<< "可借数" << setw(10)<< "已借数" << endl; 
	for(const auto &i : m_stus)
	{
		cout << setw(10) << i.getID() << setw(12) << i.getName() << setw(10) 
			 << i.getCanLend()  << setw(10) << i.getHaveLend() << endl;
	}
	cout << resetiosflags(ios::left);
}
void CLibrary::show_allbook() const
{
	cout << setiosflags(ios::left) << setw(12)<< "编号" << setw(18) << "书名" 
		 << setw(10)<< "收藏数" << setw(10)<< "已借数" << setw(10) << "可借数"<< endl; 
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
		cout << "要借阅书本不在收藏，借阅失败" << endl;
		return false;	
	}
	if(stu_it == m_stus.end())
	{
		cout << "学生信息不存在，借阅失败" << endl;
		return false; 
	}
	if(book_it->getNum() == book_it->getLendNum())
	{
		cout << "要借阅图书已经全部借出，借阅失败!" << endl;
		return false;
	}
	if(stu_it->getHaveLend() == stu_it->getCanLend())
	{
		cout << "学生可借阅数额已经用完，借阅失败！"<< endl;
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
		cout << "要还书本不在收藏，还书失败" << endl;
		return false;	
	}
	if(stu_it == m_stus.end())
	{
		cout << "学生信息不存在，还书失败" << endl;
		return false; 
	}
	if(book_it->returnbook(ID))
	{
		stu_it->returnbook(ISBN);
		return true;
	}
	else
	{
		cout << "学生没有借阅要还书本，还书失败" << endl;
		return false;
	}
}
bool CLibrary::deleteBook(const std::string &isbn)
{
	auto it = m_books.begin();
	while(it != m_books.end())
	{
		if(it->getISBN() == isbn)	//找到书本信息 
		{
			if(it->getLendNum() != 0)	//如果书本有借阅记录 
			{
				list<unsigned int> stuid = it->getIDList();	//获取借阅记录 
				for(const auto &i : stuid)	//设置记录中相应学生归还书本 
				{
					auto sit = m_stus.begin();
					while(sit != m_stus.end())	 
					{
						if(sit->getID() == i)	//在学生中找到记录中学生
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
		if(it->getID() == id)	//找到学生信息 
		{
			if(it->getHaveLend() != 0)	//如果学生有借阅记录 
			{
				list<string> books = it->getBookList();	//获取借阅记录 
				for(const auto &i : books)	//归还相应的图书 
				{
					auto bit = m_books.begin();
					while(bit != m_books.end())	 
					{
						if(bit->getISBN() == i)	//在学借阅记录中找到相应的书本 
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
		if(it->getID() == id)	//找到学生信息 
		{
			cout << setiosflags(ios::left)
				<< "编号: " << setw(10) << it->getID() 
				<< "姓名: " << setw(10) << it->getName() 
				<< "可借数: " << setw(5) << it->getCanLend() 
				<< "已借数: " << setw(5) << it->getHaveLend() << endl; 
			 if(it->getHaveLend() != 0)	//如果有借阅记录 
			 {
			 	cout << "借阅信息" << endl
				 	 << setw(18) << "图书ISBN编号" << "图书名称" << endl;
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
		cout << "未找到学生信息" << endl; 
}
void CLibrary::findBook(const std::string &isbn) const
{
	auto it = m_books.cbegin();
	while(it != m_books.cend())
	{
		if(it->getISBN() == isbn)
		{
			cout << setiosflags(ios::left)
				 << "编号: " << setw(12) << it->getISBN()
				 << "书名: " << setw(18) <<it->getName() << endl
				 << "收藏数: " << setw(5) << it->getNum()
				 << "借出数: " << setw(5) << it->getLendNum()
				 << "可借数: " << setw(5) << it->getNum() - it->getLendNum()<< endl;
			if(it->getLendNum() != 0)	//如果书本有借出信息 
			{
			 	cout << "借阅学生信息" << endl
			 		 << setw(10) << "学生编号" << "学生姓名" << endl; 
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
		cout << "未找到图书信息" << endl; 
}
bool CLibrary::editBook(const std::string &isbn)
{
	auto it = m_books.begin();
	while(it != m_books.end())
	{
		if(it->getISBN() == isbn)
		{
			char c;
			cout << "是否修改图书编号(Y/N) : ";
			cin >> c;
			if('Y' == c || 'y' == c)
			{
				cout << "请输入新的编号 : ";
				string newisbn;
				cin >> newisbn;
				it->setISBN(newisbn);
			}
			cout << "是否修改图书名称(Y/N) : ";
			cin >> c;
			if('Y' == c || 'y' == c)
			{
				cout << "请输入新的名称 : ";
				string newname;
				cin >> newname;
				it->setName(newname);
			}
			cout << "是否修改图书收藏册数(Y/N) : ";
			cin >> c;
			if('Y' == c || 'y' == c)
			{
				cout << "请输入新的名称 : ";
				unsigned int newnum;
				cin >> newnum;
				while(newnum < it->getLendNum())
				{
					cout << "输入的数量小于已借出数量，请重新输入 :";
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
			cout << "是否修改学生编号(Y/N) : ";
			cin >> c;
			if('Y' == c || 'y' == c)
			{
				cout << "请输入新的编号 : ";
				unsigned int newID;
				cin >> newID;
				it->setID(newID);
			}
			cout << "是否修改学生名称(Y/N) : ";
			cin >> c;
			if('Y' == c || 'y' == c)
			{
				cout << "请输入新的姓名 : ";
				string newname;
				cin >> newname;
				it->setName(newname);
			}
			cout << "是否修改可借图书数量(Y/N) : ";
			cin >> c;
			if('Y' == c || 'y' == c)
			{
				cout << "请输入新的可借数 : ";
				unsigned int newnum;
				cin >> newnum;
				while(newnum < it->getHaveLend())
				{
					cout << "输入的数量小于该学生已借数量，请重新输入 :";
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
