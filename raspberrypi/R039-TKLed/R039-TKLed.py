import tkinter as tk
import RPi.GPIO as GPIO

class App(tk.Frame):
    statoled = GPIO.HIGH
    
    def pressButton(self):
        self.statoled = not self.statoled
        GPIO.output(21, self.statoled)
    
    def __init__(self, master=None):
        super().__init__(master)
        self.pack()
        GPIO.setmode(GPIO.BCM)
        GPIO.setup(21, GPIO.OUT)
        
        self.bt = tk.Button(self, text="LED Switch", command = self.pressButton)
        #bt.pack()
        
        self.bt.pack()

# create the application
myapp = App()

#
# here are method calls to the window manager class
#
myapp.master.title("LED Control App")
myapp.master.geometry('300x200+50+50')


# start the program
myapp.mainloop()