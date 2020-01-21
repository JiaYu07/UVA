#include <iostream>
#include <algorithm>
using namespace std;

int t, m, msg[25],  Max, sum,edge_len;
bool use[25]={0};
bool dfs( int start, int complete,int tmp_sum){
    if (complete == 4)return true;
    if(tmp_sum==edge_len)
        if(dfs(0,complete++,0))return true;

    for (int i = start; i < m; i++){
        if (use[i] == 0){
            use[i] = 1;
            if (dfs( i + 1, complete,msg[i]+tmp_sum))return true;                
            use[i] = 0;
        }
     }    
    return false;
}

int main()
{
    cin>>t;
    while (t--){
        Max = 0;
        sum = 0;
        fill(use,use+25,0);
        cin>>m;
        for (int i = 0; i < m; i++){
            cin>>msg[i];
            if (msg[i] > Max)
                Max = msg[i];            
            sum += msg[i];
        }
        edge_len=sum/4;

        if (sum % 4 == 0 && Max <=edge_len ){
            if (dfs(0,0,0))cout<<"yes\n";            
            else  cout<<"no\n";
        }
        else  cout<<"no\n";        
    }
}

