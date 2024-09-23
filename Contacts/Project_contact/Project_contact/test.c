#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

int main() {
	
	int input;
	Contact* con = ContactInit(10);		//����ͨѶ¼��ʼ����initCapacity����ָ��
	do {
		menu();
		scanf("%d", &input);
		switch (input) {
			case 0:
				DelBlock(con);
				printf("�˳�����");
				break;
			case 1:
				AddPeople(con);
				break;
			case 2:
				DeletePeople(con);
				break;
			case 3:
				SearchPeople(con);
				break;
			case 4:
				ModifyPeople(con);
				break;
			case 5:
				SortPeople(con);
				break;
			case 6:
				PrintPeople(con);
				break;
			default:
				printf("enter error\n");
		}
	} while (input != 0);
	return 0;
}