# Mario Run

Este repositório contém o código fonte e a documentação para o jogo Mario Run, uma versão inspirada no famoso jogo "Google Dino Run", onde o jogador controla um Tiranossauro Rex que corre por um deserto pulando sobre obstáculos. Neste documento, você encontrará informações sobre o jogo, como jogá-lo, detalhes sobre o projeto e sua estrutura de dados, além de detalhes sobre a metodologia de desenvolvimento.


## Descrição do jogo:

Mario Run é uma emocionante recriação do famoso jogo "Google Dino Run", inserida no envolvente universo dos jogos do Mario. Nesta versão, o jogador assume o controle de Mario, o icônico encanador bigodudo, enquanto ele corre pelo ambiente de Super Mario Bros. Seu objetivo é pular sobre canos, evitar perigos e desafios, tudo isso para alcançar a maior pontuação possível.  




## Como jogar?

Para jogar o Mario Run, siga as instruções abaixo:

### 1. Baixar:

Para realizar o download, baixe ou clone o repositório.

  - Windows:
      As DLLs e o SDL2 estão no repositório.

  - Linux:
        Para Linux, é necessário que baixe o SDL2 e suas bibliotecas extras. Para fazer isso, pode abrir o terminal na pasta do MarioRun e rodar o comando a seguir:

        make linux-libs

### 2. Compilar e Instalar:

Apos já ter o SDL2 e suas bibliotecas auxiliares, basta dar o comando:

- Para Windowns:

      mingw32-make win
  
- Para Linux:

      make linux


### 3. Executar:

Pode se executar abrindo o executavel criado após a compilação ou utilizando o terminal:

- Para Windowns:

      ./MarioRun_win64.exe
  
- Para Linux:

      ./MarioRun_linux64

## Controles:

O jogo é controlado pelas seguintes teclas:

- **Seta para Cima ou Barra de Espaço:** Pula sobre obstáculos.
- **Seta para Baixo** Agacha ou faz o personagem cair mais rapidamente ao chão durante o pulo.

Certifique-se de usar esses controles de forma estratégica para evitar obstáculos e alcançar a maior pontuação!

## Autores e Contato:

Este jogo foi desenvolvido pelos seguintes alunos do IFSP, Campus Araraquara, no segundo semestre de 2023:

 - [Cauã Rufino de Sá](https://github.com/CauaDeSa)
 - [Giovana Trevizan Barbosa](https://github.com/giovanatrevizanbarbosa)
 - [Igor Filipi Cardoso](https://github.com/IgorFilipiCardoso)
 - [Natan Salvador Ligabo](https://github.com/natansalvadorligabo)


## Descrição do Projeto:

Toda estrutura do projeto foi desenvolvida em torno do conceito de TAD, Tipo Abstrato de Dados. No MarioRun todos tipos são um TAD, o chão, o céu, o própio mario e o obstaculo. Foram criados TADs auxiliares também, como o Text para gerar textos de forma mais simples, o ranking do jogo, e a estrutura de dados que também é um TAD é a Fila.

O jogo gira em torno de pular de obstaculos vindo em direção ao Mario, para fazermos isso utilizamos uma fila de obstaculos, onde quando o jogo é iniciado a fila é preenchida com varios obstaculos, ao começar o jogo é tirada da fila o primeiro elemento, e ao chagar ao final da tela ele é excluido e entra outro obstaculo de forma aleatoria na fila, assim sempre tendo novos obstaculos de forma aletoria.

A estratégia principal para criação do jogo foi separar os objetos, ou seja, criar TADs para cada coisa, para assim conseguirmos trabalhar de forma mais organizada e conseguir ir testando o jogo aos poucos. A primeira coisa a ser criada foi a definição base das funções de cada TAD, definindo e colocando o que cada uma iria fazer dentro do jogo. Com a evolução do jogo, foram criadas mais funções e algumas deixaram de existir.

Fomos implementando aos poucos, de coisas mais simples até as mais complexas. Começamos pelo Céu e pelo Chão, que são relativamente faceis, onde apenas andam da direita para esquerda, e quando chegam ao final da tela voltam para o inicio, assim dando a sensação de movimento. A animação do personagem foi feita com um vetor de SDL_Textures, onde cada textura era um frame da animação, que, conforme a velocidade do jogo aumenta a velocidade da animação também. Um dos sistemas mais dificeis de fazer foi o pulo e caso segure o personagem pule mais alto, agachar e trocar a textura ao clicar com a flecha para baixo e caso esteja no ar cair mais rapido. Esse sistema do personagem foi o mais complicado de deixar bom, sem parecer um pulo muito duro ou muito distoante de algo normal.

Fomos evoluindo o jogo até ele já estar praticamente funcional, onde você abria o jogo, e ele ja iniciava, morria e o jogo fechava. Essa foi a primeira versão jogavél, posteriormente fomos melhorando mais o código para criação de menu, para morte e para o inicio. 

A ultima coisa a ser adicionada até o momento foi o sistema de ranking persistente, que se utiliza um arquivo .txt para guardar as informações dos rankings, ao abrir o jogo ele lê o scores.txt e salva em um vetor(Possibilidade de uso de LSE), ao fechar o jogo ele salva os dados do vetor no arquivo, assim não perdendo os dados ao fechar o jogo.

Foi utilizado para o projeto:

- Linguagem de progamação C

Bibliotecas para interface gráfica:
- [SDL2](https://github.com/libsdl-org/SDL)
- [SDL_image](https://github.com/libsdl-org/SDL_image)
- [SDL_mixer](https://github.com/libsdl-org/SDL_mixer)
- [SDL_ttf](https://github.com/libsdl-org/SDL_ttf)


## Screenshots:

 <img width="100%" height="100%" src="https://i.imgur.com/of46iTQ.png" alt="Menu Inicial - MarioRun"/>
 <img width="100%" height="100%" src="https://i.imgur.com/CEWM8Ax.png" alt="Menu Inicial - MarioRun"/> 
 <img width="100%" height="100%" src="https://i.imgur.com/d9YoXxR.png" alt="Menu Inicial - MarioRun"/> 

  - Ranking das pessoas que jogaram na mostra de trabalho.
  <img width="100%" height="100%" src="https://i.imgur.com/Z63vbxG.png" alt="Menu Inicial - MarioRun"/> 

## Detalhes da Metodologia de Desenvolvimento:

(Obs: Aguarde a adição de detalhes sobre a metodologia de desenvolvimento, divisão de trabalhos, definição de módulos e outras informações relevantes pelos desenvolvedores.)
- Como foi a a divisão dos trabalhos?
- Como foram definidos os módulos?
- outras informações referentes ao processo de desenvolvimento...

---
