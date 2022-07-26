#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(int n, vector<int> &v, int left, int right) {
	while (left <= right) {
		int mid = (left + right) / 2;
		if (n == v[mid])
			return 1; //찾았음
		if (n < v[mid])
			right = mid - 1;
		if (n > v[mid])
			left = mid + 1;
	}
	return 0; //못 찾았음
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int N; cin >> N;
	vector<int> num(N); //숫자 카드의 값들

	/*입력받기*/
	for(int i =0; i < N; i++) {
		cin >> num[i];
	}

	/*정렬하기*/
	sort(num.begin(), num.end());

	/*탐색하기*/
	int M; cin >> M;
	int input;
	while (M--) {
		cin >> input;
		cout << binarySearch(input, num, 0, N - 1) << " ";
	}

	return 0;
}