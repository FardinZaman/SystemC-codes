#include "tb.h"

void tb::source() {
  sc_uint<4> temp;
  temp = 2;

  a.write( 0 );
  //a_vld.write( 0 );
  b.write( 0 );
  ab_vld.write( 0 );
  rst.write( 1 );
  wait();
  rst.write( 0 );
  wait();

  for( int i=0 ; i<8 ; i++)
  { 
    ab_vld.write( 1 );
    a.write( temp );
    //b_vld.write( 1 );
    b.write( temp+1 );
    do {
      wait();
    } while ( !ab_rdy.read() );
    ab_vld.write( 0 );
    //b_vld.write( 0 );
    
    temp++;

    wait();
  }

}

void tb::sink() {
  sc_uint<4> indata;

  sum_rdy.write(0);

  for( int i=0 ; i<8 ; i++)
  {
    sum_rdy.write( 1 );
    do {
      wait();
    } while ( !sum_vld.read() );
    indata = sum.read();
    sum_rdy.write( 0 );

    cout<< i << " : " << indata.to_int() << endl;
  }

  sc_stop();
}
