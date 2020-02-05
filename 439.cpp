//UVA439 骑士的移动 Knight Moves
#include <iostream>
#include <queue>
using namespace std;
struct point_info{
    int x;
    int y;
};
const int dirs[2][8]={{-1,1,2,2,-1,1,-2,-2},{-2,2,-1,1,2,-2,-1,1}};
queue<point_info> q;
point_info Start, End;

int bfs(){
    int step[9][9] = {0};// use as recording ,same as used[][]
    
    point_info cur, nxt;
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        if (cur.x == End.x && cur.y == End.y)
            return step[cur.x][cur.y];

        for (int i = 0; i < 8; ++i) {
            nxt.x = cur.x + dirs[0][i];
            nxt.y = cur.y + dirs[1][i];
            if (nxt.x <0 || nxt.x >=8 || nxt.y <0 || nxt.y >=8||step[nxt.x][nxt.y]!=0) continue;
            
            step[nxt.x][nxt.y] = step[cur.x][cur.y] + 1;
            q.push(nxt);
            
        }
    }
    return step[cur.x][cur.y];//the last visited poinit -> its nxt can't push in 
}
int main()
{

    char s1[3], s2[3];
    while (cin>>s1>>s2) {
        
        Start.x = s1[0] - 'a' ;
        Start.y = s1[1] - '1';
        End.x = s2[0] - 'a';
        End.y = s2[1] - '1';
        q.push(Start);
        int moves = bfs();
        cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<moves<<" knight moves.\n";
        while(!q.empty())q.pop();
    }
    return 0;
}