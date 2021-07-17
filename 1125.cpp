#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[10],n,a;
    cin>>n;
    while (n--){
        memset(arr,0, sizeof(arr));
        cin>>a;
        for (int i = 1; i <= a; ++i) {
            int n=i;
            while (n){
                int aux=n%10;
                n/=10;
                arr[aux]++;
            }
        }
        for (int i = 0; i < 10; ++i) {
            if(i){
                cout<<" ";
            }
            cout<<arr[i];
        }
        cout<<endl;
    }
    return 0;
}
