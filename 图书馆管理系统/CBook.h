/*
图书类
保存图书ISBN号码，图书名，收藏册数，借出册数以及借阅学生ID的list 
提供各set以及get接口
提供借出图书以及归还图书接口，以图书学生ID为参数 
*/

#ifndef CBOOK_H
#define CBOOK_H
#include <string>
#include <iostream> 
#include <list>
class CBook
{
public:
	CBook(const std::string &isbn, const std::string &name, 
		  unsigned int num, unsigned int lendnum = 0);
	~CBook();
	void setISBN(const std::string &isbn) {m_ISBN = isbn;	}
	void setName(const std::string &name) {m_name = name;	}
	void setNum(unsigned int num) {m_num = num;	}
	const std::string& getISBN() const {return m_ISBN;}
	const std::string& getName() const {return m_name;}
	unsigned int getNum() const {return m_num;}
	unsigned int getLendNum() const {return m_lendnum;}
	const std::list<unsigned int>& getIDList()const {return m_stuid;}
	void borrowbook(unsigned int ID);
	
	bool returnbook(unsigned int ID);
protected:
	std::string m_ISBN;		//编号 
	std::string m_name;		//书名 
	unsigned int m_num;		//数量 
	unsigned int m_lendnum;	//借出数量 
	std::list<unsigned int>	m_stuid;	//借书人编号链表 
	
public:
	friend std::istream& operator >> (std::istream &is, CBook &book);
	friend std::ostream& operator << (std::ostream &os, const CBook &book);
};
std::istream& operator >> (std::istream &is, CBook &book);
std::ostream& operator << (std::ostream &os, const CBook &book);
#endif
