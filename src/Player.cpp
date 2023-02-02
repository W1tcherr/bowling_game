#include "../lib/Player.h"

void Player::set_score(const uint32_t& _frame, const uint32_t& _ball, const uint32_t& _score)
{
    for(size_t i = 0; i < 9; ++i)
    {
        if(bonus[i] > 0)
        {
            score[i] += _score;
            --bonus[i];
        }     
    }

    score[_frame] += _score;

    if(score[_frame] == 10)
    {
        _ball == 1 ? bonus[_frame] = 2 : bonus[_frame] = 1;
    }
}

uint32_t Player::get_frame_score(const uint32_t& _frame)
{
    return score[_frame];
}

uint32_t Player::get_total_score()
{
    uint32_t sum = 0;

    for(const auto& el: score)
        sum += el;

    return sum;
}