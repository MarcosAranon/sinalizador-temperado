# sinalizador-temperado
Projeto com objetivo de analise individual de capacidades práticas e aplicadas.

Este projeto foi desenvolvido no emulador Wokwi utilizando uma placa ESP32, um led RGB e um sensor DHT22. A codificação utilizou a biblioteca do DHT que recebe seus dados e converte-os em graus celcius e porcentagem de umidade. Também foi printado no serial os dados de temperatura como parametro para testes do recebimento dos dados do sensor.

Para o led RGB foram utilizadas portas digistais que ligavam e desligavam as cores do led, e combinando essas cores foi possível criar outras cores como o amarelo utilizado para indicar uma das faixas de temperatura. Como o DHT22 possui uma faixa de temperatura de -40°C até 80°C a cor azul foi utilizada para representar a faixa de -40°C até 0°C a cor amarela para representar de 0°C até 40°C e a cor vermelha para representar a faixa de 40°C até 80°C. A escolha de cores foi feita linkando a cor azul com o frio, amarelo como uma faixa ensolarada ou agradável e vermelho para uma zona quente ou critíca.

Um problemafoi identificado durante a produção do projeto, esse era o que o led parecia ter uma leve mudança de intensidade luminosa enquanto reproduzia suas cores dando a sensação de que o led piscava levemente. Algumas implementações utilizando operação ternaria foi utilizada mas sem sucesso. Com a ajuda do instrutor Saulo Amaral, vulgo Orkut, concluímos que este era um problema do próprio simulador e que o mesmo não se repetirá caso o projeto saia do virtual.

Para melhorias do projeto, uma ideia que surge seria a de adicionar o monitoramento dos dados de umidade que a DHT22 fornece com leds ou até mesmo prints no serial colocando uma faixa onde é o limite de umidade é aceitável e outra que não é aceitável que coloca o equipamento em risco dando algum estimulo para o usuário perceber a situação e tomar alguma ação necessária.

Link para a simulação do projeto no Wokwi:

https://wokwi.com/projects/364813107274808321
