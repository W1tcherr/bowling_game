#include "../lib/Game.h"

void Game::start(const uint32_t& number_of_players)
{
    Players.resize(number_of_players);

    std::cout << "\n***Game START!***" << std::endl;
    for(size_t frame = 0; frame < 10; ++frame)
    {
        std::cout << "\nFrame " << frame + 1 << std::endl;
        for(size_t player_number = 0; player_number < Players.size(); ++player_number)
        {
            std::cout << "\nPlayer " << player_number + 1 << std::endl;
            get_score(score, 1);
            Players[player_number].set_score(frame, 1, score);
            if(score < 10)
            {
                get_score(score, 2);
                Players[player_number].set_score(frame, 2, score);
            }
        }

        for(size_t player_number = 0; player_number < Players.size(); ++player_number)
        {
            std::cout << "\nPlayer " << player_number + 1 << " total score: " << Players[player_number].get_score() << std::endl;
        }
    }

    std::cout << "\n*****End of the game*****\n" << std::endl;
}

void Game::get_score(uint32_t& _score,const uint32_t& ball)
{
    uint32_t score_limit;
    ball == 1? score_limit = 10: score_limit = 10 - _score;
    
    while(true)
    {
        std::cout << "Enter the number of points for the ball " << ball << ": ";
        std::cin >> _score;
        if(std::cin.fail() || _score > score_limit)
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