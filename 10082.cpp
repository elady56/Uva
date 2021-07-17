#include <bits/stdc++.h>
using namespace std;

int main() {
    string Array="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

    string word;
    while(getline(cin,word)){
        int aux=word.length();
        for(int i=0;i<aux;i++){
            if(word[i]!=' '){
                int j=0;
                while(Array[j]!=word[i]){
                    j++;
                }
                cout<<Array[j-1];
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
