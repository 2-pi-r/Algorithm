#include <iostream>

using namespace std;

int main() {
	/*선언, 입력 받기*/
	int N, L; cin >> N >> L; //물이 새는 곳의 개수, 테이프의 길이
	int count = 0; //필요한 테이프 개수
	int array[1001] = { 0 }; //물이 새는 위치 (1로 표시)

	while (N--){
		int input; cin >> input;
		array[input] = 1;
	}

	/*진행 : count 구하기*/
	for(int i = 0; i < 1001; i++)
		if (array[i] == 1) {
			count++;
			i += L - 1;
		}

	/*출력하기*/
	cout << count;

	return 0;
}