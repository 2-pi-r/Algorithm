#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	// input
	int N;
	cin >> N;

	vector<int> X(N);
	for (int i = 0; i < N; i++) {
		cin >> X[i];
	}

	// solution
	vector<int> s = X;
	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end()); // 중복 제거

	for (int i = 0; i < N; i++) {
		cout << lower_bound(s.begin(), s.end(), X[i]) - s.begin() << " ";
	}

	return 0;
}