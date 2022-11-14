#include <systemc.h>

#define WIDTH  4

SC_MODULE(adder) {
  sc_in< sc_uint<WIDTH> > a, b;
  sc_out< sc_uint<WIDTH> > sum;
  sc_in< bool > clk;
  sc_in< bool > rst;

  sc_in< bool > ab_vld;
  sc_out< bool > ab_rdy;
  //sc_in< bool > b_vld;
  //sc_out< bool > b_rdy;
  sc_in< bool > sum_rdy;
  sc_out< bool > sum_vld;

  void do_add();

  SC_CTOR(adder)       {
    //SC_METHOD(do_add);
    //sensitive << a << b;
    SC_CTHREAD( do_add, clk.pos() );
    reset_signal_is( rst, true );
  }
};

