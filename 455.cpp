#include <bits/stdc++.h>
using namespace std;



int main() {
    int n;
    cin>>n;
    string a;
    while (n--){
        cin>>a;
        int j, l =a.length();
        for (int i = 1; i <=l; ++i) {
            if(l%i==0){
                for ( j = i; j <=l; ++j) {
                    if(a[j]!=a[j%i]){
                        break;
                    }
                }
                if(j==l){
                    cout<<i<<endl;
                    break;
                }
            }
        }
        if(n){
            cout<<endl;
        }
    }
    return 0;
}
