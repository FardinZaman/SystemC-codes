#include <systemc.h>

SC_MODULE(tb) {
  sc_out< sc_uint<4> > a, b;
  sc_in< sc_uint<4> > sum;
  sc_in< bool > clk;
  sc_out< bool > rst;

  sc_out< bool > ab_vld;
  sc_in< bool > ab_rdy;
  //sc_out< bool > b_vld;
  //sc_in< bool > b_rdy;
  sc_out< bool > sum_rdy;
  sc_in< bool > sum_vld;

  void source();
  void sink();

  SC_CTOR(tb) {
    SC_CTHREAD( source, clk.pos() );
    SC_CTHREAD( sink, clk.pos() );
  }
};
