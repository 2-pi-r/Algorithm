#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	/*input*/
	int n; cin >> n;
	int e; cin >> e;

	vector<int> edge[101];
	int visited[101] = { 0 };

	stack<int> st;

	// V 집합: 1~N 자연수
	// E 집합: 
	int a, b;
	for (int i = 0; i < e; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a); // 오답: 간선에 방향X
	}
	
	/*solution*/
	st.push(1);
	visited[1] = 1;

	int curr, cnt=0;
	while (!st.empty()) {
		curr = st.top();
		st.pop();

		for (int next : edge[curr]) {
			if (visited[next]) continue;
			
			st.push(next);
			visited[next] = 1;
			cnt++; // 1번 컴퓨터 빼고 세므로 이 위치에
		}

	}

	/*output*/
	cout << cnt;

	return 0;
}