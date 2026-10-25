# Miniprojeto - Jogo da Velha (Prog II)

## Como compilar

```bash
make
```

## Como executar

```bash
./jogo_da_velha
```

## O que foi implementado

- Arquitetura POO com encapsulamento, heranca, classe abstrata e polimorfismo.
- `Tabuleiro` com estado privado e metodos de jogo.
- `Jogador` abstrato com `escolherJogada(Tabuleiro&)`.
- Classes derivadas: `JogadorHumano`, `BotAleatorio`, `BotBasico` e `BotMedio`.
- Motor com `std::unique_ptr` e `std::make_unique` (sem `new/delete` manual).
- Menu completo (1 a 6).
- Estatisticas de vit/emp/der.
- Top 10 persistente em `data/top10.txt`.
- Suspensao e continuidade da partida com `data/savegame.txt`.

## Observacoes

- Entrada de nome usa formato sem espacos para simplificar leitura de arquivos.
- A opcao de modo de funcionamento cancela partida ativa, conforme enunciado.

## Nota de Revisao
- Arquivos de codigo e Makefile receberam comentarios detalhados linha a linha.

