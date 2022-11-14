#include "tff.h"

void tff::tff_operation()
{
    //bool qn_val;

    qn.write(0);
    inp_rdy.write(0);
    out_vld.write(0);
    wait();

    while(true)
    {

        inp_rdy.write(1);
        do
        {
            wait();
        } while( !inp_vld.read() );

        cout << "preset : " << preset.read() << endl;
        cout << "clear : " << clear.read() << endl;
        cout << "clk : " << clk.read() << endl;
        cout << "t : " << t.read() << endl;

        if( !preset.read() )
        {
            qn_val = 1;
        }
        else if( !clear.read() )
        {
            qn_val = 0;
        }
        else if( clk.read() )
        {
            if( !t.read() )
            {
                qn_val = qn_val;
            }
            else
            {
                qn_val = !qn_val;
            }
        }

        inp_rdy.write(0);

        out_vld.write(1);
        
        qn.write(qn_val);

        do
        {
            wait();
        } while( !out_rdy.read() );
        out_vld.write(0);
    }

    //wait();
}