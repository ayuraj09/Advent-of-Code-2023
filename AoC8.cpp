
#include<bits/stdc++.h>
using namespace std;

#include <iostream>
long long findGCD(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find the LCM (Least Common Multiple) of two numbers
long long findLCM(long long a, long long b) {
    // LCM(a, b) = (a * b) / GCD(a, b)
    return (a / findGCD(a, b)) * b;
}




string getMiddleThreeOrFirstThree(string& s) {
    if (s.size() == 5) {
        return s.substr(1, 3);
    } else if (s.size() == 4) {
        return s.substr(0, 3);
    } else {
        return "Invalid input size";
    }
}

int main()
{
    string s;
    string temp;
    map<string,pair<string,string>> nodes;
    cout<<"Enter number of nodes"<<"\n";
    long long a;
    cin>>a;
    cin>>s;
    while(a--){
        string str,strL,strR;
        
        cin>>str;
        cin>>temp;
        cin>>strL>>strR;
        nodes[str] = make_pair(getMiddleThreeOrFirstThree(strL),getMiddleThreeOrFirstThree(strR));
    }
    string it = nodes.begin()->first;
 
    
    vector<pair<string,long long>> allA;
    for( auto itr:nodes){
        if(itr.first[itr.first.length()-1]=='A'){
            allA.push_back(make_pair(itr.first,0));
        }
    }


        for(long long z=0;z<allA.size();z++){
        string it=allA[z].first;
        // long long &count = allA[z].second;
            while(it[it.length()-1]!='Z'){
                long long i;
                    for(i=0; i<s.length() && it[it.length()-1]!='Z'; i++){
                        if(s[i]=='L'){
                            it=nodes[it].first;   
                        } else if(s[i]=='R'){
                            it=nodes[it].second;
                        }                   
                    
                    }
                    allA[z].second+=i;
                    
            }
            cout<<allA[z].second<<" ";
                       

}

long long lcmResult=findLCM(allA[0].second, allA[1].second);

for(int i=2;i<allA.size();i++){
    lcmResult = findLCM(lcmResult, allA[i].second);
}
cout<<"\n"<<lcmResult;        
               
}
    
    
