#include <bits/stdc++.h>
using namespace std;

pair <int,int> box[6];

bool check(){
    int w= (box[0].first==box[1].first)&&(box[1].first==box[2].first)&&(box[2].first==box[3].first);
    int h= (box[0].second==box[1].second)&&(box[1].second==box[4].first)&&(box[4].first==box[5].first);
    int l= (box[2].second==box[3].second)&&(box[3].second==box[4].second)&&(box[4].second==box[5].second);
    return w&&h&&l;

}


int main() {
    int a,b;
    while (cin>>a>>b){
        if(a>b){
            swap(a,b);
        }
        box[0].first=a,box[0].second=b;
        for (int i = 1; i <6; ++i) {
            cin>>a>>b;
            if(a>b){
                swap(a,b);
            }
            box[i].first=a,box[i].second=b;
        }
        sort(box,box+6);
        check()?cout<<"POSSIBLE\n":cout<<"IMPOSSIBLE\n";
    }
    return 0;
}
