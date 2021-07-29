#include <bits/stdc++.h>
using namespace std;

int length(){
    char d;
    int aux=0;
    for (int i = 2; i>=0; i--) {
        cin>>d;
        aux+=(d-'0')*pow(2,i);
    }
    return aux;
}
int top(int l){
    int aux=0;
    for (int i = 0; i < l; ++i) {
        aux+=pow(2,i);
    }
    return aux;
}


int main() {
    char d;
    string a;
    int r;
    while (getline(cin,a)) {
        int leng = length();
        while (leng&&1) {
            int aux= top(leng);
            int base= top(leng)-leng;
            r=0;
            while (aux!=r&&1){
                r=0;
                for (int i = leng-1; i>=0; --i) {
                    cin>>d;
                    r+=(d-'0')*pow(2,i);
                }
                if(aux!=r){
                    cout<<a[r+base];
                }
            }
            leng = length();
        }
        cout<<endl;
        cin.ignore();/*getchar()*/
    }
    return 0;
}
