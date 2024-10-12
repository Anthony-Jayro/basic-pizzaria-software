/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    //O software deverá auxiliar o funcionário no controle do caixa, guardando informações sobre a 
    //forma de pagamento e pedido, além de fazer o calculo de troco
    
    //Essa é uma versão provisória de código, provavelmente vai ser alterado no decorrer do desenvolvimento
    
    int continuar = 1,idPedido, formaPagamento, qtdParcelas;
    float valorPedido = 100,qtdRecebida, troco;
    
    while (continuar == 1) {
        printf("Informe o número do pedido:\n");
        scanf("%d",&idPedido);
        
        printf("Pedido Nº %d, valor total: %.2f\n", idPedido, valorPedido);

        printf("Informe a forma de pagamento:\n1 - dinheiro físico\n2 - pix\n3 - cartão débito\n4 - cartão crédito\n");
        scanf("%d",&formaPagamento);
        
        switch (formaPagamento) {
            case 1:
                printf("Dinheiro físico selecionado, informe a quantia recebida:\n");
                scanf("%f",&qtdRecebida);
                troco = valorPedido - qtdRecebida;
                printf("Troco: %f", troco);
                break;
                
            case 2:
                printf("Pix selecionado, exibindo chave pix...\n");
                break;

            case 3:
                printf("Elo débito selecionado, insira ou aproxime o cartão...");
                break;

            case 4:
                printf("Elo crédito selecionado, informe quantas vezes deseja parcelar:");
                 scanf("%d",&qtdParcelas);
                break;

                
        }
        
        
        
        
    }
    

    return 0;
}