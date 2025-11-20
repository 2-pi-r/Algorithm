#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max(int a, int b) {
	return (a >= b) ? a : b;
}

int main() {
	/*input*/
	int n; cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	/*solution*/
	sort(v.begin(), v.end(), greater<int>());

	int over_date = 0, today, finish_day;
	for (int i = 0; i < n; i++) {
		today = i + 1;
		finish_day = today + v[i];
		over_date = max(over_date, finish_day - n);
	}

	cout << n + over_date + 1; // 심는 날 + 자라는 데 추가로 필요한 날 + 다음날

	return 0;
}