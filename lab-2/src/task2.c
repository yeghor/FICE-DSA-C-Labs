#include <stdio.h>
#include <math.h>

// Program that uses dynamic programming memoization approach

double calculate(int n) {
    double result = 1.0;
    double DPCache = 0.0;
    int operations = 0;

    operations += 3;

    for(int i = 1; i <= n; i++) {
        operations += 2; // increment and compare

        double numerator;

        operations += 3;
        numerator = cos(i) + 1;

        operations += 3;
        // DPCache - step denominator
        DPCache = DPCache + sin(i);

        operations += 2;
        result *= (numerator / DPCache);
    }

    operations += 1; // Break the cycle comparison

    printf("Operations: %d\n ", operations);

    return result;
}

int main() {
    int n;
    printf("Enter the n number: ");
    scanf("%d", &n);

    double result = calculate(n);

    printf("Result: %.7f\n", result);

    return 0;
}
