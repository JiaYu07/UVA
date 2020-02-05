#include<iostream>
using namespace std;
int tile=1;                   //L型骨牌的编号(递增)
int b[100][100];  //棋盘
/*****************************************************
* 递归方式实现棋盘覆盖算法
* 输入参数：
* tr--当前棋盘左上角的行号curr_x
* tc--当前棋盘左上角的列号tc
* dr--当前特殊方格所在的行号spe_x
* dc--当前特殊方格所在的列号spe_y
* size：当前棋盘的:2^k
*****************************************************/
void chessBoard ( int curr_x, int curr_y, int spe_x, int spe_y, int size )
{
    if ( size==1 )    //棋盘方格大小为1,说明递归到最里层
        return;
    int t=tile++;     //每次递增1
    int s=size/2;    //棋盘中间的行、列号(相等的)
    //检查特殊方块是否在左上角子棋盘中
    if ( spe_x<curr_x+s && spe_y<curr_y+s )              //在
        chessBoard ( curr_x, curr_y,spe_x,spe_y, s );
    else         //不在，将该子棋盘右下角的方块视为特殊方块
    {
        b[curr_x+s-1][curr_y+s-1]=t;
        chessBoard ( curr_x,curr_y, curr_x+s-1,curr_y+s-1, s );
    }
    //检查特殊方块是否在右上角子棋盘中
    if ( spe_x<curr_x+s && spe_y>=curr_y+s )               //在
        chessBoard ( curr_x, curr_y+s, spe_x,spe_y, s );
    else          //不在，将该子棋盘左下角的方块视为特殊方块
    {
        b[curr_x+s-1][curr_y+s]=t;
        chessBoard (curr_x, curr_y+s,curr_x+s-1, curr_y+s, s );
    }
    //检查特殊方块是否在左下角子棋盘中
    if ( spe_x>=curr_x+s && spe_y<curr_y+s )              //在
        chessBoard ( curr_x+s,curr_y,spe_x, spe_y, s );
    else            //不在，将该子棋盘右上角的方块视为特殊方块
    {
        b[curr_x+s][curr_y+s-1]=t;
        chessBoard (curr_x+s, curr_y, curr_x+s, curr_y+s-1, s );
    }
    //检查特殊方块是否在右下角子棋盘中
    if (spe_x>=curr_x+s && spe_y>=curr_y+s )                //在
        chessBoard (curr_x+s, curr_y+s, spe_x, spe_y, s );
    else         //不在，将该子棋盘左上角的方块视为特殊方块
    {
        b[curr_x+s][curr_y+s]=t;
        chessBoard ( curr_x+s, curr_y+s, curr_x+s, curr_y+s, s );
    }
}

int main()
{
    int t,size,x,y,total=0;
    cin>>t;
    while(t--)
    {
        cin>>size;
        cin>>x>>y;
        total++;
        chessBoard (0,0,x,y,size );
         cout<<"CASE:"<<total<<endl;
        for ( int i=0; i<size; i++ )
        {
            for ( int j=0; j<size; j++ )
                cout<<b[i][j]<<" ";
            cout<<endl;
        }
    }
}