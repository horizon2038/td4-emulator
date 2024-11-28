#include <td4/cpu.hpp>

#include <format>
#include <iostream>

namespace td4
{
    void cpu::register_opcode(uint8_t number, std::unique_ptr<opcode> target_opcode)
    {
        if (number > 0b1111)
        {
            return;
        }

        opcodes[number] = std::move(target_opcode);
        std::cout << std::format("[td4] register opcode[{:0>04b}]", number) << std::endl;
    }

    void cpu::register_port(
        std::unique_ptr<input_port>  target_input,
        std::unique_ptr<output_port> target_output
    )
    {
        input  = std::move(target_input);
        output = std::move(target_output);
        std::cout << "[td4] register input/output ports" << std::endl;
    }

    void cpu::register_rom(std::unique_ptr<rom> target_rom)
    {
        internal_rom = std::move(target_rom);
        std::cout << "[td4] register rom" << std::endl;
    }

    void cpu::clock(void)
    {
        opcodes[fetch_opcode()]->execute();

        if (registers.pc >= 16)
        {
            registers.pc = 0;
        }
    }

    uint8_t cpu::fetch_opcode(void)
    {
        if (!internal_rom)
        {
            std::cout << "rom not found" << std::endl;
            return 0;
        }

        auto op = internal_rom->at(registers.pc);
        return (op >> 4) & 0b1111;
    }

    uint8_t cpu::fetch_operand(void)
    {
        if (!internal_rom)
        {
            return 0;
        }

        return internal_rom->at(registers.pc) & 0b1111;
    }

    uint8_t cpu::port_in(void)
    {
        if (!input)
        {
            uint8_t value = 0;
            return value & 0b1111;
        }

        uint8_t value = input->read();
        return value & 0b1111;
    }

    void cpu::port_out(uint8_t value)
    {
        value &= 0b1111;

        if (!output)
        {
            bool led_0 = (value >> 0) & 1;
            bool led_1 = (value >> 1) & 1;
            bool led_2 = (value >> 2) & 1;
            bool led_3 = (value >> 3) & 1;

            std::cout << "[td4] " << (led_3 ? "o" : "-") << (led_2 ? "o" : "-")
                      << (led_1 ? "o" : "-") << (led_0 ? "o" : "-") << std::endl;
            return;
        }

        output->write(value);
        return;
    }
}
