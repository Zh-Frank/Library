/*
学生类
保存学生ID号码，姓名名，可借阅册数，已借阅册数以及学生借阅图书的ISBN号码的list 
提供各set以及get接口
提供借出图书以及归还图书接口，以图书isbn编号为参数 
*/
#ifndef CSTUDENT_H
#define CSTUDENT_H
#include <string>
#include <iostream> 
#include <list>
class CStudent
{
public:
	CStudent(unsigned int ID, const std::string &name, unsigned int lend = 5, unsigned int havelend = 0)
		: m_ID(ID), m_name(name), m_can_lend(lend), m_have_lend(havelend)
	{	}
	void setID(unsigned int ID) {m_ID = ID;	}
	void setName(const std::string &name) {m_name = name;	}
	void setCanLend(unsigned int num) {m_can_lend = num;	}
	unsigned int getID() const {return m_ID;}
	const std::string& getName() const {return m_name;}
	unsigned int getCanLend() const {return m_can_lend;}
	unsigned int getHaveLend() const {return m_have_lend;}
	const std::list<std::string>& getBookList() const {return m_books;} 
	void borrowbook(const std::string &ISBN);
	void returnbook(const std::string &ISBN);
protected:
	unsigned int m_ID;
	std::string m_name;
	unsigned int m_can_lend;
	unsigned int m_have_lend;
	std::list<std::string> m_books; 
	
	
	friend std::istream& operator >> (std::istream &is, CStudent &book);
	friend std::ostream& operator << (std::ostream &os, const CStudent &book);
};
std::istream& operator >> (std::istream &is, CStudent &stu);
std::ostream& operator << (std::ostream &os, const CStudent &stu);
#endif
