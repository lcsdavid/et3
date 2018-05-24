package sample.view;

import javafx.event.Event;
import sample.controller.Percentage_Controller;


public interface Percentage_View   {

	Percentage_Controller controller = null;

	public abstract void update(Event event);

}
