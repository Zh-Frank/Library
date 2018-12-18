/*
定义显示主菜单以及各二级菜单操作函数 
*/
#ifndef MENU_H_H
#define MENU_H_H
#include "CLibrary.h"
void menu();	//主菜单 
void menu_add(CLibrary &lib);	//添加 
void menu_find(const CLibrary &lib);//查找 
void menu_edit(CLibrary &lib);	//修改 
void menu_delete(CLibrary &lib);	//删除 
void menu_bor_re(CLibrary &lib);	//借书还书 
#endif

