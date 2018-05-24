package sample.controller;

import sample.event.ValueChangedEvent;
import sample.event.ValueListener;
import sample.view.Percentage_View;

public interface Controller_Interface {

    public double getValue() ;
    public void addListenerValue(ValueListener valueL) ;
    public void removeListenerValue(ValueListener valueL);
    public void notifyValueChanged(double value);


    }
