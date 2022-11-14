#include <systemc.h>

SC_MODULE(tb)
{
    sc_in<bool> clock;
    
    sc_out<bool> preset, clear, t, clk;
    sc_in<bool> qn;

    // bool ff_rdy;
    // bool ff_vld;
    sc_out<bool> inp_vld;
    sc_in<bool> inp_rdy;
    sc_out<bool> out_rdy;
    sc_in<bool> out_vld;

    void source();
    void sink();

    SC_CTOR(tb)
    {
        SC_CTHREAD( source, clock.pos() );
        SC_CTHREAD( sink, clock.pos() );
    }
};