/*
ͼ��ݹ����࣬��װһ��ͼ�����list�Լ�һ��ѧ�����list���ֱ��ʾ����ͼ���Լ�����ѧ��
�ṩ���ͼ�顢ѧ����ɾ��ͼ�顢ѧ������ѯͼ�顢ѧ�����޸�ͼ�顢ѧ������ʾ����ͼ�顢ѧ���Ƚӿ�
�ṩ���黹��ӿڡ� 
*/ 
#ifndef CLIBRARY_H
#define CLIBRARY_H
#include "CStudent.h"
#include "CBook.h"

class CLibrary
{
public:
	CLibrary() {		} 
	~CLibrary(){		}
	void AddBook(const CBook &book)
	{
		m_books.push_back(book);
	}
	void AddStudent(const CStudent &stu)
	{
		m_stus.push_back(stu);
	}
	bool deleteBook(const std::string &isbn);
	bool deleteStu(unsigned int id);
	
	void show_allstu() const;
	void show_allbook() const;
	
	bool borrowbook(const std::string &ISBN, unsigned int ID);
	bool returnbook(const std::string &ISBN, unsigned int ID);
	
	void findStudent(unsigned int id) const;
	void findBook(const std::string &isbn) const; 
	
	bool editBook(const std::string &isbn);
	bool editStudent(unsigned int ID);

	bool readFile(const std::string &bookfile = "bookinfo.txt", 
				  const std::string &stufile = "stuinfo.txt");
	void saveFile(const std::string &bookfile = "bookinfo.txt", 
				  const std::string &stufile = "stuinfo.txt");
protected:
	std::list<CBook> m_books;
	std::list<CStudent> m_stus;
};

#endif
