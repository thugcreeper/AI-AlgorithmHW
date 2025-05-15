// Program that creates a panel for the user to draw shapes.
// Allows the user to choose the shape and color.
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class DrawFrame extends JFrame implements ItemListener, ActionListener {
	// Array of possible colors
	private Color colors[] = { Color.BLUE, Color.CYAN, Color.GRAY, Color.GREEN, Color.MAGENTA, Color.ORANGE, Color.PINK,
			Color.RED, Color.YELLOW, Color.WHITE, Color.BLACK };

	// Array of names corresponding to the possible colors
	private String colorNames[] = { "Blue", "Cyan", "Gray", "Green", "Magenta", "Orange", "Pink", "Red", "Yellow", "White", "Black" };

	private DrawPanel drawPanel; // panel that handles the drawing

	private final JLabel colorLabel;
	private final JComboBox<String> colorChoices; // combo box for selecting the color
	private final JButton clearButton; // button to clear all shapes

	// constructor
	public DrawFrame() {
		super("Java Drawings");

		// create a panel to store the components at the top of the frame
		JPanel topPanel = new JPanel();

		colorLabel = new JLabel("Color of New Rectangle:");
		topPanel.add(colorLabel);

		// create a combo-box for choosing colors
		colorChoices = new JComboBox<String>(colorNames);//下拉式選單
		colorChoices.addItemListener(this);
		topPanel.add(colorChoices);

		// create a button for clearing all drawings
		clearButton = new JButton("Clear All");
		clearButton.addActionListener(this);
		topPanel.add(clearButton);

		// add the top panel to the frame
		add(topPanel, BorderLayout.NORTH);

		// create the DrawPanel with its status bar label
		drawPanel = new DrawPanel();

		add(drawPanel); // add the drawing area to the center
	} // end DrawFrame constructor

	// handle selections made to a combo box of check box
	/*this method is invoked when an item has been selected or deselected by the user.
	It takes an ItemEvent object as a parameter, providing information about the event,
	such as the source of the event and the type of change (selected or deselected).*/
	public void itemStateChanged(ItemEvent e) {
		if(e.getStateChange()== ItemEvent.SELECTED){
			//getSelectedIndex是combobox提供的方法
			int index=colorChoices.getSelectedIndex();//get selected color index
			drawPanel.setDrawingColor(colors[index]);
		}
	} // end method itemStateChanged

	// handle button clicks
	public void actionPerformed(ActionEvent e) {
		drawPanel.clearDrawing();
	} // end method actionPerformed
} // end class DrawFrame
