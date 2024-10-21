#include <stdlib.h>
#include <stdio.h>

int main(){
    int num;
    int random_num = rand() % 100 + 1;
    do{
        printf("Enter a number: ");
        scanf("%d",&num);
        if(num>random_num){
            printf("The number is too high. Try again. ");
        }
        else if(num<random_num){
            printf("The number is too low. Try again. ");
        }
        else if(num==random_num){
            printf("You win!!");
        }
    }while(num!=random_num);
}