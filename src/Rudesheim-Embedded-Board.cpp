#include "Rudesheim-Embedded-Board.hpp"

#include "Rudesheim-Embedded-Base.hpp"

#include <stdexcept>
#include <Arduino.h>

namespace Rudesheim::Embedded
{
  namespace
  {
    struct Esp32:
      virtual public Board
    {
      virtual auto DigitalSignal() const -> Option::Signal const & override;
      virtual auto Analog8BitSignal() const -> Option::Signal const & override;
      virtual auto Analog12BitSignal() const -> Option::Signal const & override;

      virtual auto DefaultMode() const -> Option::Mode const & override;
      virtual auto PullUpMode() const -> Option::Mode const & override;

      virtual auto SteadyOn() const -> Option::Steady const & override;
      virtual auto SteadyOff() const -> Option::Steady const & override;

      virtual auto Wait( Duration duration ) const -> void override
      {
        delayMicroseconds( duration.AsMicroseconds() );
      }

      virtual auto BeginCommunication( unsigned long baudRate ) const -> void override
      {
        Serial.begin( baudRate );
      }
    };
  }

  Board const
    &board = Class< Esp32 >::SoleObject();

  namespace Option
  {
    namespace
    {
      struct Digital:
        virtual public Signal
      {
        virtual auto Write( Location const &location, float value ) const -> void override
        {
          digitalWrite( location.Number(), static_cast< float >( 0.5f <= value ) );
        }

        virtual auto Read( Location const &location ) const -> float override
        {
          return static_cast< float >( digitalRead( location.Number() ) );
        }

        virtual auto Resolution() const -> uint8_t override
        {
          return 1;
        }
      };

      struct Analog:
        virtual public Signal
      {
        virtual auto Write( Location const &location, float value ) const -> void override
        {
          analogWrite( location.Number(), static_cast< uint8_t >( value * MaxValue() + 0.5f ) );
        }

        virtual auto Read( Location const &location ) const -> float override
        {
          return static_cast< float >( analogRead( location.Number() ) ) / MaxValue();
        }
      };

      struct Analog8Bit:
        virtual public Analog
      {
        virtual auto Resolution() const -> uint8_t override
        {
          return 8;
        }
      };

      struct Analog12Bit:
        virtual public Analog
      {
        virtual auto Resolution() const -> uint8_t override
        {
          return 12;
        }
      };

      struct Default:
        virtual public Mode
      {
        virtual auto ConfigureInput( Location const &location ) const -> void override
        {
          pinMode( location.Number(), INPUT );
        }

        virtual auto ConfigureOutput( Location const &location ) const -> void override
        {
          pinMode( location.Number(), OUTPUT );
        }
      };

      struct PullUp:
        virtual public Mode
      {
        virtual auto ConfigureInput( Location const &location ) const -> void override
        {
          pinMode( location.Number(), INPUT_PULLUP );
        }

        virtual auto ConfigureOutput( Location const & ) const -> void override
        {
          throw std::logic_error( "PullUp is not valid for Output pins" );
        }
      };

      struct On:
        virtual public Steady
      {
        virtual auto Name() const -> char const* override
        {
          return "ON";
        }

        virtual auto Level() const -> float override
        {
          return 1.0f;
        }
      };

      struct Off:
        virtual public Steady
      {
        virtual auto Name() const -> char const* override
        {
          return "OFF";
        }

        virtual auto Level() const -> float override
        {
          return 0.0f;
        }
      };
    }
  }

  namespace
  {
    auto Esp32::DigitalSignal() const -> Option::Signal const &
    {
      return Class< Option::Digital >::SoleObject();
    }

    auto Esp32::Analog8BitSignal() const -> Option::Signal const &
    {
      return Class< Option::Analog8Bit >::SoleObject();
    }

    auto Esp32::Analog12BitSignal() const -> Option::Signal const &
    {
      return Class< Option::Analog12Bit >::SoleObject();
    }

    auto Esp32::DefaultMode() const -> Option::Mode const &
    {
      return Class< Option::Default >::SoleObject();
    }

    auto Esp32::PullUpMode() const -> Option::Mode const &
    {
      return Class< Option::PullUp >::SoleObject();
    }

    auto Esp32::SteadyOn() const -> Option::Steady const &
    {
      return Class< Option::On >::SoleObject();
    }

    auto Esp32::SteadyOff() const -> Option::Steady const &
    {
      return Class< Option::Off >::SoleObject();
    }
  }
}
