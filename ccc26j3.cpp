#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string ng, mi;
    cin >> ng >> mi;
    int n = 0, m = 0;
    stack<char> a,b;
    for (int i = ng.length()-1; i > -1; i--) {
        a.emplace(ng[i]);
    }
    for (int i = mi.length()-1; i > -1; i--) {
        b.emplace(mi[i]);
    }
    while (!a.empty()&&!b.empty()) {
        char c1 = a.top();
        char c2 = b.top();
        if (c1 == c2) {
            a.pop(); n++;
            b.pop(); m++;
        }else if ((c1 == 'R' && c2 == 'G' ) || (c1 == 'G' && c2 == 'B' ) || (c1 == 'B' && c2 == 'R' )) {
            b.pop(); n++;
        }else {
            a.pop(); m++;
        }
    }
    n += a.size();
    m += b.size();
    cout << n << "\n" << m << "\n";
}