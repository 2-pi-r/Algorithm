#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check(string str) {
	for (int i = 0; i < (str.size()/ 2); i++) {
		if (str[i] != str[str.size() - 1 - i]) return false;
	}
	return true;
}

void solution() {
	int k; cin >> k;

	vector<string> voca(k);
	for (int i = 0; i < k; i++) {
		cin >> voca[i];
	}

	// solution
	//bool is_found = false;

	for (int i = 0; i < k; i++) {
	//for (int i = 0; i < k && !is_found; i++) {
		for (int j = 0; j < k; j++) {
			if (i == j)
				continue;
			if (check(voca[i] + voca[j])) {
				cout << voca[i] + voca[j] << "\n";
				return;
				//is_found = true;
				//break;
			}
		}
	}
	cout << "0\n";
}

int main() {
	// input
	int T; cin >> T;

	for (int t = 0; t < T; t++) {
		solution();
	}

	return 0;
}