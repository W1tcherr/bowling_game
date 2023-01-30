#pragma once

#include <vector>
#include "Player.h"

class Game
{
    uint32_t score; //number of score for the ball
    std::vector<Player> Players;

    //set _score
    void get_score(uint32_t& _score, const uint32_t& ball);

    public:
    //main cycle
    void start(const uint32_t& number_of_players);
};