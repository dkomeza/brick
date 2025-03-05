#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef enum
{
  SPADES,
  HEARTS,
  DIAMONDS,
  CLUBS
} Suit;

typedef enum
{
  NORTH,
  EAST,
  SOUTH,
  WEST
} PlayerPosition;

typedef struct
{
  Suit suit;
  int value; // 2-14
} card_t;

typedef struct
{
  card_t cards[13];
  int num_cards;
  PlayerPosition position;
} player_t;

typedef struct
{
  player_t players[4];
  card_t trick[4];
} game_t;
