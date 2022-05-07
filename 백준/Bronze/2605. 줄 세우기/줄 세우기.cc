#include <iostream>
#include <deque>

using namespace std;

int main() {
	int N; cin >> N; //
	deque<int> line;

	for (int student = 1; student <= N; student++) {
		int input; cin >> input;
		line.insert(line.end() - input, student);
	}

	for (int i = 0; i < N; i++)
		cout << line[i] << " ";

	return 0;
}