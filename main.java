import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.net.URI;
import java.net.http.*;
import java.net.*;

public class main {

    public static void main(String[] args) {
        JFrame frame = new JFrame("PFM.COM(APP)");
        frame.setSize(700, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new FlowLayout());

        // Label
        JLabel label = new JLabel("See My Website");
        label.setFont(new Font("Arial", Font.PLAIN, 24));
        frame.add(label);

        // Button
        JButton button = new JButton("See Website");
        button.setFont(new Font("Arial", Font.PLAIN, 24));
        button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                try {
                    // Open website
                    Desktop.getDesktop().browse(new URI("https://pfmcodes.tiiny.site"));
                } catch (Exception ex) {
                    ex.printStackTrace();
                }
            }
        });
        frame.add(button);

        frame.setVisible(true);
    }
}
