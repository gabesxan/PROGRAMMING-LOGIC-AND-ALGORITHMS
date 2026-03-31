

#include <stdio.h>   // Precisamos dessa biblioteca pra conseguir
                     // exibir texto na tela e ler o que o usuário digita.

#include <string.h>  // Essa aqui a gente usa pra trabalhar com textos,
                     // como remover o Enter que fica sobrando depois
                     // que o usuário digita algo.

int main() {

    // Aqui a gente declara todas as variáveis que vamos usar.
    // Pensa nelas como "caixinhas" que guardam informações
    // enquanto o programa está rodando.

    char nome_passageiro[80];  // Nome de quem vai usar o app.
                               // Cabe até 80 letras.

    char cidade_origem[60];    // De onde a pessoa está saindo.
    char cidade_destino[60];   // Pra onde ela quer ir.
    char observacao[300];      // Um comentário que o passageiro pode
                               // deixar no final da corrida.

    int genero;          // 1 se for homem, 2 se for mulher.
    int nota;            // A estrelinhas que o passageiro dá pro motorista.
    int deseja_gorjeta;  // Se a pessoa quer dar gorjeta ou não.

    float km;               // A distância que o usuário vai informar.
    float taxa_fixa = 5.00; // Todo mundo paga isso, independente da distância.
    float preco_km = 1.75;  // Cada km rodado custa esse valor.
    float valor_km;         // Aqui vai o resultado de: km × preco_km.
    float valor_total;      // O valor final da corrida: taxa fixa + valor dos km.
    float gorjeta = 0.00;   // Começa zerado. Só muda se o passageiro quiser dar.
    float total_pago;       // Tudo junto: corrida + gorjeta (se tiver).

    // Boas-vindas e coleta do nome do passageiro

    printf("Bem vindo ao Peythons!\n");

    printf("\nSeu nome:");

    // fgets é a forma mais segura de ler um texto que o usuário digita,
    // porque a gente consegue limitar quantos caracteres ele aceita.
    // O "stdin" ali no final significa "lê do teclado".
    fgets(nome_passageiro, sizeof(nome_passageiro), stdin);

    // Quando o usuário aperta Enter, o fgets guarda um '\n' junto com o texto.
    // Essa linha aqui remove esse Enter pra não bagunçar o nome.
    nome_passageiro[strcspn(nome_passageiro, "\n")] = '\0';

    // Agora a gente pergunta o gênero pra poder alocar o motorista certo

    printf("\nSeu genero:\n");
    printf("1 - Masculino\n2 - Feminino\n");
    printf("Opção: ");

    // scanf lê o que o usuário digitou. O "%d" diz que esperamos um número.
    // O "&" antes de "genero" é obrigatório — ele indica onde na memória
    // o valor deve ser guardado.
    scanf("%d", &genero);

    // Se a pessoa digitar qualquer coisa que não seja 1 ou 2,
    // o programa fica pedindo de novo até ela digitar certo.
    while(genero != 1 && genero != 2) {
        printf("Opcao invalida. Por favor, selecione 1 para Masculino ou 2 para Feminino.\n");
        printf("Opção: ");
        scanf("%d", &genero);
    }

    // Com base no gênero, a gente escolhe qual motorista vai aparecer.
    // Se for mulher, por segurança, alocamos uma motorista feminina.
    if (genero == 2) {
        printf("[Segurança] Motorista feminina alocada.\n");
        printf("Motorista: Ana Silva\n");
        printf("Veículo: Toyota Corolla 2020\n");
    }
    else {
        printf("Motorista: Carlos Souza\n");
        printf("Veículo: Honda Civic 2019\n");
    }

    // Aqui tem um detalhe importante: o scanf deixa um Enter "sobrando"
    // no buffer do teclado. Se a gente não limpar isso com getchar(),
    // o fgets lá embaixo vai ler esse Enter em vez de esperar
    // o usuário digitar a cidade. É chato, mas é assim que o C funciona.
    getchar();

    printf("\nCidade de origem:");
    fgets(cidade_origem, sizeof(cidade_origem), stdin);
    cidade_origem[strcspn(cidade_origem, "\n")] = '\0'; // Tira o Enter do final

    printf("\nCidade de destino:");
    fgets(cidade_destino, sizeof(cidade_destino), stdin);
    cidade_destino[strcspn(cidade_destino, "\n")] = '\0'; // Tira o Enter do final

    printf("\nDistância em km (em números apenas):");
    scanf("%f", &km); // "%f" porque km é um número com casas decimais

    // Cálculo do valor da corrida.
    // Primeiro vemos quanto os km custam, depois somamos a taxa fixa.
    // Exemplo: 10km × R$1,75 = R$17,50 + R$5,00 de taxa = R$22,50 no total.
    valor_km    = km * preco_km;
    valor_total = valor_km + taxa_fixa;

    // Mostra um resumo bonitinho pra o usuário conferir tudo antes de pagar.
    // %s exibe textos e %.2f exibe números com 2 casas decimais.
    printf("\nResumo da Corrida:\n");
    printf("Passageiro: %s\n", nome_passageiro);
    printf("Origem: %s\n", cidade_origem);
    printf("Destino: %s\n", cidade_destino);
    printf("Distância: %.2f km\n", km);
    printf("Valor por km: R$ %.2f\n", preco_km);
    printf("Total: R$ %.2f\n", valor_total);

    // Chegou a hora de avaliar o motorista!
    // A nota vai de 1 a 5 estrelas.
    printf("\nAvalie o motorista (1 a 5 estrelas): ");
    scanf("%d", &nota);

    // Se a pessoa digitar algo fora do intervalo, a gente pede de novo.
    while(nota < 1 || nota > 5) {
        printf("Nota inválida. Por favor, avalie entre 1 e 5 estrelas: ");
        scanf("%d", &nota);
    }

    // A gorjeta só aparece se a nota for 3 ou mais.
    // Notas baixas (1 e 2) significam que o motorista não merece gorjeta.
    // Quanto melhor a nota, maior o percentual sugerido:
    // 3 estrelas → 3% | 4 estrelas → 5% | 5 estrelas → 10%
    if(nota >= 3) {
        float percentual;

        if(nota == 3)       percentual = 0.03;
        else if (nota == 4) percentual = 0.05;
        else                percentual = 0.10;

        float gorjeta = valor_total * percentual;

        printf("\nVoce Avaliou com %d estrela(s)\n", nota);
        printf("Deseja dar uma gorjeta de R$ %.2f?\n", gorjeta);
        scanf("%d", &deseja_gorjeta);
    }

    // Se o usuário confirmou a gorjeta, ela é adicionada ao total.
    // Se não quis, o valor continua zero mesmo.
    if(deseja_gorjeta == 1) {
        gorjeta = gorjeta;
        printf("Obrigado pela gorjeta de R$ %.2f!\n", gorjeta);
    }
    else {
        printf("Obrigado por avaliar o motorista!\n");
    }

    // Mostra o fechamento financeiro da corrida.
    // O motorista leva 80% do total — os outros 20% ficam com a plataforma.
    total_pago = valor_total + gorjeta;

    printf("Corrida: R$ %.2f\n", valor_total);
    printf("Gorjeta: R$ %.2f\n", gorjeta);
    printf("-------------------------\n");
    printf("PAGAMENTO FINAL: R$ %.2f\n", total_pago);
    printf(" Repasse para o/a motorista: R$ %.2f\n", total_pago * 0.80);
    printf("--------------------------\n");

    // Por último, o passageiro pode deixar um comentário sobre a corrida.
    // É opcional — se não quiser escrever nada, é só apertar Enter.
    getchar(); // Limpa o buffer de novo pelo mesmo motivo de antes

    printf("\n Escreva uma observação para o motorista (opcional):");
    fgets(observacao, sizeof(observacao), stdin);
    observacao[strcspn(observacao, "\n")] = '\0';

    // strlen conta quantas letras têm no texto.
    // Se for zero, o usuário não escreveu nada e a gente ignora.
    if(strlen(observacao) > 0) {
        printf("Observação registrada: \"%s\"\n", observacao);
    }

    // Tudo certo! Programa finalizado sem erros.
    // O "return 0" é uma convenção do C pra avisar o sistema
    // que tudo correu bem.
    printf("\nObrigado por usar o Peythons! Tenha um ótimo dia!\n");

    return 0;
}