#include <systemc.h>
#include "adder.h"
#include "tb.h"

SC_MODULE( SYSTEM ) {
  tb *tb0;
  adder *adder0;

  sc_signal< sc_uint<4> > a_sig, b_sig, sum_sig;
  sc_signal< bool > rst_sig;
  sc_clock clk_sig;

  sc_signal< bool > ab_sig_rdy;
  sc_signal< bool > ab_sig_vld;
  sc_signal< bool > sum_sig_rdy;
  sc_signal< bool > sum_sig_vld;

  SC_CTOR( SYSTEM )
	  : clk_sig ("clk_sig", 10, SC_NS)
  {
    tb0 = new tb("tb0");
    tb0->clk(clk_sig);
    tb0->rst(rst_sig);
    tb0->a(a_sig);
    tb0->b(b_sig);
    tb0->sum(sum_sig);

    tb0->ab_rdy(ab_sig_rdy);
    tb0->ab_vld(ab_sig_vld);
    tb0->sum_rdy(sum_sig_rdy);
    tb0->sum_vld(sum_sig_vld);

    adder0 = new adder("adder0");
    adder0->clk(clk_sig);
    adder0->rst(rst_sig);
    adder0->a(a_sig);
    adder0->b(b_sig);
    adder0->sum(sum_sig);

    adder0->ab_rdy(ab_sig_rdy);
    adder0->ab_vld(ab_sig_vld);
    adder0->sum_rdy(sum_sig_rdy);
    adder0->sum_vld(sum_sig_vld);
  }

  ~SYSTEM() {
    delete tb0;
    delete adder0;
  }

};


int sc_main( int argc, char* argv[] )
{
  SYSTEM *top = NULL;
  top = new SYSTEM("top");
  sc_start();
  return 0;
}
