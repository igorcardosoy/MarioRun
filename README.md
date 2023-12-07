# Mario Run

Este repositório contém o código-fonte e a documentação para o jogo Mario Run, uma versão inspirada no famoso jogo "Google Dino Run", no qual o jogador controla um Tiranossauro Rex que corre por um deserto, pulando sobre obstáculos. Neste documento, você encontrará informações sobre o jogo, como jogá-lo, detalhes sobre o projeto e sua estrutura de dados, além de informações sobre a metodologia de desenvolvimento.

## Descrição do jogo:

Mario Run é uma emocionante recriação do famoso jogo "Google Dino Run", inserida no envolvente universo dos jogos do Mario. Nesta versão, o jogador assume o controle de Mario, o icônico encanador bigodudo, enquanto ele corre pelo ambiente de Super Mario Bros. Seu objetivo é pular sobre canos, evitar perigos e desafios, tudo isso para alcançar a maior pontuação possível.

## Como jogar?

Para jogar o Mario Run, siga as instruções abaixo:

### 1. Baixar:

Para realizar o download, baixe ou clone o repositório.

- Windows:
  As DLLs e o SDL2 estão no repositório.

- Linux:
  Para Linux, é necessário baixar o SDL2 e suas bibliotecas extras. Para fazer isso, abra o terminal na pasta do MarioRun e execute o seguinte comando:

  ```bash
  make linux-libs
  ```

### 2. Compilar e Instalar:

Após já ter o SDL2 e suas bibliotecas auxiliares, basta dar o comando:

- Para Windows:

  ```bash
  mingw32-make win
  ```

- Para Linux:

  ```bash
  make linux
  ```

### 3. Executar:

Pode-se executar abrindo o executável criado após a compilação ou utilizando o terminal:

- Para Windows:

  ```bash
  ./MarioRun_win64.exe
  ```

- Para Linux:

  ```bash
  ./MarioRun_linux64
  ```

## Controles:

O jogo é controlado pelas seguintes teclas:

- **Seta para Cima ou Barra de Espaço:** Pula sobre obstáculos.
- **Seta para Baixo:** Agacha ou faz o personagem cair mais rapidamente ao chão durante o pulo.

Certifique-se de usar esses controles de forma estratégica para evitar obstáculos e alcançar a maior pontuação!

## Autores e Contato:

Este jogo foi desenvolvido pelos seguintes alunos do IFSP, Campus Araraquara, no segundo semestre de 2023:

- [Cauã Rufino de Sá](https://github.com/CauaDeSa)
- [Giovana Trevizan Barbosa](https://github.com/giovanatrevizanbarbosa)
- [Igor Filipi Cardoso](https://github.com/IgorFilipiCardoso)
- [Natan Salvador Ligabo](https://github.com/natansalvadorligabo)

## Descrição do Projeto:

Toda a estrutura do projeto foi desenvolvida em torno do conceito de TAD, Tipo Abstrato de Dados. No MarioRun, todos os tipos são um TAD: o chão, o céu, o próprio Mario e o obstáculo. Foram criados TADs auxiliares também, como o Text para gerar textos de forma mais simples, o ranking do jogo e a estrutura de dados que também é um TAD, a Fila.

O jogo gira em torno de pular obstáculos que vêm em direção ao Mario. Para fazer isso, utilizamos uma fila de obstáculos. Quando o jogo é iniciado, a fila é preenchida com vários obstáculos. Ao começar o jogo, o primeiro elemento é retirado da fila, e ao chegar ao final da tela, ele é excluído e outro obstáculo entra na fila de forma aleatória, garantindo sempre novos obstáculos de forma aleatória.

A estratégia principal para a criação do jogo foi separar os objetos, ou seja, criar TADs para cada coisa, para conseguirmos trabalhar de forma mais organizada e ir testando o jogo aos poucos. A primeira coisa a ser criada foi a definição base das funções de cada TAD, colocando o que cada um faria dentro do jogo. Com a evolução do jogo, foram criadas mais funções, e algumas deixaram de existir.

Fomos implementando aos poucos, desde coisas mais simples até as mais complexas. Começamos pelo Céu e pelo Chão, que são relativamente fáceis, onde apenas andam da direita para a esquerda, e quando chegam ao final da tela, voltam para o início, dando a sensação de movimento. A animação do personagem foi feita com um vetor de SDL_Textures, onde cada textura era um frame da animação. Conforme a velocidade do jogo aumenta, a velocidade da animação também aumenta. Um dos sistemas mais difíceis de fazer foi o pulo e, caso o jogador segure, o personagem pula mais alto, agacha e troca a textura ao clicar com a seta para baixo, e caso esteja no ar, cai mais rapidamente. Esse sistema do personagem foi o mais complicado de ajustar para que parecesse um pulo natural e não muito duro ou distante da realidade.

Fomos evoluindo o jogo até ele estar praticamente funcional, onde ao abrir o jogo, ele já iniciava, o jogador podia morrer, e o jogo fechava. Essa foi a primeira versão jogável. Posteriormente, fomos melhorando mais o código para criação de menus, para a tela de morte e para o início do jogo.

A última coisa a ser adicionada até o momento foi o sistema de ranking persistente, que utiliza um arquivo .txt para guardar as informações dos rankings. Ao abrir o jogo, ele lê o scores.txt e salva em um vetor (com a possibilidade de uso de LSE). Ao fechar o jogo, ele salva os dados do vetor no arquivo, garantindo que os dados não sejam perdidos ao fechar o jogo.

Foi utilizado para o projeto:

- Linguagem de programação C

Bibliotecas para interface gráfica:
- [SDL2](https://github.com/libsdl-org/SDL)
- [SDL_image](https://github.com/libsdl-org/SDL_image)
- [SDL_mixer](https://github.com/libsdl-org/SDL_mixer)
- [SDL_ttf](https://github.com/libsdl-org/SDL_ttf)

## Screenshots:

![Jogo Rodando - MarioRun](https://i.imgur.com/of46iTQ.png)
![Menu Inicial - MarioRun](https://i.imgur.com/CEWM8Ax.png)
![Menu de Morte - MarioRun](https://i.imgur.com/d9YoXxR.png)

- Ranking das pessoas que jogaram na mostra de trabalho.
 
![Ranking - MarioRun](https://i.imgur.com/bjr7dwe.png)

## Detalhes da Metodologia de Desenvolvimento:

A divisão dos trabalhos foi realizada de forma colaborativa entre os desenvolvedores utilizando a plataforma Trello. Cada membro da equipe tinha responsabilidades específicas atribuídas a ele, e as tarefas eram organizadas em cartões no Trello. Durante as aulas da faculdade, realizamos discussões para definir as metas, as prioridades e as dependências entre as tarefas. Essa abordagem permitiu uma distribuição de responsabilidades e uma visão clara do progresso de cada aspecto do projeto.

![Quadro - Trello](https://i.imgur.com/wAh292k.png)

A definição dos módulos foi realizada de maneira estruturada, seguindo o conceito de Tipo Abstrato de Dados (TAD). Cada elemento no jogo, como o chão, o céu, o personagem Mario e os obstáculos, foi tratado como um TAD separado. Isso proporcionou uma abstração clara e organizada do sistema, facilitando o desenvolvimento e a manutenção do código. Além disso, foram criados TADs auxiliares, como o Text para simplificar a geração de textos, o ranking do jogo e a estrutura de dados Fila para gerenciar os obstáculos de forma eficiente.

Em resumo, o processo de desenvolvimento foi marcado por uma abordagem iterativa, divisão clara de tarefas, discussões em aula para tomada de decisões e utilização eficiente de ferramentas como o Trello para o gerenciamento do projeto.
