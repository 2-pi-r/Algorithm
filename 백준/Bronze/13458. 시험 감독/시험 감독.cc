#include <iostream>
#include <vector>

using namespace std;

int main() {
	// input
	int N, B, C;
	cin >> N;

	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> B >> C;

	// solution
	long long result = 0;
	for (int i = 0; i < N; i++) {
		result += 1; // 총감독관
		if (B >= A[i]) continue;
		A[i] -= B;
		result += (A[i] % C == 0)? (A[i] / C): (A[i] / C) + 1; // 부감독관
	}

	// output
	cout << result;
	return 0;
}