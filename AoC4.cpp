#include<bits/stdc++.h>
using namespace std;



bool bsearch(int a, vector<int> &q,int f, int l){
    while (f <= l) {
        int mid = f + (l - f) / 2;

        if (q[mid] == a) {
            return true;
        }

        if (q[mid] > a) {
            l = mid - 1;
        } else {
            f = mid + 1;
        }
    }

    return false;
}

int main(){

    vector<int> cardnum(193,1);

    int a=193;
    int card;
    
    for(card=0;card<a;card++){
        // int count = 0;
        string s;
        cin>>s;
        cin>>s;
        cin>>s;    
        
        vector<int> p,q;
        for(int i=0;s!="|";i++){
            p.push_back(stoi(s));
            cin>>s;
        }
        getline(cin,s);

        istringstream secondp(s);
        while (secondp >> s){
            q.push_back(stoi(s));            
        }
        sort(q.begin(),q.end());
        int count=0;
        for(int i=0;i<p.size();i++){
            
            bool check = bsearch(p[i],q,0,q.size());
            if(check==1){
                count++;
            }           

        }            
        
        for(int i=card+1;i<=count+card;i++){
           cardnum[i]+=cardnum[card]*1;
        }
    }

    int ans=0;
    for(int i=0;i<193;i++){
        ans+=cardnum[i];
    }
    cout<<ans;
        
    
            
}

