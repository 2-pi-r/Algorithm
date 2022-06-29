#include <iostream>
using namespace std;

int n, m;
int parent[1000001];

// 부모 가져오기
int Getparent(int num) {
    if (parent[num] == num)
        return num;
    return parent[num] = Getparent(parent[num]);
}

// 합치기
void Union(int a, int b) {
    int aParent = Getparent(a);
    int bParent = Getparent(b);
    if (aParent > bParent)
        parent[aParent] = bParent;
    else
        parent[bParent] = aParent;
}

// 부모가 같은지 확인
void Find(int a, int b) {
    int aParent = Getparent(a);
    int bParent = Getparent(b);
    if (aParent == bParent)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++) {
        bool com;
        int a, b;
        cin >> com >> a >> b;

        // Find
        if (com) {
            Find(a, b);
        }
        // Union
        else {
            Union(a, b);
        }
    }
    return 0;
}
