using System;
using System.Windows.Forms;

namespace WebsiteApp
{
    public class MainForm : Form
    {
        public MainForm()
        {
            // Form settings
            this.Text = "PFM.COM(APP)";
            this.Width = 700;
            this.Height = 400;
            this.StartPosition = FormStartPosition.CenterScreen;

            // Label
            Label label = new Label
            {
                Text = "See My Website",
                Font = new System.Drawing.Font("Arial", 16),
                AutoSize = true,
                Location = new System.Drawing.Point(250, 50)
            };
            this.Controls.Add(label);

            // Button
            Button button = new Button
            {
                Text = "See Website",
                Font = new System.Drawing.Font("Arial", 14),
                Location = new System.Drawing.Point(250, 150),
                Width = 200
            };
            button.Click += (sender, args) =>
            {
                try
                {
                    // Use Process.Start to open the URL in the default browser
                    System.Diagnostics.Process.Start(new System.Diagnostics.ProcessStartInfo
                    {
                        FileName = "https://pfmcodes.tiiny.site",
                        UseShellExecute = true // Ensures the default browser is used
                    });
                }
                catch (Exception ex)
                {
                    MessageBox.Show($"Failed to open website: {ex.Message}", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            };
            this.Controls.Add(button);
        }

        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new MainForm());
        }
    }
}
