#include "CStudent.h"
#include <string>
using namespace std;

istream& operator >> (istream &is, CStudent &stu)
{
	stu.m_books.clear();
	is >> stu.m_ID >> stu.m_name >> stu.m_can_lend >> stu.m_have_lend;
	if(stu.m_have_lend != 0)
	{
		for(int i = 0; i != stu.m_have_lend; ++i)
		{
			string isbn;
			is >> isbn;
			stu.m_books.push_back(isbn);
		}
	}
	return is;
}
ostream& operator << (ostream &os, const CStudent &stu)
{
	os << stu.m_ID << '\t' << stu.m_name << "\t" 
		<< stu.m_can_lend << '\t' << stu.m_have_lend << '\t';
	if(stu.m_have_lend != 0)
	{
		for(const auto &i : stu.m_books)
			os << i << '\t';
	}
	return os;
}



void CStudent::borrowbook(const string &ISBN)
{
	++m_have_lend;
	m_books.push_back(ISBN);
}
void CStudent::returnbook(const string &ISBN)
{
	--m_have_lend;
	auto it = m_books.cbegin();
	while(it != m_books.cend())
	{
		if(*it == ISBN)
			break;
		++it;
	}
	m_books.erase(it);
}
