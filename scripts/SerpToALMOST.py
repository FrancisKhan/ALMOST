import tkinter as tk
import tkinter.filedialog
import os.path
import xs_gen

class GeneratorGUI:
    def __init__(self, master, nInputEntries):
        self.master = master
        self.nInputEntries = nInputEntries
        self.master.title("Serpent to Almost Input Generator")
        self.OPTIONS = ["C", "K"]

        self.fileValuesList = [None] * (self.nInputEntries + 1)
        self.tempValuesList = [0.0] * self.nInputEntries

        self.fileEntryList = []
        self.tempTkStrList = []
        self.unitMenuList  = []

        self.tkUnitSolverMenu = tk.StringVar()
        self.tkCheckLeakage   = tk.IntVar()
        self.tkCheckTransport = tk.IntVar()

        self.inputFilesAndTemps = {}
        self.outputFiles = ""

        frameInputs = tk.Frame()
        lbl_value = tk.Label(master=frameInputs, text="Serpent inputs:", font=('Helvetica', 15, 'bold'))
        lbl_value.grid(row=0, column=0)
        self.createInputLines(frameInputs)
        frameInputs.grid(row=1, column=0)

        frameOutput = tk.Frame()
        self.createOutput(frameOutput)
        frameOutput.grid(row=2, column=0, sticky="w")

        frameParam = tk.Frame()
        self.createParametersAndGenerate(frameParam)
        frameParam.grid(row=3, column=0, sticky="w")

    def generate(self):

        j = 1

        for i in range(len(self.tempTkStrList)):
            if(self.unitMenuList[i].get() == "K"):
                self.tempValuesList[i] = self.fromStrToFloat(self.tempTkStrList[i].get()) - 273.15
            else:
                self.tempValuesList[i] = self.fromStrToFloat(self.tempTkStrList[i].get())

            if self.tempValuesList[i] == -273.15:
                self.tempValuesList[i] = self.tempValuesList[i] + j

            j = j + 1         

        for i in range(len(self.tempValuesList)):
            self.inputFilesAndTemps[self.tempValuesList[i]] = self.fileValuesList[i]

        self.outputFile = self.fileValuesList[3]

        xs_gen.Generator(self.tkCheckLeakage.get(), self.tkCheckTransport.get(), self.tkUnitSolverMenu.get(), 
                         self.inputFilesAndTemps, self.outputFile)

    def browseDirectories(self, n):
        filename = tkinter.filedialog.askopenfilename(filetypes=(("Matlab files", "*.m"), ("All files", "*.*")))
        self.fileEntryList[n].delete(0, tk.END)
        self.fileEntryList[n].insert(tk.END, filename)
        self.fileValuesList[n] = self.fileEntryList[n].get()

    def saveFile(self, n):
        fileStr = tkinter.filedialog.asksaveasfile(filetypes=(("text files", "*.txt"), ("All files", "*.*")))
        self.fileEntryList[n].delete(0, tk.END)
        self.fileEntryList[n].insert(tk.END, fileStr.name)
        self.fileValuesList[n] = fileStr.name

    def fromStrToFloat(self, value):
       
        if value == "":
            return 0.0
        else:
            return float(value)

    def createInputLines(self, frame):

        for n in range(self.nInputEntries):
            lbl = tk.Label(master=frame, text="File " + str(n + 1) + ": ")
            lbl.grid(row=n+1, column=0)

        # First line

        self.fileEntryList.append(tk.Entry(master=frame, font=40, width=60))
        self.fileEntryList[0].grid(row=1, column=1, padx=10)

        btn1 = tk.Button(master=frame, text="Open...",font=40, command= lambda: self.browseDirectories(0))
        btn1.grid(row=1, column=2, padx=10)

        self.tempTkStrList.append(tk.StringVar())
        entTemp1 = tk.Entry(master=frame, textvariable=self.tempTkStrList[0], font=40, width=10)
        entTemp1.grid(row=1, column=3, padx=10)
        
        self.unitMenuList.append(tk.StringVar(frame))
        self.unitMenuList[0].set(self.OPTIONS[1])
        menu1 = tk.OptionMenu(frame, self.unitMenuList[0], *self.OPTIONS)
        menu1.grid(row=1, column=4)

        # Second line

        self.fileEntryList.append(tk.Entry(master=frame, font=40, width=60))
        self.fileEntryList[1].grid(row=2, column=1, padx=10)

        btn2 = tk.Button(master=frame, text="Open...",font=40, command= lambda: self.browseDirectories(1))
        btn2.grid(row=2, column=2, padx=10)

        self.tempTkStrList.append(tk.StringVar())
        entTemp2 = tk.Entry(master=frame, textvariable=self.tempTkStrList[1], font=40, width=10)
        entTemp2.grid(row=2, column=3, padx=10)
        
        self.unitMenuList.append(tk.StringVar(frame))
        self.unitMenuList[1].set(self.OPTIONS[1])
        menu2 = tk.OptionMenu(frame, self.unitMenuList[1], *self.OPTIONS)
        menu2.grid(row=2, column=4)

        # Third line

        self.fileEntryList.append(tk.Entry(master=frame, font=40, width=60))
        self.fileEntryList[2].grid(row=3, column=1, padx=10)

        btn3= tk.Button(master=frame, text="Open...",font=40, command= lambda: self.browseDirectories(2))
        btn3.grid(row=3, column=2, padx=10)

        self.tempTkStrList.append(tk.StringVar())
        entTemp3 = tk.Entry(master=frame, textvariable=self.tempTkStrList[2], font=40, width=10)
        entTemp3.grid(row=3, column=3, padx=10)
        
        self.unitMenuList.append(tk.StringVar(frame))
        self.unitMenuList[2].set(self.OPTIONS[1])
        menu3 = tk.OptionMenu(frame, self.unitMenuList[2], *self.OPTIONS)
        menu3.grid(row=3, column=4)
    
    def createOutput(self, frame):

        lblOutput = tk.Label(master=frame, text="Output:", font=('Helvetica', 15, 'bold'))
        lblOutput.grid(row=0, column=0)

        lblFile = tk.Label(master=frame, text="File: ")
        lblFile.grid(row=1, column=0)

        self.fileEntryList.append(tk.Entry(master=frame, font=40, width=60))
        self.fileEntryList[3].grid(row=1, column=1, padx=10)

        btnOpen = tk.Button(master=frame, text="Open...",font=40, command= lambda: self.saveFile(3))
        btnOpen.grid(row=1, column=2, padx=20)

    def createParametersAndGenerate(self, frame):

        SOLVEROPTIONS = ["Diffusion", "Transport (CPM)"]

        lblOutput = tk.Label(master=frame, text="Parameters:", font=('Helvetica', 15, 'bold'))
        lblOutput.grid(row=0, column=0)

        lblFile = tk.Label(master=frame, text="Solver: ")
        lblFile.grid(row=1, column=0, padx=10)

        self.tkUnitSolverMenu = tk.StringVar(frame)
        self.tkUnitSolverMenu.set(SOLVEROPTIONS[0])
        menu = tk.OptionMenu(frame, self.tkUnitSolverMenu, *SOLVEROPTIONS)
        menu.grid(row=1, column=1, padx=10)
    
        self.tkCheckLeakage.set(1)
        checkBox1 = tk.Checkbutton(master=frame, variable=self.tkCheckLeakage, onvalue=1, offvalue=0, text="Leakage correction")
        checkBox1.grid(row=1, column=2, padx=10)

        self.tkCheckTransport.set(1)
        checkBox2 = tk.Checkbutton(master=frame, variable=self.tkCheckTransport, onvalue=1, offvalue=0, text="Tranport correction")
        checkBox2.grid(row=1, column=3, padx=50)

        btnGenerate = tk.Button(master=frame, text="Generate",font=('Helvetica', 11, 'bold'), command=self.generate)
        btnGenerate.grid(row=1, column=4)

root = tk.Tk()    
my_gui = GeneratorGUI(root, 3)
root.mainloop()