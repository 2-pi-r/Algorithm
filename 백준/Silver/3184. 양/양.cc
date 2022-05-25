#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

char arr[250][250]; //마당의 구조 저장
int visited[250][250] = { 0 };
int wolf, sheep; //특정 구역의 늑대, 양의 수
int resultWolf = 0, resultSheep = 0; //최종 결과 (늑대, 양의 수)

void bfs(int startR, int startC, int R, int C);

int main() {
	int R, C; cin >> R >> C;

	/*마당의 구조(울타리, 양, 늑대의 위치) 입력받기*/
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char input; cin >> input;
			arr[i][j] = input;

			if(input == '#') {
				visited[i][j] = 1; //울타리는 지나갈 수 없음.
			}
		}
	}

	/*탐색*/
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (visited[i][j]) { continue; }
			bfs(i, j, R, C); //같은 영역에 속하는 늑대, 양의 수 구하기

			if (sheep > wolf) 	{ resultSheep += sheep;	} //양이 이긴 경우 : 양 살아남음, 늑대 퇴출
			else						{ resultWolf += wolf; }  //그렇지 않은 경우 : 양 잡아먹힘, 늑대 남아있음
			                                                                   //양, 늑대 없는 경우는 += wolf 해도 어차피 += 0라서 문제X
		}
	}

	/*결과 출력*/
	cout << resultSheep << " " << resultWolf;

	return 0;
}

void bfs(int startR, int startC, int R, int C) {
	queue<pair<int, int>> q;
	wolf = 0; sheep = 0; //초기화

	q.push({ startR, startC });
	if (arr[startR][startC] == 'v') { wolf++; }
	if (arr[startR][startC] == 'o') { sheep++; }
	visited[startR][startC] = 1;

	while (!q.empty()) {
		int currR = q.front().first;
		int currC = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nextR = currR + dr[k];
			int nextC = currC + dc[k];

			if (nextR < 0 || nextC < 0 || nextR >= R || nextC >= C) { continue; }
			if (visited[nextR][nextC]) { continue; }

			visited[nextR][nextC] = 1;
			if (arr[nextR][nextC] == 'v') { wolf++; }
			if (arr[nextR][nextC] == 'o') { sheep++; }
			q.push({ nextR, nextC });
		}
	}
}