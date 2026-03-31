#include <stdio.h>
int main()
{
    printf("Bem vindo ao verificador de números pares e ímpares!\n"); // Exibe uma mensagem de boas-vindas ao usuário
   
    float num; // Declaração de uma variável do tipo float para armazenar o número digitado pelo usuário
   
    printf("Digite um número: "); // Solicita ao usuário que digite um número
  
    scanf("%f", &num); // Lê um número do usuário e armazena na variável 'num'

    if (num == 0) { // Verifica se o número é zero
   
    printf("O número é zero, que é considerado par.\n"); // Informa que o número é zero e é considerado par
} 
else if ((int)num % 2 == 0) { // Verifica se o número é par (após converter para inteiro)
    
    printf("O número %.f é par.\n", num); // Informa que o número é par
} 
   else{ // Caso contrário, o número é ímpar
   
    printf("O número %.f é ímpar.\n", num); // Informa que o número é ímpar
}
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
