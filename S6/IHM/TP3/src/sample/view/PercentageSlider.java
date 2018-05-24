package sample.view;

import javafx.beans.value.ObservableValue;
import javafx.scene.control.Slider;
import sample.controller.Controller_Interface;
import sample.controller.Percentage_Controller;

/**
 * A PercentagePieSlider acts boths as a MVC View and Controller of a Percentage
 * It maintains a reference to its sample.model in order to update it.
 */
public class PercentageSlider extends Slider implements TODO {

	private static final long serialVersionUID = 1L;
	
	private final Percentage_Controller myController;

	public PercentageSlider(Percentage_Controller controller) {
		myController = controller;
		setMin(0);
		setMax(100);

		this.setMinorTickCount(5);
		this.setMajorTickUnit(10);
		this.setShowTickLabels(true);
		this.setShowTickMarks(true);
		this.setBlockIncrement(10);
		this.setSnapToTicks(true);

		// "Controller" behaviour : when the value of the slider changes,
		// The sample.model must be updated
		valueProperty().addListener(new javafx.beans.value.ChangeListener<Number>() {
            @Override
			public void changed(ObservableValue<? extends Number> observable, Number oldValue, Number newValue) {
				//Do something with the sample.controller
			}
		});
	}

	
	//Override the good method 
	//TODO


	//getter of the sample.controller
    public Controller_Interface getController() {
        return sample.controller;
    }
}
