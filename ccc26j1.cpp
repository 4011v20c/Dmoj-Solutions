#include <bits/stdc++.h>

using namespace std;

int main() {

    int a,b,c;
    cin >> a >> b >> c;
    int diff = b - a - c;
    if(diff < 0){
        cout << "N\n"; return 0;
    }else{
        cout << "Y "; cout << diff << endl;
    }
}