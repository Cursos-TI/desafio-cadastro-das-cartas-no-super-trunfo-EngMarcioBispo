#include <stdio.h>

// Estrutura para representar uma carta do Super Trunfo
typedef struct {
    char estado[3];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Função para calcular os valores derivados da carta (densidade populacional e PIB per capita)
void calcular_valores(Carta *c) {
    c->densidade_populacional = c->populacao / c->area;
    c->pib_per_capita = c->pib / c->populacao;
}

// Função para comparar duas cartas e determinar a vencedora
void comparar_cartas(Carta c1, Carta c2, char atributo[]) {
    float valor1, valor2;
    int menor_vence = 0;

    // Escolha do atributo para comparação
    if (strcmp(atributo, "populacao") == 0) {
        valor1 = c1.populacao;
        valor2 = c2.populacao;
    } else if (strcmp(atributo, "area") == 0) {
        valor1 = c1.area;
        valor2 = c2.area;
    } else if (strcmp(atributo, "pib") == 0) {
        valor1 = c1.pib;
        valor2 = c2.pib;
    } else if (strcmp(atributo, "densidade") == 0) {
        valor1 = c1.densidade_populacional;
        valor2 = c2.densidade_populacional;
        menor_vence = 1; // Densidade populacional: menor valor vence
    } else if (strcmp(atributo, "pib_per_capita") == 0) {
        valor1 = c1.pib_per_capita;
        valor2 = c2.pib_per_capita;
    } else {
        printf("Atributo desconhecido!\n");
        return;
    }

    // Determinação do vencedor
    printf("Comparação de cartas (Atributo: %s):\n\n", atributo);
    printf("Carta 1 - %s (%s): %.2f\n", c1.cidade, c1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", c2.cidade, c2.estado, valor2);
    
    if ((menor_vence && valor1 < valor2) || (!menor_vence && valor1 > valor2)) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", c1.cidade);
    } else if ((menor_vence && valor2 < valor1) || (!menor_vence && valor2 > valor1)) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", c2.cidade);
    } else {
        printf("\nResultado: Empate!\n");
    }
}

int main() {
    // Definição das cartas (predefinidas no código)
    Carta carta1 = {"SP", "C001", "São Paulo", 12300000, 1521.0, 699000000000.0, 15};
    Carta carta2 = {"RJ", "C002", "Rio de Janeiro", 6000000, 1200.0, 415000000000.0, 12};
    
    // Calcular valores derivados
    calcular_valores(&carta1);
    calcular_valores(&carta2);
    
    // Escolher atributo para comparação (modifique conforme desejado)
    char atributo[] = "pib";
    
    // Comparar as cartas
    comparar_cartas(carta1, carta2, atributo);
    
    return 0;
}
