#include <stdio.h>
int fibonacci(int n){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}
int main(){
    int n;
    int res;
    printf("Enter n: ");
    scanf("%d", &n);
    res = fibonacci(n);
    printf("%d",res);
}