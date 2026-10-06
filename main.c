#include <stdio.h>
#include <stdlib.h>
#include "bib_P1.h"

int main() {

    lista *gerenciador = crialista();
    gerenciador = inicializa_lista(gerenciador);


    int opt;
    equipamento novo_equip;
    printf("Escolha uma opção: \n\n 1 - Inserir nova solicitacao \n 2 - Remover solicitacao \n 3 - Consultar solicitacao \n 4 - Alterar prioridade ou periodo \n 5 - Exibir ordem de realizacao de manutencao \n 6 - Exibir todas as solicitacoes \n 0 - Finalizar \n");
    scanf("%d", &opt);
    switch (opt){
        case 1:
                int flag = 0;
                do {
                    printf("Digite o codigo da solicitacao: ");
                    flag = scanf("%d", &novo_equip.cod_sltc);
                    if (flag != 1){
                        printf("Valor incorreto. Tente novamente!\n\n");
                        flag = 0;
                        while (getchar() != '\n');
                        continue;
                    } else if (novo_equip.cod_sltc < 1000 || novo_equip.cod_sltc > 9999){
                        printf("O código deve ter 4 digitos. Tente novamente! \n\n");
                        flag = 0;
                    }
                } while(flag != 1);

                do {
                    while (getchar() != '\n');
                    printf("Digite o código do equipamento:");

                    fgets(novo_equip.cod_equip, 8, stdin);
                    novo_equip.cod_equip[strcspn(novo_equip.cod_equip, "\n")] = '\0';


                    if (strlen(novo_equip.cod_equip) > 6) {
                        printf("Erro: O código '%s' tem mais de 6 caracteres!\n\n", novo_equip.cod_equip);
                        flag = 0;
                    } else if (strlen(novo_equip.cod_equip) == 0) {
                        printf("Erro: O código nao pode ser vazio!\n\n");
                        flag = 0;
                    } else {
                        flag = 1;
                    }

                } while(flag != 1);

                do {
                    flag = 0;
                    printf("Digite o nome do equipamento: ");

                    fgets(novo_equip.nome_equip, 22, stdin);
                    novo_equip.nome_equip[strcspn(novo_equip.nome_equip, "\n")] = '\0';

                    if (strlen(novo_equip.nome_equip) > 20) {
                        printf("O nome deve ter no máximo 20 caracteres!\n\n");
                        flag = 1;
                    } else if (strlen(novo_equip.nome_equip) < 2) {
                        printf("Nome muito curto! O nome deve ter no mínimo 2 caracteres.");
                        flag = 1;
                    } else {
                        flag = 0;
                    }
                } while(flag != 0);

                do {
                    flag = 0;
                    printf("Selecione a prioridade do equipamento: \n\n 1 - Alta \n 2 - Média \n 3 - Baixa");
                    flag = scanf("%d", &novo_equip.prioridade);

                    printf("Valor inválido. Digite um numero de  1 a 3");
                } while(flag != 1);

                do {
                    flag = 0;
                    printf("Selecione o período para o equipamento:");
                    // Criar função para mostrar somente o período de acordo com a prioridade
                    flag = scanf("%d", &novo_equip.periodo);
                } while(flag != 1);

                InsereNovaSol(gerenciador, novo_equip);

                exibir_lista(gerenciador);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 0:
            break;
        default:
            break;
    }
}
