# :computer: Trabalho 3 APC

## Objetivo

O intuito do projeto é a prática no uso de vetores, strings, estruturas de controle e funções, compreendendo assim praticamente todo o conteúdo visto na disciplina de Algoritmos e Programação de Computadores.

## Problema

Após o ótimo desempenho em seu último trabalho, você foi contratado pela Calanguinho Games. A empresa solicitou que você assumisse a criação de um novo jogo, encomendado para o lançamento do mais novo ﬁlme de ação e aventura “India Joanes e o Mistério de Piraporinha”, onde a protagonista, uma famosa arqueóloga, é encarregada de desvendar os mistérios da tumba do falecido pajé Moacir dos Milagres.

## Especificações

O jogo consiste em uma série de desaﬁos que deverão ser resolvidos pelo jogador ao longo de sua aventura para encontrar o tesouro perdido. A história se passa dentro de uma catacumba que será representada por meio de um mapa 2D, constituído por salas, corredores e portas. As salas são protegidas por capciosos desaﬁos e possuem pistas importantes para o acesso ao tesouro. É missão do jogador coletar todas as pistas e resolver os desaﬁos presentes no jogo.

### Ambiente

#### Elementos Físicos

<ul>
  <li># Paredes, delimitam o ambiente e restringem os movimentos do personagem no mapa.</li>
  <li>* Pista, revela alguma informação sobre a palavra chave necessária para resolver o enigma.</li>
  <li>C Enigma, abre a porta da Tumba (quando decifrado).</li>
  <li>Espaço vazio, local por onde a personagem poderá se movimentar.</li>
  <li>! Porta, impede a passagem da personagem.</li>
  <li>W Tumba de Moacir dos Milagres, ao alcançá-la a aventura deve ser encerrada.</li>
  <li>? Desaﬁo, abre a porta (quando vencido).</li>
</ul>

#### Elementos Móveis

<ul>
  <li>@ Jogador, a representação da personagem principal da história.</li>
</ul>
  
**Obs:** A largura do mapa deve variar de 60 a 90 espaços e a altura de 20 a 40.
  
 
### Controle de Entrada
  
A movimentação do jogador é controlada pelas teclas A (esquerda), D (direita), W (acima) e S (abaixo). Caso alguma outra tecla seja escolhida, o jogador não deve se movimentar (uma mensagem de erro deve ser impressa na tela). O jogo também deve contar com um menu (tecla M) com as seguintes opções: **retornar ao jogo** e **sair do jogo**.
  
### Iluminação
  
Os pontos de vida e as bordas do mapa devem sempre aparecer na tela para o usuário, além de uma área 5x7, iluminada, ao redor do jogador, representando seu campo de visão.
  
### Salas
  
O mapa deve obrigatoriamente contar com um determinado número de salas (de 3 a 5), além da **Tumba do Pajé**. Todas as salas deverão possuir portas e cada porta será protegida por um desaﬁo. Dentro de cada sala estará guardada uma das pistas necessárias para desvendar o “Enigma”.
**Obs:** As pistas, portas e desaﬁos deverão sumir do mapa após serem encontradas, abertas e resolvidos, respectivamente.
A Tumba do Pajé será um tipo especial de sala, ela não será protegida por um mero desaﬁo, mas sim por um soﬁsticado mecanismo que deverá ser desvendado com o auxílio das pistas encontradas.

### Vida

O jogador deve começar com 5 pontos de vida. A cada desaﬁo perdido, a personagem perde um ponto de vida (que não podem ser recuperados) - portanto ela deve ser bem habilidosa para chegar à tumba.
**Obs:** Os pontos de vida do jogador deve sempre estar visíveis durante a execução do jogo.

### Desafios

Para ter acesso a pista, o jogador deve passar por um dos desaﬁos existentes no jogo. Cada desaﬁo estará localizado na frente da porta da sala, e caso obtenha sucesso, a porta será liberada. 
O jogo deve contar com no mínimo dois desaﬁos diferentes (e, no máximo, quatro). Um dos desaﬁos deve ser, obrigatoriamente, um jogo de adivinhar o número. Nele, o jogador precisa acertar, em até 20 tentativas, qual o número inteiro aleatório entre 0 e 1000 foi escolhido pelo computador (este número sempre deve ser diferente). Os demais desaﬁos ﬁcam a seu critério (tente fazer algo mais interessante!).

### Enigma

O enigma deve ser desvendado para abrir a porta ﬁnal, e consiste na combinação de um número de sílabas (de 3 a 5), que formarão uma palavra-chave necessária para abrir a porta da tumba. Contudo, essas sílabas devem estar espalhadas pela catacumba (dentro das salas) em forma de pistas.
Após coletar todas as pistas, leve a personagem à entrada da Tumba do Pajé (local indicado por C), onde será solicitada a resposta do enigma para ter acesso.
**Obs:** caso uma palavra errada seja inserida, uma mensagem de erro deve ser impressa na tela e um ponto de vida descontado.

## Fim de Jogo

<ul>
  <li> Derrota: O jogador perde o jogo caso perca todos os seus pontos de vida.</li>
  <li> Vitória: Ao chegar à Tumba do Pajé (W), o jogador deve receber uma mensagem parabenizando-o pelo tesouro encontrado.</li>
</ul>

Ambos os casos devem levar o jogador ao menu, que deve possuir as opções de **jogar novamente**e **sair do jogo**.
