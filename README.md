<h1>Jogo da Velha</h1>
<p>Este jogo foi desenvolvido nas aulas de Laboratório de Programação I, curso de Sistemas de Informação, UFSM, com o professor Benhur Stein.</p>
<p>O programa utiliza-se do arquivo <b>tela.c</b> e <b>tecla.c</b>, desenvolvidos pelo professor para auxiliar no desenvolvimento do jogo.</p>
<h2>Rodando o programa e dependências</h2>
<p>O jogo foi desenvolvido em um ambiente Linux (WSL - Ubuntu) e roda no próprio terminal.</p>
<ul>
  <li>Compilação manual: <b>gcc -Wall -o sudoku sudoku.c telag2.c -lallegro_font -lallegro_color -lallegro_ttf -lallegro_primitives -lallegro</b></li>
  <li>Para executar: <b>./tic-tac-toe</b></li>
</ul>
<h2>Como jogar?</h2>
<p>Basicamente, o jogo funciona com comandos do teclado:</p>
<ul>
  <li>Enter => atribui o número atual à casa no tabuleiro onde o player está.</li>
  <li>A, W, S, D => controlam a movimentação do player no tabuleiro;</li>
</ul>
<h2>Imagens</h2>
<p>Seguem abaixo algumas imagens da interface do jogo.</p>
<img src="img/cover.png">
<img src="img/game_screen.png">
<img src="img/playing_screen.png">
<img src="img/score.png">
