// ����ʱ�䣺2025/1/3 20:42:49
#include <iostream>

using namespace std;
#if 0
//�����ݹ飬��ʱ
int cnt = 0;
void fun(int n) {
	if (n < 1)
		return;
	for (int i = 1; i <= n / 2; i++){
		fun(i);
		cnt++;
	}
}

int main()
{
	int n;
	cin >> n;
	fun(n);
	cout << cnt;
	return 0;
}
#elif 1
//Ӧ�ҵ����ƹ�ϵʽ��ʹ�õ���
int main() {
	int n,f[1010];
	f[0] = f[1] = 1;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		if (i % 2 == 0)
			f[i] = f[i - 1] + f[i / 2];
		else
			f[i] = f[i - 1];
	}
	cout << f[n];
	return 0;
}
#endif
