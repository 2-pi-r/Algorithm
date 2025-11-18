#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	/* input */
	int N, sum=0;
	cin >> N;
	
	vector<int> p(N);
	for (int i = 0; i < N; i++) {
		cin >> p[i];
	}

	/* solve */
	sort(p.begin(), p.end(), greater<int>()); // 내림차순
	for (int i = 0; i < N; i++) {
		sum += p[i] * (i+1);
	}

	/* output */
	cout << sum;

	return 0;
}