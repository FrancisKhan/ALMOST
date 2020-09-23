import numpy as np
import serpentTools
import sys
from serpentTools.settings import rc

rc.__setitem__("serpentVersion", "2.1.30")

def main(argv):
    resFile = ''
    leakageCorrection = False

    if(len(argv) < 2):
        print("\nPlease provide Serpent input file name and leakage correction mode!\n")
    elif(len(argv) == 2):
        resFile = argv[0]
        if(argv[1] == "b1"):
           leakageCorrection = True 
        elif(argv[1] == "inf"):
           leakageCorrection = False
        else:
            print("\nPlease provide leakage correction mode: b1 or inf!\n")
    else:
        print("\nToo many arguments!\n")
        
    res = serpentTools.read(resFile)
    output = resFile + "_ALMOST.txt"
    f = open(output, 'w')

    if(leakageCorrection == False):

        print("\nLeakage correction: Infinite", sep="", file=f)

        for key in res.universes:
            univ = res.getUniv(key[0], key[1])
            energyGroups = len(univ.infExp['infTot'])
    
            print("\nmaterial ", key[0], "\n", sep="", file=f)

            for i in range(energyGroups):
                print("ni(", i+1, ")      ", "{:.5e}".format(univ.infExp['infNubar'][i]), sep="", file=f)
                print("chi(", i+1, ")     ", "{:.5e}".format(univ.infExp['infChip'][i]),  sep="", file=f)
                print("fission(", i+1, ") ", "{:.5e}".format(univ.infExp['infFiss'][i]),  sep="", file=f)
                print("total(", i+1, ")   ", "{:.5e}".format(univ.infExp['infTot'][i]),   sep="", file=f)
                print("", file=f)
        
            for i in range(energyGroups):
                for j in range(energyGroups):
                    print("scattMatrix(", i+1, ", ", j+1, ") ", "{:.5e}".format(univ.infExp['infS0'][j + i * energyGroups]),  sep="", file=f)

            print("", file=f)
    else:
        
        print("\nLeakage correction: B1", sep="", file=f)
        
        for key in res.universes:
            univ = res.getUniv(key[0], key[1])
            energyGroups = len(univ.b1Exp['b1Tot'])
    
            print("\nmaterial ", key[0], "\n", sep="", file=f)

            for i in range(energyGroups):
                print("ni(", i+1, ")      ", "{:.5e}".format(univ.b1Exp['b1Nubar'][i]), sep="", file=f)
                print("chi(", i+1, ")     ", "{:.5e}".format(univ.b1Exp['b1Chip'][i]),  sep="", file=f)
                print("fission(", i+1, ") ", "{:.5e}".format(univ.b1Exp['b1Fiss'][i]),  sep="", file=f)
                print("total(", i+1, ")   ", "{:.5e}".format(univ.b1Exp['b1Tot'][i]),   sep="", file=f)
                print("", file=f)
        
            for i in range(energyGroups):
                for j in range(energyGroups):
                    print("scattMatrix(", i+1, ", ", j+1, ") ", "{:.5e}".format(univ.b1Exp['b1S0'][j + i * energyGroups]),  sep="", file=f)

            print("", file=f)

if __name__ == "__main__":
   main(sys.argv[1:])
