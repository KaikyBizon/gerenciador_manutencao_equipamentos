#include <stdio.h>
#include <stdlib.h>
#include "bib_P1.h"
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Portuguese");
    lista *gerenciador = crialista();
    gerenciador = inicializa_lista(gerenciador);

    int opt = -1;
    int flag = 0;
    equipamento novo_equip;

    do {
        printf("Escolha uma opção: \n\n 1 - Inserir nova solicitação \n 2 - Remover solicitação \n 3 - Consultar solicitação \n 4 - Alterar prioridade ou período \n 5 - Exibir ordem de realização de manutenção \n 6 - Exibir todas as solicitações \n 0 - Finalizar \n \n Opção: ");
        if (scanf("%d", &opt) != 1) {
            printf("Opção inválida! Digite um número.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opt) {
            case 1: {
                do {
                    novo_equip.cod_sltc = ler_codigo_solicitacao("\nDigite o código da solicitação (4 dígitos): ");
                    if (consultar_solicitacao_silencioso(gerenciador, novo_equip.cod_sltc) != NULL) {
                        printf("Erro: Já existe uma solicitação com o código %d!\n\n", novo_equip.cod_sltc);
                    } else {
                        break;
                    }
                } while (1);

                do {
                    while (getchar() != '\n');
                    printf("Digite o código do equipamento (ex: OSC023): ");
                    fgets(novo_equip.cod_equip, 8, stdin);
                    novo_equip.cod_equip[strcspn(novo_equip.cod_equip, "\n")] = '\0';

                    if (strlen(novo_equip.cod_equip) != 6) {
                        printf("Erro: O código deve ter exatamente 6 caracteres (ex: OSC023)!\n\n");
                        flag = 0;
                    } else {
                        flag = 1;
                    }
                } while (flag != 1);

                do {
                    printf("Digite o nome do equipamento: ");
                    fgets(novo_equip.nome_equip, 22, stdin);
                    novo_equip.nome_equip[strcspn(novo_equip.nome_equip, "\n")] = '\0';

                    if (strlen(novo_equip.nome_equip) > 20 || strlen(novo_equip.nome_equip) < 2) {
                        printf("Erro: O nome deve ter entre 2 e 20 caracteres!\n\n");
                        flag = 0;
                    } else {
                        flag = 1;
                    }
                } while (flag != 1);

                do {
                    printf("Selecione a prioridade (1 - Alta | 2 - Média | 3 - Baixa): ");
                    if (scanf("%d", &novo_equip.prioridade) != 1 || novo_equip.prioridade < 1 || novo_equip.prioridade > 3) {
                        printf("Valor inválido. Digite um número de 1 a 3!\n");
                        while (getchar() != '\n');
                        flag = 0;
                    } else {
                        flag = 1;
                    }
                } while (flag != 1);

                do {
                    printf("A prioridade é %d (%s).\n", novo_equip.prioridade, obter_periodo(novo_equip.prioridade));
                    printf("Digite o período em dias: ");
                    if (scanf("%d", &novo_equip.periodo) != 1 || !validar_periodo(novo_equip.prioridade, novo_equip.periodo)) {
                        printf("Período fora do limite permitido para esta prioridade!\n\n");
                        while (getchar() != '\n');
                        flag = 0;
                    } else {
                        flag = 1;
                    }
                } while (flag != 1);

                gerenciador = InsereNovaSol(gerenciador, novo_equip);
                printf("\nSolicitação inserida com sucesso!\n");
                break;
            }

            case 2: {
                if (gerenciador == NULL || gerenciador->inicio == NULL) {
                    printf("\nNão há solicitações cadastradas para remover.\n");
                    break;
                }

                int cod_remover = ler_codigo_solicitacao("\nDigite o código da solicitação que deseja remover: ");
                gerenciador = remove_solicitacao(gerenciador, cod_remover);
                break;
            }

            case 3: {
                if (gerenciador == NULL || gerenciador->inicio == NULL) {
                    printf("\nNão há solicitações cadastradas para consultar.\n");
                    break;
                }

                int cod_consultar = ler_codigo_solicitacao("\nDigite o código da solicitação que deseja consultar: ");
                consultar_solicitacao(gerenciador, cod_consultar);
                break;
            }

            case 4: {
                if (gerenciador == NULL || gerenciador->inicio == NULL) {
                    printf("\nNão há solicitações cadastradas para alterar.\n");
                    break;
                }

                int cod_alterar = ler_codigo_solicitacao("\nDigite o código da solicitação que deseja alterar: ");
                alterar_prioridade_periodo(gerenciador, cod_alterar);
                break;
            }

            case 5: {
                if (gerenciador == NULL || gerenciador->inicio == NULL) {
                    printf("\nNão há solicitações cadastradas para ordenar.\n");
                    break;
                }

                exibir_ordem_manutencao(gerenciador);
                break;
            }

            case 6: {
                if (gerenciador == NULL || gerenciador->inicio == NULL) {
                    printf("\nA lista de solicitações está vazia.\n");
                    break;
                }

                exibir_lista(gerenciador);
                break;
            }

            case 0: {
                printf("\nEncerrando o sistema e liberando memória...\n");
                gerenciador = liberar_lista(gerenciador);
                printf("Sistema finalizado com sucesso!\n");
                break;
            }

            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }

    } while (opt != 0);

    return 0;
}
