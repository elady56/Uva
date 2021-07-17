#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int kase=0;
    while (cin>>n&&n!=0){
        cout<<"Game "<<++kase<<":\n";
        int secret[n];
        for (int i = 0; i < n; ++i) {
            cin>>secret[i];
        }
        while (1) {
            int A=0,B=0;
            int d[n];
            for (int i = 0; i < n; ++i) {
                cin>>d[i];
                if(d[i]==secret[i]) A++;
            }
            if(d[0] == 0) break;
            for (int j= 1; j <= 9; ++j) {
                int c1 = 0, c2 = 0;
                for(int i = 0; i < n; i++) {
                    if(secret[i] == j) c1++;
                    if(d[i] == j) c2++;
                }
                (c1 < c2)?B+=c1:B += c2;
            }
            cout<<"    ("<<A<<","<<B-A<<")\n";
        }
    }
    return 0;
}
