#include <iostream>
using namespace std;
int msg[13];
int data[6],t,m;
void  dfs(int depth,int start){
    if(depth==6){
        int i=0;
        while(depth--){
            cout<<data[i++];
            if(depth)cout<<" ";
        }
        cout<<endl;
        return ;
    }
    for(int i=start;i<m;++i){
        data[depth]=msg[i];
        dfs(depth+1,i+1);
    }
        
}
int main(){
   int cnt=0;
    while(cin>>t&&t){
        int i=0;
        m=t;
        if(cnt++)cout<<endl;
        while(t--)cin>>msg[i++];
        dfs(0,0);
    }
    return 0;
}