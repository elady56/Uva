#include <bits/stdc++.h>
using namespace std;
#define maxn 1000
double eps=1e-5;

map<string,int> si;
struct spms{
    string SID,name;
    int  CID,score[5];
}SPMS[maxn];

int n=0,removed[maxn];
const char* course_name[]={"Chinese","Mathematics","English","Programming"};


int Rank(int x){
    vector<pair<int,int>> V;
    int a=1;
    int aux1=SPMS[x].score[0]+SPMS[x].score[1]+SPMS[x].score[2]+SPMS[x].score[3];
    for (int i = 0; i < n; ++i) {
        int aux=SPMS[i].score[0]+SPMS[i].score[1]+SPMS[i].score[2]+SPMS[i].score[3];
        if(!removed[i]&&aux>aux1){
          a++;
        }
    }
    return a;
}

void show(int i){
    int aux=0;
    cout<<Rank(i)<<" "<<SPMS[i].SID<<" "<<SPMS[i].CID<<" "<<SPMS[i].name<<" ";
    for (int j = 0; j< 4; ++j) {
        printf("%d ",SPMS[i].score[j]);
        aux+=SPMS[i].score[j];
    }
    printf("%d %.2f\n",aux,(float)aux/4);

}

void mainP(){
    cout<<"Welcome to Student Performance Management System (SPMS).\n\n";
    printf("1 - Add\n"
          "2 - Remove\n"
          "3 - Query\n"
          "4 - Show ranking\n"
          "5 - Show Statistics\n"
          "0 - Exit\n\n");
}

int aux(string sid){
    for (int i = 0; i < n; ++i) {
        if(SPMS[i].SID==sid&&!removed[i]) return 0;
    }
    return 1;
}
void add(){
    while (1){
        cout<<"Please enter the SID, CID, name and four scores. Enter 0 to finish.\n";
        cin>>SPMS[n].SID;
        if(SPMS[n].SID=="0") break;
        else{
            cin >> SPMS[n].CID >> SPMS[n].name;
            for (int i = 0; i < 4; ++i) {
                cin>>SPMS[n].score[i];
            }
            if(!aux(SPMS[n].SID)){
                cout<<"Duplicated SID.\n";
            }else{
                n++;
            }
        }
    }

}

void RQ(int isq){
    while (1){
        cout<<"Please enter SID or name. Enter 0 to finish.\n";
        string aux;
        cin>>aux;
        if(aux == "0") break;
        int r=0;
        for (int i = 0; i <= n; ++i) if(!removed[i]){
            if((aux==SPMS[i].name) ||(aux==SPMS[i].SID) ){
                if(isq)show(i);
                else{removed[i]=1;r++;}
            }
        }
        if(!isq)cout<<r<<" student(s) removed.\n";
    }
}

void get_all_stat(int cnt[4],int cid){
    for (int i = 0; i < n; ++i) {
        if ((cid==0||SPMS[i].CID==cid)&&!removed[i]){
            int t=0;
            for (int j = 0; j < 4; ++j) {
                if(SPMS[i].score[j]>=60)t++;
            }
            cnt[t]++;
        }

    }
}
double get_course_stat( int cid,int i,int *passed,int *failed){
    double aux=0;
    for (int j = 0; j < n; ++j) {
        if((cid==0||SPMS[j].CID==cid)&&!removed[j]){
            if(SPMS[j].score[i]>=60)(*passed)++;
            else (*failed)++;
            aux+=SPMS[j].score[i];
        }
    }
    return aux/((*passed)+(*failed));

}

void Stat(){
    int cnt[5];
    memset(cnt,0, sizeof(cnt));
    cout<<"Please enter class ID, 0 for the whole statistics.\n";
    int cid;cin >> cid;
    for (int i = 0; i < 4; ++i) {
        int passed=0,failed=0;
        double avg=get_course_stat(cid,i,&passed,&failed)+eps;
        cout<<course_name[i]<<endl;
        printf("Average Score: %.2f\n",avg);
        printf("Number of passed students: %d\n",passed);
        printf("Number of failed students: %d\n\n",failed);
    }
    get_all_stat(cnt,cid);
    printf("Overall:\n");
    printf("Number of students who passed all subjects: %d\n",cnt[4]);
    printf("Number of students who passed 3 or more subjects: %d\n",cnt[4]+cnt[3]);
    printf("Number of students who passed 2 or more subjects: %d\n",cnt[4]+cnt[3]+cnt[2]);
    printf("Number of students who passed 1 or more subjects: %d\n",cnt[4]+cnt[3]+cnt[2]+cnt[1]);
    printf("Number of students who failed all subjects: %d\n\n",cnt[0]);


}
int main() {
    int cmd;
    mainP();
    memset(removed,0, sizeof(removed));
    while (cin>>cmd&&cmd){
        if(cmd==1) add();
        if(cmd==2) RQ(0);
        if(cmd==3) RQ(1);
        if(cmd==4) cout<<"Showing the ranklist hurts students' self-esteem. Don't do that.\n";
        if(cmd==5) Stat();
        mainP();
    }
    return 0;
}


