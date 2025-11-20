#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) {
	return (a >= b) ? a : b;
}

int main() {
	// input
	int n; cin >> n;

	vector<vector<int>> v(n);
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> temp;
			v[i].push_back(temp);
		}
	}

	// solution
	vector<vector<int>> dp(n);

	dp[0].push_back(v[0][0]); // base case

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				temp = dp[i - 1][j] + v[i][j];
			}
			else if (j == i) {
				temp = dp[i - 1][j - 1] + v[i][j];
			}
			else {
				temp = max(dp[i - 1][j - 1], dp[i - 1][j]) + v[i][j];
			}
			dp[i].push_back(temp);
		}
	}
	
	int i = n - 1;
	int result = dp[i][0];
	for (int j = 1; j <= i; j++) {
		result = max(result, dp[i][j]);
	}
	cout << result;

	return 0;
}