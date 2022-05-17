#include <iostream>
using namespace std;

int color[128][128]; //전체 종이에서 각 칸의 색
int white = 0, blue = 0; //각각 색종이 개수

int isCompletePaper(pair<int, int> p, int n) //시작점 좌표, 변 길이
{
	int start = color[p.first][p.second];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (color[p.first + i][p.second + j] != start)
				return -1; //전부 같은 색인 건 아닌 경우.

	if (start == 0)
		white++;
	if (start == 1)
		blue++;
	return 1; //전부 같은 색인 경우.
}

void numOfPaper(pair<int, int> p, int n) //시작점 좌표, 변 길이
{
	if(isCompletePaper(p, n) == 1) //base case
		return;

	//아니면 한 번 더 쪼개야 함.
	for (int i = 0; i < n; i += n / 2) // i = 0, i = n / 2
		for (int j = 0; j < n; j += n / 2) // j = 0, j = n / 2
			numOfPaper({p.first + i, p.second + j}, n / 2);
}

int main()
{
	/*입력 받기*/
	int N; cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> color[i][j];

	/*본론*/
	numOfPaper({ 0, 0 }, N);

	/*출력하기*/
	cout << white << endl << blue << endl;

	return 0;
}