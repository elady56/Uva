#include <bits/stdc++.h>
using namespace std;

bool search(string a, int *i, char b){
    int l=a.length();
    for (int j = (*i); j < l; ++j) {
        (*i)++;
        if(b==a[j]){
            return true;
        }
    }
    return false;
}

int main() {
    string a,b;
    while (cin>>a>>b){
        int l=a.length();
        int auxl=0;
        bool flag= true;
        for (int i = 0; i < l&&flag; ++i) {
            if(!search(b,&auxl,a[i])){
                flag= false;
            }
        }
        if(flag){cout<<"Yes\n";}
        else{cout<<"No\n";}
    }
    return 0;
}
