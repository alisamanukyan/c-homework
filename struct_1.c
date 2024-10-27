// Define a structure named Time with members hours, minutes, and seconds.
// Write a C program to input two times, add them, and display the result in
// proper time format.
#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

struct Time addTimes(struct Time t1, struct Time t2){
    struct Time result;

    result.seconds = t1.seconds + t2.seconds;
    result.minutes = t1.minutes + t2.minutes + result.seconds/60;
    result.seconds %= 60;
    result.hours = t1.hours + t2.hours + result.minutes / 60;
    result.minutes %= 60;
    result.hours %= 24;
    
    return result;
}

int main() {
    struct Time time1; 
    struct Time time2;
    struct Time result;
    
    printf("Hour Minute Second: ");
    scanf("%d %d %d", &time1.hours, &time1.minutes, &time1.seconds);

    printf("Hour Minute Second: ");
    scanf("%d %d %d", &time2.hours, &time2.minutes, &time2.seconds);
    
    result = addTimes(time1, time2);
    printf("You entered: %02d:%02d:%02d\n", result.hours, result.minutes, result.seconds);
    return 0;
}


