#include <bits/stdc++.h>
using namespace std;
#define maxn 5


struct Blank{
    int x,y;
}blank;



bool move(char a,char puzzle[5][5]){
        switch (a) {
            case 'A':
                if(blank.x-1>=0){
                    puzzle[blank.x][blank.y]=puzzle[blank.x-1][blank.y];;
                    puzzle[blank.x-1][blank.y]=' ';
                    blank.x--;
                }else{
                    return false;
                }
                return true;
            case 'B':
                if(blank.x+1<5){
                    puzzle[blank.x][blank.y]=puzzle[blank.x+1][blank.y];
                    puzzle[blank.x+1][blank.y]=' ';
                    blank.x++;
                }else{
                    return false;
                }
                return true;
            case 'L':
                if(blank.y-1>=0){
                    puzzle[blank.x][blank.y]=puzzle[blank.x][blank.y-1];
                    puzzle[blank.x][blank.y-1]=' ';
                    blank.y--;
                }else{
                    return false;
                }
                return true;
            case 'R':
                if(blank.y+1<5){
                    puzzle[blank.x][blank.y]=puzzle[blank.x][blank.y+1];
                    puzzle[blank.x][blank.y+1]=' ';
                    blank.y++;
                }else{
                    return false;
                }
                return true;
            default:
                return false;
        }

}

int main() {
    int k=0;
    char a;
    char puzzle[5][5];
    while (1){
        bool empty= false;
        for (int i = 0; i < maxn; i++) {
            gets(puzzle[i]);
            if(puzzle[0][0]=='Z'){
                return 0;
            }
            for (int j = 0; j < maxn&&!empty; ++j) {
                if(puzzle[i][j]==' '||puzzle[i][j]=='\n'){
                    blank.x=i;
                    blank.y=j;
                    empty= true;
                }
            }
        }
        if(k){
            printf("\n");
        }
        cout<<"Puzzle #"<<++k<<":\n";
        bool flag= true;
        while (cin>>a&&a!='0'&&flag){
            flag=move(a,puzzle);
        }
        while (a!='0'){
            cin>>a;
        }
        if(flag){
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if(j)printf(" ");
                    printf("%c",puzzle[i][j]);
                }
                printf("\n");
            }
        }else{
            printf("This puzzle has no final configuration.\n");
        }
        char aux[5];
        gets(aux);
    }
}
