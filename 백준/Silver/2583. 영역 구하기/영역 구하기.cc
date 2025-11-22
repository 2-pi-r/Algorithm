#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int arr[101][101] = { 0 }; // 모눈종이
//int visited[101][101] = { 0 }; // arr값 0인 영역 탐사라서 arr를 visited처럼 씀


int main() {
	/*input*/
	int m; cin >> m; // row (y) 개수
	int n; cin >> n; // col (x) 개수
	int k; cin >> k;

	int x1, y1, x2, y2;
	for (int i = 0; i < k; i++) { // k번 입력
		cin >> x1 >> y1 >> x2 >> y2;

		for (int x = x1; x < x2; x++) {
			for (int y = y1; y < y2; y++) {
				arr[y][x]++;
			}
		}
	}

	
	/*solution*/
	vector<int> ereas; // 영역(연결 요소)별 넓이

	int currR, currC, nr, nc;

	for (int start_r = 0; start_r < m; start_r++) {
		for (int start_c = 0; start_c < n; start_c++) {
			
			if (arr[start_r][start_c]) continue; // visited
			int erea = 0; // 해당 영역의 넓이

			// DFS
			stack<P> st;

			st.push(P(start_r, start_c));
			arr[start_r][start_c] = 1;
			erea++;

			while (!st.empty()) {
				currR = st.top().first;
				currC = st.top().second;
				st.pop();

				for (int i = 0; i < 4; i++) {
					nr = currR + dx[i];
					nc = currC + dy[i];

					if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
					if (arr[nr][nc]) continue; // visited

					st.push(P(nr, nc));
					arr[nr][nc] = 1; // visited
					erea++;
				}
			}
			ereas.push_back(erea); // 영역 넓이
		}
	}

	sort(ereas.begin(), ereas.end());
	cout << ereas.size() << "\n"; // 영역 개수
	for (int erea: ereas) cout << erea << " "; // 영역별 넓이

	return 0;
}