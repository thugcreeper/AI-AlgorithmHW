import javax.swing.ButtonGroup;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.BorderLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class TemperatureConversion extends JFrame {
	private final JLabel fromLabel;
	private final JLabel toLabel;
	private final JLabel sourceLabel;
	private final JLabel targetLabel;
	private final ButtonGroup fromOptions;
	private final ButtonGroup toOptions;
	private final JRadioButton fromFahrenheit;
	private final JRadioButton fromCelsius;
	private final JRadioButton fromKelvin;
	private final JRadioButton toFahrenheit;
	private final JRadioButton toCelsius;
	private final JRadioButton toKelvin;
	private final JPanel fromPanel;
	private final JPanel toPanel;
	private final JPanel inputPanel;
	private final JTextField inputField;
	private final JTextField outputField;
	private final JButton convesionButton;

	public TemperatureConversion() {
		super("Temperature Conversion");
		setLayout(new GridLayout(8,1));
		fromLabel =new JLabel("Convert from:");
		toLabel =new JLabel("Convert to:");
		sourceLabel=new JLabel("Source Temprature");
		targetLabel =new JLabel("Target Temperature");

		MyEventListner handler = new MyEventListner();

		fromFahrenheit = new JRadioButton("Fahrenheit", true);
		fromCelsius = new JRadioButton("Celsius", false);
		fromKelvin = new JRadioButton("Kelvin", false);

		fromFahrenheit.addActionListener(handler);//註冊事件監聽器
		fromCelsius.addActionListener(handler);
		fromKelvin.addActionListener(handler);

		toFahrenheit = new JRadioButton("Fahrenheit", true);
		toCelsius = new JRadioButton("Celsius", false);
		toKelvin = new JRadioButton("Kelvin", false);

		toFahrenheit.addActionListener(handler);//註冊事件監聽器
		toCelsius.addActionListener(handler);
		toKelvin.addActionListener(handler);

		fromOptions = new ButtonGroup();//創建按鈕群組
		fromOptions.add(fromFahrenheit);
		fromOptions.add(fromCelsius);
		fromOptions.add(fromKelvin);

		toOptions = new ButtonGroup();
		toOptions.add(toFahrenheit);
		toOptions.add(toCelsius);
		toOptions.add(toKelvin);

		inputField = new JTextField();
		outputField = new JTextField();
		convesionButton = new JButton("Convert");
		convesionButton.addActionListener(handler);
		add(fromLabel);
		fromPanel = new JPanel(new GridLayout(1,3));
		fromPanel.add(fromFahrenheit);//不能加按鈕group
		fromPanel.add(fromCelsius);
		fromPanel.add(fromKelvin);
		add(fromPanel);//將panel加入視窗

		add(toLabel);
		toPanel = new JPanel(new GridLayout(1,3));
		toPanel.add(toFahrenheit);
		toPanel.add(toCelsius);
		toPanel.add(toKelvin);
		add(toPanel);

		inputPanel = new JPanel( new BorderLayout());//border layout將元件放在中間並確保使用所有可用空間
		inputPanel.add(inputField);
		inputPanel.add(convesionButton,BorderLayout.EAST);//按鈕放東邊
		add(inputPanel);

		add(targetLabel);
		add(outputField);
		outputField.setEditable (false);//唯讀

	}

	private class MyEventListner implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent e) {
			//若點擊按鈕或按下enter
			double temperature=Double.parseDouble(inputField.getText());//攝氏
			if(e.getSource() == convesionButton || e.getSource()==inputField){
				if(fromFahrenheit.isSelected()){
					temperature= (temperature -32) *5.0/9;//華式轉攝氏
				}
				else if(fromKelvin.isSelected()){
					temperature -= 273.15;
				}

				if(toFahrenheit.isSelected()){
					temperature=temperature*9/5.0 +32;//攝氏轉華式
				}
				else if(toKelvin.isSelected()){
					temperature += 273.15;
				}
			}
			outputField.setText(String.format("%f",temperature));
		}
	}
	
}