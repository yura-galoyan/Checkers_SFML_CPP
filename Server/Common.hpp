#ifndef COMMON_HPP
#define COMMON_HPP

#include <cstdint>

enum class ChessMsgTypes : std::uint32_t
{
    ServerAccept,
    ServerDeny,
    ServerPing,
    MessageAll,
    ServerMessage,
    Player1,
    Player2,
    PlayerMove1,
    PlayerMove2
};

#endif //COMMON_HPP