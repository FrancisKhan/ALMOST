import numpy as np
import serpentTools
import sys
import os.path
from serpentTools.settings import rc
from datetime import datetime
import numpy as np
from scipy import interpolate
from numpy.polynomial.polynomial import Polynomial

class Generator:
    def __init__(self, leakageCorrection, transportCorrection, solver, 
                 inputFilesAndTemps, outputFile):

        rc.__setitem__("serpentVersion", "2.1.30")

        self.leakageCorrection   = leakageCorrection
        self.transportCorrection = transportCorrection
        self.solver = solver
        self.inputFilesAndTemps = inputFilesAndTemps
        self.outputFile = outputFile

        self.serpentFilesAndTemps = {}

        self.mesh = Mesh()

        self.prepareSerpentFiles()
        self.fileObject = open(self.outputFile, 'w')
        self.printHeader()

        for temp in self.serpentFilesAndTemps: 
            res = serpentTools.read(self.serpentFilesAndTemps[temp])

            if temp == list(self.serpentFilesAndTemps.keys())[0]:
                self.createMaterials(res)

            self.readSerpentOutput(res, temp)

        self.calculateALMOSTCrossSections()
        self.printAlmostOutput()

    # def __del__(self):
    #     self.fileObject.close()

    def calculateALMOSTCrossSections(self):   

        temps = self.mesh.getTemperatures()

        if len(self.mesh.materialList[0].groupConstantsList) == 1:
            
            for mat in self.mesh.materialList:

                gc1 = mat.groupConstantsList[0]

                for xskey in mat.crossSectionset.xs:

                    xsInterValues = {}

                    for e in range(gc1.energyGroups):
                        xsInterValues[e] = np.array(gc1.set[xskey][e])

                    mat.crossSectionset.xs[xskey] = xsInterValues

                for xskey in mat.crossSectionMatrixSet.matrix:

                    xsInterValues = {}

                    for i in range(gc1.energyGroups):
                        for j in range(gc1.energyGroups):
                            xsInterValues[(i, j)] = np.array(gc1.set[xskey][i][j])

                    mat.crossSectionMatrixSet.matrix[xskey] = xsInterValues

        elif len(self.mesh.materialList[0].groupConstantsList) == 2:

            for mat in self.mesh.materialList:

                gc1 = mat.groupConstantsList[0]
                gc2 = mat.groupConstantsList[1]

                for xskey in mat.crossSectionset.xs:

                    xsInterValues = {}

                    for e in range(gc1.energyGroups):

                        xsSerpentValues = np.array([gc1.set[xskey][e], gc2.set[xskey][e]])

                        func = interpolate.lagrange(temps, xsSerpentValues)
                        xsInterValues[e] = np.flipud(np.array(Polynomial(func).coef))

                    mat.crossSectionset.xs[xskey] = xsInterValues

                for xskey in mat.crossSectionMatrixSet.matrix:

                    xsInterValues = {}

                    for i in range(gc1.energyGroups):
                        for j in range(gc1.energyGroups):

                            xsSerpentValues = np.array([gc1.set[xskey][i][j], gc2.set[xskey][i][j]])

                            func = interpolate.lagrange(temps, xsSerpentValues)
                            xsInterValues[(i, j)] = np.flipud(np.array(Polynomial(func).coef))

                    mat.crossSectionMatrixSet.matrix[xskey] = xsInterValues

        elif len(self.mesh.materialList[0].groupConstantsList) == 3:

            for mat in self.mesh.materialList:

                gc1 = mat.groupConstantsList[0]
                gc2 = mat.groupConstantsList[1]
                gc3 = mat.groupConstantsList[2]

                for xskey in mat.crossSectionset.xs:

                    xsInterValues = {}

                    for e in range(gc1.energyGroups):

                        xsSerpentValues = np.array([gc1.set[xskey][e], gc2.set[xskey][e], gc3.set[xskey][e]])

                        func = interpolate.lagrange(temps, xsSerpentValues)
                        xsInterValues[e] = np.flipud(np.array(Polynomial(func).coef))

                    mat.crossSectionset.xs[xskey] = xsInterValues

                for xskey in mat.crossSectionMatrixSet.matrix:

                    xsInterValues = {}

                    for i in range(gc1.energyGroups):
                        for j in range(gc1.energyGroups):

                            xsSerpentValues = np.array([gc1.set[xskey][i][j], gc2.set[xskey][i][j], gc3.set[xskey][i][j]])

                            func = interpolate.lagrange(temps, xsSerpentValues)
                            xsInterValues[(i, j)] = np.flipud(np.array(Polynomial(func).coef))

                    mat.crossSectionMatrixSet.matrix[xskey] = xsInterValues

    def prepareSerpentFiles(self):

        serpentTemp1 = float(list(self.inputFilesAndTemps.keys())[0])
        serpentTemp2 = float(list(self.inputFilesAndTemps.keys())[1])
        serpentTemp3 = float(list(self.inputFilesAndTemps.keys())[2])

        serpentFile1 = self.inputFilesAndTemps[serpentTemp1]
        serpentFile2 = self.inputFilesAndTemps[serpentTemp2]
        serpentFile3 = self.inputFilesAndTemps[serpentTemp3]
    
        if os.path.exists(serpentFile1) and serpentFile1:
            if not serpentFile2:
                self.serpentFilesAndTemps[0] = serpentFile1
            else:
                self.serpentFilesAndTemps[serpentTemp1] = serpentFile1
            
                if os.path.exists(serpentFile2):
                    self.serpentFilesAndTemps[serpentTemp2] = serpentFile2

                    if serpentFile3:
                        if os.path.exists(serpentFile3):
                            self.serpentFilesAndTemps[serpentTemp3] = serpentFile3
                        else:
                            print("Third Serpent output not found!")
                            sys.exit()

                else:
                    print("Second Serpent output not found!")
                    sys.exit()
        else:
            print("First Serpent output not found!")
            sys.exit()

    def printAlmostOutput(self):

        energyGroups = self.mesh.materialList[0].getEnergiesNumber()

        for mat in self.mesh.materialList:

            print("\nmaterial ", mat.matNumber, "\n", sep="", file=self.fileObject)

            for i in range(energyGroups):

                print("ni(", i+1, ")         ", scientific(mat.crossSectionset.xs["ni"][i]), sep="", file=self.fileObject)
                print("chi(", i+1, ")        ", scientific(mat.crossSectionset.xs["chi"][i]),  sep="", file=self.fileObject)
                print("total(", i+1, ")      ", scientific(mat.crossSectionset.xs["total"][i]), sep="", file=self.fileObject)
                print("fission(", i+1, ")    ", scientific(mat.crossSectionset.xs["fission"][i]),  sep="", file=self.fileObject)
            
                if(self.solver == "Diffusion"):
                    print("diffCoeff(", i+1, ")  ", scientific(mat.crossSectionset.xs["diffCoeff"][i]), sep="", file=self.fileObject)

                print("", file=self.fileObject)
        
            for i in range(energyGroups):
                for j in range(energyGroups):
                    print("scattMatrix(", i+1, ", ", j+1, ") ", scientific(mat.crossSectionMatrixSet.matrix["scattMatrix0"][(i, j)]),  sep="", file=self.fileObject)

            print("\nxs_reference_temperature ", scientific(mat.getMinimumTemperature()), "\n", file=self.fileObject)


    def readSerpentOutput(self, output, temp):
    
        for key in output.universes:
            univ = output.getUniv(key[0], key[1])
            energyGroups = len(univ.infExp['infTot'])
        
            total           = []
            ni              = []
            chi             = []
            fission         = []
            absorption      = []
            diffCoeff       = []
            scatt0          = []
            scatt1          = []
            scattMatrix0Vec = []

            scattMatrix0 = np.zeros((energyGroups, energyGroups))
        
            if(self.leakageCorrection == False):
            
                total           = univ.infExp['infTot']
                ni              = univ.infExp['infNubar']
                chi             = univ.infExp['infChip']
                fission         = univ.infExp['infFiss']
                absorption      = univ.infExp['infAbs']
                diffCoeff       = univ.infExp['infDiffcoef']
                scatt0          = univ.infExp['infScatt0']
                scatt1          = univ.infExp['infScatt1']
                scattMatrix0Vec = univ.infExp['infS0']
            
            else:
            
                total           = univ.b1Exp['b1Tot']
                ni              = univ.b1Exp['b1Nubar']
                chi             = univ.b1Exp['b1Chip']
                fission         = univ.b1Exp['b1Fiss']
                absorption      = univ.b1Exp['b1Abs']
                diffCoeff       = univ.b1Exp['b1Diffcoef']
                scatt0          = univ.b1Exp['b1Scatt0']
                scatt1          = univ.b1Exp['b1Scatt1']
                scattMatrix0Vec = univ.b1Exp['b1S0']
            
            for i in range(energyGroups):
            
                if(self.solver == "Transport (CPM)"):
                
                    if(self.transportCorrection):
                        total[i] = total[i] - scatt1[i]
                        scattMatrix0Vec[i + i * energyGroups] = scattMatrix0Vec[i + i * energyGroups] - scatt1[i]
            
                elif(self.solver == "Diffusion"):
                
                    if(not self.transportCorrection):
                        diffCoeff[i] = scatt0[i] / (3.0 * total[i] **2)
            
            for i in range(energyGroups):
                for j in range(energyGroups):
                    scattMatrix0[i, j] = scattMatrix0Vec[j + i * energyGroups]

            gps = GroupConstants(total, ni, chi, fission, absorption, diffCoeff, scattMatrix0, temp)
            self.mesh.getMaterial(key[0]).addGroupConstants(gps)


    def createMaterials(self, output):  
        for key in output.universes:
            mat = Material(key[0])
            self.mesh.addMaterial(mat)

    def printHeader(self):
        print(datetime.now().strftime("%d %b %Y %H:%M:%S"), file=self.fileObject)
        print("\nSolver:               ", self.solver, file=self.fileObject)
        print("Transport Correction: ", self.transportCorrection, file=self.fileObject)
        print("Leakage Correction:   ", self.leakageCorrection, "\n", file=self.fileObject)

        print("Serpent input files:", file=self.fileObject)

        for key in self.serpentFilesAndTemps:
            print("Temperature: ", key, " File: ", self.serpentFilesAndTemps[key], file=self.fileObject)


class CrossSectionMatrixSet:
    def __init__(self):
        self.matrix = {
        "scattMatrix0" : []}

class CrossSectionSet:
    def __init__(self):
        self.xs = {
        "total" : [],
        "ni" : [],
        "chi" : [],
        "fission" : [],
        "absorption" : [],
        "diffCoeff" : []}

class GroupConstants:
    def __init__(self, total, ni, chi, fission, absorption, diffCoeff, scattMatrix0, temp):
        self.set = {
        "total" : total,
        "ni" : ni,
        "chi" : chi,
        "fission" : fission,
        "absorption" : absorption,
        "diffCoeff" : diffCoeff,
        "scattMatrix0" : scattMatrix0}
        self.temp = temp
        self.energyGroups = len(total)


class Material:
    def __init__(self, matNumber):
        self.matNumber = matNumber
        self.groupConstantsList = []
        self.temperatures = np.array([])
        self.crossSectionset = CrossSectionSet()
        self.crossSectionMatrixSet = CrossSectionMatrixSet()

    def AreGroupConstantsAlreadyThere(self, i):
        areThere = False
        for gc in self.groupConstantsList:
            if gc.temp == i.temp:
                areThere = True
                break

        return areThere          

    def addGroupConstants(self, i):
        if len(self.groupConstantsList) == 0:
            self.groupConstantsList.append(i)
            self.temperatures = np.append(self.temperatures, i.temp)
        else:
            if not self.AreGroupConstantsAlreadyThere(i):
                self.groupConstantsList.append(i)
                self.temperatures = np.append(self.temperatures, i.temp)
                    
    def getMaterialNumber(self):
        return self.matNumber

    def getTemperatures(self):
        return self.temperatures

    def getMinimumTemperature(self):
        return np.amin(self.temperatures)

    def getEnergiesNumber(self):
        return len(self.crossSectionset.xs["total"])

class Mesh:
    def __init__(self):
        self.materialList = []

    def getMaterial(self, i):
        for mat in self.materialList:
            if mat.getMaterialNumber() == i:
                return mat

    def isMaterialAlreadyThere(self, i):
        isThere = False
        for mat in self.materialList:
            if mat.getMaterialNumber() == i.getMaterialNumber():
                isThere = True
                break

        return isThere          

    def addMaterial(self, i):

        if len(self.materialList) == 0:
            self.materialList.append(i)
        else:
            if not self.isMaterialAlreadyThere(i):
                self.materialList.append(i)
            else:
                self.getMaterial(i.getMaterialNumber()).addGroupConstants(i.groupConstantsList[0])

    def getTemperatures(self):
        return self.materialList[0].getTemperatures()


def scientific(s):

    result = ""
    if s.shape == ():
        result = np.format_float_scientific(s, unique=False, precision=5)
    else:
        for i in s:
            result += np.format_float_scientific(i, unique=False, precision=5) + " "

    return result

def main():

    inputFilesAndTemps = {26.0 : "/home/why/Serpent/input/cyl_water_reactor_two_materials.txt_res.m",
                          56.0 : "/home/why/Serpent/input/cyl_water_reactor_two_materials_600.txt_res.m",
                          96.0 : "/home/why/Serpent/input/cyl_water_reactor_two_materials_900.txt_res.m"}

    outputFile = os.getcwd() + "/output.txt"

    Generator(True, True, "Diffusion", inputFilesAndTemps, outputFile)
    
if __name__ == "__main__":
    main()
