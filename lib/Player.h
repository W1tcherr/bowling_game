#pragma once

#include <iostream>
#include <vector>

class Player
{
    std::vector<uint32_t> score = std::vector<uint32_t>(10); // score for 'i' round
    std::vector<uint32_t> bonus = std::vector<uint32_t>(10); // if strike set 2, if spear set 1
    
    public:

    //adds score to the desired frame and handles the strike and spear
    void set_score(const uint32_t& _frame, const uint32_t& _ball, const uint32_t& _score);

    //return total player score
    uint32_t get_score();
};