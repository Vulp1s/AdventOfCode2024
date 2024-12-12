#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b, safe = 0, flag;
    int check, valid;

    for(int i = 0 ; i<1000 ; i++){
        scanf("%d %d", &a, &b);
        valid = 1;
        flag = a<b ? 1 : -1;
        if(abs(a-b)>3 || a==b) valid = 0;
        while ((check = getchar()) != '\n' ){
            ungetc(check,stdin);
            scanf("%d",&a);
            if(abs(a-b)>3 || a-b==0){
                valid = 0;
            }
            if((a-b) * flag < 0){
                valid = 0;
            }
            b = a;
        }
        safe += valid;
                
    }
    printf("number of valid reports is %d", safe);
    
}