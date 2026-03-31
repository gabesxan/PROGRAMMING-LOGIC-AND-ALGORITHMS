#include   <stdio.h>
int main() {
    float num;
    printf("Nota do Aluno:");
    scanf("%f", &num);
    if (num >= 7) {
        printf("O aluno foi aprovado com a nota %.1f\n", num);
        } 
        else if (num >= 6) {
                printf("O aluno está de recuperação com a nota %.1f\n", num);
        } 
        else {
                printf("O aluno foi reprovado com a nota %.1f\n", num);
        }
        return 0;
 }