#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n; cin >> n;
    set<pi> vis;
    int x= 0;
    int y= 0;
    vis.insert({0, 0});
    int ans=0;
    while (n--){
        char d;
        int s;
        cin >>d >> s;
        int dx = 0;
        int dy = 0;
        if (d == 'N') dy = 1;
        else if (d == 'S') dy = -1;
        else if (d == 'E') dx = 1;
        else if (d == 'W') dx = -1;
        for (int i = 0; i < s; i++) {
            x += dx;
            y += dy;
            if (vis.count({x, y})){
                ans++;
            } else{
                vis.insert({x, y});
            }
        }
    }
    cout << ans << "\n";
    return 0;
}