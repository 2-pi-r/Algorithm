#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	int N; cin >> N;
	deque<int> dq;
	string input;

	for (int i = 0; i < N; i++)
	{
		cin >> input; //명령 입력

		if (input == "push_front") { //정수 X를 덱의 앞에 넣는다.
			int X;  cin >> X;
			dq.push_front(X);
		}

		else if (input == "push_back") { //정수 X를 덱의 뒤에 넣는다.
			int X;  cin >> X;
			dq.push_back(X);
		}

		else if (input == "pop_front") { //덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다.
			if (dq.empty()) //만약, 덱에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
				cout << -1 << endl;
			else {
				cout << dq.front() << endl;
				dq.pop_front();
			}
		}

		else if (input == "pop_back") { //덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다.
			if (dq.empty()) //만약, 덱에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
				cout << -1 << endl;
			else {
				cout << dq.back() << endl;
				dq.pop_back();
			}
		}

		else if (input == "size") { //덱에 들어있는 정수의 개수를 출력한다.
			cout << dq.size() << endl;
		}

		else if (input == "empty") { //덱이 비어있으면 1을, 아니면 0을 출력한다.
			if (dq.empty())
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}

		else if (input == "front") { //덱의 가장 앞에 있는 정수를 출력한다.
			if (dq.empty()) //만약, 덱에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
				cout << -1 << endl;
			else
				cout << dq.front() << endl;
		}

		else if (input == "back") { //덱의 가장 뒤에 있는 정수를 출력한다.
			if (dq.empty()) //만약, 덱에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
				cout << -1 << endl;
			else
				cout << dq.back() << endl;
		}
	}

	return 0;
}