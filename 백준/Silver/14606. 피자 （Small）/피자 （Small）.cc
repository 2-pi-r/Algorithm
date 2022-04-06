#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N; cin >> N;
	vector<int> d(N + 1); //자동으로 0으로 초기화됨.
	//d(n) : 높이n 피자판 분리하면서 얻은 "즐거움 총합의 최댓값"

	for (int curr = 2; curr <= N; curr++) //base case : d[1] = 0
		for (int k = 1; k <= curr / 2; k++)
			d[curr] = max(d[curr], k * (curr - k) + d[k] + d[curr - k]);

	cout << d[N];
	return 0;
}