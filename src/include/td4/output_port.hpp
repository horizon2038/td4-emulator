#ifndef TD4_OUTPUT_PORT_HPP
#define TD4_OUTPUT_PORT_HPP

#include <stdint.h>

namespace td4
{
    class output_port
    {
      public:
        virtual void write(uint8_t value) = 0;

        virtual ~output_port(void)
        {
        }
    };

}

#endif
