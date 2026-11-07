#include <stdio.h>
 
int main() {
    int pacotes[20];
    int n;
    int entregues = 0;
    int perdidos = 0;
    int sequenciaAtual = 0;
    int maiorSequencia = 0;
    int i;
 
    printf("=== SIMULADOR DE PERDA DE PACOTES ===\n");
 
    do {
        printf("Quantidade de pacotes (1 a 20): ");
        scanf("%d", &n);
        if (n < 1 || n > 20) {
            printf("Entrada invalida! Digite um valor entre 1 e 20.\n");
        }
    } while (n < 1 || n > 20);
 
    for (i = 0; i < n; i++) {
        do {
            printf("Pacote %d (1 = entregue, 0 = perdido): ", i + 1);
            scanf("%d", &pacotes[i]);
            if (pacotes[i] != 0 && pacotes[i] != 1) {
                printf("Entrada invalida! Digite somente 0 ou 1.\n");
            }
        } while (pacotes[i] != 0 && pacotes[i] != 1);
    }
 
    for (i = 0; i < n; i++) {
        if (pacotes[i] == 1) {
            entregues = entregues + 1;
            sequenciaAtual = 0;
        } else {
            perdidos = perdidos + 1;
            sequenciaAtual = sequenciaAtual + 1;
            if (sequenciaAtual > maiorSequencia) {
                maiorSequencia = sequenciaAtual;
            }
        }
    }
 
    double taxaPerda = perdidos * 100.0 / n;
 
    printf("\n=== RELATORIO ===\n");
    printf("Entregues: %d\n", entregues);
    printf("Perdidos: %d\n", perdidos);
    printf("Taxa de perda: %.1f%%\n", taxaPerda);
    printf("Maior sequencia de perdas: %d\n", maiorSequencia);
 
    if (taxaPerda > 20.0) {
        printf("ALERTA: taxa de perda acima de 20%%!\n");
    } else {
        printf("Situacao normal: sem alerta.\n");
    }
 
    printf("\nLembrete: simulacao com dados digitados; nenhum pacote foi transmitido.\n");
 
    return 0;
}
 
