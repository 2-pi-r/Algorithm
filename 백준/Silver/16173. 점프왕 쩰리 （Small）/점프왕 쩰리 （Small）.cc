#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int dr[2] = {1, 0}; // (k = 0) → / (k = 1) ↓ 이동
int dc[2] = {0, 1};

int arr[3][3]; //게임판의 맵 저장
int visited[3][3] = { 0 }; //0으로 초기화
bool flag = false; //쩰리가 끝 점에 도달할 수 있으면 true

void dfs(int startR, int startC, int N);

int main() {
	int N; cin >> N;

	/*게임판의 맵 입력받기*/
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	/*쩰리가 끝 점에 도달할 수 있는지 탐색*/
	dfs(0, 0, N);

	/*결과 출력*/
	cout << ((flag) ? "HaruHaru" : "Hing");

	return 0;
}

void dfs(int startR, int startC, int N) {
	stack<pair<int, int>> st;

	st.push({ startR, startC });
	visited[startR][startC] = 1;

	while (!st.empty()) {
		int currR = st.top().first;
		int currC = st.top().second;
		st.pop();

		int move = arr[currR][currC];
		if (move == 0) { continue; } //nextR, nextC를 따지는 게 불가능함.
		if (move == -1) { //끝 점에 도착
			flag = true;
			break;
		}

		for (int k = 0; k < 2; k++) {
			int nextR = currR + move * dr[k];
			int nextC = currC + move * dc[k];

			if (nextR < 0 || nextC < 0 || nextR >= N || nextC >= N) { continue; }
			if (visited[nextR][nextC]) { continue; }

			visited[nextR][nextC] = 1;
			st.push({ nextR, nextC });
		}
	}
}