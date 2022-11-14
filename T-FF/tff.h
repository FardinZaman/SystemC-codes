#include <systemc.h>

SC_MODULE(tff)
{
    sc_in<bool> clock;

    sc_in<bool> preset, clear, t, clk;
    sc_out<bool> qn;

    sc_in<bool> inp_vld;
    sc_out<bool> inp_rdy;
    sc_in<bool> out_rdy;
    sc_out<bool> out_vld;

    bool qn_val;

    void tff_operation();

    SC_CTOR(tff)
    {
        // SC_METHOD(tff_operation);
        // sensitive << preset.neg() << clear.neg() << clk.pos();
        SC_CTHREAD( tff_operation, clock.pos() );
    }
};