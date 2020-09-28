#ifndef _GATE_H
#define _GATE_H
typedef int Pin;
typedef bool Signal;

class Gate{
    private:
        Gate* _to_gate;
        Pin _to_pin;
    protected:
        Signal _input1;
        Signal _input2;  
    public:
        Gate();
        void connect(Gate& gate, Pin input_pin);
        void input(Pin pin, Signal signal);
        Signal input(Pin pin);
        virtual Signal output();
};
#endif
