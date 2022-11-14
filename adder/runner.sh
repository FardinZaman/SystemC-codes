export SYSTEMC_HOME=/usr/local/systemc-2.3.3/

gcc -o main main.cpp adder.cpp tb.cpp -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib-linux64 -Wl,-rpath=$SYSTEMC_HOME/lib-linux64 -lsystemc -lstdc++ -lm

./main
