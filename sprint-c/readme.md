O programa desenvolvido para a Sprint 2 simula um sistema inteligente de gerenciamento de recarga de carros elétricos, permitindo múltiplas sessões de recarga, controle de potência entre veículos conectados, tarifação dinâmica e simulação de integração com sistemas externos utilizando mensagens inspiradas nos protocolos OCPP/MODBUS.

Foram utilizadas diversas funções auxiliares antes do main(), como calculo_porcentagem, responsável por calcular a diferença entre a porcentagem inicial e final da bateria, calculo_kwh, que calcula a energia carregada em kWh, e calcular_tempo, utilizada para calcular o tempo estimado da recarga. Também foram implementadas as funções controle_potencia, que divide a potência entre os veículos conectados, calcular_tarifa, responsável pela tarifação dinâmica conforme horário, demanda e tipo de carregamento, e sistema_externo, que simula o envio de dados da sessão para um sistema externo.

No início do programa, o usuário informa a quantidade de sessões de recarga. Em seguida, para cada sessão, são solicitadas informações como capacidade da bateria, quantidade de veículos conectados, horário da recarga e tipo de carregamento. O sistema realiza validações utilizando estruturas do-while para garantir entradas válidas.

Depois disso, o usuário escolhe entre carregar até 100% ou até uma porcentagem específica. O programa então calcula energia carregada, potência utilizada, tempo estimado, tarifa aplicada e custo total da sessão. Após o pagamento, a recarga é simulada utilizando um laço for com a função Sleep(), tornando a execução mais próxima de um sistema real.

Ao final de cada sessão, é exibido um relatório contendo informações como bateria do veículo, porcentagem inicial e final, energia carregada, tarifa aplicada, tempo estimado e custo total. Também é apresentado um relatório geral contendo a quantidade total de sessões realizadas, energia total carregada, tempo total estimado e valor arrecadado pelo sistema.

Equipe 04 - 1CCPI

Rafael Gandolfi Gonçalves - 569036 - 1CCPI
Rafael Lins - 570588 - 1CCPI
Cauã Paes - 569906 - 1CCPI
Guilherme Miranda - 573107 - 1CCPI
Carlos Eduardo - 572949 - 1CCPI
João Pedro Soler - 569725 - 1CCPI