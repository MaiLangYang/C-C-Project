#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

Peo PresentContacts[Init_size]={
					{"Alice", 28, "Female", "17700630233", "123 Maple Street"},
					{"Bob", 34, "Male", "17700630232", "456 Oak Avenue"},
					{"Charlie", 40, "Male", "17700630231", "789 Pine Road"},
					{"Diana", 22, "Female", "17700630234", "101112 Little Lane"},
					{"Edward", 29, "Male", "17700630238", "121 Big Street"},
					{"Cat", 22, "Male", "17700630235", "122 Big Street" } };

//��ӡһ���˵�
void menu(void) {
	printf("************************************************************\n");
	printf("************1.������ϵ��***********2.ɾ��ָ����ϵ��*********\n");
	printf("************3.������ϵ��***********4.�޸���ϵ��*************\n");
	printf("************5.����*****************6.��ʾ��ϵ��*************\n");
	printf("************0.�˳�����**************************************\n");
	printf("************************************************************\n");
	printf("������������ִ�ж�Ӧ������");
}

#if 1
//ͨѶ¼��ʼ������ָ��
Contact* ContactInit(int initCapacity) {		
	Contact* contacts = (Contact * )malloc(sizeof(Contact));	//Ϊcontact�ṹ�����ռ�

	if (contacts == NULL)
		return NULL;
	contacts->data = (Peo *)calloc(initCapacity, sizeof(Peo));
	if (contacts->data == NULL) {
		free(contacts);		//�ͷ��ѷ�����ڴ�
		return NULL;	//����ʧ��
	}
	contacts->capacity = initCapacity;
	contacts->count = 0;
	
	for (int i = 0; i < Init_size; i++) {				//����Ԥ����ϵ��
		if (i < initCapacity) {
			contacts->data[i] = PresentContacts[i];
			contacts->count++;
		}
	}
	return contacts;
}

#else
//ͨѶ¼��ʼ��������������
Contact* ContactInit(int initCapacity) {	
	//Contact contacts;
	Contact contacts;
	Peo* ptr = calloc(initCapacity, sizeof(Peo));
	if (ptr == NULL) {
		printf("%s\n", strerror(errno));
		return;
	}
	contacts.data = ptr;
	for (int i = 0; i < Init_size; i++) {				//����Ԥ����ϵ��
		if (i < initCapacity) {
			ptr[i] = PresentContacts[i];
			contacts.count++;
		}
	}
	return contacts;
}
#endif

#if 1
//1.������ϵ�ˡ���ָ��
void AddPeople(Contact* pc) {
	assert(pc);				
	Peo per = { 0 };		//��ʼ��
	int status = 1;			//Ĭ���п����ڴ�
	if (pc->count == pc->capacity) {	//��ϵ����������ͨѶ¼����ʱ
		Peo* ptr = (Peo*)realloc(pc->data, sizeof(Peo) * (pc->capacity + 2));		//��ԭ����������������������ϵ�˵�����
		if (ptr == NULL)
			status = -1;		//����ʧ��
		else {
			pc->data = ptr;			//pc->dataָ�����·�����ڴ��ַ
			pc->capacity += 2;	//����ͨѶ¼����
			printf("���ݳɹ���\n");
		}
	}

	if (status == -1)
		printf("�����ϵ��ʧ�ܣ�\n");
	else {
		//�����ϵ�˲���
		printf("������������");
		scanf("%49s", per.name);		//�������볤��
		getchar();					//����������еĻ��з�

		printf("���������䣺");
		scanf("%hd", &per.age);
		getchar();

		printf("�������Ա�");
		scanf("%9s", per.sex);
		getchar();

		printf("������绰��");
		scanf("%19s", per.telephone);
		getchar();

		printf("�������ַ��");
		fgets(per.address, sizeof(per.address), stdin);		//ʹ��fgets��ȡ��ַ
		per.address[strcspn(per.address, "\n")] = 0;		//ȥ�����з�

		pc->data[pc->count++] = per;						//�ṹ�帳ֵȻ��count++
	}
}
#else
//1.������ϵ�ˡ�����������
void AddPeople(Contact* pc) {
	assert(pc);
	Peo per = { 0 };		//��ʼ��
	int status = 1;			//Ĭ���п����ڴ�
	if (pc->count == pc->capacity) {	//��ϵ����������ͨѶ¼����ʱ
		Peo* ptr = (Peo*)realloc(pc->data, sizeof(Peo) * (pc->capacity + 2));		//��ԭ����������������������ϵ�˵�����
		if (ptr == NULL)
			status = -1;		//����ʧ��
		else {
			pc->data = ptr;			//pc->dataָ�����·�����ڴ��ַ
			pc->capacity += 2;	//����ͨѶ¼����
			printf("���ݳɹ���\n");
		}
	}

	if (status == -1)
		printf("�����ϵ��ʧ�ܣ�\n");
	else {
		//�����ϵ�˲���
		printf("������������");
		scanf("%49s", per.name);		//�������볤��
		getchar();					//����������еĻ��з�

		printf("���������䣺");
		scanf("%hd", &per.age);
		getchar();

		printf("�������Ա�");
		scanf("%9s", per.sex);
		getchar();

		printf("������绰��");
		scanf("%19s", per.telephone);
		getchar();

		printf("�������ַ��");
		fgets(per.address, sizeof(per.address), stdin);		//ʹ��fgets��ȡ��ַ
		per.address[strcspn(per.address, "\n")] = 0;		//ȥ�����з�

		pc->data[pc->count++] = per;						//�ṹ�帳ֵȻ��count++
	}
}

#endif

//2.ɾ��ָ����ϵ��
void DeletePeople(Contact* pc) {
	assert(pc);
	Peo per = { 0 };
	printf("������Ҫɾ������ϵ��������");
	scanf("%49s", per.name);
	//�ҵ�Ҫɾ����ϵ����ͨѶ¼�е�λ��
	for (int i = 0; i < pc->count; i++) {
		if (strcmp(pc->data[i].name, per.name) == 0) {		//�ҵ���ϵ��
			for (int j = i; j < pc->count - 1; j++) {		//100��Ԫ�أ�j=99ʱ��j+1�ͻ�Խ�磻��һ���䲻���ø��ǵķ�ʽɾ����100��Ԫ�أ���count--��Ͳ�����ʵ���100��Ԫ��
				pc->data[j] = pc->data[j + 1];		//��ǰ�ƶ�����
			}
			pc->count--;
			printf("��ϵ����ɾ����\n");		
			return;
		}	
	}
	printf("Ҫ�ҵ���ϵ�˲����ڣ�\n");
}

//3.������ϵ��
void SearchPeople(Contact* pc) {
	assert(pc);
	Peo per = { 0 };
	printf("������Ҫ������ϵ�˵�������");
	scanf("%49s", per.name);

	for (int i = 0; i < pc->count; i++) {
		if (strcmp(pc->data[i].name, per.name) == 0) {		//�ҵ���ϵ��
			printf("����ϵ����Ϣ���£�\n");
			printf("������%-10s\n���䣺%-6hd\n�Ա�%-10s\n�绰��%-15s\n��ַ��%-20s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].telephone, pc->data[i].address);
			return;
		}
	}
	printf("��ϵ�˲����ڡ�\n");
}

//4.�޸���ϵ����Ϣ
void ModifyPeople(Contact* pc) {
	assert(pc);
	Peo per = { 0 };
	int n;		//ȷ��Ҫ�޸�������Ϣ
	printf("������Ҫ�޸���ϵ�˵�������");		//�жϸ���ϵ���Ƿ����
	scanf("%49s", per.name);
	for (int i = 0; i < pc->count; i++) {
		if (strcmp(pc->data[i].name, per.name) == 0) {		//�ҵ���ϵ��
			printf("��Ҫ�޸ĵ���Ϣ�ǣ�\n");
			printf("1.����\t2.����\t3.�Ա�\t4.�绰\t5.��ַ\t0.�����޸�\n");
			do{
				printf("������ѡ�\n");
				scanf("%d", &n);
				getchar();		//������з�
				switch (n) {
					case 0:
						break;
					case 1:
						printf("�������޸ĺ��������");
						scanf("%49s", per.name);
						getchar();		//������з�
						strcpy(pc->data[i].name, per.name);
						break;
					case 2:
						printf("�������޸ĺ�����䣺");
						scanf("%hd", &per.age);
						getchar();		//������з�
						pc->data[i].age = per.age;
						break;
					case 3:
						printf("�������޸ĺ���Ա�");
						scanf("%9s", per.sex);
						getchar();		//������з�
						strcpy(pc->data[i].sex, per.sex);
						break;
					case 4:
						printf("�������޸ĺ�ĵ绰��");
						scanf("%15s", per.telephone);
						getchar();		//������з�
						strcpy(pc->data[i].telephone, per.telephone);
						break;
					case 5:
						printf("�������޸ĺ�ĵ�ַ��");
						fgets(per.address, sizeof(per.address), stdin);
						per.address[strcspn(per.address, "\n")] = 0;		//������з�
						strcpy(pc->data[i].address, per.address);
						break;
					default:
						printf("������������������!\n");
				}
			} while (n);

			// ��ӡ�޸ĺ����ϵ����Ϣ����֤
			printf("�޸ĺ����ϵ����Ϣ��\n");
			printf("������%s\n", pc->data[i].name);
			printf("���䣺%hd\n", pc->data[i].age);
			printf("�Ա�%s\n", pc->data[i].sex);
			printf("�绰��%s\n", pc->data[i].telephone);
			printf("��ַ��%s\n", pc->data[i].address);
			return;
		}
	}
	printf("��ϵ�˲����ڡ�\n");
}

//5.����
// �ȽϺ���
//�Ƚ�����		static�޶��ú���ֻ�������.c�ļ���ʹ��
static int CompareName(const void *a, const void *b) {
	assert(a);
	assert(b);
	Peo* pa = (Peo*)a;
	Peo* pb = (Peo*)b;
	return strcmp((*pa).name, (*pb).name);
}

//�Ƚ�����
static int CompareAge(const void* a, const void* b) {
	assert(a);
	assert(b);
	return ((Peo*)a)->age - ((Peo*)b)->age;		//����1�����򣬷���-1�ǽ���
}

//�Ƚϵ绰
static int CompareTel(const void* a, const void* b) {
	assert(a);
	assert(b);
	return strcmp(((Peo*)a)->telephone, ((Peo*)b)->telephone);
}

//�Ƚϵ�ַ
static int CompareAddress(const void* a, const void* b) {
	assert(a);
	assert(b);
	return strcmp(((Peo*)a)->address, ((Peo*)b)->address);
}

//������
void SortPeople(Contact* pc) {
	assert(pc);
	int n;		//����ѡ��
	printf("�������������Ϣ��������\n");
	printf("1.����\t2.����\t3.�绰\t4.��ַ\n");
	scanf("%d", &n);
	getchar();
	switch (n) {
	case 1:
		qsort(pc->data, pc->count, sizeof(pc->data[0]), CompareName);
		break;
	case 2:
		qsort(pc->data, pc->count, sizeof(pc->data[0]), CompareAge);
		break;
	case 3:
		qsort(pc->data, pc->count, sizeof(pc->data[0]), CompareTel);
		break;
	case 4:
		qsort(pc->data, pc->count, sizeof(pc->data[0]), CompareAddress);
		break;
	default:
		printf("������������\n");
	}

	//��ӡ��������ϵ��
	printf("��������ϵ����Ϣ���£�\n");
	PrintPeople(pc);
}

//6.��ʾ��ϵ��
void PrintPeople(Contact* pc) {
	assert(pc);
	// ��ӡ������������ϵ�˵���Ϣ
	for (int i = 0; i < pc->count; i++) {
		printf("%10s%6hd%10s%15s%20s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].telephone, pc->data[i].address);
	}
}

//7.�ڴ��ͷ�
void DelBlock(Contact* pc) {
	assert(pc);
	free(pc->data);
	pc->data = NULL;		//�����Ҫ�����ٲ���Ҫ����
}