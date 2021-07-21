#include<stdio.h>

long long int result(long long int number_i,int * iteration);

int main(){
    int n,i,aux,iteration;
    long long int number_i,number_e,a;
    scanf("%d",&n);
    for (i=0; i < n; i++) {
        scanf("%lld",&number_i);
        a=number_i;
        number_e=0;
        while(a!=0){
            aux=a%10;
            number_e=(number_e*10)+aux;
            a=a/10;
        }
        iteration=1;
        number_i=number_i+number_e;
        number_e=result(number_i,&iteration);
        printf("%d %lld\n",iteration,number_e);
    }
    return 0;
}

long long int result(long long int number_i,int * iteration){
    long long int number_e;
    int aux;
    number_e=0;
    long long int a=number_i;
    while(a!=0){
        aux=a%10;
        number_e=(number_e*10)+aux;
        a=a/10;
    }
    if(number_e==number_i){
        return number_i;
    }else{
        (*iteration)++;
        number_i=number_e+number_i;
        result(number_i,iteration);
    }
}