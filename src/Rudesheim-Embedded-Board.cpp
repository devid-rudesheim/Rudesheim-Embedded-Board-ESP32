#include "Rudesheim-Embedded-Board.hpp"

#include <stdexcept>
#include <WiFi.h>

namespace Rudesheim::Embedded
{
  namespace
  {
    struct Esp32:
      public Arduino
    {
      virtual auto ConnectWifi( Credentials const &credentials ) const -> IpAddress override
      {
        WiFi.begin( credentials.Id(), credentials.Password() );

        for( auto attempt = 0U; attempt < 100U && WiFi.status() != WL_CONNECTED; ++attempt )
        {
          board.Wait( Second( Milli( 100 ) ) );
        }

        if( WiFi.status() != WL_CONNECTED )
        {
          throw WifiConnectionError( "Failed to connect to WiFi" );
        }

        auto const
          ip = WiFi.localIP();

        return IpAddress( ip[ 0 ], ip[ 1 ], ip[ 2 ], ip[ 3 ] );
      }

      virtual auto DisconnectWifi() const -> void override
      {
        WiFi.disconnect();
      }
    };
  }

  Board const
    &board = Class< Esp32 >::SoleObject();
}
