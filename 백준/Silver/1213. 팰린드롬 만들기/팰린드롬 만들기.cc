#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	/* input */
	string str;
	cin >> str;
	
	/* solve */
	// alpha_count 구하기
	vector<int> alpha_count(26, 0);
	for (int i = 0; i < str.size(); i++) {
		alpha_count[str.at(i) - 'A']++;
	}
	// part1,2 구하기
	string part1 = "", part2 = "", part3;
	for (int i = 0; i < 26; i++) {
		if (alpha_count[i] % 2 == 1) {
			if (!part2.empty()) {
				cout << "I'm Sorry Hansoo";
				return 0;
			}
			else { 
				part2 = ('A' + i); 
			}
		}
		//part1 += ('A' + i) * (alpha_count[i] / 2); // 파이썬이랑 다르게 곱셈 안 됨
		part1.append((alpha_count[i] / 2), ('A' + i));
	}
	// part3 구하기
	part3 = part1;
	reverse(part3.begin(), part3.end());

	/* output */
	cout << (part1 + part2 + part3);

	return 0;
}