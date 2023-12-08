#include<bits/stdc++.h>
using namespace std;



int getnumber(vector<string> matrix, int i, int j, vector<vector<bool>> visited){
    int sum=1;
    int count =0;
    
    if(j-1>=0 && i+1<matrix.size() && visited[i+1][j-1]==0){   //down left
        string s="";
        int b=0;
        if(matrix[i+1][j-1]>='0'&&matrix[i+1][j-1]<='9'){
            
            int k=j-1;
            while((k>=0 && matrix[i+1][k]>='0'&& matrix[i+1][k]<='9')){                              
                    k--;      
            }
            k++;
            while(k<matrix[0].size() && matrix[i+1][k]>='0'&& matrix[i+1][k]<='9'){
                s+=matrix[i+1][k];
                if(visited[i-1][k]==1)
                {break;
                b=1;}
                visited[i+1][k]=1;
                k++;
            }
            if(b==0){
            count++;
            sum*=stoi(s);}
        }
    }
    
    


    if(j+1<matrix.size() && i+1<matrix.size() && visited[i+1][j+1]==0){   //down right
        string s="";
        int b=0;
        if(matrix[i+1][j+1]>='0'&&matrix[i+1][j+1]<='9'){
            
            int k=j+1;
            while((k>=0 && matrix[i+1][k]>='0'&& matrix[i+1][k]<='9')){                              
                    k--;      
            }
            k++;
            while(k<matrix[0].size() && matrix[i+1][k]>='0'&& matrix[i+1][k]<='9'){
                s+=matrix[i+1][k];
                if(visited[i-1][k]==1)
                {break;
                b=1;}
                visited[i+1][k]=1;
                k++;
            }
            if(b==0){
            count++;
            sum*=stoi(s);}
        }
    }
    if(j+1<matrix.size() && i-1>=0 && visited[i-1][j+1]==0){   //up right
        string s="";
        int b=0;
        if(matrix[i-1][j+1]>='0'&&matrix[i-1][j+1]<='9'){
            
            int k=j+1;
            while((k>=0 && matrix[i-1][k]>='0'&& matrix[i-1][k]<='9')){ 
                              
                    k--;    
            }
            k++;
            while(k<matrix[0].size() && matrix[i-1][k]>='0'&& matrix[i-1][k]<='9'){
                s+=matrix[i-1][k];
                if(visited[i-1][k]==1)
                {break;
                b=1;}
                visited[i-1][k]=1;
                k++;
            }
            if(b==0){
            count++;
            sum*=stoi(s);}
        }
    }
    
    if(i-1>=0 && j-1 >=0 && visited[i-1][j-1]==0){   //up left
        string s="";
        int b=0;
        if(matrix[i-1][j-1]>='0'&&matrix[i-1][j-1]<='9'){
            
            int k=j-1;
            while((k>=0 && matrix[i-1][k]>='0'&& matrix[i-1][k]<='9')){ 
                              
                    k--;    
            }
            k++;
            while(k<matrix[0].size() && matrix[i-1][k]>='0'&& matrix[i-1][k]<='9'){
                s+=matrix[i-1][k];
                if(visited[i-1][k]==1)
                {break;
                b=1;}
                visited[i-1][k]=1;
                k++;
            }
            if(b==0){
            count++;
            sum*=stoi(s);}
        }
    }
    


    if(i+1<matrix.size() && visited[i+1][j]==0){   //down
        string s="";
        int b=0;
        if(matrix[i+1][j]>='0'&&matrix[i+1][j]<='9'){
            
            int k=j;
            while((k>=0 &&matrix[i+1][k]>='0'&& matrix[i+1][k]<='9')){                              
                    k--;      
            }
            k++;
            while(k<matrix[0].size() && matrix[i+1][k]>='0'&& matrix[i+1][k]<='9'){
                s+=matrix[i+1][k];
                if(visited[i-1][k]==1)
                {break;
                b=1;}
                visited[i+1][k]=1;
                k++;
            }
            if(b==0){
            count++;
            sum*=stoi(s);}
        }
    }
    if(i-1>=0 && visited[i-1][j]==0){   //up
        string s="";
        int b=0;
        if(matrix[i-1][j]>='0'&&matrix[i-1][j]<='9'){
            
            int k=j;
            while((k>=0 && matrix[i-1][k]>='0'&& matrix[i-1][k]<='9')){ 
                              
                    k--;    
            }
            k++;
            while(k<matrix[0].size() && matrix[i-1][k]>='0'&& matrix[i-1][k]<='9'){
                s+=matrix[i-1][k];
                if(visited[i-1][k]==1)
                {break;
                b=1;}
                visited[i-1][k]=1;
                k++;
            }
            if(b==0){
            count++;
            sum*=stoi(s);}
        }
    }
    if(j+1<matrix[0].size() && visited[i][j+1]==0){     // right    
        string s="";int b=0;
        if(matrix[i][j+1]>='0'&&matrix[i][j+1]<='9'){
            
            int k=j+1;
            
            while(k<matrix[0].size() && matrix[i][k]>='0'&& matrix[i][k]<='9'){
                if(visited[i][k]==1){
                    break;
                    b=1;
                }
                s+=matrix[i][k];
                visited[i][k]=1;
                k++;

            }
            if(b==0){
            count++;
            sum*=stoi(s);}
        }
    }

    if(j-1>=0 && visited[i][j-1]==0){       //left
        string s="";int b=0;
        if(matrix[i][j-1]>='0'&&matrix[i][j-1]<='9'){
            int k=j-1;
            while((k>=0 && matrix[i][k]>='0'&& matrix[i][k]<='9')){
                k--;    
            }
            k++;
            while(matrix[i][k]>='0'&& matrix[i][k]<='9'){
                if(visited[i][k]==1){
                    break;
                    b=1;
                }
                s+=matrix[i][k];
                visited[i][k]=1;
                k++;
            }
            if(b==0){
            count++;
            sum*=stoi(s);}
        }
    }

    


    if(count>1)
    return sum;
    else return 0;
}

int main(){
    vector<string> matrix;
    int sum=0;
    string s;
    int a=140;
    while(a--){
        cin>>s;
        matrix.push_back(s);
    }

    vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));

    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if(matrix[i][j]=='*'){
                // visited[i][j]=1;
                int num = getnumber(matrix,i,j,visited);
                sum+=num;
            }
        }
    }
    cout<<sum;


}