#include <td4/factory.hpp>

#include <td4/opcode_add.hpp>
#include <td4/opcode_io.hpp>
#include <td4/opcode_jmp.hpp>
#include <td4/opcode_mov.hpp>

namespace td4
{
    td4::cpu make_cpu()
    {
        td4::cpu core {};

        core.register_opcode(0b0011, std::make_unique<td4::mov_a_im>(core));
        core.register_opcode(0b0111, std::make_unique<td4::mov_b_im>(core));
        core.register_opcode(0b0001, std::make_unique<td4::mov_a_b>(core));
        core.register_opcode(0b0100, std::make_unique<td4::mov_b_a>(core));
        core.register_opcode(0b0000, std::make_unique<td4::mov_a_im>(core));
        core.register_opcode(0b0101, std::make_unique<td4::mov_b_im>(core));
        core.register_opcode(0b0010, std::make_unique<td4::in_a>(core));
        core.register_opcode(0b0110, std::make_unique<td4::in_b>(core));
        core.register_opcode(0b1011, std::make_unique<td4::out_im>(core));
        core.register_opcode(0b1001, std::make_unique<td4::out_b>(core));
        core.register_opcode(0b1111, std::make_unique<td4::jmp_im>(core));
        core.register_opcode(0b1110, std::make_unique<td4::jnc_im>(core));

        return core;
    }
}
