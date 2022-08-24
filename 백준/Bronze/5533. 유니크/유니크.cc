#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N; cin >> N;
	vector<int> score(N);
	int input[3][201];
	int isThere[3][101] = {0};

	for (int i = 0; i < N; i++) {
		for (int turn = 0; turn < 3; turn++) {
			cin >> input[turn][i];
			isThere[turn][input[turn][i]]++;
		}
	}

	for (int turn = 0; turn < 3; turn++) {
		for (int i = 0; i < N; i++) {
			if (isThere[turn][input[turn][i]] == 1)
				score[i] += input[turn][i];
		}
	}

	
	for (int i = 0; i < N; i++) {
		cout << score[i] << "\n";
	}

	return 0;
}