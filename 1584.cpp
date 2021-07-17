/*#include <bits/stdc++.h>
using namespace std;


int small(string a,int d,int q){
    int n=a.length();
    string b;
    for (int i = 0; i < n; ++i) {
        if(a[(d+i)%n] != a[(q+i)%n]) return a[(d+i)%n] < a[(q+i)%n];
    }
    return 0;
}*/
/*int main() {
   /* int n;
    cin>>n;
    string a;
    while (n--){
        cin>>a;
        int ans=0;
        int l=a.length();
        for (int i = 0; i <l ; ++i) {
            if(small(a,i,ans)) ans=i;
        }
        for (int i = 0; i < l; ++i) {
            putchar(a[(i+ans)%l]);
        }
        cout<<endl;

    }*/
    /*int a=12;
    printf("%d %o %x\n", a,a,a);
    printf("%u\n",-1);
    printf("%u\n",1);
    printf("%u\n",0);
    printf("%u\n",-0);
    return 0;*/

/*}*/

#include<bits/stdc++.h>
using namespace std;

#define maxn 10000000+10
char s[maxn];

int main() {
    scanf("%s", s);
    int tot = 0;
    for(int i = 0; i < strlen(s); i++)
        if(s[i] == '1') tot++;
    printf("%d\n", tot);
}

