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
        _input1 = signal;
    }
    else if(pin==2){
        _input2 = signal;
    }
    if(_to_gate!=nullptr){
        _to_gate->input(_to_pin, output());
    }
}

Signal Gate::input(Pin pin){
    if(pin==1){return _input1;}
    return _input2;
}

Signal Gate::output(){return false;}
