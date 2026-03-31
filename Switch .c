#include <stdio.h>
int main() {
 int nota =0; 
 printf("Digite a nota do aluno: ");
 scanf("%d", &nota);
 switch(nota) {
    case 10:   
    case 9:
    case 8:
    case 7:
printf("Aprovado\n");
    break;
    case 6:
printf("Recuperação\n");
    break;
    default:
    printf("Reprovado\n");
    }
    return 0;
}
