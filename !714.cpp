//greedy
#include<iostream>
#include<algorithm>
using namespace std;
const int maxm = 500 + 5;
int m, k, p[maxm];

// how many scribers needed if each scriber can work on at most maxp pages
int solve(long long maxp) {
  long long done = 0;
  int ans = 1;
  for(int i = 0; i < m; i++) {
    if(done + p[i] <= maxp) done += p[i];
    else { ans++; done = p[i]; }
  }
  return ans;
}
/*先假設負擔最重的人應該抄p頁,若小於所求答案,則會抄不完回傳的ans會大於k,vise versa */

int last[maxm]; // last[i] = 1 if i is the last book assigned to someone 之後會輸出"/" 
void print(long long ans) {
  long long done = 0;
  fill(last,last+maxm,0);
  int remain = k;
  for(int i = m-1; i >= 0; i--) {
    if(done + p[i] > ans || i+1 < remain){//後面的"或 or" 是在處理每人至少要分到一頁的題目要求
      last[i] = 1; remain--; done = p[i];
    }
    else  done += p[i];
    
  }
  for(int i = 0; i < m-1; i++){
    cout<<p[i]<<" ";
    if(last[i]) cout<<"/ ";
  }
  cout<<p[m-1]<<endl;
}

int main() {
  int T;
 cin>>T;
  while(T--) {
    cin>>m>>k;
    long long tot = 0;
    int maxp = -1;
    for(int i = 0; i < m; i++) {
      cin>>p[i];
      tot += p[i];
      maxp = max(maxp, p[i]);
    }
    long long L = maxp, R = tot;//負擔最重的人至少會被分到頁數最多的書,最多會到每本書加起來的總頁數
    while(L < R) {
      long long M = L + (R-L)/2;
      if(solve(M) <= k) R = M; //回傳的ans 小於或等於所求, 表示負擔最重的人被分配到的可以更少
      else L = M+1;
    }
    print(L);
  }
  return 0;
}