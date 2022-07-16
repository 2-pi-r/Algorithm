#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;
	int arr[10001] = { 0 }; //i의 개수

	int input;
	for (int n = 0; n < N; n++) { //N번 반복
		cin >> input;
		arr[input]++;
	}

	for (int i = 1; i < 10001; i++) //i = 10,000보다 작거나 같은 자연수
		for (int n = 0; n < arr[i]; n++) //i를 arr[i]번 출력
			cout << i << "\n";

	return 0;
}