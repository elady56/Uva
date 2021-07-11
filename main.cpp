#include <bits/stdc++.h>
using namespace std;

char puzzle[10][10];

int main() {
    int r,c,k=0;
    while (cin>>r>>c&&r!=0){
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin>>puzzle[i][j];
            }
        }

        cout<<"puzzle #"<<++k<<":\n";
        int aux=1;
        cout<<"Across\n";
        for (int i = 0; i <r; ++i) {
            for (int j = 0; j < c; ++j) {
                printf("%2.d.",aux++);
                while (puzzle[i][j]!='*'&&j<c){
                    cout<<puzzle[i][j];
                    j++;
                }
                cout<<endl;
            }
        }
        aux=1;
        cout<<"\nDown\n";
        printf("%2.d.",aux);
        for (int i = 0; i <r; ++i) {
            for (int j = 0; j < c; ++j) {
                if(puzzle[j][i]!='*'){
                    cout<<puzzle[j][i];
                }else{
                    cout<<"\n";
                    aux++;
                    printf("%2.d.",aux);
                }

            }
        }
    }
    return 0;
}
