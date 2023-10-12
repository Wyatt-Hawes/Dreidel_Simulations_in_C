#include "mtrand.h"
#include <stdio.h>

unsigned long long my_seed;
int print_elims = 0;

int mt_rand(void){

	uint64_t  value = mtrand_rand64();
	return value % 4;
}

void enable_elims(){
	print_elims = 1;
}


char spin_dreidel(void){
	int val = mt_rand();
	switch (val){
	
	case 0:
		//printf("in case 0");
		return 'G';
		break;
	case 1:
		//printf("in case 1");
		return 'H';
		break;
	case 2:
		//printf("in case 2");
		return 'N';
		break;
	case 3:
		//printf("in case 3");
		return 'S';
		break;
	}
	//printf("Defaulting error");
	return 'e';
}

int play_game(int n_players, int coins_per_player, int *total_rounds){
	
	//printf("total_rounds:%d\n", *total_rounds);
	
	char *name[] = {"Aharon", "Batsheva", "Chanah", "David", "Ephraim", "Faige", "Gamaliel", "Hannah"};
	int player_coins[n_players];
	int pot = 0;
	for (int i = 0; i < n_players; i++){
		player_coins[i] = coins_per_player;	
	}
	int take;
	int rounds = 1;
	int count = 0;
	while (1==1)
	{
		
		//Loop through every player for the current round
		for (int player = 0; player < n_players; player++){
			
			//Player is out so turn gets skipped
			if (player_coins[player] <= -1){	
				//printf("Player %d skipped turn b/c eliminated\n", player);
				continue;
			}
			
			//Getting players roll
			char players_roll = spin_dreidel();	

			switch(players_roll){
				
				case 'G':
					//gimel roll, take the pot
					player_coins[player] = player_coins[player] + pot;
					pot = 0;
					break;
					
				case 'H': 
					//hayh roll, take half the pot, rolling down				
					take = pot / 2;
					
					player_coins[player] = player_coins[player] + take;
					pot =pot - take;
					break; 
					
				case 'N':
					//nun roll, nothing happens
					break;
					
					
				case 'S':
					//shin roll, player puts in coin
					player_coins[player] = player_coins[player] - 1;
					//If player has no coin to give, dont add to pot and eliminate player
					if (player_coins[player] >= 0){
						pot = pot + 1;
					}
					
					//printf("New pot is %d\n",pot);
					break;
					
			}
			//checking if the players coins are less than 0 after their roll, if so, they are eliminated
			if (player_coins[player] <= -1){
				if (print_elims){
					printf("%s: eliminated in round %d of a %d player game.\n", name[player], rounds, n_players);
					}
				count += 1;
			}
			if (n_players - count == 1){
				for (int i = 0; i < n_players; i++){
					if (player_coins[i] > 0){
						//setting total rounds memory to "return" the value
						*total_rounds = rounds;
						//returning index of winner
						return i;
					}
				}
			}
		}
		rounds = rounds + 1;
	}
	return -1;	
}
