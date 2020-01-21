#include <iostream>
#include<algorithm>
#include <iomanip>
using namespace std;
const int MAXN=105;
int n,m,ans,isize=0;
int msg[MAXN][MAXN];
bool chk[MAXN];
int dfs(int x,int y){

}
void record(int n,int m){
    msg[n][m]=1;
    chk[n]=true;
    chk[m]=true;
}
int main(){
    while (cin>>n>>m&&n&&m){
        ans=0;  
        isize=0;      
        fill (msg[0],msg[0]+MAXN*MAXN,0);
        fill(chk,chk+MAXN,false);
        record(n,m);

        while(cin>>n>>m&&n&&m) record(n,m);

        for(auto &i:chk)if(chk[i]==true) isize++;
        for(int i=1;i<=isize;++i)
            for(int j=1;j<=isize;++j)
                if(msg[i][j]!=0)ans+=dfs(i,j);            

        cout  <<  fixed <<  setprecision(3) <<(double)(isize)*(isize-1)/(double) ans <<  endl;
    }
    
    return 0;
} 

