#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	/*input*/
	int n; cin >> n;
	int m; cin >> m;

	vector<int> adj[1001];
	int visited[1001] = { 0 };

	stack<int> st;

	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u); // 간선에 방향X
	}
	
	/*solution*/
	int curr, cnt=0;
	for(int i = 1; i <= n; i++){
		if (visited[i]) continue;

		cnt++; // 연결 요소 개수

		// DFS
		st.push(i);
		visited[i] = 1;
		while (!st.empty()) {
			curr = st.top();
			st.pop();

			for (int next : adj[curr]) {
				if (visited[next]) continue;
				st.push(next);
				visited[next] = 1;
			}
		}

	}

	/*output*/
	cout << cnt;

	return 0;
}