#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[10001];

int Find(int a) {
	if (parent[a] == a)
		return a;
	parent[a] = Find(parent[a]); //union-find 최적화
	return parent[a];
}

void Union(int a, int b) {
	parent[Find(a)] = Find(b);
}

bool IsSameParents(int a, int b) {
	if (Find(a) == Find(b))
		return true;
	else
		return false;
}

int main() {
	int V, E; cin >> V >> E; //정점 개수, 간선 개수
	int A, B, C, result = 0;
	vector<pair<int, pair<int, int>>> edge;
	
	/*parent 배열 초기화*/
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	/*간선 입력받기*/
	while(E--) {
			cin >> A >> B >> C;
			edge.push_back({ C, {A, B} });
	}

	/*solve*/
	sort(edge.begin(), edge.end());
	for (int i = 0, cnt = 0; i < edge.size() && cnt < V; i++) {
		A = edge[i].second.first;
		B = edge[i].second.second;
		C = edge[i].first;

		if (!IsSameParents(A, B)) { //사이클 발생X이면 해당 간선 선택
			Union(A, B);
			result += C;
			cnt++; //선택한 간선 개수
		}
	}

	cout << result;

	return 0;
}