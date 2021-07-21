
#include <stdio.h>

int main(){

    int n1,n2;
    while (scanf("%d %d",&n1,&n2)== 2) {
        int start,end;
        if (n1<n2){
             start = n1;
             end   = n2;
        }else{
             start = n2;
             end   = n1;
        }
        int maximo = 0;

        int i = start;
        for ( i = start; i <= end; i++) {

            int counter = 1;
            int currentValue = i;
            while (currentValue != 1) {
                counter++;
                if (currentValue % 2 != 0) {
                    currentValue = 3 * currentValue + 1;
                } else {
                    currentValue = currentValue / 2;
                }
            }
            if (counter > maximo) {
                maximo = counter;
            }
        }
        printf("%d %d %d\n", n1, n2, maximo);
    }
}