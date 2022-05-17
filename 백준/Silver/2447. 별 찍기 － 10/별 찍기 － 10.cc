#include<iostream>
#include<string>

using namespace std;

void star(int x, int y, int n, char** arr)
{
	/*base case*/
	if (n == 1) {
		arr[x][y] = '*';
		return;
	}

	/*9개로 쪼개서, 가운데 빼고 나머지 8번 재귀*/
	for (int i = 0; i < n; i += n / 3)
		for (int j = 0; j < n; j += n / 3) {
			if (i == n / 3 && j == n / 3)
				continue;
			star(x + i, y + j, n / 3, arr);
		}
}

int main() {
	int N; cin >> N;
	
	char** arr = new char* [N]; //전역변수, 2차원 배열, 동적할당
	for (int i = 0; i < N; i++)
		arr[i] = new char[N];
	
	for (int i = 0; i < N; i++) ////전부 공백으로 초기화
		for (int j = 0; j < N; j++)
			arr[i][j] = ' ';

	star(0, 0, N, arr);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << arr[i][j];
		cout << endl;
	}

	return 0;
}