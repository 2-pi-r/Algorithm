#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
	/*input*/
	int n; cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	/*solution*/
	deque<int> dq; // 손에 들고 있던 카드
	int curr_card, temp;

	for (int i = 0; i < n; i++) {
		curr_card = i + 1; // curr : 바닥에 있는 카드 중 맨 위 카드
		switch (v[n - i - 1]) // 최근 연산부터 순서대로
		{
		case 1: // 맨 위로
			dq.push_front(curr_card);
			break;
		case 2: // 위에서 두번째로
			temp = dq.front();
			dq.pop_front();
			dq.push_front(curr_card);
			dq.push_front(temp);
			break;
		case 3: // 맨 밑으로
			dq.push_back(curr_card);
			break;
		}
	}

	/*output*/
	for (int i = 0; i < n; i++) {
		cout << dq[i] << " ";
	}

	return 0;
}