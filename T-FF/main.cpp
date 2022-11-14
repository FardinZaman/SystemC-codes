#include <systemc.h>
#include "tff.h"
#include "tb.h"

SC_MODULE(SYSTEM)
{
    tb *tb0;
    tff *tff0;

    sc_signal<bool> preset_sig, clear_sig, clk_sig, t_sig, qn_sig;
    sc_clock clock_sig;

    sc_signal< bool > inp_sig_rdy;
    sc_signal< bool > inp_sig_vld;
    sc_signal< bool > out_sig_rdy;
    sc_signal< bool > out_sig_vld;

    SC_CTOR(SYSTEM) : clock_sig("clock_sig", 10, SC_NS)
    {
        tb0 = new tb("tb0");
        tff0 = new tff("tff0");

        tb0->clock(clock_sig);
        tb0->preset(preset_sig);
        tb0->clear(clear_sig);
        tb0->clk(clk_sig);
        tb0->t(t_sig);
        tb0->qn(qn_sig);

        tb0->inp_vld(inp_sig_vld);
        tb0->inp_rdy(inp_sig_rdy);
        tb0->out_vld(out_sig_vld);
        tb0->out_rdy(out_sig_rdy);

        tff0->clock(clock_sig);
        tff0->preset(preset_sig);
        tff0->clear(clear_sig);
        tff0->clk(clk_sig);
        tff0->t(t_sig);
        tff0->qn(qn_sig);

        tff0->inp_vld(inp_sig_vld);
        tff0->inp_rdy(inp_sig_rdy);
        tff0->out_vld(out_sig_vld);
        tff0->out_rdy(out_sig_rdy);
    }

    ~SYSTEM()
    {
        delete tb0;
        delete tff0;
    }
};

int sc_main(int argc, char* argv[])
{
    SYSTEM *top = NULL;
    top = new SYSTEM("top");
    sc_start();

    return 0;
}