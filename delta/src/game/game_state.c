#include <stdio.h>

#include "game_state.h"

game_t game;

void init_game(game_t *game)
{
  card_t deck[52];
  init_deck(deck);
  shuffle_deck(deck);

  for (int i = 0; i < 4; i++)
  {
    game->players[i].position = i;
    game->players[i].num_cards = 13;
    for (int j = 0; j < 13; j++)
    {
      game->players[i].cards[j] = deck[i * 13 + j];
    }
  }
}

void print_game(game_t *game)
{
  for (int i = 0; i < 4; i++)
  {
    printf("Player %d: ", i);
    print_hand(game->players[i]);
    printf("\n");
  }
}