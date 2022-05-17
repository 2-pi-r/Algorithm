#include <iostream>

using namespace std;

int dr[4] = { 0, 1, 0, 1 };
int dc[4] = { 0, 0, 1, 1 };

int paper[128][128]; //전체 종이 정보 저장
int result[2] = { 0, 0 }; //result[0] = 하얀색 색종이 개수, result[1] = 파란색 ~~


void cut(int r, int  c, int  l) { //맨 왼쪽 위 칸의 위치(r, c), 색종이 한 변 길이(l)
	int value = paper[r][c]; //첫번째칸(왼쪽 위) 값

	/*base case*/
	if (l == 1) {
		result[value]++;
		return;
	}

	/*모든 칸 같은지 확인*/
	bool flag = true;
	for (int i = r; i < r + l && flag; i++) { // && flag --> flag = false 한 이후로는 탈출 (break이랑 같은 효과)
		for (int j = c; j < c + l; j++) {
			if (value != paper[i][j]) {
				flag = false;
				break;
			}
		}
	}

	/*개수 업데이트 or 다음 함수 호출*/
	if (flag) {
		result[value]++;
	}
	else {
		int m = l / 2;
		for (int i = 0; i < 4; i++)
			cut(r + m * dr[i], c + m * dc[i], m);
	}

	return;
}

int main() {
	int N; cin >> N;

	/*전체 종이 입력받기*/
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}

	cut(0, 0, N);

	cout << result[0] << endl << result[1];

	return 0;
}
