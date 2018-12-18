/*
ͼ����
����ͼ��ISBN���룬ͼ�������ղز�������������Լ�����ѧ��ID��list 
�ṩ��set�Լ�get�ӿ�
�ṩ���ͼ���Լ��黹ͼ��ӿڣ���ͼ��ѧ��IDΪ���� 
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
	std::string m_ISBN;		//��� 
	std::string m_name;		//���� 
	unsigned int m_num;		//���� 
	unsigned int m_lendnum;	//������� 
	std::list<unsigned int>	m_stuid;	//�����˱������ 
	
public:
	friend std::istream& operator >> (std::istream &is, CBook &book);
	friend std::ostream& operator << (std::ostream &os, const CBook &book);
};
std::istream& operator >> (std::istream &is, CBook &book);
std::ostream& operator << (std::ostream &os, const CBook &book);
#endif
