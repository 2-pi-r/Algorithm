#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct fastRoad {
	int from;
	int to;
	int length;
};

int main() {
	/*input*/
	int N, D; cin >> N >> D; //지름길 개수, 고속도로 길이 (최종 도착점)
	vector<int> d(D+1); //i위치까지 가는 최단 거리
	vector<fastRoad> fast; //지름길 정보
	
	int from, to, length;
	while (N--) {
		cin >> from >> to >> length;

		if (to - from <= length || D < to) //고려할 필요가 없는 지름길
			continue;

		fast.push_back({ from, to, length });
	}


	/*solve*/
	d[0] = 0; //base case
	for (int i = 1; i <= D; i++) {
		d[i] = d[i - 1] + 1;

		for (auto r : fast) {
			if (r.to == i)
				d[i] = min(d[i], d[r.from] + r.length);
		}
	}

	
	cout << d[D];

	return 0;
}