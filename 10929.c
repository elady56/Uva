#include <stdio.h>

int result(int nNeed,int nChange,int *nBuy);


int main(){
    int nNeed,nChange,nBuy;
    scanf("%d %d %d",&nNeed,&nChange,&nBuy);
    while(nNeed>0){
        if(nChange>=nNeed){
            printf("RUINA\n");
        } else{
            int aux=nBuy;
            int nEat=result(nNeed,nChange,&nBuy);
            printf("%d %d\n",nEat+aux,nBuy);
        }
        scanf("%d %d %d",&nNeed,&nChange,&nBuy);
    }
    return 0;
}

int result(int nNeed,int nChange,int *nBuy){
    int aux=((*nBuy)/nNeed)*nChange;
    if(*nBuy<nNeed){
        return aux;
    } else{
        *nBuy=(*nBuy%nNeed)+aux;
        return aux + result(nNeed,nChange,nBuy);
    }
}
