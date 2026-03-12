#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    vector<int> v(5);
    for (int i = 0; i < 5; i++) {
        cin >> v[i];
    }
    int x; cin >> x;
    sort(v.begin(), v.end());
    cout << (v[1] + v[2] + v[3]) * x << "\n";
}