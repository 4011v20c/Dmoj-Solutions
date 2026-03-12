#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int a,b,c;
    cin >> a >> b >> c;
    vector<int> psa(a + 1);
    for (int  i = 0; i < b; i++) {
        int x,y;
        cin >> x >> y;
        int n = x -y;
        int m = x + y + 1;
        if (n < 1) {
            psa[1]++;
        }else {
            psa[n]++;
        }
        if (m <= a) {
            psa[m]--;
        }
    }

    vector<int> v(a+1);
    v[0] = 0;
    for (int i = 1; i < a+1; i++) {
        v[i] = v[i-1] + psa[i];
    }
    while (c--) {
        int q; cin >> q;
        if (v[q] > 0) {
            cout << "Y\n";
        }else {
            cout << "N\n";
        }
    }

}