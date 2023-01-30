
#include "../lib/Game.h"

//set _number_of_players
void manual_input(uint32_t& _number_of_players);

int main()
{
    uint32_t number_of_players;
    Game Bowling;

    std::cout << "\n*****Welcome to the bowling game!*****" << std::endl;
    manual_input(number_of_players);
    Bowling.start(number_of_players);
   
    return 0;
}

void manual_input(uint32_t& _number_of_players)
{
	while(true)
	{
		std::cout << "Enter the number of players: ";
		std::cin >> _number_of_players;
		if(std::cin.fail() || _number_of_players > 5)
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "\nWrong number, please re-enter.\n";
		}
        else
        {
            return;
        }
    }
}