#include <iostream>
#include <vector>

using namespace std;

int n, s;
int arr[20]; // 주어진 수열
int sum = 0, cnt = 0;

void solve(int curr_idx) {
	// base case
	if (curr_idx == n && sum == s) { // 오답: (curr_idx == n) 조건을 추가해야 했다.
		cnt++;
		return;
	}
	if (curr_idx >= n) return;

	// 더한 경우
	sum += arr[curr_idx];
	solve(curr_idx + 1);

	// 안 더한 경우
	sum -= arr[curr_idx];
	solve(curr_idx + 1);
}

int main() {
	/*input*/
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	/*solution*/
	solve(0);
	if (s == 0) cnt--; // 오답: 부분수열 길이는 양수여야 하므로, 아무것도 안 고른 경우는 빼줘야 한다.
	cout << cnt;

	return 0;
}