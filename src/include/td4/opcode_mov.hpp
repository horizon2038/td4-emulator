#ifndef TD4_OPCODE_MOV
#define TD4_OPCODE_MOV

#include <td4/cpu.hpp>
#include <td4/opcode.hpp>

namespace td4
{
    class add_a_im : public opcode
    {
      public:
        add_a_im(cpu &target_cpu) : core { target_cpu }
        {
        }

        virtual void execute(void) override
        {
            uint8_t value = core.registers.a + core.fetch_operand();
            if (value > 0b1111)
            {
                core.registers.carry = true;
            }

            core.registers.a = value & 0b1111;
            core.registers.pc++;
        }

      private:
        cpu &core;
    };

    class add_b_im : public opcode
    {
      public:
        add_b_im(cpu &target_cpu) : core { target_cpu }
        {
        }

        virtual void execute(void) override
        {
            uint8_t value = core.registers.b + core.fetch_operand();
            if (value > 0b1111)
            {
                core.registers.carry = true;
            }

            core.registers.b = value & 0b1111;
            core.registers.pc++;
        }

      private:
        cpu &core;
    };
}

#endif
