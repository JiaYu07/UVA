#include<iostream>
#include<algorithm>
using namespace std;
 int n,m=0;
 char msg[101][101];
 bool vis[101][101];
 int _x[8]={-1,-1,-1,0,1,1,1,0};
 int _y[8]={-1,0,1,1,1,0,-1,-1};
 int ans=0;
void dfs(int x,int y){
    for(int i=0;i<8;++i){
       int  tmp_x=x+_x[i],tmp_y=y+_y[i];
        if(tmp_x>=0&&tmp_x<n&&tmp_y>=0&&tmp_y<m&&vis[tmp_x][tmp_y]==false){           
            if(msg[tmp_x][tmp_y]=='@'){ 
                vis[tmp_x][tmp_y]=true;
                dfs(tmp_x,tmp_y);                     
            }          
        }
    }
    return;
}
int main(){

    while(cin>>n>>m){
        if(n==0&&m==0)return 0;
        ans=0;
        fill(vis[0],vis[0]+101*101,false);

        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                cin>>msg[i][j]; 

         for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                if(vis[i][j]==false&&msg[i][j]=='@'){
                    vis[i][j]=true;
                    dfs(i,j);              
                    ans++;                    
                }
            cout<<ans<<endl;
    }
    return 0;
}