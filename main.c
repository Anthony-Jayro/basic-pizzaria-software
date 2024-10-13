#include <stdio.h>

void confirmar_pagamento() {
    
    int escolha;
    
    printf("Verifique a maquininha, se o pagamento for autorizado, tecle 1, se não, tecle 2\n");
    scanf("%d", &escolha);
    if(escolha == 1) {
        printf("Pagamento confirmado!\nretornando ao menu...");
    }
    else{
        printf("Pagamento não confirmado!\nretornando ao menu...");
    }
    
}


void pagamento_cartaoCredito (int continuar, float valorPedido) {
    
    int escolha;
    float valorParcela, qtdParcelas, taxaMaquina = valorPedido * 0.03 ;
    
    while (continuar == 1) {
        printf("Elo crédito selecionado, informe quantas vezes deseja parcelar:\n");
        scanf("%f",&qtdParcelas);
        valorParcela = (valorPedido+taxaMaquina)/qtdParcelas;
        printf("O valor da parcela é %.2f\nDeseja continuar?\n 1 - Sim\n 2 - Não\n", valorParcela);
        scanf("%d", &escolha);
        if(escolha == 1) {
            confirmar_pagamento();
            break;
        }
        else if (escolha == 2){
            printf("Retornando ao inicio...");
            break;
        }
    }
    
}


void pagamento_dinheiroFisico(float valorPedido, float qtdCaixaAtual) {
    
    float troco, qtdRecebida;
    
    printf("Dinheiro físico selecionado, informe a quantia recebida:\n");
    scanf("%f",&qtdRecebida);
    troco = (valorPedido - qtdRecebida);
    if(troco > 0){
        printf("Pagamento insuficiente, ainda é necessário pagar R$ %f", (valorPedido - troco));
        printf(" retornando ao menu para a efetuação do pagamento do restante...\n");
                    
    }
    else {
        if(troco > qtdCaixaAtual) {
            printf("Não há dinheiro suficiente no caixa, avise ao cliente");
        }
        else{
            printf("Troco: %.2f\n", troco *(-1));
            printf("Obrigado por comprar aqui!\n");
            qtdCaixaAtual += troco;
            qtdCaixaAtual += qtdRecebida;
        }
    }
        
}
    


int main()
{
    //O software deverá auxiliar o funcionário no controle do caixa, guardando informações sobre a 
    //forma de pagamento e pedido, além de fazer o calculo de troco
    
    //Essa é uma versão provisória de código, provavelmente vai ser alterado no decorrer do desenvolvimento
    
    int continuar = 1,idPedido, formaPagamento, escolha;
    float valorPedido = 100, qtdCaixaAtual = 200;
    

    while (continuar == 1) {
        printf("\nInforme o número do pedido:\n");
        scanf("%d",&idPedido);
        printf("Pedido Nº %d, valor total: %.2f\n", idPedido, valorPedido);
        printf("Informe a forma de pagamento:\n1 - dinheiro físico\n2 - pix\n3 - cartão débito\n4 - cartão crédito\n");
        scanf("%d",&formaPagamento);
        
        switch (formaPagamento) {
            case 1:
                pagamento_dinheiroFisico(valorPedido,qtdCaixaAtual);
                break;
                
            case 2:
                printf("Pix selecionado, exibindo chave pix...\n");
                confirmar_pagamento();
                break;

            case 3:
                printf("Elo débito selecionado, insira ou aproxime o cartão...");
                confirmar_pagamento();
                break;
                

            case 4:
                pagamento_cartaoCredito(1,valorPedido);
                break;
        }
        printf("Encerrar sessão?\n 0 - sim\n 1 - não\n");
        scanf("%d", &continuar);
    }

    return 0;
}