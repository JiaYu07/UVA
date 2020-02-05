#include <iostream>
using namespace std;
bool chk;
int solve(){
    int w1,d1,w2,d2;
    cin>>w1>>d1>>w2>>d2;
    if(w1==0)w1=solve();
    if(w2==0)w2=solve();
    if(w1*d1!=w2*d2){
        chk=false;
        return false;
    }
    else return w1+w2 ;       
}
int main(){
    int t=0;cin>>t;
    while(t--){
        chk=true;
        solve();
        if(chk)cout<<"YES\n";
        else cout<<"NO\n";
        if(t)cout<<endl;
    }
    return 0;
}