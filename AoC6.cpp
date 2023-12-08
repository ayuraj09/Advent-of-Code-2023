#include<bits/stdc++.h>
using namespace std;

int main(){
    // int count=0;
    // vector<int> time,dis;
    string s;
    cin>>s;
    int k=4;
    string race1="";
    string race2 = "";
    for(int i=0;i<k;i++){
        cin>>s;
        race1+=s;
    }
    cin>>s;
    for(int i=0;i<k;i++){
        cin>>s;
        race2+=s;
    }

    long long time = stoll(race1);
    long long dis = stoll(race2);

    cout<<time<<" "<<dis;
    
    
    
        int count=0;
    for(int j=0; j<=time;j++){
        if(((time - j )*j)>dis){            
            count++;
            // cout<<j<<" ";
        }
    }
    cout<<"\n"<<count<<"\n";
}