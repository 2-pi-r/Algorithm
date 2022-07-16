#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int K; cin>>K;
    int arr[51];

    for(int k = 1; k<=K; k++){
        int N; cin >> N;
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }      

        sort(arr, arr+N, greater<int>()); //내림차순 정렬
        
        cout << "Class " << k << endl;
        cout << "Max " << arr[0] << ", ";
        cout << "Min " << arr[N - 1] << ", ";     

        int gap, largest = 0; //largest : 가장 큰 인접한 점수 차이
        for(int i = 1; i < N; i++){
            gap = arr[i - 1] - arr[i];
            if(largest < gap)
                largest = gap;
        }
        cout << "Largest gap " << largest << endl;
    }

    return 0;
}