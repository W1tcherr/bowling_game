#include "../lib/Game.h"
#include <cstdint>

void Game::start(const uint32_t& number_of_players)
{
    Players.resize(number_of_players);

    std::cout << "\n***Game START!***" << std::endl;
    for(size_t frame = 0; frame < 9; ++frame)
    {
        std::cout << "\nFrame " << frame + 1 << std::endl;
        for(size_t player_number = 0; player_number < Players.size(); ++player_number)
        {
            score = 0;
            plyaers_score(frame, player_number, ball = 1);
        }
        totap_score();
    }

    std::cout << "\n*****This is the last Frame*****\n" << std::endl;
    for(size_t player_number = 0; player_number < Players.size(); ++player_number)
    {
        score = 0;
        plyaers_score(9, player_number, ball = 1);

        if(Players[player_number].get_frame_score(9) == 10)
        {
            if(ball == 1)
            {
                //strike
                plyaers_score(9, player_number, ball = 2);
                if(ball == 2)
                {
                    //strike
                    player_input_score(score, ball = 3);
                    Players[player_number].set_score(9, ball, score);
                }
            }
            else
            {
                //spear
                player_input_score(score = 0, ball = 3);
                Players[player_number].set_score(9, ball, score);
            }
        }
    }
    totap_score();
    std::cout << "\n*****End of the game*****\n" << std::endl;
}

void Game::player_input_score(uint32_t& _score, const uint32_t& ball)
{
    uint32_t score_limit = 10;
    if(ball == 2 && score != 10) score_limit = 10 - _score;
    
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
            std::cin.clear();
			std::cin.ignore(32767, '\n');
            return;
        }
    }
}

 void Game::totap_score()
 {
    for(size_t player_number = 0; player_number < Players.size(); ++player_number)
    {
        std::cout << "\nPlayer " << player_number + 1 << " total score: " << Players[player_number].get_total_score() << std::endl;
    }
 }

 void Game::plyaers_score(const uint32_t& frame, const uint32_t& player_number, uint32_t& _ball)
 {
    std::cout << "\nPlayer " << player_number + 1 << std::endl;
    player_input_score(score, _ball);
    Players[player_number].set_score(frame, _ball, score);
    if(score < 10)
    {
        ++_ball;
        player_input_score(score, _ball);
        Players[player_number].set_score(frame, _ball, score);
    }
 }