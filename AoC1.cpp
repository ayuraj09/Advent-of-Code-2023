#include<bits/stdc++.h>
using namespace std;

int main() {
    std::unordered_map<string, char> stringToNumber;
    stringToNumber["one"] = '1';
    stringToNumber["two"] = '2';
    stringToNumber["three"] = '3';
    stringToNumber["four"] = '4';
    stringToNumber["five"] = '5';
    stringToNumber["six"] = '6';
    stringToNumber["seven"] = '7';
    stringToNumber["eight"] = '8';
    stringToNumber["nine"] = '9';
    string number[10] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    string a;
    int ans = 0;
    // int k=1000;
    while (cin>>a) {
        
        string s = "ab";
        int posf = 45698, posl = -2;

        for (int i = 0; i < a.length(); i++) {
            if ('0' <= a[i] && a[i] <= '9') {
                s[0] = a[i];
                posf = i;
                break;
            }
        }

        for (int i = a.length() - 1; i >= 0; i--) {
            if ('0' <= a[i] && a[i] <= '9') {
                s[1] = a[i];
                posl = i;
                break;
            }
        }

        int found=-1;
        
        for (int i = 0; i < 9; i++) {
            found = a.find(number[i]);

            if (found != -1) {
                if (found < posf) {
                    posf = found;
                    s[0] = stringToNumber[number[i]];
                }
                
            }
        }

        for (int i = 0; i < 9; i++) {
            found = a.rfind(number[i]);

            if (found != -1) {
                if (found > posl) {
                    posl = found;
                    s[1] = stringToNumber[number[i]];
                }
            }
        }
        
        
        
        int value=0;
        if (s != "ab") {
            value = stoi(s); 
            ans += value;
        }
        cout<<value<<" "<<ans<<"\n";

    }
    // cout << ans << "\n";
    
    return 0;
}


