
#include <getopt.h>
#include "dreidel.h"
#include <stdio.h>
#include <stdlib.h>
#include "mtrand.h"
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv){
	
	extern int opterr;
	opterr = 0;
	int players = 4;
	int starting_coins = 3;
	int total_rounds= 0;
	uint64_t seed = 613;

	int value;
	
	
	while ((value = getopt(argc, argv, "c:s:p:v")) != -1){
		
		switch(value) {
		
			case 'c':
		       		//set starting coins
				starting_coins = atoi(optarg);
				break;

			case 's':
				//set seed
				seed = atol(optarg);
				//mtrand_seed(seed);
				break;

			case 'p': 
				//set players
				players = atoi(optarg);
				break;
			
			case 'v':
				//enable elimination messages
				enable_elims();
				break;
			default:
				//Invalid input
				return 1;
		
		}
		
	}
	
	
	if ((2 > players) || (players > 8)){
		//invalid input
		return 1;
	}
	
	if ((1 > starting_coins) || (starting_coins > 20)){
		//invalid input
		return 1;
	}
	
	if ((seed <= 0) || (seed > 9999999999)){
		//invalid input
		return 1;
	}
		
	
	char *name[8] = {"Aharon", "Batsheva", "Chanah", "David", "Ephraim", "Faige", "Gamaliel", "Hannah"};
	
	
	
	mtrand_seed(seed);
	int winner = play_game(players, starting_coins, &total_rounds);
	//printf("player %d won  Congrats %s\n", winner, name[winner]);
	//printf("total rounds is %d\n", total_rounds);
	
	//printf("Names: %s %s %s %s", name[0], name[1], name[2], name[3]);
	printf("%s %d %d %d %lu\n", name[winner], players, starting_coins, total_rounds, seed);
	
	return 0;
}

