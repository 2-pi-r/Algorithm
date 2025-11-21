#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	/*input*/
	int n; cin >> n;

	vector<int> card(n);
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	int m; cin >> m;

	vector<int> num(m);
	for (int i = 0; i < m; i++) {
		cin >> num[i];
	}
	
	/*solution*/
	sort(card.begin(), card.end());

	int cnt;
	vector<int>::iterator lb_iter, ub_iter;
	for (int i = 0; i < m; i++) {
		lb_iter = lower_bound(card.begin(), card.end(), num[i]);
		if (lb_iter != card.end()) {
			ub_iter = upper_bound(card.begin(), card.end(), num[i]);
			cnt = ub_iter - lb_iter;
		}
		else {
			cnt = 0;
		}
		cout << cnt << " ";
	}

	return 0;
}