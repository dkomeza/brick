#include "cards.h"

#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>

void init_deck(card_t *deck)
{
  int i = 0;
  for (int suit = SPADES; suit <= CLUBS; suit++)
  {
    for (int value = 2; value <= 14; value++)
    {
      deck[i].suit = suit;
      deck[i].value = value;
      i++;
    }
  }
}

void shuffle_deck(card_t *deck)
{
  srand(time(NULL));
  for (int i = 0; i < 52; i++)
  {
    int j = rand() % 52;
    card_t temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }
}

void print_card(card_t card)
{
  char *suit;  // Use char* to store a string
  char *value; // Use char* to store a string

  switch (card.suit)
  {
  case SPADES:
    suit = "♠"; // UTF-8 encoded string
    break;
  case HEARTS:
    suit = "♥";
    break;
  case DIAMONDS:
    suit = "♦";
    break;
  case CLUBS:
    suit = "♣";
    break;
  default:
    suit = "?"; // Handle unexpected suit values
    break;
  }

  switch (card.value)
  {
  case 11:
    value = "J";
    break;
  case 12:
    value = "Q";
    break;
  case 13:
    value = "K";
    break;
  case 14:
    value = "A";
    break;
  default:
    break;
  }

  if (card.value >= 2 && card.value <= 10)
  {
    printf("%s%d", suit, card.value); // Print as a string
  }
  else
  {
    printf("%s%s", suit, value); // Print as a string
  }
  printf(" ");
}

/*
 * Print the cards in a player's hand in a sorted order (Suit first).
 */
void print_hand(player_t player)
{
  card_t hand[13];
  for (int i = 0; i < player.num_cards; i++)
  {
    hand[i] = player.cards[i];
  }

  // Bubble sort
  for (int i = 0; i < player.num_cards - 1; i++)
  {
    for (int j = 0; j < player.num_cards - i - 1; j++)
    {
      if (hand[j].suit > hand[j + 1].suit)
      {
        card_t temp = hand[j];
        hand[j] = hand[j + 1];
        hand[j + 1] = temp;
      }
      else if (hand[j].suit == hand[j + 1].suit && hand[j].value > hand[j + 1].value)
      {
        card_t temp = hand[j];
        hand[j] = hand[j + 1];
        hand[j + 1] = temp;
      }
    }
  }

  for (int i = 0; i < player.num_cards; i++)
  {
    print_card(hand[i]);
  }
  printf("\n");
}

void print_deck(card_t *deck)
{
  for (int i = 0; i < 52; i++)
  {
    print_card(deck[i]);
  }
  printf("\n");
}