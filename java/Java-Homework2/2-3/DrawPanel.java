// JPanel that allows the user to draw shapes with the mouse. 
import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.JPanel;

public class DrawPanel extends JPanel {
	private MyShape shapes[]; // array containing all the shapes
	private int shapeCount; // statistic on the number of each shape

	private MyShape currentShape; // the current shape being drawn
	private Color currentColor; // the color of the shape
	private boolean filledShape; // whether this shape is filled

	// constructor
	public DrawPanel() {
		shapes = new MyShape[100]; // create the array
		shapeCount = 0; // initially we have no shapes

		setBackground(Color.WHITE); // set a white background

		setDrawingColor(Color.BLUE); // start drawing with black
		filledShape = true;// not filled by default
		currentShape = null; // not drawing anything initially

		// add the mouse listeners
		MouseHandler mouseHandler = new MouseHandler();
		this.addMouseListener(mouseHandler);
		this.addMouseMotionListener(mouseHandler);

	} // end DrawPanel constructor

	// draw shapes using polymorphism
	public void paintComponent(Graphics g) {
		super.paintComponent(g);

		for (int i = 0; i < shapeCount; i++)
			shapes[i].draw(g);

		// TODO
	} // end method paintComponent

	// sets the drawing color
	public void setDrawingColor(Color c) {
		currentColor = c;
	} // end method setDrawingColor

	// clears all drawings on this panel
	public void clearDrawing() {
		shapeCount = 0;
		repaint();
	} // end method clearDrawing

	// Handles mouse events for this JPanel
	private class MouseHandler extends MouseAdapter {
		// creates and sets the initial position for the new shape
		public void mousePressed(MouseEvent e) {
			currentShape = new MyRect(e.getX(),e.getY(),e.getX(),e.getY(),currentColor,filledShape);
			shapes[shapeCount++]=currentShape;
			repaint();
		} // end method mousePressed

		// fixes the current shape onto the panel
		public void mouseReleased(MouseEvent e) {
			currentShape.setX2(e.getX());
			currentShape.setY2(e.getY());
			shapes[shapeCount++]=currentShape;
			currentShape=null;
		} // end method mouseReleased

		
		// update the shape to the current mouse position while dragging
		public void mouseDragged(MouseEvent e) {
			currentShape.setX2(e.getX());
			currentShape.setY2(e.getY());
			repaint();
		} // end method mouseDragged

	} // end class MouseHandler
} // end class DrawPanel