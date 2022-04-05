#include <iostream>

using namespace std;

int main() {
	int N; cin >> N;

	switch ((N - 1) % 4)
	{
		case 0:
		case 2:
			cout << "CY";
		break;

		case 1:
		case 3:
			cout << "SK";
			break;
	}

	return 0;
}