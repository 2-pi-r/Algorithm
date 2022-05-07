#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, w, L; cin >> n >> w >> L; //트럭 개수, 다리 길이(=건너는 데 걸리는 시간), 다리 위 최대무게
	int time = 0, weightB = 0; //걸린 시간, 다리 위 무게 총합
	queue<int> waiting; //아직 다리에 진입X 트럭의 무게
	queue<pair<int, int>>	bridge; //다리 위 트럭 {무게, 진입 시각}
	
	/*입력 받기 : 트럭무게*/
	while (n--) {
		int input; cin >> input;
		waiting.push(input);
	}

	/*초기 상태 : 처음 트럭 한 대 --> 다리 진입*/
	time++;
	weightB += waiting.front();
	bridge.push({ waiting.front(), time });
	waiting.pop();

	/*진행 : 다리 건너는 최단시간 구하기*/
	while (!waiting.empty() || !bridge.empty()) {
		time++;

		if (!bridge.empty() && bridge.front().second + w == time) { //다리 탈출
			weightB -= bridge.front().first;
			bridge.pop();
		}

		if (!waiting.empty() && weightB + waiting.front() <= L) { //다리 진입
			weightB += waiting.front();
			bridge.push({waiting.front(), time });
			waiting.pop();
		}
	}

	/*출력하기*/
	cout << time;

	return 0;
}