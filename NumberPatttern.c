#include<stdio.h>
int main()
{
    int n;
    printf("Enter the value of n:\n");
    scanf("%d",&n);
    //n = 5;
    int k = n;
    for(int i = 0;i < n;i++){
            k = n;
        for(int j = 0;j < 2*n-1;j++){
            printf("%4d",k);
            if(j < i)
                k--;

            else if(j == n-1 && i == n-1)
                k++;
            else if(j >= 2*n-2-i && j > i)
                k++;

        }
        printf("\n");
    }
    //putchar('\n');
    for(int i = n-2;i >= 0;i--){
            k = n;
        for(int j = 0;j < 2*n-1;j++){
            printf("%4d",k);
            if(j < i)
                k--;

            else if(j == n-1 && i == n-1)
                k++;
            else if(j >= 2*n-2-i && j > i)
                k++;

        }
        printf("\n");
    }
    return 0;
}
/*
0       n-1
0 1 2 3 4 5 6 7 8
5 4 3 2 2 2 3 4 5
5 4 3 2 1 2 3 4 5
*/
