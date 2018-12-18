#include "CBook.h"
using namespace std;
istream& operator >> (istream &is, CBook &book)
{
	book.m_stuid.clear();
	is >> book.m_ISBN >> book.m_name >> book.m_num >> book.m_lendnum;
	if(book.m_lendnum != 0)
	{
		for(int i = 0; i != book.m_lendnum; ++i)
		{
			int id;
			is >> id;
			book.m_stuid.push_back(id);
		}
	}
	return is;
}
ostream& operator << (ostream &os, const CBook &book)
{
	os << book.m_ISBN << '\t' << book.m_name << "\t" 
		<< book.m_num << '\t' << book.m_lendnum << '\t';
	if(book.m_lendnum != 0)
	{
		for(const auto &i : book.m_stuid)
			os << i << '\t';
	}
	return os;
}


CBook::CBook(const string &isbn, const string &name, 
			 unsigned int num, unsigned int lendnum)
		: m_ISBN(isbn), m_name(name), m_num(num), m_lendnum(lendnum) 
{
	
}
CBook::~CBook()
{
}
void CBook::borrowbook(unsigned int ID)
{
	++m_lendnum;
	m_stuid.push_back(ID);
}
bool CBook::returnbook(unsigned int ID)
{
	auto it = m_stuid.cbegin();
	while(it != m_stuid.cend())
	{
		if(*it == ID)
			break;
		++it;
	}
	if(it == m_stuid.cend())
		return false;
	--m_lendnum;
	m_stuid.erase(it);
	return true; 
}
