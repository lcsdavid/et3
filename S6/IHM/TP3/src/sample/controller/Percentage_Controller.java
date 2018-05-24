package sample.controller;

import sample.event.ValueListener;
import sample.model.Percentage_Model;
import sample.event.ValueChangedEvent;
import sample.view.Percentage_View;

/**
 * This class is a MVC "Controller" of a percentage (a value such as 0 <= x <= 1)
 **/
public class Percentage_Controller implements Controller_Interface {
	private final Percentage_Model myModel;

	/**
	 * Create a Percentage with a sample.model
	 * @param model : the sample.model of this sample.controller
	 * @throws IllegalArgumentException if value is not correct
	 **/
	public Percentage_Controller(Percentage_Model model) {
		myModel = model;
	}



	/**
	 * Change the value of this Percentage.
	 * Update the views
	 * @param value : the value
	 * @throws IllegalArgumentException if value is not correct
	 **/
	public void setValue(Double value) {
        //TODO set the value of the sample.model
	}


    /**
	 * Get the value from the sample.model
	 * @return the percentage value
	 */
	public double getValue() {
		return 0.0f; // TODO return the value of the percentage from the sample.model instead
	}

	/**
	 * Add a new Listener to the sample.model
	 * @param valueL     the new listener
	 **/
	@Override
	public void addListenerValue(ValueListener valueL) {
		// TODO add the listener from the sample.model

	}

	/**
	 * Remove a Listener from the sample.model
	 * @param valueL     the  listener to remove
	 **/
    @Override
    public void removeListenerValue(ValueListener valueL) {
    		// TODO remove the listener from the sample.model

	}

    public void notifyValueChanged(double value){
        //TODO refere the sample.model that the value changed
    }




}
