#include <bits/stdc++.h>
using namespace std;

int sh[3005], yu[3005], mark[3005];

int main() {
    int a,b,t;
    while (cin>>a>>b){
        memset(sh,0,sizeof (sh));
        memset(yu,0,sizeof (yu));
        int count=0;
        sh[count++]=a/b;
        t=a;
        a=a%b;
        while(a&&!mark[a]){
            mark[a]=count;
            yu[count]=a;
            sh[count++]=a/b;
            a=10* a%b;
        }
        cout<<t<<"/"<<b<<" = "<<sh[0];
        for (int i = 1; i < count&&i<=50; ++i) {
            cout<<sh[i];
        }
        if(count>50) cout<<"...";
        if(!a) cout<<"(0";
        cout<<")\n";
        cout<< (!a?1:(count-mark[a]))<<"= number of digits in repeating cycle";
    }
    return 0;
}
