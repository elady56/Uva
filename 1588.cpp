#include <bits/stdc++.h>
using namespace std;

int check(string a,string b){
    int l=a.length();
    int l2=b.length();
    int k=0,i,aux;
    for (int j = 0; j < l&&k<l; ++j) {
        k=j;
        aux=0;
        for (i = 0; i < l2&&k<l; ++i) {
            if(((b[i]-'0')+(a[k]-'0'))>3){
                break;
            }else{
                aux++;
            }
            k++;
        }
        if(i==l2||k==l||aux==l) break;
    }
    return l+l2-aux;
}
int main() {
    string a,b;
    while (cin>>a>>b){
        int ans=min(check(a,b), check(b,a));
        cout<<ans<<endl;
    }
    return 0;
}
