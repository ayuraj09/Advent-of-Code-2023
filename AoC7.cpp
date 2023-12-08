#include<bits/stdc++.h>
using namespace std;
unordered_map<int,vector<string>> type;

unordered_map<char, int> countCharacters(string hand) {
    unordered_map<char, int> charCount;

    for (char c : hand) {
        charCount[c]++;
    }

    // Check if the count of 'J' is not zero
    if (charCount['J'] < 5 && charCount['J']>0 ) {
        int maxCount = 0;
        char y;
        // Find the maximum count of characters in the map
        for (auto pair : charCount) {
            if(pair.first!='J'){
                if(maxCount<pair.second) { 
                    maxCount=pair.second;              
                    y=pair.first;
                }
            }
        }

        // Add the count of 'J' to the max count of all characters
        charCount[y]+= charCount['J'];
        charCount['J']=0;
     
    }

    return charCount;
}


bool customSort(string& card1, string& card2) {
    string order = "J23456789TQKA";
        for(int i=0;i<5;i++){
            if(card1[i]!=card2[i])
                return order.find(card1[i]) < order.find(card2[i]);
        } 
    return 1; 
}
void categorizePokerHand(string hand) {
    unordered_map<char, int> charCount = countCharacters(hand);

    // Analyze the counts and categorize the hand
    int numPairs = 0, numTriples = 0, numQuads = 0, numfive = 0;
    for (const auto& pair : charCount) {
        if (pair.second == 2) {
            numPairs++;
        } else if (pair.second == 3) {
            numTriples++;
        } else if (pair.second == 4) {
            numQuads++;
        }  else if (pair.second == 5) {
            numfive++;
        }
    }

    // Categorize the hand based on counts
    if(numfive==1){
        type[7].push_back(hand);   
    } else if (numQuads == 1) {
        type[6].push_back(hand);  
    } else if (numTriples == 1 && numPairs == 1) {
        type[5].push_back(hand);  
    } else if (numTriples == 1) {
        type[4].push_back(hand);  
    } else if (numPairs == 2) {
        type[3].push_back(hand);  
    } else if (numPairs == 1) {
        type[2].push_back(hand);  
    } else {
        type[1].push_back(hand);  
    }
}

int main() {
    // Example hands
    map<string,long long> hand;
    string s; int a;
    long long ans=0;
    long long count=1; 
    int itr=1000;
    while(itr--){
        cin>>s;
        cin>>a;
        hand[s]=a;
        categorizePokerHand(s);
    }


    for(int i=1;i<=7;i++){
        cout<<"TYPE :"<<i<<"\n";
        sort(type[i].begin(),type[i].end(), customSort);
        // cout<<type[i].size()<<" ";

        for(int j=0;j<type[i].size();j++){
            cout<<type[i][j]<<" "<<hand[type[i][j]]<<" "<<count<<"\n";
            

            ans+=(count++)*hand[type[i][j]];
        }
        cout<<"\n\n";
        
    }



    cout<<"final"<<ans;
   

    return 0;
}

// 251515496