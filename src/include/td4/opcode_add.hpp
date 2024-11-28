#ifndef TD4_OPCODE_ADD
#define TD4_OPCODE_ADD

#include <td4/cpu.hpp>
#include <td4/opcode.hpp>

namespace td4
{
    class mov_a_im : public opcode
    {
      public:
        mov_a_im(cpu &target_cpu) : core { target_cpu }
        {
        }

        virtual void execute(void) override
        {
            core.registers.a     = core.fetch_operand();
            core.registers.carry = 0;
            core.registers.pc++;
        }

      private:
        cpu &core;
    };

    class mov_b_im : public opcode
    {
      public:
        mov_b_im(cpu &target_cpu) : core { target_cpu }
        {
        }

        virtual void execute(void) override
        {
            core.registers.b     = core.fetch_operand();
            core.registers.carry = 0;
            core.registers.pc++;
        }

      private:
        cpu &core;
    };

    class mov_a_b : public opcode
    {
      public:
        mov_a_b(cpu &target_cpu) : core { target_cpu }
        {
        }

        virtual void execute(void) override
        {
            core.registers.a     = core.registers.b;
            core.registers.carry = false;
            core.registers.pc++;
        }

      private:
        cpu &core;
    };

    class mov_b_a : public opcode
    {
      public:
        mov_b_a(cpu &target_cpu) : core { target_cpu }
        {
        }

        virtual void execute(void) override
        {
            core.registers.b     = core.registers.a;
            core.registers.carry = false;
            core.registers.pc++;
        }

      private:
        cpu &core;
    };

}

#endif
