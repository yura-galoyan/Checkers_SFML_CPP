#ifndef COMMON_HPP
#define COMMON_HPP

#include <cstdint>

enum class ChessMsgType : std::uint32_t
{
    ServerAccept,
    ServerDeny,
    ServerPing,
    MessageAll,
    ServerMessage,
    Player1,
    Player2,
    PlayerMove1,
    PlayerMove2,
    Assign_id
};

enum class Color : std::uint32_t{
    White,Black,None
};

struct Player{
    std::size_t id;
    Color color;
};

#endif //COMMON_HPP