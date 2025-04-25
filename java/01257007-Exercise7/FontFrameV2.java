//javac -d . *.java
package ntou.cs.java2025;
import java.awt.BorderLayout;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class FontFrameV2 extends JFrame {
	private JButton increaseButton; // button to increase font size
	private JButton decreaseButton; // button to decrease font size
	private JTextArea text; // displays example text
	private int fontSize = 20; // current font size

	public FontFrameV2() {
		super("Font Test");//title
        increaseButton = new JButton("Increase Font Size");//button init
        decreaseButton = new JButton("Decrease Font Size");
		MyEventListner handler = new MyEventListner();
		// create buttons and add action listeners
		increaseButton.addActionListener(handler);
		decreaseButton.addActionListener(handler);
		// create text area and set initial font
		text = new JTextArea("Test");
		text.setFont(new Font("Consolos", Font.PLAIN, fontSize));

		// add GUI components to frame
		JPanel panel = new JPanel(); // used to get proper layout
		panel.add(decreaseButton);
		panel.add(increaseButton);

		add(panel, BorderLayout.NORTH); // add buttons at top
		add(new JScrollPane(text)); // allow scrolling
	}

	private class MyEventListner implements ActionListener {
		// change font size when user clicks on a button
		@Override 
		public void actionPerformed(ActionEvent event){//increase size
			if(event.getSource()==increaseButton){
			    if(fontSize+2>160){
			        JOptionPane.showMessageDialog(FontFrameV2.this,"No, it cannot be larger!");
			        fontSize=160;
			    }
			    else{
			        fontSize+=2;
			    }
			}
			else if(event.getSource()==decreaseButton){
			    if(fontSize-2<8){
			        JOptionPane.showMessageDialog(FontFrameV2.this,"No, it cannot be smaller!");
			        fontSize=8;//FontFrameV2.this表示show在fontframV2上
			    }
			    else{
			        fontSize-=2;
			    }
			}
			text.setFont(new Font("Consolos", Font.PLAIN, fontSize));//change font size
		}
	}

} 