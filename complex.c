#include <stdio.h>

// Define a structure for complex numbers
typedef struct {
    double real;
    double imag;
} Complex;

// Function to read a complex number from the user
Complex readComplex() {
    Complex num;
    printf("Enter the real part: ");
    scanf("%lf", &num.real);
    printf("Enter the imaginary part: ");
    scanf("%lf", &num.imag);
    return num;
}

// Function to subtract two complex numbers
Complex subtractComplex(Complex num1, Complex num2) {
    Complex result;
    result.real = num1.real - num2.real;
    result.imag = num1.imag - num2.imag;
    return result;
}

// Function to multiply two complex numbers
Complex multiplyComplex(Complex num1, Complex num2) {
    Complex result;
    result.real = num1.real * num2.real - num1.imag * num2.imag;
    result.imag = num1.real * num2.imag + num1.imag * num2.real;
    return result;
}

// Function to compare two complex numbers and return the smallest among them
Complex findSmallestComplex(Complex num1, Complex num2) {
    if (num1.real < num2.real || (num1.real == num2.real && num1.imag < num2.imag)) {
        return num1;
    } else {
        return num2;
    }
}

int main() {
    Complex num1, num2, result;

    printf("Enter the first complex number:\n");
    num1 = readComplex();

    printf("\nEnter the second complex number:\n");
    num2 = readComplex();

    // Subtract two complex numbers
    result = subtractComplex(num1, num2);
    printf("\nSubtraction: %.2lf + %.2lfi\n", result.real, result.imag);

    // Multiply two complex numbers
    result = multiplyComplex(num1, num2);
    printf("Multiplication: %.2lf + %.2lfi\n", result.real, result.imag);

    // Compare two complex numbers and return the smallest among them
    result = findSmallestComplex(num1, num2);
    printf("Comparison: %.2lf + %.2lfi is the smallest.\n", result.real, result.imag);

    return 0;
}
