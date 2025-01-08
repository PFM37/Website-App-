using System;
using System.Diagnostics;
using System.Drawing;
using System.Windows.Forms;

namespace WebsiteApp
{
    public class MainForm : Form
    {
        public MainForm()
        {
            // Window Settings
            this.Text = "PFM.COM(APP)";
            this.Size = new Size(700, 400);
            this.StartPosition = FormStartPosition.CenterScreen;

            // Label
            Label label = new Label();
            label.Text = "See My Website";
            label.Font = new Font("Arial", 24, FontStyle.Regular);
            label.AutoSize = true;
            label.Location = new Point(250, 50);
            this.Controls.Add(label);

            // Button
            Button button = new Button();
            button.Text = "See Website";
            button.Font = new Font("Arial", 24, FontStyle.Regular);
            button.Size = new Size(200, 50);
            button.Location = new Point(250, 150);
            button.Click += (sender, e) => Process.Start(new ProcessStartInfo("https://www.pfm.com") { UseShellExecute = true });
            this.Controls.Add(button);
        }

        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.Run(new MainForm());
        }
    }
}
