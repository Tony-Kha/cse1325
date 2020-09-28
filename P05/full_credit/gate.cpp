#include "gate.h"

Gate::Gate(){
    _to_gate = nullptr;
    _to_pin = 1;
    _input1 = true;
    _input2 = false;
}

void Gate::connect(Gate& gate, Pin input_pin){
    _to_gate = &gate;
    _to_pin = input_pin;
}

void Gate::input(Pin pin, Signal signal){
    if(pin==1){
        signal = _input1;
    }
    else if(pin==2){
        signal = _input2;
    }
    if(_to_gate==nullptr){
        _to_gate->input(_to_pin, signal);
    }
}

Signal Gate::input(Pin pin){
    if(pin==1){return _input1;}
    if(pin==2){return _input2;}
}
