#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, long long> P;

int N, K;

bool compare(P x, P y) {
	if (x.second == y.second)
		return x.first == K;
	return x.second > y.second;
}

int findIndex(vector<P> &v, int country) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first == country)
			return i;
	}
}

int main() {
	cin >> N >> K; //국가의 수, 등수를 알고 싶은 국가
	vector<P> medal(N + 1);

	int country, gold, silver, bronze;
    long long M = 1000000; //전체 메달 수의 총합은 1,000,000 이하
	while (N--) {
		cin >> country >> gold >> silver >> bronze;
		medal.push_back( { country, M*M*gold + M*silver + 1*bronze} );
	}

	sort(medal.begin(), medal.end(), compare); //내림차순 + 같은 점수면 K나라가 우선.

	cout << findIndex(medal, K) + 1;

	return 0;
}