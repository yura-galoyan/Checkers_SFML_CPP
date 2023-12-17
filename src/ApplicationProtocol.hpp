#ifndef APPLICATION_PROTOCOL
#define APPLICATION_PROTOCOL

#include "../Utils/Ynet/Client.hpp"

#include "../Common/Common.hpp"


class ApplicationProtocol : public Ynet::ClientInterface<CheckersMsgType>
{
};


#endif //APPLICATION_PROTOCOL