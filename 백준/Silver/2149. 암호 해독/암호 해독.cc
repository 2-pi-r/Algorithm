#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	/*선언*/
	string key, code; //키, 암호문
	vector<pair<char, int>> k; //key의 { 각 문자, 문자의 처음순서(i)}
	vector<vector<char>> c; // c[col] : code의 col번째 열 담는 벡터
	vector<pair<int, int>> temp; //{ key에서의 처음순서 (i), code에서의 열 번호 (col)}


	/*입력*/
	cin >> key >> code;

	for (int i = 0; i < key.length(); i++)
		k.push_back({ key[i], i });

	c.resize(key.length());
	int i = 0;
	for (int col = 0; col < key.length(); col++)
		for (int row = 0; row < code.length() / key.length(); row++)
			c[col].push_back(code[i++]);


	/*본문*/
	sort(k.begin(), k.end()); //k벡터를 알파벳 기준으로 정렬

	for (int i = 0; i < k.size(); i++)
		temp.push_back({ k[i].second, i });

	sort(temp.begin(), temp.end()); //temp벡터를 처음숫자 기준으로 정렬


	/*출력*/
	for (int row = 0; row < code.length() / key.length(); row++)
		for (int i = 0; i < temp.size(); i++) {
			int col = temp[i].second;
			cout << c[col][row]; //col = temp[i].second
		}

	return 0;
}