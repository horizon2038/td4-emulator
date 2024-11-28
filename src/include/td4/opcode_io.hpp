#ifndef TD4_OPCODE_IO
#define TD4_OPCODE_IO

#include <td4/cpu.hpp>
#include <td4/opcode.hpp>

namespace td4
{
    class in_a : public opcode
    {
      public:
        in_a(cpu &target_cpu) : core { target_cpu }
        {
        }

        virtual void execute(void) override
        {
            core.registers.a     = core.port_in();
            core.registers.carry = false;
            core.registers.pc++;
        }

      private:
        cpu &core;
    };

    class in_b : public opcode
    {
      public:
        in_b(cpu &target_cpu) : core { target_cpu }
        {
        }

        virtual void execute(void) override
        {
            core.registers.b     = core.port_in();
            core.registers.carry = false;
            core.registers.pc++;
        }

      private:
        cpu &core;
    };

    class out_im : public opcode
    {
      public:
        out_im(cpu &target_cpu) : core { target_cpu }
        {
        }

        virtual void execute(void) override
        {
            core.port_out(core.fetch_operand());

            core.registers.carry = false;
            core.registers.pc++;
        }

      private:
        cpu &core;
    };

    class out_b : public opcode
    {
      public:
        out_b(cpu &target_cpu) : core { target_cpu }
        {
        }

        virtual void execute(void) override
        {
            core.port_out(core.registers.b);

            core.registers.carry = false;
            core.registers.pc++;
        }

      private:
        cpu &core;
    };

}

#endif
