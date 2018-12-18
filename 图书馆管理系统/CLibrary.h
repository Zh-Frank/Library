/*
图书馆管理类，封装一个图书类的list以及一个学生类的list，分别表示所有图书以及所有学生
提供添加图书、学生，删除图书、学生，查询图书、学生，修改图书、学生，显示所有图书、学生等接口
提供借书还书接口。 
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
