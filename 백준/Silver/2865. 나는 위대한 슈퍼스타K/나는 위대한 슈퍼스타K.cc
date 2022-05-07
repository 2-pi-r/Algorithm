#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool standard(float a, float b) {
	return a > b;
}

int main() {
	int N, M, K; cin >> N >> M >> K; // 예선 참가자 머릿수, 장르 개수, 본전 진출자 머릿수

	int i; double s; // i: 참가자의 번호, s: 참가자의 장르에 대한 능력
	vector<double> v(N + 1); // 각 참가자별 능력치 중 최댓값 (0으로 자동 초기화)
	double sum = 0; // 본선 참가자의 능력의 합

	while (M--) {
		for(int num = 0; num < N; num++){
			cin >> i >> s;
			if (v[i] < s)
				v[i] = s;
		}
	}

	sort(v.begin(), v.end(), standard);
	for (int idx = 0; idx < K; idx++)
		sum += v[idx];

	cout << fixed;
	cout.precision(1);
	cout << sum;

	return 0;
}