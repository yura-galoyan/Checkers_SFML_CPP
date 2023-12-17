#include "CustomServer.hpp"

int main(){
    CustomServer server(60000);
    server.start();

    while(1)
    {
        server.update(-1,true);
    } 
    return 0;
}
