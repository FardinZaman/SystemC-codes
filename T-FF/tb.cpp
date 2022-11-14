#include "tb.h"

void tb::source()
{
    //cout << "Inside source" << endl;
    preset.write(1);
    clear.write(1);
    clk.write(0);
    t.write(0);
    inp_vld.write(0);
    //ff_vld = 0;
    wait();

    srand(0);
    //cout << "Inside source\n" << endl;
    for(int i=0 ; i<20 ; i++)
    {
        //ff_vld = 1;
        inp_vld.write(1);
        
        bool temp;
        temp = rand() & 1;
        //cout<<temp;
        preset.write(temp);
        temp = rand() & 1;
        //cout<<temp;
        clear.write(temp);
        temp = rand() & 1;
        //cout<<temp;
        clk.write(temp);
        temp = rand() & 1;
        //cout<<temp;
        t.write(temp);
        //cout<<endl;
        
        do{
            wait();
        } while(!inp_rdy.read());
        inp_vld.write(0);

        //ff_vld = 0;
    }
}

void tb::sink()
{
    bool indata;

    //ff_rdy = 0;
    out_rdy.write(0);

    //wait();

    for(int i=0 ; i<20 ; i++)
    {
        //ff_rdy = 1;
        out_rdy.write(1);
        do 
        {
            wait();
        } while( !out_vld.read() );
        indata = qn.read();
        //ff_rdy = 0;
        out_rdy.write(0);

        cout << "Qn : " << indata << endl;
        cout<<endl;

        //wait();
    }

    sc_stop();
}