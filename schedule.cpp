#include <iostream>
#include <algorithm>
using namespace std;

int a[1024][1024];

int main(){
    int k;
    while(cin>>k){
        fill(a[0],a[0]+1024*1024,0);
        a[0][0]=1;
        for(int i=0;i<k;i++){
            int len=2<<i;//2 bitwise 往左移幾格
            int mid=len>>1;
            for(int j=0;j<mid;j++) {
                for (int k = 0; k < mid; k++) {
                    a[j + mid][k] = a[j][k + mid] = a[j][k] + mid;
                    a[j+mid][k+mid]=a[j][k];//對角線
                }
            }
        }
        for(int i=0;i<(1<<k);i++){
            for(int j=0;j<(1<<k);j++){
                if(j) cout << '\t';
                cout << a[i][j];
            }
            cout << endl;
        }
    }
}