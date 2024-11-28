#ifndef TD4_OPCODE
#define TD4_OPCODE

namespace td4
{
    class cpu;

    class opcode
    {
      public:
        virtual void execute(void) = 0;

        virtual ~opcode(void)
        {
        }
    };

}

#endif
