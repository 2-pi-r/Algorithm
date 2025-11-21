#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[7]; // 고른 숫자 저장

void solve(int idx) {
	if (idx == m) { // base case: m개 다 고름 → 부분수열 출력하고 끝
		for (int i = 0; i < m; i++) cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int curr = 1; curr <= n; curr++) { // idx에 curr 고른 경우 탐색
		arr[idx] = curr;
		solve(idx + 1);
	}
}

int main() {
	/*input*/
	cin >> n >> m;

	/*solution*/
	solve(0);

	return 0;
}