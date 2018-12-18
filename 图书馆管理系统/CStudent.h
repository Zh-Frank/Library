/*
ѧ����
����ѧ��ID���룬���������ɽ��Ĳ������ѽ��Ĳ����Լ�ѧ������ͼ���ISBN�����list 
�ṩ��set�Լ�get�ӿ�
�ṩ���ͼ���Լ��黹ͼ��ӿڣ���ͼ��isbn���Ϊ���� 
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
