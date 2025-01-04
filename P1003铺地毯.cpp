// 创建时间：2025/1/3 20:00:05
//没有AC，两个测试用例都能过，题解中可以用4个数组类分别存储a,b,g,k4个数据
#include <iostream>

using namespace std;

int main()
{
	int n;//地毯数
	int k = -1;//
	int x, y;//所求点坐标

	cin >> n;
	int (*arr)[4] = new int[n+1][4];//创建大小为n的数组，数组中元素为int[4]

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
