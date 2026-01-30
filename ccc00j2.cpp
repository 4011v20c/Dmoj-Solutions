#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool valid(string w){

    string w2 = "";
    for(int i = w.length() - 1; i >= 0; i--){
        char test = w[i];
        if(test == '1' or test == '8')
            w2 += w[i];
        if (test == '0')
            w2 += w[i];
        if(test == '6')
            w2 += '9';
        if(test == '9')
            w2 += '6';
    }
    if(w2 == w)
        return true;
    return false;

}


int main(){
    int x, y;
    cin >> x >> y;
    int c = 0;

    for(int i = x; i <= y; i++){
        if(valid(to_string(i)))
            c ++;
    }
    cout << c;

}
