#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	/*input*/
	int n; cin >> n;
	long long k; cin >> k;

	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	/*solution*/
	sort(v.begin(), v.end()); // 그리디로 풀어봤음. 시간 초과가 날지도?

	long long t = v[0];
	long long need; // t=v[i]가 되도록 v[0]~v[i-1]들을 v[i]까지 레벨업시키는 데 필요한 레벨 수

	for (int i = 1; i < n; i++) {
		if (v[i - 1] == v[i]) continue;
		need = (v[i] - v[i - 1]) * (long long)i;

		if (k >= need) { // k가 충분히 남았으면 -> v[i]까지 레벨업
			t = v[i];
			k -= need;
			if (k == 0) break;
		}else { // 부족하면 -> 가능한 만큼만 레벨업
			t += k / i;
			k = 0;
			break;
		}
	}

	if (k > 0) { // t = v[n-1]인데도 여전히 k가 남아있으면
		t += k / n;
	}

	cout << t;

	return 0;
}