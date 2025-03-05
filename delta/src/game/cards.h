#pragma once

#include "types.h"

void init_deck(card_t *deck);
void shuffle_deck(card_t *deck);
void deal_hands(card_t *deck, player_t *players);

void print_card(card_t card);
void print_hand(player_t player);
void print_deck(card_t *deck);
