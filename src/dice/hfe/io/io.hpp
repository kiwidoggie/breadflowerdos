#pragma once

namespace dice
{
    namespace hfe
    {
        namespace io
        {
            class NetworkManager;
            class SocketManager;
            
            // TODO: Implement
            // bf2: 00850820
            // NOTE: Should we move this to like an io.hpp??
            SocketManager* setSocketManager();

            static NetworkManager* g_networkManager;
        }
    }
}