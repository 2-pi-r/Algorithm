#include <iostream>
#include <vector>

using namespace std;

int test(vector<char[5][7]> &picture, int n1, int n2) { //n1번째 그림, n2번째 그림
	int cnt = 0; //서로 다른 칸의 개수
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 7; j++) {
			if (picture[n1][i][j] != picture[n2][i][j])
			{ cnt++; }
		}
	}

	return cnt;
}


int main() {
	int N; cin >> N;
	int cnt, minOfCnt = 2501;
	int result1, result2;
	vector<char[5][7]> picture(N + 1); //그림 정보 저장

	/*그림 정보 입력받기*/
	for (int n = 1; n <= N; n++) {

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 7; j++) {
				cin >> picture[n][i][j];
			}
		}
	}

	/*가능한 조합 별로 탐색하기*/
	for (int n1 = 1; n1 <= N; n1++) {
		for (int n2 = n1 + 1; n2 <= N; n2++) {//중복 방지를 위해 n1 = n2 인 경우만 따지기
			cnt = test(picture, n1, n2);
			if (minOfCnt > cnt) {
				minOfCnt = cnt;
				result1 = n1;
				result2 = n2;
			}
		}
	}
		
	/**/
	cout << result1 << " " << result2;

	return 0;
}