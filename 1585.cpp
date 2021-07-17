#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    string a;
    while (n--){
        cin>>a;
        int l=a.length();
        int aux=0,d=0;
        for (int i = 0; i < l; ++i) {
            if(a[i]=='X'){
                d=0;
            }else{
                d++;
            }
            aux+=d;
        }
        cout<<aux<<endl;
    }
    return 0;
}
