#include <bits/stdc++.h>
using namespace std;

const int maxn=100004;

int ans[maxn];

int a(int n){
    int aux=0;
    while (n>0){
        aux+=n%10;
        n/=10;
    }
    return aux;
}



int main() {
    /*int kase;
    cin>>kase;
    int n;
    memset(ans,0, sizeof(ans));
    for (int i = 1; i < maxn; ++i) {
        int aux=i+a(i);
        if(ans[aux]==0||i<ans[aux]){
            ans[aux]=i;
        }

    }
    while (kase--){
        cin>>n;
        cout<<ans[n]<<endl;
    }*/
    time_t timep=1970;
    time(&timep);
   //* asctime(gmtime(&timep));
   /* 86400*(StrToDateTime("2006-1-1 9:59:31")-StrToDateTime("1970-1-1 0:0:0"));*/
    srand(time(&timep));
    cout<<  asctime(gmtime(&timep));


    return 0;
}
