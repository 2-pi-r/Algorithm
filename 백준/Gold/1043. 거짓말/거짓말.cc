#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	/*input*/
	int N, M; cin >> N >> M; //사람의 수, 파티의 수
	bool people[51] = { false }; //각 사람이 진실을 아는지
	bool party[51] = { false }; //각 파티에서 진실을 말해야 하는지
	vector<vector<int>> member(M); //각 파티에 누가 오는지

	int T; cin >> T; //진실을 아는 사람 수
	while(T--) {
		int input; cin >> input;
		people[input] = true;
	}

	for (int i = 0; i < M; i++) {
		int m; cin >> m; //i번째 파티에 오는 사람 수
		while(m--) {
			int input; cin >> input;
			member[i].push_back(input);
		}
	}


	/*solve*/
	for (int i = 0; i < M; i++) {
		bool isThereTruth = false; //진실을 아는 사람이 파티에 오는지
		for (int j = 0; j < member[i].size(); j++) {
			if (people[member[i][j]]) {
				isThereTruth = true;
				party[i] = true;
				break;
			}
		}

		if (!isThereTruth) { continue; } //안 온다면 상관없고,

		for (int j = 0; j < member[i].size(); j++) { //온다면
			if (people[member[i][j]] == false) {
				people[member[i][j]] = true; //그 파티의 모든 참석자는 지민이한테 진실을 듣게 됨.
				//근데 이번에 true로 바꿔준 사람들은, 여태까지는 배열 값이 false여서 넘어갔었음.
				i = -1; // 그러므로 첫번째 파티부터 다시 반복문 돌기.
			}
		}
	}


	int cnt = 0;
	for (int i = 0; i < M; i++) {
		if (!party[i])
			cnt++;
	}
	cout << cnt;


	return 0;
}