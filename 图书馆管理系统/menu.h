/*
������ʾ���˵��Լ��������˵��������� 
*/
#ifndef MENU_H_H
#define MENU_H_H
#include "CLibrary.h"
void menu();	//���˵� 
void menu_add(CLibrary &lib);	//��� 
void menu_find(const CLibrary &lib);//���� 
void menu_edit(CLibrary &lib);	//�޸� 
void menu_delete(CLibrary &lib);	//ɾ�� 
void menu_bor_re(CLibrary &lib);	//���黹�� 
#endif
