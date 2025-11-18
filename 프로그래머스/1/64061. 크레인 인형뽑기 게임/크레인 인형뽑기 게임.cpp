#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;

    int col;
    for (int m = 0; m < moves.size(); m++) {
        col = moves[m] - 1;
        for (int row = 0; row < board.size(); row++) {
            if (board[row][col] == 0) continue;

            if (!st.empty() && st.top() == board[row][col]) {
                st.pop();
                answer += 2;
            }
            else {
                st.push(board[row][col]);
            }
            board[row][col] = 0;
            break;
        }
    }
    return answer;
}