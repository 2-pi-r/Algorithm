/*
풀이방법 :
벡터 result에 이름의 각 알파벳 획수를 저장한다.
result의 원소 둘씩 더해서, 그 일의자리 값을 벡터 temp에 담는다.
다 더하고 나면 둘을 swap해서 result에 획수의 합들이 저장되도록 한다.
둘씩 더하고 swap하기를 반복하다가, sesult의 원소가 두 개이면 출력한다.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int count[] = { 3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1 }; //알파벳 획수
	string A, B; cin >> A >> B;
	
	vector<int> temp, result(2 * A.size());
	for(int i = 0; i < A.size(); i++) {
		result[2* i] = count[A[i] - 'A'];
		result[2 * i+1] = count[B[i] - 'A'];
	}

	while(result.size() > 2) {
		for (int i = 0; i < result.size() - 1; i++)
			temp.push_back((result[i] + result[i + 1]) % 10); //result 원소 둘씩 더해서, 그 일의자리 값을 temp로 옮겨 담음.

		result.clear();
		result.swap(temp); //temp에 저장된 합들은 result로 옮겨지고, temp에는 clear된 벡터가 옮겨짐.
	}

	if(result.size() == 1) //한자릿수 나오면
		result.insert(result.begin(), 0); //0번째 위치에 0 삽입

	cout << result[0] << result[1];

	return 0;
}
