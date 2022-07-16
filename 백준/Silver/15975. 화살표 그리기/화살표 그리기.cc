#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	vector<vector<int>> point(N + 1); //point[i] : 색깔 i인 점의 좌표들

	/*점 정보 입력받기*/
	int x, y;
	for (int n = 0; n < N; n++) { //N번 반복
		cin >> x >> y; //좌표 x, 색깔 y
		point[y].push_back(x);
	}

	/*정렬하기, 화살표 거리 합 구하기*/
	long long sum = 0;
	int left, right, J;
	for (int i = 1; i <= N; i++) {
		J = point[i].size();
		if (J == 0 || J == 1)
			continue; //1이면 sum += 0이므로.

		sort(point[i].begin(), point[i].end());
		sum += point[i][1] - point[i][0];
		sum += point[i][J - 1] - point[i][J - 2];
		for (int j = 2; j < J; j++) {
			right = point[i][j] - point[i][j - 1];
			left = point[i][j - 1] - point[i][j - 2];
			sum += min(right, left);
		}
	}

	cout << sum;

	return 0;
}