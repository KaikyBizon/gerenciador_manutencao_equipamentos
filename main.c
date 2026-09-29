#include <stdio.h>
#include <stdlib.h>

typedef struct equipamento {
    int cod_sltc;
    char cod_equip[8];
    char nome_equip[22];
    int prioridade;
    int periodo;
};



int main() {

    Lista *gerenciador = crialista();
    gerenciador = inicializa_lista();


    int opt;
    printf("Escolha uma opção: \n\n 1 - Inserir nova solicitacao \n 2 - Remover solicitacao \n 3 - Consultar solicitacao \n 4 - Alterar prioridade ou periodo \n 5 - Exibir ordem de realizacao de manutencao \n 6 - Exibir todas as solicitacoes \n 0 - Finalizar \n");
    scanf("%d", &opt);
    switch (opt){
        case 1:
                int flag = 0;
                do {
                    printf("Digite o codigo da solicitacao: ");
                    flag = scanf("%d", &equipamento.cod_sltc);
                    if (flag != 1){
                        printf("Valor incorreto. Tente novamente!");
                    }
                } while(flag != 1);

                do {
                    flag = 0;
                    printf("Digite o código do equipamento:");

                    fgets(equipamento.cod_equip, 8, stdin);
                    equipamento.cod_equip[strcspn(equipamento.cod_equip, "\n")] = '\0';


                    if (strlen(equipamento.cod_equip) > 6) {
                        printf("Erro: O código '%s' tem mais de 6 caracteres!\n\n", equipamento.cod_equip);
                        flag = 1;
                    } else if (strlen(equipamento.cod_equip) == 0) {
                        printf("Erro: O código nao pode ser vazio!\n\n");
                        flag = 1;
                    } else {
                        flag = 0;
                    }

                } while(flag != 0);

                do {
                    flag = 0;
                    printf("Digite o nome do equipamento: ");

                    fgets(equipamento.cod_equip, 22, stdin);
                    equipamento.nome_equip[strcspn(equipamento.nome_equip, "\n")] = '\0';

                    if (strlen(equipamento.nome_equip) > 20) {
                        printf("O nome deve ter no máximo 20 caracteres!\n\n");
                        flag = 1;
                    } else if (strlen(equipamento.nome_equip) < 2) {
                        printf("Nome muito curto! O nome deve ter no mínimo 2 caracteres.");
                        flag = 1;
                    } else {
                        flag = 0;
                    }
                } while(flag != 0);

                do {
                    flag = 0;
                    printf("Selecione a prioridade do equipamento: \n\n 1 - Alta \n 2 - Média \n 3 - Baixa");
                    flag = scanf("%d", &equipamento.prioridade);

                    printf("Valor inválido. Digite um numero de  1 a 3");
                } while(flag != 1);

                do {
                    flag = 0;
                    printf("Selecione o período para o equipamento:")
                    // Criar função para mostrar somente o período de acordo com a prioridade
                    flag = scanf("%d", &equipamento.periodo);
                } while(flag != 1);
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
