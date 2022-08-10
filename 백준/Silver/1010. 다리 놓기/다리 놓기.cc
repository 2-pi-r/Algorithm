#include <iostream>

using namespace std;

int main() {
	int T; cin >> T;

	while (T--) {
		int N, M; cin >> N >> M;
		long long result = 1; //다리 개수 = 조합 mCn

		if (N > M / 2) // //N이 너무 클 때는 long long으로 커버 불가
			N = M - N; //mCm-n로 계산
		for (int i = M; i > M - N; i--)
			result *= i;
		for (int i = 1; i <= N; i++)
			result /= i;

		cout << result << "\n";
	}

	return 0;
}