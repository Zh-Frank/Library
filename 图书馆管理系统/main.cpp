#include "menu.h"
#include <iostream>
using namespace std;
int main(int argc, char** argv) 
{
	CLibrary lib;
	lib.readFile();
	menu();
	int sel;
	while(cin >> sel)
	{
		if(1 == sel)
			menu_add(lib);
		else if(2 == sel)
			menu_find(lib);
		else if(3 == sel)
			menu_edit(lib);
		else if(4 == sel)
			menu_delete(lib);
		else if(5 == sel)
			menu_bor_re(lib);
		else if(0 == sel)
		{
			lib.saveFile();
			cout << "׼���˳�ϵͳ......" << endl;
			break;
		}
		else
			cout << "ѡ���������������: ";
	}
	return 0;
}
