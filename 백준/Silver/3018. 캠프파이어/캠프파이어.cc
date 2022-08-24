#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void newSong(int E, vector<int> &m, vector<set<int>> &know) {
	for (int i = 0; i < m.size(); i++) {
		know[m[i]].insert(E);
	}
}

void shareSong(vector<int>& m, vector<set<int>>& know) {
	set<int> all;
	for (int i = 0; i < m.size(); i++) {
		for (int song : know[m[i]]) {
			all.insert(song);
		}
	}
	for (int i = 0; i < m.size(); i++) {
		for (int song : all) {
			know[m[i]].insert(song);
		}
	}
}


int main() {
	int N; cin >> N;
	int E; cin >> E;
	vector<set<int>> knowSongs(N + 1);
	vector<int> result;

	while(E--) {
		int K; cin >> K;
		vector<int> member(K);

		for (int k = 0; k < K; k++)
			cin >> member[k];
		sort(member.begin(), member.end());

		if (member[0] == 1) {//선영 있으면
			newSong(E, member, knowSongs);
		}
		else { //선영 없으면
			shareSong(member, knowSongs);
		}
	}

	for (int i = 1; i <= N; i++) {
		if (knowSongs[i].size() == knowSongs[1].size())
			result.push_back(i);
	}

	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}

	return 0;
}