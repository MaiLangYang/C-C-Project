#define _CRT_SECURE_NO_WARNINGS 1

#ifndef CONTACT_H
#define CONTACT_H

#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"assert.h"

#define Init_size 6

typedef struct people {
	char name[20];		//姓名
	short age;			//年龄
	char sex[10];		//性别
	char telephone[20];	//电话
	char address[30];	//地址
}Peo;

//静态通讯录
#if 0
typedef struct contact {
	Peo data[N];		//存放联系人信息
	int count;		//记录当前所存放的学生信息个数
}Contact;

#elif 1
//动态通讯录——指针实现
typedef struct contact {
	Peo* data;			//指向联系人信息
	int count;			//记录当前所存放的学生信息个数
	int capacity;		//记录当前通讯录容量
}Contact;
#elif 0
//动态通讯录——柔性数组实现
typedef struct contact {
	int count;		//记录当前所存放的学生信息个数
	int capacity;	//记录当前通讯录容量
	Peo data[];			//指向联系人信息
}Contact;
#endif

void menu(void);						//菜单
Contact* ContactInit(int initCapacity);	//初始化联系人信息——指针
//void ContactInit(int initCapacity);		// 通讯录初始化——柔性数组
void AddPeople(Contact* pc);			//增加联系人
void PrintPeople(Contact* pc);			//显示联系人
void DeletePeople(Contact* pc);			//删除指定联系人
void SearchPeople(Contact* pc);			//查找联系人
void ModifyPeople(Contact* pc);			//修改联系人
void SortPeople(Contact* pc);			//排序
void DelBlock(Contact* pc);
#endif