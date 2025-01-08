import customtkinter as ctk
import webbrowser

def open_website():
    # This will open a website in the default browser
    webbrowser.open("https://pfmcodes.tiiny.site")  # Replace with your URL

def main():
    # Root
    root = ctk.CTk()

    # Window Settings
    ctk.set_appearance_mode("Dark")
    root.title("PFM.COM(APP)")
    root.geometry("700x400")

    # Label
    label = ctk.CTkLabel(root, text="See My Website", font=ctk.CTkFont("Arial", size=24))
    label.pack(pady=20)

    # Button
    button = ctk.CTkButton(root, text="See Website", font=ctk.CTkFont("Arial", size=24), command=open_website)
    button.pack(pady=20)

    # Run the app
    root.mainloop()

if __name__ == "__main__":
    main()
