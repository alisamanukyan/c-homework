#include <stdio.h>
struct Complex{
    float real;
    float imaginary;
};

struct Complex addComplex(struct Complex num1, struct Complex num2){
    struct Complex result;
    result.real = num1.real + num2.real;
    result.imaginary = num1.imaginary + num2.imaginary;

    return result;
}

struct Complex multiplyComplex(struct Complex num1, struct Complex num2){
    struct Complex result;
    result.real = num1.real * num2.real - num1.imaginary * num2.imaginary;
    result.imaginary = num1.real * num2.imaginary + num1.imaginary * num2.real;
    
    return result;
}

int main(){
    struct Complex num1, num2, sum, product;

    printf("Enter the first complex number: ");
    scanf("%f %f", &num1.real, &num1.imaginary);

    printf("\n");

    printf("Enter the second complex number: ");
    scanf("%f %f", &num2.real, &num2.imaginary);

    sum = addComplex(num1, num2);
    product = multiplyComplex(num1, num2);

    printf("Sum = %.2f + %.2fi\n", sum.real, sum.imaginary);

    printf("Product = %.2f ", product.real);
    if (product.imaginary < 0) {
        printf("- %.2fi\n", -product.imaginary); 
    } else {
        printf("+ %.2fi\n", product.imaginary);
    }
    return 0;
}
