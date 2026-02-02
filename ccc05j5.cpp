#include <bits/stdc++.h>

using namespace std;

bool isMonkeyLang(string line);
bool isAWord(string str);

int main(){
    vector<string> invec;
    string line;
    while(getline(cin, line)){
        if (line.compare("X") == 0){
            break;
        }else{
            invec.push_back(line);
        }
    }

    vector<string>::iterator it = invec.begin();
    while (it != invec.end()){
        //cout << *it << endl;
        if (isMonkeyLang(*it)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        it++;
    }

}

bool isMonkeyLang(string line){
    if (isAWord(line)){
        return true;
    }else {
        int len = line.length();
        int pos = 0;
        int loc = -1;
        while ((loc = line.find('N', pos)) >= 0){
            string str1 = line.substr(0, loc);
            string str2 = line.substr(loc+1);
            if (isAWord(str1) && isMonkeyLang(str2)){
                return true;
            }else{
                pos = loc + 1;
            }
        }
        return false;
    }
}

bool isAWord(string str){
    int len = str.length();
    if (len == 0) return false;
    if (len == 1) return str[0] == 'A';

    return str[0] == 'B' && str[len -1] =='S' && isMonkeyLang(str.substr(1, len-2));
}