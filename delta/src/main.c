#include <stdio.h>
#include <string.h>

#include "game/game_state.h"

typedef enum ACTION
{
  ACTION_NONE,

  ACTION_GAME,
  ACTION_ANALYZE,

  ACTION_HELP,
  ACTION_VERSION,
} ACTION;

ACTION parse_action(int argc, char **argv)
{
  if (argc == 1)
  {
    return ACTION_NONE;
  }

  if (argc == 2)
  {
    if (strcmp(argv[1], "game") == 0)
    {
      return ACTION_GAME;
    }

    if (strcmp(argv[1], "analyze") == 0)
    {
      return ACTION_ANALYZE;
    }

    if (strcmp(argv[1], "help") == 0)
    {
      return ACTION_HELP;
    }

    if (strcmp(argv[1], "version") == 0)
    {
      return ACTION_VERSION;
    }
  }

  return ACTION_NONE;
}

int main(int argc, char **argv)
{
  ACTION action = parse_action(argc, argv);

  switch (action)
  {
  case ACTION_GAME:
    printf("Game\n");
    break;
  case ACTION_ANALYZE:
    printf("Analyze\n");
    break;
  case ACTION_HELP:
    printf("Help\n");
    break;
  case ACTION_VERSION:
    printf("Version\n");
    break;
  default:
    init_game(&game);
    print_game(&game);
    break;
  }

  return 0;
}