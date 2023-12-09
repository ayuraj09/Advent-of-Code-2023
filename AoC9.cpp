#include<bits/stdc++.h>
using namespace std;
bool checkzero(vector<long long> A){
    for(int i=0;i<A.size();i++){
        if(A[i]!=0)
        return 1;
    }
    return 0;
}
int main(){
    vector<vector<long long>> history;
    
    string line;
    getline(cin,line);
    while(!line.empty()){
        vector<long long> temp;
        istringstream num(line);
        while (num >> line){
            temp.push_back(stoll(line));            
        }
        history.push_back(temp);
        getline(cin,line);
    }
    long long ans1=0,ans2=0;
    
    for (int i = 0; i < history.size(); i++){
        vector<vector<long long>> pred;
        pred.push_back(history[i]);
        int j=0;
        while(checkzero(pred[j])){
            vector<long long> temp;
            for(int i=0;i<pred[j].size()-1;i++){
                temp.push_back(pred[j][i+1]-pred[j][i]);
            }
            pred.push_back(temp);
            j++;
        }

        long long k;
    // part 1
        pred[pred.size()-1].push_back(0);
        for(int i=pred.size()-1;i>0;i--){
            k = pred[i][pred[i].size()-1] + pred[i-1][pred[i-1].size()-1];
            pred[i-1].push_back(k);            
        }
        ans1+=k;

    // part 2        
        pred[pred.size()-1].push_back(0);
            for(int i=pred.size()-1;i>0;i--){
                k = pred[i-1][0] - pred[i][0];
                    pred[i-1].insert(pred[i-1].begin(), k);            
            }
        ans2+=k;
    }   

    cout<<"Part 1: "<<ans1<<"\n"<<"Part 2: "<<ans2;
    
}
