#include <iostream>
#include <vector>

using namespace std;

int main() {
	string str1, str2;
	cin >> str1 >> str2;

	vector<vector<int>> lcsLength(str1.length()); //dp에서 겹치는 부분 저장할 공간

	/*base case*/
	bool flag = false;
	for (int j = 0; j < str2.length(); j++) { // i == 0 이거나 (둘 다 0인 경우는 여기서 다뤄줌)
		if (str1[0] == str2[j])
			flag = true;
		
		(flag)? lcsLength[0].push_back(1) : lcsLength[0].push_back(0);
	}

	flag = false;
	for (int i = 1; i < str1.length(); i++) { // j == 0일 때
		if (str1[i] == str2[0])
			flag = true;

		(flag) ? lcsLength[i].push_back(1) : lcsLength[i].push_back(0);
	}


	/*점화식*/
	for (int i = 1; i < str1.length(); i++) {
		for (int j = 1; j < str2.length(); j++) {
			if (str1[i] == str2[j])
				lcsLength[i].push_back(lcsLength[i - 1][j - 1] + 1); // curr = prev + 1
			else
				lcsLength[i].push_back(max(lcsLength[i][j - 1], lcsLength[i - 1][j])); // curr = max(prev1, prev2)
		}
	}

	cout << lcsLength[str1.length() - 1][str2.length() - 1];

	return 0;
}