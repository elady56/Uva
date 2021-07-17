#include <bits/stdc++.h>
using namespace std;

const char* rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

char reverse(char ch) {
    if(isalpha(ch)) return rev[ch - 'A'];
    return rev[ch - '0' + 25];
}

int main() {
    string s;
    const char* msg[]= {"not a palindrome", "a regular palindrome",
                        "a mirrored string", "a mirrored palindrome"};
    while(cin>>s){
        cout<<s<<" -- is ";
        int l=s.length();
        int p=1,m=1;
        for (int i = 0; i <(l+1)/2; i++) {
            if(s[i] != s[l-1-i]) p = 0;
            if(reverse(s[i]) != s[l-1- i]) m=0;
        }
        cout<<msg[2*m+p]<<"."<<endl<<endl;
    }
    return 0;
}
