
#coding:utf-8

import libvtp
from Tkinter import *

vtp = libvtp.VideoPicture()
vtp.SetVideoPath("lumin")

def text_callback():
    print("fsdfsf")

window = Tk()

text = Entry(window, background='white').pack()

window.mainloop()


