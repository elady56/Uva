/*Copied from there
 * https://blog.csdn.net/thudaliangrx/article/details/50700688?locationNum=2&fps=1#t9*/
#include <bits/stdc++.h>
using namespace std;

struct Chess{
    char t;
    int x,y;
};


char tab0[11][11],tab[11][11];
Chess gnr;
int n;
Chess pos[8];

int mov[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int movH[8][2]={{1,2},{-1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,1},{-2,-1}};

bool legal(int x,int y){
    return 1<=x&&x<=3&&y<=6&&y>=4;
}

int cnt(Chess p1,Chess p2){
    int cnt=0;
    if(p1.x==p2.x){
        int add=(p1.y<p2.y?1:-1);
        for (int i = p1.y+add; i!=p2.y; i+=add) {
            if(tab[p1.x][i]!='0') cnt++;
        }
    }
    else if(p1.y==p2.y){
        int add=(p1.x<p2.x?1:-1);
        for (int i = p1.x+add; i!=p2.x; i+=add) {
            if(tab[i][p1.y]!='0') cnt++;
        }
    }else
        cnt=-1;
    return cnt;
}

bool check(){
    for (int i = 1; i <=n; i++) {
        if(pos[0].x==pos[i].x&&pos[0].y==pos[i].y) continue;
        if(pos[i].t=='G'||pos[i].t=='R'){
            if(cnt(pos[0],pos[i])==0) return false;
        }else if(pos[i].t=='C'){
            if(cnt(pos[0],pos[i])==1) return false;
        }else if(pos[i].t=='H'){
            for (int j = 0; j <8; ++j) {
                if(pos[i].x+movH[j][0]==pos[0].x&&
                pos[i].y+movH[j][1]==pos[0].y&&
                tab[pos[i].x+mov[j/2][0]][pos[i].y+mov[j/2][1]]=='0')
                    return false;
            }
        }
    }
    return true;
}

int main(){
    while ((cin>>n>>gnr.x>> gnr.y)&&(n|| gnr.y||gnr.y)){
        memset(tab0,'0', sizeof(tab0));
        tab0[gnr.x][gnr.y]='1';
        for (int i = 1; i <=n; i++) {
            cin>>pos[i].t>>pos[i].x>>pos[i].y;
            tab0[pos[i].x][pos[i].y]=pos[i].t;
        }
        bool res=true;
        for (int i = 1; i <=8; ++i) {
            if (pos[i].t == 'G') {
                memcpy(tab,tab0, sizeof(tab0));
                pos[0].x=gnr.x;
                pos[0].y=gnr.y;
                if(cnt(pos[0],pos[i])==0){res=false;}
                break;
            }
        }
        for (int i = 0; i <4&&res ; ++i) {
            memcpy(tab,tab0, sizeof(tab0));
            pos[0].x=gnr.x+mov[i][0];
            pos[0].y=gnr.y+mov[i][1];
            if(!legal( pos[0].x, pos[0].y)) continue;
            tab[ pos[0].x][ pos[0].y]='1';
            tab[gnr.x][gnr.y]='0';
            if(check()){res=false;break;}
        }
        if(res)puts("YES");
        else puts("NO");
        getchar();
    }
}