#include<stdio.h>
int main(){
    int m = 7;
    int cnt = 0;
    int n = m;
//    int temp = n;
    while(n){
    n = n & (n-1);
    cnt++;  
    }
    printf("%d\n",cnt);

    for (int i = m+1; i<100;i++){
        int cnt1 = 0;
	int z = i;
        while(z!=0){
            z = z & (z-1);
            cnt1++;
        }
        if (cnt1 == cnt){
            printf("%d ",i);
	    break;
        }

    }
    printf("\n");
    return 0;
}
