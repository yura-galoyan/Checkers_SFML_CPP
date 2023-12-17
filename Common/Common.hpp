#ifndef COMMON_HPP
#define COMMON_HPP

#include <cstdint>

enum class CheckersMsgType : std::uint32_t
{
    ServerAccept,
    ServerDeny,
    ServerPing,
    MessageAll,
    ServerMessage,
    OtherPlayer,
    Player1,
    Player2,
    PlayerMove,
    PlayerMove1,
    PlayerMove2,
    Assign_id
};

enum class Color : std::uint32_t{
    White,Black,None
};

struct Player{
    std::uint16_t id;
    Color color;
};

#endif //COMMON_HPP