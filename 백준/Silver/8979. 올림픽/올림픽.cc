#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, K; cin >> N >> K; //국가의 수, 등수를 알고 싶은 국가
	vector<long long> medal(N + 1);

	int country, gold, silver, bronze;
    long long M = 1000000; //전체 메달 수의 총합은 1,000,000 이하
	while (N--) {
		cin >> country >> gold >> silver >> bronze;
		medal[country] = M*M*gold + M*silver + bronze;
	}

	int result = 0;
	for (int i = 1; i < medal.size(); i++) {
		if (medal[i] > medal[K])
			result++;
	}
	cout << result + 1;

	return 0;
}