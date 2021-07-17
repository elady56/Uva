#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    string a;
    map<char,float> m;
    m['C']=12.010;
    m['H']=1.008;
    m['O']=16.00;
    m['N']=14.01;
    while(n--){
        cin>>a;
        int l=a.length();
        float act=m[a[0]],total=0,aux=0;
        for (int i = 1; i <= l; ++i) {
            while(isdigit(a[i])){
                aux=aux*10+(a[i]-'0');
                i++;
            }
            if(isalpha(a[i])){
                if(!aux){
                    total+=act;
                }else{
                    total+=aux*act;
                }
                aux=0;
                act=m[a[i]];
            }
        }
            if(isdigit(a[l-1])){
                total+=act*aux;
            }else{
                total+=act;
            }
        printf("%.3f\n",total);
    }
    return 0;
}
