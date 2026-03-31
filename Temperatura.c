#include <stdio.h>
float F, C;
int main() {
    printf("Entre com a temperatura em Celsius: ");
    scanf("%f", &C);
    F = C * 1.8 + 32;
    printf("Temperatura em Fahrenheit: %.2f\n", F);
    return 0;
}