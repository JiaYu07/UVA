#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 105;
 int n,m=0;
 char msg[105][105];
 bool vis[105][105];
 int ans=0;
void dfs(int x,int y){
    if(x<0||x>=n||y<0||y>=m)return ;
    if(vis[x][y]==true||msg[x][y]!='@')return;
    vis[x][y]=true;
    for(int tmp_x=-1;tmp_x<=1;++tmp_x)//這樣就不用一個一個去思考
        for(int tmp_y=-1;tmp_y<=1;++tmp_y)
            if(tmp_x!=0||tmp_y!=0)dfs(x+tmp_x,y+tmp_y);//不會重複dfs原點
}
int main(){

    while(cin>>n>>m&&n&&m){
        ans=0;
        fill(vis[0],vis[0]+105*105,false);

        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                cin>>msg[i][j]; 

         for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                if(vis[i][j]==false&&msg[i][j]=='@'){
                    dfs(i,j);              
                    ans++;                    
                }
            cout<<ans<<endl;
    }
    return 0;
}