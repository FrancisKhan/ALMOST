import numpy as np
import serpentTools
import sys
from serpentTools.settings import rc

rc.__setitem__("serpentVersion", "2.1.30")

def main(argv):
    resFile = ''

    if(len(sys.argv) == 1):
        print("\nPlease provide Serpent input file name!\n")
    elif(len(sys.argv) == 2):
        resFile = sys.argv[1]
    else:
        print("\nToo many arguments, I only need one!\n")

    #resFile = 'PWRpin.txt_res.m'
    res = serpentTools.read(resFile)

    output = "Out_" + resFile + ".txt"
    f = open(output, 'w')

    for key in res.universes:
        univ = res.getUniv(key[0], key[1])
        energyGroups = len(univ.b1Exp['b1Tot'])
    
        print("\nmaterial ", key[0], "\n", sep="", file=f)

        for i in range(energyGroups):
            print("ni(", i+1, ")      ", "{:.5e}".format(univ.b1Exp['b1Nubar'][i]), sep="", file=f)
            print("chi(", i+1, ")     ", "{:.5e}".format(univ.b1Exp['b1Chip'][i]),  sep="", file=f)
            print("fission(", i+1, ") ", "{:.5e}".format(univ.b1Exp['b1Fiss'][i]),  sep="", file=f)
            print("total(", i+1, ")   ", "{:.5e}".format(univ.b1Exp['b1Tot'][i]),  sep="", file=f)
            print("", file=f)
        
        for i in range(energyGroups):
            for j in range(energyGroups):
                print("scattMatrix(", i+1, ", ", j+1, ") ", "{:.5e}".format(univ.b1Exp['b1S0'][j + i * energyGroups]),  sep="", file=f)

        print("", file=f)

if __name__ == "__main__":
   main(sys.argv[1:])
