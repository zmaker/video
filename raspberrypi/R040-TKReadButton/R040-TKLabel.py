import tkinter as tk
import RPi.GPIO as GPIO

class App(tk.Frame):
    
    def onclick(self):
        print("ok")
        self.lb.config(text="----")
    
    def readInput(self):
        bt = GPIO.input(20)
        if bt:
            self.lb.config(text="PRESSED")
        else:
            self.lb.config(text="...")
        self.after(100, self.readInput) # run itself again after 1000 ms

    def __init__(self, master=None):
        super().__init__(master)
        self.pack()
        GPIO.setmode(GPIO.BCM)
        GPIO.setup(20, GPIO.IN)
        
        self.lb = tk.Label(self, text="GPIO INPUT")
        self.lb.pack()
        
        self.btn = tk.Button(self, text="OK", command=self.onclick)
        self.btn.pack()
        
        self.readInput()

# create the application
myapp = App()

#
# here are method calls to the window manager class
#
myapp.master.title("LED Control App")
myapp.master.geometry('300x200+50+50')


# start the program
myapp.mainloop()