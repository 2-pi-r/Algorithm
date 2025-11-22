#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef pair<int, int> P;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int n;
char arr[101][101] = { 0 };

int solve(bool is_color_blind) {
	int visited[101][101] = { 0 };

	stack<P> st;
	int currR, currC, nr, nc;
	char curr_color, next_color;
	bool is_same_color;
	int cnt = 0; // 연결 요소 개수

	for (int start_r = 0; start_r < n; start_r++) {
		for (int start_c = 0; start_c < n; start_c++) {
			if (visited[start_r][start_c]) continue;
			cnt++; // 연결 요소 개수
			
			// DFS
			st.push(P(start_r, start_c));
			visited[start_r][start_c] = 1;

			while (!st.empty()) {
				currR = st.top().first;
				currC = st.top().second;
				st.pop();

				for (int i = 0; i < 4; i++) {
					nr = currR + dx[i];
					nc = currC + dy[i];

					if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
					if (visited[nr][nc]) continue;

					// is_same_color 구하기
					curr_color = arr[currR][currC];
					next_color = arr[nr][nc];
					if (!is_color_blind)
						is_same_color = (curr_color == next_color);
					else
						is_same_color = ((curr_color == 'B') == (next_color == 'B'));
					// 연결된 노드 (색상 동일) 아니면
					if (!is_same_color) continue;

					st.push(P(nr, nc));
					visited[nr][nc] = 1;
				}
			}
		}
	}

	return cnt;
}


int main() {
	/*input*/
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	
	/*solution*/
	cout << solve(false) << " " << solve(true);

	return 0;
}