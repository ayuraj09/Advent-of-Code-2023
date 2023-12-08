#include<bits/stdc++.h>
using namespace std;


int main(){

    vector<pair<unsigned long long, bool>> seed;

    string s, z;
    cin >> s;
    getline(cin, s);
    istringstream sd(s);

    unsigned long long ans = ULLONG_MAX;

    while (sd >> s >> z) {
        unsigned long long startValue = stoull(s);
        unsigned long long count = stoull(z);

        for (unsigned long long i = 0; i < count; ++i) {
            seed.emplace_back(startValue + i, false);
        }
    }

getline(cin,s);

getline(cin,s);
if(s[s.length()-1]==':'){
    getline(cin,s);
}


    unsigned long long soils=0, fertis=0, waterf=0, lightw=0, templ=0, humidt=0, locationh=0;
    int a=7;
    while(a--){
    while(!s.empty())
        {   
            istringstream sl(s);
            unsigned long long j,i,range;
            sl>>j>>i>>range;
            for(int P=0;P<seed.size();P++){
                if((seed[P].first>=i ) && (i+range)>seed[P].first && seed[P].second==0){
                seed[P].first = j+seed[P].first-i;
                seed[P].second=1;
                } 
            } 
            
            getline(cin,s);
        }
        for(int i =0;i<seed.size();i++){
            seed[i].second=0;
        }

    
    getline(cin,s);
    if(s[s.length()-1]==':'){
        getline(cin,s);
    }
    }
        

    sort(seed.begin(),seed.end());
    cout<<seed[0].first;
    }
    