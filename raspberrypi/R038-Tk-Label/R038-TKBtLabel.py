import tkinter as tk

class App(tk.Frame):
    
    def pressButton(self):
        self.lb["text"] = "Hello World!"
    
    def __init__(self, master=None):
        super().__init__(master)
        self.pack()
        
        self.bt = tk.Button(self, text="Press Me", command = self.pressButton)
        self.bt.pack()
        
        self.lb = tk.Label(self, text="...")
        self.lb.pack()

# create the application
myapp = App()
myapp.master.title("Button App")
myapp.master.geometry('300x200+50+50')
myapp.mainloop()