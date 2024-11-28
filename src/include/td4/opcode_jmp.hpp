#ifndef TD4_OPCODE_JMP
#define TD4_OPCODE_JMP

#include <td4/cpu.hpp>
#include <td4/opcode.hpp>

namespace td4
{
    class jmp_im : public opcode
    {
      public:
        jmp_im(cpu &target_cpu) : core { target_cpu }
        {
        }

        virtual void execute(void) override
        {
            core.registers.pc    = core.fetch_operand();
            core.registers.carry = false;
        }

      private:
        cpu &core;
    };

    class jnc_im : public opcode
    {
      public:
        jnc_im(cpu &target_cpu) : core { target_cpu }
        {
        }

        virtual void execute(void) override
        {
            core.registers.carry = false;

            if (core.registers.carry)
            {
                core.registers.pc++;
                return;
            }

            core.registers.pc = core.fetch_operand();
        }

      private:
        cpu &core;
    };

}

#endif
