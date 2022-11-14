#include "adder.h"

void adder::do_add() {
  sc_uint<4> a_in;
  sc_uint<4> b_in;
  
  sum.write( 0 );
  ab_rdy.write( 0 );
  //b_rdy.write( 0 );
  sum_vld.write( 0 );
  wait();

  while( true ){
    
    ab_rdy.write( 1 );
    //b_rdy.write( 1 );
    do {
      wait();
    } while ( !ab_vld.read() );
    a_in = a.read();
    b_in = b.read();
    ab_rdy.write( 0 );
    //b_rdy.write( 0 );
    
    sum_vld.write( 1 );
    sum.write( a_in + b_in );
    do {
      wait();
    } while ( !sum_rdy.read() );
    sum_vld.write( 0 );

  }
}
