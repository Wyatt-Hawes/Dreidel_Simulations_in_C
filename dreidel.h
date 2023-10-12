#pragma once
#include "stdio.h"
#include <stdint.h>

int play_game(int n_players, int coins_per_player, int *n_rounds);

char spin_dreidel(void);

uint64_t mt_rand(void);

void enable_elims(void);
