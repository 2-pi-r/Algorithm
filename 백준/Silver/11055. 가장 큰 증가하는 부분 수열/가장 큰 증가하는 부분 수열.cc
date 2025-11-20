#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) {
	return (a >= b) ? a : b;
}

int main() {
	/*input*/
	int n; cin >> n;

	vector<int> v(n);
	vector<int> dp(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

    /*solution*/
    // dp 구하기
	for (int i = 0; i < n; i++) {
		// dp[k]의 max값 구하기
		int max_dp_k = 0;
		for (int k = i - 1; k >= 0; k--) {
			if (v[k] < v[i]) {
				max_dp_k = max(max_dp_k, dp[k]);
			}
		}
		// dp[i] 구하기
		dp[i] = max_dp_k + v[i];
	}
	// result 구하기
	int result = 0;
	for (int i = 0; i < n; i++) {
		result = max(result, dp[i]);
	}
	cout << result;

	return 0;
}