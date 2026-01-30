#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    string adj[n];
    string noun[m];
    for(int i = 0; i < n; i++){
        cin >> adj[i];
    }
    for(int i = 0; i < m; i++){
        cin >> noun[i];
    }
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++){
            cout << adj[i] << " as " << noun[j] << "\n";
        }
    }
}