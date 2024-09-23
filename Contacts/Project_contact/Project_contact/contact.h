#define _CRT_SECURE_NO_WARNINGS 1

#ifndef CONTACT_H
#define CONTACT_H

#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"assert.h"

#define Init_size 6

typedef struct people {
	char name[20];		//����
	short age;			//����
	char sex[10];		//�Ա�
	char telephone[20];	//�绰
	char address[30];	//��ַ
}Peo;

//��̬ͨѶ¼
#if 0
typedef struct contact {
	Peo data[N];		//�����ϵ����Ϣ
	int count;		//��¼��ǰ����ŵ�ѧ����Ϣ����
}Contact;

#elif 1
//��̬ͨѶ¼����ָ��ʵ��
typedef struct contact {
	Peo* data;			//ָ����ϵ����Ϣ
	int count;			//��¼��ǰ����ŵ�ѧ����Ϣ����
	int capacity;		//��¼��ǰͨѶ¼����
}Contact;
#elif 0
//��̬ͨѶ¼������������ʵ��
typedef struct contact {
	int count;		//��¼��ǰ����ŵ�ѧ����Ϣ����
	int capacity;	//��¼��ǰͨѶ¼����
	Peo data[];			//ָ����ϵ����Ϣ
}Contact;
#endif

void menu(void);						//�˵�
Contact* ContactInit(int initCapacity);	//��ʼ����ϵ����Ϣ����ָ��
//void ContactInit(int initCapacity);		// ͨѶ¼��ʼ��������������
void AddPeople(Contact* pc);			//������ϵ��
void PrintPeople(Contact* pc);			//��ʾ��ϵ��
void DeletePeople(Contact* pc);			//ɾ��ָ����ϵ��
void SearchPeople(Contact* pc);			//������ϵ��
void ModifyPeople(Contact* pc);			//�޸���ϵ��
void SortPeople(Contact* pc);			//����
void DelBlock(Contact* pc);
#endif