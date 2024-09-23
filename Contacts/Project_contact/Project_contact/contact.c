#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

Peo PresentContacts[Init_size]={
					{"Alice", 28, "Female", "17700630233", "123 Maple Street"},
					{"Bob", 34, "Male", "17700630232", "456 Oak Avenue"},
					{"Charlie", 40, "Male", "17700630231", "789 Pine Road"},
					{"Diana", 22, "Female", "17700630234", "101112 Little Lane"},
					{"Edward", 29, "Male", "17700630238", "121 Big Street"},
					{"Cat", 22, "Male", "17700630235", "122 Big Street" } };

//打印一个菜单
void menu(void) {
	printf("************************************************************\n");
	printf("************1.增加联系人***********2.删除指定联系人*********\n");
	printf("************3.查找联系人***********4.修改联系人*************\n");
	printf("************5.排序*****************6.显示联系人*************\n");
	printf("************0.退出程序**************************************\n");
	printf("************************************************************\n");
	printf("请输入数字来执行对应操作：");
}

#if 1
//通讯录初始化——指针
Contact* ContactInit(int initCapacity) {		
	Contact* contacts = (Contact * )malloc(sizeof(Contact));	//为contact结构体分配空间

	if (contacts == NULL)
		return NULL;
	contacts->data = (Peo *)calloc(initCapacity, sizeof(Peo));
	if (contacts->data == NULL) {
		free(contacts);		//释放已分配的内存
		return NULL;	//分配失败
	}
	contacts->capacity = initCapacity;
	contacts->count = 0;
	
	for (int i = 0; i < Init_size; i++) {				//复制预设联系人
		if (i < initCapacity) {
			contacts->data[i] = PresentContacts[i];
			contacts->count++;
		}
	}
	return contacts;
}

#else
//通讯录初始化——柔性数组
Contact* ContactInit(int initCapacity) {	
	//Contact contacts;
	Contact contacts;
	Peo* ptr = calloc(initCapacity, sizeof(Peo));
	if (ptr == NULL) {
		printf("%s\n", strerror(errno));
		return;
	}
	contacts.data = ptr;
	for (int i = 0; i < Init_size; i++) {				//复制预设联系人
		if (i < initCapacity) {
			ptr[i] = PresentContacts[i];
			contacts.count++;
		}
	}
	return contacts;
}
#endif

#if 1
//1.增加联系人——指针
void AddPeople(Contact* pc) {
	assert(pc);				
	Peo per = { 0 };		//初始化
	int status = 1;			//默认有空闲内存
	if (pc->count == pc->capacity) {	//联系人数量等于通讯录容量时
		Peo* ptr = (Peo*)realloc(pc->data, sizeof(Peo) * (pc->capacity + 2));		//在原有容量基础上增加两个联系人的容量
		if (ptr == NULL)
			status = -1;		//分配失败
		else {
			pc->data = ptr;			//pc->data指向重新分配的内存地址
			pc->capacity += 2;	//更新通讯录容量
			printf("增容成功！\n");
		}
	}

	if (status == -1)
		printf("添加联系人失败！\n");
	else {
		//添加联系人操作
		printf("请输入姓名：");
		scanf("%49s", per.name);		//限制输入长度
		getchar();					//清除缓冲区中的换行符

		printf("请输入年龄：");
		scanf("%hd", &per.age);
		getchar();

		printf("请输入性别：");
		scanf("%9s", per.sex);
		getchar();

		printf("请输入电话：");
		scanf("%19s", per.telephone);
		getchar();

		printf("请输入地址：");
		fgets(per.address, sizeof(per.address), stdin);		//使用fgets读取地址
		per.address[strcspn(per.address, "\n")] = 0;		//去除换行符

		pc->data[pc->count++] = per;						//结构体赋值然后count++
	}
}
#else
//1.增加联系人——柔性数组
void AddPeople(Contact* pc) {
	assert(pc);
	Peo per = { 0 };		//初始化
	int status = 1;			//默认有空闲内存
	if (pc->count == pc->capacity) {	//联系人数量等于通讯录容量时
		Peo* ptr = (Peo*)realloc(pc->data, sizeof(Peo) * (pc->capacity + 2));		//在原有容量基础上增加两个联系人的容量
		if (ptr == NULL)
			status = -1;		//分配失败
		else {
			pc->data = ptr;			//pc->data指向重新分配的内存地址
			pc->capacity += 2;	//更新通讯录容量
			printf("增容成功！\n");
		}
	}

	if (status == -1)
		printf("添加联系人失败！\n");
	else {
		//添加联系人操作
		printf("请输入姓名：");
		scanf("%49s", per.name);		//限制输入长度
		getchar();					//清除缓冲区中的换行符

		printf("请输入年龄：");
		scanf("%hd", &per.age);
		getchar();

		printf("请输入性别：");
		scanf("%9s", per.sex);
		getchar();

		printf("请输入电话：");
		scanf("%19s", per.telephone);
		getchar();

		printf("请输入地址：");
		fgets(per.address, sizeof(per.address), stdin);		//使用fgets读取地址
		per.address[strcspn(per.address, "\n")] = 0;		//去除换行符

		pc->data[pc->count++] = per;						//结构体赋值然后count++
	}
}

#endif

//2.删除指定联系人
void DeletePeople(Contact* pc) {
	assert(pc);
	Peo per = { 0 };
	printf("请输入要删除的联系人姓名：");
	scanf("%49s", per.name);
	//找到要删除联系人在通讯录中的位置
	for (int i = 0; i < pc->count; i++) {
		if (strcmp(pc->data[i].name, per.name) == 0) {		//找到联系人
			for (int j = i; j < pc->count - 1; j++) {		//100个元素，j=99时，j+1就会越界；减一后虽不能用覆盖的方式删除第100个元素，但count--后就不会访问到第100个元素
				pc->data[j] = pc->data[j + 1];		//向前移动覆盖
			}
			pc->count--;
			printf("联系人已删除。\n");		
			return;
		}	
	}
	printf("要找的联系人不存在！\n");
}

//3.查找联系人
void SearchPeople(Contact* pc) {
	assert(pc);
	Peo per = { 0 };
	printf("请输入要查找联系人的姓名：");
	scanf("%49s", per.name);

	for (int i = 0; i < pc->count; i++) {
		if (strcmp(pc->data[i].name, per.name) == 0) {		//找到联系人
			printf("该联系人信息如下：\n");
			printf("姓名：%-10s\n年龄：%-6hd\n性别：%-10s\n电话：%-15s\n地址：%-20s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].telephone, pc->data[i].address);
			return;
		}
	}
	printf("联系人不存在。\n");
}

//4.修改联系人信息
void ModifyPeople(Contact* pc) {
	assert(pc);
	Peo per = { 0 };
	int n;		//确定要修改哪项信息
	printf("请输入要修改联系人的姓名：");		//判断该联系人是否存在
	scanf("%49s", per.name);
	for (int i = 0; i < pc->count; i++) {
		if (strcmp(pc->data[i].name, per.name) == 0) {		//找到联系人
			printf("您要修改的信息是：\n");
			printf("1.姓名\t2.年龄\t3.性别\t4.电话\t5.地址\t0.结束修改\n");
			do{
				printf("请输入选项：\n");
				scanf("%d", &n);
				getchar();		//清除换行符
				switch (n) {
					case 0:
						break;
					case 1:
						printf("请输入修改后的姓名：");
						scanf("%49s", per.name);
						getchar();		//清除换行符
						strcpy(pc->data[i].name, per.name);
						break;
					case 2:
						printf("请输入修改后的年龄：");
						scanf("%hd", &per.age);
						getchar();		//清除换行符
						pc->data[i].age = per.age;
						break;
					case 3:
						printf("请输入修改后的性别：");
						scanf("%9s", per.sex);
						getchar();		//清除换行符
						strcpy(pc->data[i].sex, per.sex);
						break;
					case 4:
						printf("请输入修改后的电话：");
						scanf("%15s", per.telephone);
						getchar();		//清除换行符
						strcpy(pc->data[i].telephone, per.telephone);
						break;
					case 5:
						printf("请输入修改后的地址：");
						fgets(per.address, sizeof(per.address), stdin);
						per.address[strcspn(per.address, "\n")] = 0;		//清除换行符
						strcpy(pc->data[i].address, per.address);
						break;
					default:
						printf("输入有误，请重新输入!\n");
				}
			} while (n);

			// 打印修改后的联系人信息以验证
			printf("修改后的联系人信息：\n");
			printf("姓名：%s\n", pc->data[i].name);
			printf("年龄：%hd\n", pc->data[i].age);
			printf("性别：%s\n", pc->data[i].sex);
			printf("电话：%s\n", pc->data[i].telephone);
			printf("地址：%s\n", pc->data[i].address);
			return;
		}
	}
	printf("联系人不存在。\n");
}

//5.排序
// 比较函数
//比较姓名		static限定该函数只能在这个.c文件内使用
static int CompareName(const void *a, const void *b) {
	assert(a);
	assert(b);
	Peo* pa = (Peo*)a;
	Peo* pb = (Peo*)b;
	return strcmp((*pa).name, (*pb).name);
}

//比较年龄
static int CompareAge(const void* a, const void* b) {
	assert(a);
	assert(b);
	return ((Peo*)a)->age - ((Peo*)b)->age;		//返回1是增序，返回-1是降序
}

//比较电话
static int CompareTel(const void* a, const void* b) {
	assert(a);
	assert(b);
	return strcmp(((Peo*)a)->telephone, ((Peo*)b)->telephone);
}

//比较地址
static int CompareAddress(const void* a, const void* b) {
	assert(a);
	assert(b);
	return strcmp(((Peo*)a)->address, ((Peo*)b)->address);
}

//排序函数
void SortPeople(Contact* pc) {
	assert(pc);
	int n;		//定义选项
	printf("您想根据哪项信息进行排序：\n");
	printf("1.姓名\t2.年龄\t3.电话\t4.地址\n");
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
		printf("您的输入有误！\n");
	}

	//打印排序后的联系人
	printf("排序后的联系人信息如下：\n");
	PrintPeople(pc);
}

//6.显示联系人
void PrintPeople(Contact* pc) {
	assert(pc);
	// 打印数组中所有联系人的信息
	for (int i = 0; i < pc->count; i++) {
		printf("%10s%6hd%10s%15s%20s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].telephone, pc->data[i].address);
	}
}

//7.内存释放
void DelBlock(Contact* pc) {
	assert(pc);
	free(pc->data);
	pc->data = NULL;		//编程需要，减少不必要风险
}