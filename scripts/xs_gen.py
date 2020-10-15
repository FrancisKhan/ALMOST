import numpy as np
import serpentTools
import sys
from serpentTools.settings import rc

rc.__setitem__("serpentVersion", "2.1.30")

leakageCorrection   = True
transportCorrection = True
solver = "diffusion" # diffusion or transport

def main(argv):
    resFile = ''
    
    if(len(argv) < 1):
        print("\nPlease provide Serpent input file name!\n")
    elif(len(argv) == 1):
        resFile = argv[0]
    else:
        print("\nToo many arguments!\n")
        
    res = serpentTools.read(resFile)
    output = resFile + "_ALMOST.txt"
    f = open(output, 'w')
    
    print("\nSolver: ", solver, file=f)
    print("Transport Correction ", transportCorrection, file=f)
    print("Leakage Correction:  ", leakageCorrection, "\n\n", file=f)
    
    for key in res.universes:
        univ = res.getUniv(key[0], key[1])
        energyGroups = len(univ.infExp['infTot'])
        
        total        = {}
        ni           = {}
        chi          = {}
        fission      = {}
        absorption   = {}
        diffCoeff    = {}
        scatt0       = {}
        scatt1       = {}
        scattMatrix0 = {}
        
        if(leakageCorrection == False):
            
            total        = univ.infExp['infTot']
            ni           = univ.infExp['infNubar']
            chi          = univ.infExp['infChip']
            fission      = univ.infExp['infFiss']
            absorption   = univ.infExp['infAbs']
            diffCoeff    = univ.infExp['infDiffcoef']
            scatt0       = univ.infExp['infScatt0']
            scatt1       = univ.infExp['infScatt1']
            scattMatrix0 = univ.infExp['infS0']
            
        else:
            
            total        = univ.b1Exp['b1Tot']
            ni           = univ.b1Exp['b1Nubar']
            chi          = univ.b1Exp['b1Chip']
            fission      = univ.b1Exp['b1Fiss']
            absorption   = univ.b1Exp['b1Abs']
            diffCoeff    = univ.b1Exp['b1Diffcoef']
            scatt0       = univ.b1Exp['b1Scatt0']
            scatt1       = univ.b1Exp['b1Scatt1']
            scattMatrix0 = univ.b1Exp['b1S0']
    
        print("\nmaterial ", key[0], "\n", sep="", file=f)

        for i in range(energyGroups):
            print("ni(", i+1, ")         ", "{:.5e}".format(ni[i]), sep="", file=f)
            print("chi(", i+1, ")        ", "{:.5e}".format(chi[i]),  sep="", file=f)
            print("fission(", i+1, ")    ", "{:.5e}".format(fission[i]),  sep="", file=f)
            
            if(solver == "transport"):
                
                if(transportCorrection):
                    for i in range(energyGroups):
                        total[i] = total[i] - scatt1[i]
                        scattMatrix0[i + i * energyGroups] = scattMatrix0[i + i * energyGroups] - scatt1[i]
                
                print("total(", i+1, ")      ", "{:.5e}".format(total[i]), sep="", file=f)
            
            elif(solver == "diffusion"):
                
                print("absorption(", i+1, ") ", "{:.5e}".format(absorption[i]), sep="", file=f)
                
                if(transportCorrection):
                    print("diffCoeff(", i+1, ")  ", "{:.5e}".format(diffCoeff[i]), sep="", file=f)
                else:  
                    D = scatt0[i] / (3.0 * total[i] **2)
                    print("diffCoeff(", i+1, ")  ", "{:.5e}".format(D), sep="", file=f)
            
            else:
                print("ERROR: solver parameter not recognized!")
                print("Please use: transport or diffusion")
                sys.exit()
                
            print("", file=f)
        
        for i in range(energyGroups):
            for j in range(energyGroups):
                print("scattMatrix(", i+1, ", ", j+1, ") ", "{:.5e}".format(scattMatrix0[j + i * energyGroups]),  sep="", file=f)

        print("", file=f)

if __name__ == "__main__":
    main(sys.argv[1:])
