#ifndef TD4_INPUT_PORT_HPP
#define TD4_INPUT_PORT_HPP

#include <stdint.h>

namespace td4
{
    class input_port
    {
      public:
        virtual uint8_t read(void) = 0;

        virtual ~input_port(void)
        {
        }
    };
}

#endif
