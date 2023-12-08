#include<bits/stdc++.h>
using namespace std;
int main()
{
        int a,sum=0;           //number of games
        cin>>a;
        for(int i=0;i<a;i++){
                string s;
                cin>>s;
                cin>>s;
                int a;
                s="red;";
                int re=0,gr=0,bl=0;
                
                while(s[s.length()-1]==','||s[s.length()-1]==';'){
                        cin>>a;
                        cin>>s;
                        
                        if(s=="red,"||s=="red;"||s=="red"){
                                re=max(re,a);
                        }
                        else if(s=="green,"||s=="green;"||s=="green"){
                                gr=max(gr,a);
                        }
                        else if(s=="blue,"||s=="blue;"||s=="blue"){
                                bl=max(bl,a);
                        }
                }
                        int mul=bl*re*gr;
                        sum+=mul;
                }
                
        
        cout<<sum<<endl;
}