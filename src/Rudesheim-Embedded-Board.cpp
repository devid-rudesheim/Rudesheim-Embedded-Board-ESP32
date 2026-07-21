#include "Rudesheim-Embedded-Board.hpp"

namespace Rudesheim::Embedded
{
  namespace
  {
    struct Esp32:
      public Arduino
    {
    };
  }

  Board const
    &board = Class< Esp32 >::SoleObject();
}
