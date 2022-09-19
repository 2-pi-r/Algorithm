#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	string str; cin >> str;
	stack<int> st;
	int answer = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(' && str[i + 1] != ')') //막대 시작
			st.push(str[i]);

		else if (str[i] == ')' && str[i - 1] == '(') { //레이저
			answer += ((!st.empty())? st.size(): 0);
		}
		
		else if (str[i] == ')' && !st.empty() && st.top() == '(') { //막대 끝
			st.pop();
			answer += 1;
		}
	}

	cout << answer;

	return 0;
}