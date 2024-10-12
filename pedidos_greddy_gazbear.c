#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

// COLUNAS E LINHAS são a respeito da matriz, toda a lógica do código foi montada em cima da "matriz_pedidos".

// Função para anotar os itens de um novo pedido. Esta é uma função que será chamada em outra função.
int anotar_pedido(int colunas, int itens_novo_pedido[colunas]){
    char pizzas[7][50] = { // matriz das pizzas
        "1 - Margherita",
        "2 - Quatro Queijos",
        "3 - Calabresa",
        "4 - Portuguesa",
        "5 - Brigadeiro",
        "6 - Americano",
        "7 - Churrasco"
    };

    char ingredientes[8][255] = { // matriz dos igredientes
        "Molho de tomate, Queijo muçarela, Manjericão, Azeite de oliva, Sal",
        "Molho de tomate, Queijo muçarela, Gorgonzola, Parmesão, Provolone",
        "Molho de tomate, Queijo muçarela, Linguiça calabresa, Cebola, Azeitonas",
        "Molho de tomate, Queijo muçarela, Presunto, Ovos cozidos, Cebola, Azeitonas, Pimentão",
        "Caldo de chocolate, Ovomaltine, Confete",
        "Queijo muçarela, Molho de tomate, Frango desfiado, Cheddar, Orégano",
        "Queijo muçarela, Carne de boi temperada, Calabresa, Molho de tomate, Barbecue"
    };

    float precos[7] = {40.0, 50.0, 45.0, 47.0, 45.0, 50.0, 55.0}; // vetor dos preços
    int item_opcao, item_quantidade, item_tipo_bebida;
    
    // O vetor itens_novo_pedido é o que carregará a quantidade de itens do pedido. Ele tem que ser preenchido com 0 neste momento.
    for (int i = 0; i < colunas; i++){
        itens_novo_pedido[i] = 0;
    }
    
    while(1){
        // cardápio de pizzas
        printf("\n\n====================== CARDÁPIO DE PIZZAS ======================\n");
        printf("| %-15s | %-100s | %-10s |\n", "Pizza", "Ingredientes", "Preço");
        for (int i = 0; i < 7; i++) {
            printf("| %-15s | %-100s | R$%-9.2f |\n", pizzas[i], ingredientes[i], precos[i]); //formatação de texto
        }
        
        // cardápio de bebidas
        printf("\n====================== CARDÁPIO DE BEBIDAS ======================\n");
        printf("| %-20s \t| %-20s | %-10s |\n", "Bebida", "1 litro", "2 litros");
        printf("| %-20s \t| %-20s | %-10s |\n", "8 - Coca-Cola", "R$7,50", "R$10,00");
        printf("| %-15s | %-20s | %-10s |\n", "9 - Guaraná Antártica", "R$7,00", "R$9,50");
        printf("| %-20s \t| %-20s | %-10s |\n", "10 - Sprite", "R$5,00", "R$10,00");
        printf("| %-20s \t| %-20s | %-10s |\n", "11 - Fanta Laranja", "R$7,00", "R$9,50");
        printf("| %-20s \t| %-20s | %-10s |\n", "12 - Água Mineral", "R$5,00", "R$7,00");
        printf("| %-20s \t| %-20s | %-10s |\n", "13 - Suco de Laranja", "R$9,00", "R$12,00");
        
        printf("\nDigite o número do item desejado, ou digite 0 para encerrar o pedido: ");
        scanf("%d", &item_opcao);

        if (item_opcao == 0){
            break;
        }
      
            
        // A partir daqui, "item_opcao" é considerado como posição de vetor/matriz. Por isso, é subtraido 1.
        item_opcao -= 1;
        
        // 0 a 12 são os valores dos itens do cardápio, em alguns casos vão de 1-18. Na matriz são 1-19, sendo 0 o 'status' do pedido.
        if (item_opcao > 12 || item_opcao < 0){
            printf("\nDigite uma opção válida!");
            continue;
        }
                
        if (item_opcao > 6){
            printf("\nDigite o volume: 1 - 1 Litro, 2 - 2 - Litros: ");
            scanf("%d", &item_tipo_bebida);
           
            // As bebidas possuem espaços próprios para cada volume diferete, 1L e 2L, esse switch é para colocar o valor correto no vetor. 
            switch(item_tipo_bebida){
                case 1:
                    switch(item_opcao){
                        case 7:
                            item_opcao = 7;
                            break;
                        case 8:
                            item_opcao = 9;
                            break;
                        case 9:
                            item_opcao = 11;
                            break;
                        case 10:
                            item_opcao = 13;
                            break;
                        case 11:
                            item_opcao = 15;
                            break;
                        case 12:
                            item_opcao = 17;
                            break;
                    }
                    break;
        
                case 2:
                    switch(item_opcao){
                        case 7:
                            item_opcao = 8;
                            break;
                        case 8:
                            item_opcao = 10;
                            break;
                        case 9:
                            item_opcao = 12;
                            break;
                        case 10:
                            item_opcao = 14;
                            break;
                        case 11:
                            item_opcao = 16;
                            break;
                        case 12:
                            item_opcao = 18;
                            break;
                    }
                    break;
                }
            }
        
        // A posição no vetor diz respeito a qual é o item, agindo como um tipo de ID. Entretanto, o valor nessas posições diz sobre a quantidade.
        printf("\nDigite a quantidade do item selecionado: ");
        scanf("%d", &item_quantidade);
           
        itens_novo_pedido[item_opcao] = item_quantidade;
    }
    
    // Retorna o vetor com os itens do pedido.
    return itens_novo_pedido;
}

// Função que lista os itens salvos em cada pedido. Também é chamada em outra função.
void escrever_itens(int colunas, int itens_pedido[colunas]){
    int i, quantidade;
    for(i = 0; i < colunas; i++){
        quantidade = itens_pedido[i];
        
        // Como não temos estruturas de dados melhores, esse if e switch serve para verificar a quantidade dos itens e escrever caso seja maior que 0.
        if (quantidade > 0){
            switch (i){
                case 0:
                    printf("Margherita x%d", quantidade);
                    break;
                case 1:
                    printf("Quatro Queijos x%d", quantidade);
                    break;
                case 2:
                    printf("Calabresa x%d", quantidade);
                    break;
                case 3:
                    printf("Portuguesa x%d", quantidade);
                    break;
                case 4:
                    printf("Brigadeiro x%d", quantidade);
                    break;
                case 5:
                    printf("Americano x%d", quantidade);
                    break;
                case 6:
                    printf("Churrasco x%d", quantidade);
                    break;
                case 7:
                    printf("Coca-Cola 1L x%d", quantidade);
                    break;
                case 8:
                    printf("Coca-Cola 2L x%d", quantidade);
                    break;
                case 9:
                    printf("Guaraná Antártica 1L x%d", quantidade);
                    break;
                case 10:
                    printf("Guaraná Antártica 2L x%d", quantidade);
                    break;
                case 11:
                    printf("Sprite 1L x%d", quantidade);
                    break;
                case 12:
                    printf("Sprite 2L x%d", quantidade);
                    break;
                case 13:
                    printf("Fanta Laranja 1L x%d", quantidade);
                    break;
                case 14:
                    printf("Fanta Laranja 2L x%d", quantidade);
                    break;
                case 15:
                    printf("Água Mineral 1L x%d", quantidade);
                    break;
                case 16:
                    printf("Água Mineral 2L x%d", quantidade);
                    break;
                case 17:
                    printf("Suco de Laranja 1L x%d", quantidade);
                    break;
                case 18:
                    printf("Suco de Laranja 2L x%d", quantidade);
                    break;
            }
            
            // Apenas uma forma de escrever a vírgula e ponto de acordo com a posição dos itens listados no pedido.
            if (i != colunas-1){
                if(itens_pedido[i+1] != 0){
                    printf(", ");
                }
            }
        }
    }
        printf(".");
}

// Função que lista todos os pedidos ativos (Os que a posição [0] for diferente de 'Vazio'/0).
void listar_pedidos(int linhas, int colunas, int matriz_pedidos[linhas][colunas]){
    // O "vetor_pedido_loop" é o vetor que salva os itens do pedido no loop atual e, posteriormente, é usada na Função "escrever_itens".
    // Aqui e em alguns casos no futuro há "colunas-1" para alguns vetores, isso é devido que apenas os itens são necessários, por isso a posição dos status é excluída.
    int i, y, vetor_pedido_loop[colunas-1];
    
    printf("\n| ID do Pedido \t\t | Status \t\t\t | Itens \t\t\t |\n");
    
    for (i = 0; i < linhas; i++){
        // 'Caso o status seja vazio, pule a repetição atual'
        if(matriz_pedidos[i][0] == 0){
            continue;
        }
        
        printf("| %d \t\t\t | ", i);
        
        // Posição do status do pedido.
        switch (matriz_pedidos[i][0]){
            case 1:
                printf("No aguardo\t");
                break;
            case 2:
                printf("Em preparação");
                break;
            case 3:
                printf("Entregue\t");
                break;
        }
        
        printf("\t\t | ");
        
        // Salva os itens do pedido do loop no vetor.
        for (y = 0; y < colunas-1; y++){
            vetor_pedido_loop[y] = matriz_pedidos[i][y+1];
        }
        
        escrever_itens(colunas, vetor_pedido_loop);
        
        printf("\t | \n");
    }
}

// Função para alterar os status de determinado pedido.
int alterar_status_pedido(int linhas, int colunas, int matriz_pedidos[linhas][colunas]){
    int id_pedido, status_novo, escolha;
    
    // Antes da execução de outros comandos chama essa função para mostrar a situação dos pedidos.
    listar_pedidos(linhas, colunas, matriz_pedidos);
    
    // ID é a "linha" correspondente da matriz. Ex: ID 0 - igual a matriz_pedidos[0].
    printf("\nDigite o ID pedido que será alterado: ");
    scanf("%d", &id_pedido);
    
    // Se for escolhido um pedido não ativo, isso cancela a função, evitando possíveis erros de lógica futuramente.
    if (matriz_pedidos[id_pedido][0] == 0){
        printf("\nPedido inválido selecionado! Retornando ao menu inicial.\n");
        return matriz_pedidos;
    }
    
    printf("\nStatus atual: %d \n* 1 - No aguardo, 2 - Em preparação, 3 - Entregue * \nDigite o status atualizado: ", matriz_pedidos[id_pedido][0]);
    scanf("%d", &status_novo);
    
    matriz_pedidos[id_pedido][0] = status_novo;
    
    // Caso o pedido seja escolhido como entregue, também é possível reiniciar o espaço dele.
    if(status_novo == 3){
        printf("\nO status escolhido foi 'Entregue', o pedido deve ser finalizado? 1 - SIM, 2 - NÃO: ");
        scanf("%d", &escolha);
        
        if(escolha == 1){
            for (int i = 0; i < colunas; i ++){
                matriz_pedidos[id_pedido][i] = 0;
            }
        }
    }
    
    printf("\nPedido alterado!\n");
    
    return matriz_pedidos;
}

// Função que cria um novo pedido.
int cadastrar_novo_pedido(int linhas, int colunas, int matriz_pedidos[linhas][colunas]){
    int itens_novo_pedido[colunas-1];
    int i, ID_novo_pedido = 99;
    
    // Chama a função para mostrar o cardápio e salvar os itens escolhidos. Aqui "colunas" não é subtraido, pois o vetor referenciado já passou por isso.
    anotar_pedido(colunas, itens_novo_pedido);
    
    // Seleciona um pedido com status "vazio" automaticamente.
    for (i = 0; i < linhas; i++){
        if (matriz_pedidos[i][0] != 0){
            continue;
        } else {
            printf("\nO Pedido será armazenado no ID %d.", i);
            ID_novo_pedido = i;
            break;
        }
    }
    
    // Caso não haja, um pedido com status "entregue" será reiniciado e escolhido para o novo cadastro.
    if (ID_novo_pedido == 99){
        printf("\nNenhum pedido vazio disponível. O novo pedido será colocado no ID de um pedido 'Entregue', caso haja.");
        for (i = 0; i < linhas; i++){
            if (matriz_pedidos[i][0] != 2){
                continue;
            } else {
                printf("\nO Pedido será armazenado no ID %d.", i);
                ID_novo_pedido = i;
                
                //Reinicia o pedido
                for (int i = 0; i < colunas; i++){
                    matriz_pedidos[ID_novo_pedido][i] = 0;
                }
                
                break;
            }
        } 
    }
    
    // Caso não exista nenhum pedido disponível para cadastro, a função é cancelada.
    if (ID_novo_pedido == 99){
        printf("\nNenhum ID disponível para o pedido, mude manualmente o estado de um pedido.\n");
        return matriz_pedidos;
    }
    
    // Salva os itens do pedido no espaço certo da matriz.
    for (i = 1; i < colunas; i++){
        matriz_pedidos[ID_novo_pedido][i] = itens_novo_pedido[i-1];
    }
    
    // Altera o status para "Em preparo".
    matriz_pedidos[ID_novo_pedido][0] = 1;
    
    printf("\nPedido adicionado!\n");
    
    return matriz_pedidos;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    // Constantes
    int const LINHAS = 15, COLUNAS = 20;
    
    // Variáveis
    int matriz_pedidos[15][20] = {{0}};
    int opcao;
    char ENTER; // Variável para um "pause" durante o fim da execução dos comandos.
    
    while(1){
        printf("\n====================== MENU GREDDY GAZBEAR'S PIZZA ======================\n");
        printf("\n1 - Anotar Pedido");
        printf("\n2 - Listar Pedidos");
        printf("\n3 - Alterar Status do Pedido");
        printf("\n4 - Sair\n: ");
        scanf("%d", &opcao);
        
        if (opcao == 1){
            cadastrar_novo_pedido(LINHAS, COLUNAS, matriz_pedidos);
        } 
        else if (opcao == 2) {
            listar_pedidos(LINHAS, COLUNAS, matriz_pedidos);
        } 
        else if (opcao == 3){
            alterar_status_pedido(LINHAS, COLUNAS, matriz_pedidos);
        }
        else if (opcao == 4){
            exit(0);
        }
        else {
            printf("Opção inválida!\n");
        }
        
        getchar();        
        printf("\nAperte ENTER para prosseguir.");
        getchar();
    }
}