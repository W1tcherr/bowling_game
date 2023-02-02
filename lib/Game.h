#pragma once

#include <vector>
#include "Player.h"

class Game
{
    uint32_t score; //number of score for the ball
    uint32_t ball;
    std::vector<Player> Players;

    //set _score
    void player_input_score(uint32_t& _score,const uint32_t& ball);

    //print players total score
    void totap_score();

    //call player_input_score and player.set_score 
    void plyaers_score(const uint32_t& frame, const uint32_t& player_number, uint32_t& _ball);

    public:
    //main cycle
    void start(const uint32_t& number_of_players);
};