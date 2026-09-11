// importando as bibliotecas necessarias
#include <stdio.h>
#include <windows.h>
// criando a função calculo_porcentagem
int calculo_porcentagem(int porcentagem_atual, int porcentagem_final){
    // utiliza os parametros de porcentagem atual e porcentagem final
    // retorna a diferença de porcentagem atual e final
    return porcentagem_final-porcentagem_atual;
}
// criando a funçao calculo_kwh
float calculo_kwh(int porcentagem_atual, int porcentagem_final, float bateria_total){
    // utiliza como parametros a porcentagem atual, a porcentagem final e a bateria total
    // declara a variavel diferença
    // porcentagem final-porcentagem atual
    int diferenca=porcentagem_final-porcentagem_atual;
    // declara a variavel calculo
    //(diferença/100.0)*bateria total
    float calculo=(diferenca/100.0)*bateria_total;
    // retorna a variavel calculo
    return calculo;
}
// criando a funça calcular_tempo
float calcular_tempo(float energia, float potencia){
    // utiliza como parametros a energia e a potencia
    // cria a variavel calculo
    // energia/potencia
    float calculo=energia/potencia;
    // retorna a variavel calculo
    return calculo;
}
// criando a funçao controle_potencia
float controle_potencia(float potencia_total, int veiculos_conectados){
    // utiliza como parametros a potencia total e a quantidade de veiculos conectados
    // retorna a potencia total/veiculos conectados
    return potencia_total / veiculos_conectados;
}
// criando a funçao calcular_tarifa
float calcular_tarifa(int hora, int veiculos_conectados, int tipo_carregamento){
    // utiliza como parametros a hora, os veiculos conectados e o tipo de carregamento
    // declara a atarifa como sendo 0.80
    float tarifa=0.80;
    //se a hota for entre 18 e 21
    if (hora>=18 && hora<=21){
        // adiciona 0.30 a tarifa
        tarifa+=0.30;
    }
    // senao se a hora estiver entre 0 e 6
    else if (hora>=0 && hora<=6){
        // retira 0.10 da tarifa
        tarifa-=0.10;
    }
    // se tiver mais de 4 veiculos conectados
    if (veiculos_conectados>=4){
        // adiciona 0.25 a tarifa atual
        tarifa+=0.25;
    }
    // senao se a quantidade de veiculos for entre 4 e 2
    else if (veiculos_conectados>=2){
        // adiciona 0.10 a tarifa atual
        tarifa+=0.10;
    }
    // se o tipo de carregamento for o 1
    if (tipo_carregamento==1){
        // adciona 0.40 a tarifa atual
        tarifa+=0.40;
    }
    // senao se o tipo de carregamento for o 2
    else if (tipo_carregamento==2){
        // adiciona 0.15 a tarifa atual
        tarifa+=0.15;
    }
    // retorna a tyarifa calculada
    return tarifa;
}
// criando a funçao sistema_externo
void sistema_externo(int sessao, float energia, float custo){
    // utiliza como parametros a sessao, a energia e o custo
    // mostra uma mensagem de simulaçao
    printf("\nSimulando integracao OCPP/MODBUS...\n");
    // delay de 1 segundo
    Sleep(1000);
    // mostra que a sessao atual foi enviada para o sistema externo
    printf("Sessao %d enviada para o sistema externo\n", sessao);
    // mostra que a energia foi enviada ao sistema externo
    printf("Energia enviada: %.2f kWh\n", energia);
    // mostra que o custo foi enviado ao sistema externo
    printf("Custo enviado: R$ %.2f\n", custo);
}
// funçao main
int main() {
    // declarando as variaveis de tipo int
    int porcentagem;
    int porcentagem_final;
    int calculo;
    int escolha;
    int quantidade_sessoes;
    int veiculos_conectados;
    int hora;
    int tipo_carregamento;
    // declarando as variaveis de tipo float
    float potencia=22.0;
    float potencia_usada;
    float tarifa=0.80;
    float bateria_total;
    float tempo_hora;
    float tempo_min;
    float energia;
    float custo;
    float dinheiro;
    float troco;
    float energia_total=0;
    float custo_total=0;
    float tempo_total=0;
    // iniciando o simuladoe
    printf("----------SIMULADOR DE RECARGA----------\n");
    // delay de 1 segundo
    Sleep(1000);
    // faça
    do{
        // pergunta ao usuario a quantidade de sessoes de recarga
        printf("Digite a quantidade de sessoes de recarga: ");
        // coleta a informaçao
        scanf("%d",&quantidade_sessoes);
        // se a quantidade de sessoes for menor ou igual a zero
        if (quantidade_sessoes<=0){
            // mostra que esta invalido
            printf("Quantidade de sessoes invalida\n");
        }
    // enquanto a quantidade de sessoes for menor ou igual a zero
    } while (quantidade_sessoes<=0);
    // inicia um loop para diferentes recargas
    for (int sessao=1; sessao<=quantidade_sessoes; sessao++){
        // inicia a sessao de carregamento
        printf("------SESSAO %d------\n",sessao);
        // faça
        do{
            // pergunta ao usuario a capacidade da bateria do carro
            printf("Digite a capacidade da bateria do carro (kWh): ");
            // coleta a informaçao
            scanf("%f",&bateria_total);
            // se a bateria for menor ou igual a zerop
            if (bateria_total<=0){
                // mostra que esta invalido
                printf("Bateria invalida\n");
            }
        // enquanto a bateria total for menor ou igual a zero
        }while(bateria_total<=0);
        // faça
        do{
            // pergunta ao usuario a quantidade de veiculos conectados
            printf("Digite a quantidade de veiculos conectados: ");
            // coleta a informaçao
            scanf("%d",&veiculos_conectados);
            // se a quantidade de veiculos conectados for menor ou igual a zero
            if (veiculos_conectados<=0){
                // mostra que esta invalido
                printf("Quantidade de veiculos invalida\n");
            }
        // enquanro a quantidade de veiculos conectados for menor ou igual a 
        } while(veiculos_conectados<=0);
        // faça
        do{
            // pergunta ao usuario a hora atual
            printf("Digite a hora atual: ");
            // coleta a informaçao
            scanf("%d",&hora);
            // se a hota for menor  que 0 ou maior que 23
            if (hora<0 || hora>23){
                // mostra que esta invalido
                printf("Hora invalida\n");
            }
        // enquanto a hora for menor que 0 ou maior que 23
        }while (hora<0 || hora>23);
        // faça
        do{
            // pergunta ao usuario o tipo de carregamento
            printf("Tipo de carregamento:\n1-Rapido\n2-Normal\n3-Economico\nEscolha: ");
            // coleta a informaçao
            scanf("%d",&tipo_carregamento);
            // se o tipo de carregamento for diferente de 1 e 2 e 3
            if (tipo_carregamento!=1 && tipo_carregamento!=2 && tipo_carregamento!=3){
                // mostra que esta invalido
                printf("Tipo de carregamento invalido\n");
            }
        // enquanto o tipo de carregamento for diferente de 1 e 2 e 3 
        } while(tipo_carregamento!=1 && tipo_carregamento!=2 && tipo_carregamento!=3);
        // faça
        do {
            // pergunta para o usuario ate quanto ele quer carregar
            printf("1-Carregar ate 100%%\n2-Carregar ate x%%\nEscolha: ");
            // coleta a informaçao
            scanf("%d",&escolha);
            // se a escolha for diferente de 1 e 2
            if (escolha!=1 && escolha!=2){
                // mostra que esta invalido
                printf("Escolha invalida\n");
            }
        // enquanto a escolha for diferente de 1 e 2
        } while (escolha!=1 && escolha!=2);
        // switch da variavel escolha
        switch (escolha){
            // caso seja 1
            case 1:
            // faça
                do{
                    // pergunta ao usuario sua porcentagem atual da bateria
                    printf("Digite a porcentagem de sua bateria (em porcentagem): ");
                    // coleta a informaçao
                    scanf("%d",&porcentagem);
                    // se a porcentagem for menor que 0 ou maior que 100
                    if (porcentagem<0 || porcentagem>100){
                        // mostra que esta invalido
                        printf("Porcentagem invalida\n");
                    }
                // enquanto a porcentagem for menor que 0 ou maior que 100
                } while(porcentagem<0 || porcentagem>100);
                // se a porcentagem for igual a 100
                if (porcentagem==100){
                    // mostra que a bateria esta cheia
                    printf("A bateria ja esta cheia\n");
                    // pula para o proximo loop
                    continue;
                }
                // define a porcentagem final
                porcentagem_final=100;
                // break do case
                break;
            // caso seja 2
            case 2:
            // faça
                do{
                    // pergunta ao usuario a porcentagem atual de sua bateria
                    printf("Digite a porcentagem de sua bateria (em porcentagem): ");
                    // coleta a informaçao
                    scanf("%d",&porcentagem);
                    // se a porcentagem estiver menor que 0 ou maior que 100
                    if (porcentagem<0 || porcentagem>100){
                        // mostra que a porcentagem esta invalida
                        printf("Porcentagem invalida\n");
                    }
                // enquanto a porcenatagem final for menor que 0 ou maior que 100
                } while(porcentagem<0 || porcentagem>100);
                // se a porcentagem for igual a 100
                if (porcentagem==100){
                    // mostra que a bateria ja esta cheia
                    printf("A bateria ja esta cheia\n");
                    // pula para o proximo loop
                    continue;
                }
                // faça
                do{
                    // pergunta ao usuario ate quanto ele gostaria de carregar
                    printf("Deseja carregar ate quantos porcento ? ");
                    // coleta a informaçao
                    scanf("%d",&porcentagem_final);
                    // se a porcentagem final for menor que 0 ou maior que 100 ou menor ou igual a porcentagemn atual
                    if (porcentagem_final<0 || porcentagem_final>100 || porcentagem_final<=porcentagem){
                        // mostra que a porcentagem esta invalida
                        printf("Porcentagem invalida\n");
                    }
                // enquanto a porcentagem final for menor que 0 ou maior que 100 ou menor ou igual a porcentagem atual
                }while(porcentagem_final<0 || porcentagem_final>100 || porcentagem_final<=porcentagem);
                // break do case
                break;
            // caso n satisfaça as condiçoes dos cases
            default:
                // mostra que esta invalida
                printf("Escolha invalida\n");
        }
        // calculo de variaveis utilizando as funçoes criadas anterioprmente
        calculo=calculo_porcentagem(porcentagem,porcentagem_final);
        energia=calculo_kwh(porcentagem,porcentagem_final,bateria_total);
        potencia_usada=controle_potencia(potencia,veiculos_conectados);
        tempo_hora=calcular_tempo(energia,potencia_usada);
        tempo_min=tempo_hora*60;
        tarifa=calcular_tarifa(hora,veiculos_conectados,tipo_carregamento);
        custo=energia*tarifa;
        // mostra informaçoes da recarga
        printf("Carregar %d%%\n",calculo);
        printf("Potencia por veiculo: %.2f kW\n",potencia_usada);
        printf("Tempo estimado: %.2f horas (%.0f minutos)\n",tempo_hora,tempo_min);
        printf("Tarifa: R$ %.2f por kWh\n",tarifa);
        printf("Total a pagar R$%.2f\n",custo);
        // pergunta ao usuario a quantidade de dinheiro a ser fornecida
        printf("Digite a quantia de dinheiro que ira fornecer: ");
        // coleta a informaçao
        scanf("%f",&dinheiro);
        // se o dinheiro fornecido somado a uma margem ainda for menor que o custo
        if (dinheiro + 0.01 < custo){
            // mostra que o saldo e insuficiente
            printf("Saldo insuficiente\n");
            // informa que a sessao sera cancelada
            printf("Pulando para a proxima sessao...\n");
            // pula para a proxima sessao
            continue;
        }
        // senao
        else{
            // calcula o troco
            troco=dinheiro-custo;
            // se o troco ficar negativo por causa de arredondamento
            if (troco < 0){
                // zera o troco
                troco=0;
            }
            // mostra o troco ao usuario
            printf("Troco: R$ %.2f\n",troco);
        }
        // simula uma recarga
        for (int i=porcentagem; i<=porcentagem_final; i++){
            // mostra a porcentagem da bateria
            printf("%d%%\n",i);
            // delay de 1 segundo
            Sleep(1000);
        }
        // mostra que a recarga foi concluida
        printf("Carga concluida!!\n");
        // chama a funçao sistema_externo
        sistema_externo(sessao, energia, custo);
        // realiza calculos de informaçoes
        energia_total+=energia;
        custo_total+=custo;
        tempo_total+=tempo_hora;
        // mostra o relatorio da sessao
        printf("\n----------RELATORIO DA SESSAO %d----------\n",sessao);
        printf("Tipo de carregamento: %d",tipo_carregamento);
        printf("Bateria do carro: %.0f kWh\n",bateria_total);
        printf("Carga inicial: %d%%\n",porcentagem);
        printf("Carga final: %d%%\n",porcentagem_final);
        printf("Energia carregada: %.2f kWh\n",energia);
        printf("Tempo estimado: %.2f horas (%.0f minutos)\n",tempo_hora,tempo_min);
        printf("Tarifa: R$ %.2f por kWh\n",tarifa);
        printf("Custo total: R$ %.2f\n",custo);
    }
    // mostra o relatorio final de tudo junto
    printf("\n----------RELATORIO GERAL----------\n");
    printf("Quantidade de sessoes: %d\n", quantidade_sessoes);
    printf("Energia total carregada: %.2f kWh\n", energia_total);
    printf("Tempo total estimado: %.2f horas\n", tempo_total);
    printf("Custo total arrecadado: R$ %.2f\n", custo_total);
    // termina o porgrama
    return 0;
}