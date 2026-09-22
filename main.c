#include <stdio.h>
#include <stdlib.h>

typedef struct equipamento {
    int cod_sltc;
    char cod_equip[8];
    char nome_equip[21];
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
                    printf("Digite o código do equipamento:");
                    fgets(equipamento.cod_equip, 8, stdin);
                } while();

                do {
                    printf("Digite o nome do equipamento: ");
                    fgets(equipamento.cod_equip, 22, stdin);
                } while();

                do {
                    flag = 0;
                    printf("Selecione a prioridade do equipamento: \n\n 1 - Alta \n 2 - Média \n 3 - Baixa");
                    flag = scanf("%d", &equipamento.prioridade);
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
