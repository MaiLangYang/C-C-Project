// ����ʱ�䣺2025/1/3 20:00:05
//û��AC�����������������ܹ�������п�����4��������ֱ�洢a,b,g,k4������
#include <iostream>

using namespace std;

int main()
{
	int n;//��̺��
	int k = -1;//
	int x, y;//���������

	cin >> n;
	int (*arr)[4] = new int[n+1][4];//������СΪn�����飬������Ԫ��Ϊint[4]

	for(int i=1;i <= n;i++)
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
		}

	cin >> x >> y;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 4; j++) {
			if (x >= arr[i][j] && x <= arr[i][j + 2] && y >= arr[i][j + 1] && y <= arr[i][j + 3])
				k = i;
		}
	cout << k;
	return 0;
}
