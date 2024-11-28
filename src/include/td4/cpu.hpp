#ifndef TD4_CPU_HPP
#define TD4_CPU_HPP

#include <memory>
#include <td4/input_port.hpp>
#include <td4/opcode.hpp>
#include <td4/output_port.hpp>

#include <array>
#include <stdint.h>

namespace td4
{
    inline constexpr uintmax_t MAX_ROM_SIZE = 16;
    using rom                               = std::array<uint8_t, MAX_ROM_SIZE>;

    class cpu
    {
      public:
        struct hardware_context
        {
            struct
            {
                uint8_t a : 4;
                uint8_t b : 4;
            };

            uint8_t pc { 0 };
            bool    carry;
        } registers;

        void register_opcode(uint8_t number, std::unique_ptr<opcode> target_opcode);
        void register_port(
            std::unique_ptr<input_port>  target_input,
            std::unique_ptr<output_port> target_output
        );
        void register_rom(std::unique_ptr<rom> target_rom);

        void    clock(void);
        uint8_t fetch_opcode(void);
        uint8_t fetch_operand(void);
        uint8_t port_in(void);
        void    port_out(uint8_t value);

      private:
        std::unique_ptr<opcode>      opcodes[0b1111];
        std::unique_ptr<input_port>  input;
        std::unique_ptr<output_port> output;
        std::unique_ptr<rom>         internal_rom;
    };
}

#endif
