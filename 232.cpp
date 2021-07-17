#include <bits/stdc++.h>
using namespace std;

typedef  pair<char,int> PAIR;

int main() {
    int r,c,k=0;
    while (cin>>r&&r!=0){
        cin>>c;
        PAIR puzzle[r][c];
        int aux=1;
        memset(puzzle,0, sizeof(puzzle));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin>>puzzle[i][j].first;
                if(puzzle[i][j].first!='*'){
                    if(i==0||j==0||(puzzle[i][j-1].first=='*'&&j>0)||puzzle[i-1][j].first=='*'&&i>0){
                        puzzle[i][j].second=aux++;
                    }
                }

            }
        }
        if(k) cout<<endl;
        cout<<"puzzle #"<<++k<<":\n";
        cout<<"Across\n";

        for (int i = 0; i <r; ++i) {
            for (int j = 0; j < c; ++j) {
                if(puzzle[i][j].first=='*') continue;
                printf("%3.d.",puzzle[i][j].second);
                while (puzzle[i][j].first!='*'&&j<c){
                    cout<<puzzle[i][j].first;
                    j++;
                }
                cout<<endl;
            }
        }
        cout<<"Down\n";
        int visited[r][c];
        memset(visited,0,sizeof (visited));
        for (int i = 0; i <r; ++i) {
            for (int j = 0; j < c; ++j) {
                if(visited[i][j]==1||puzzle[i][j].first=='*') continue;
                printf("%3.d.",puzzle[i][j].second);
                int k=i;
                while (puzzle[k][j].first!='*'&&k<r){
                    cout<<puzzle[k][j].first;
                    visited[k][j]++;
                    k++;
                }
                cout<<endl;
            }
        }

    }
    return 0;
}
