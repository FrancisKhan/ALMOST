[![Actions Status](https://github.com/FrancisKhan/ALMOST/workflows/CI-Linux/badge.svg)](https://github.com/FrancisKhan/ALMOST/actions)

# ALMOST

Advanced Lightweight Multi-physics Object-oriented Simulation Tool (ALMOST), is a C++ open source code for nuclear multi-physics simulations. The ALMOST project aims to provide a simple and user-friendly code package where physics solvers can be used standalone or coupled together.

ALMOST is being developed on Linux for Linux. However, you don't need to compile it if you just want to play with it, the Ubuntu installer is available in the *installers* folder.

The code makes use of free-format text input files. If you want to see ALMOST capabilities and start running some simulations please have a look at the *inputs* folder within the repository, it contains all ALMOST integrations tests.

Every solver is continuously tested via GitHub workflows, at the moment there are more than 130 integration tests.

## Solvers list:
* *1-D Collision Probability Method (CPM) solver for neutron transport calculation*
* *1-D Neutron diffusion solver*
* *1-D Heat transfer solver*
* *0-D Point kinetics solver*

The 1-D solvers have been implemented for spherical, cylindrical and slab geometries. The neutronics codes are able to calculate all spatial eigenmodes not just the fundamental one. Furthermore, the diffusion code supports the calculation of the adjoint flux as well.

For more detailed information visit the **wiki** page:
* [Examples](https://github.com/FrancisKhan/ALMOST/wiki/Examples)
* [Tests](https://github.com/FrancisKhan/ALMOST/wiki/Tests)
* [Input syntax](https://github.com/FrancisKhan/ALMOST/wiki/Input-syntax)
* [Compilation](https://github.com/FrancisKhan/ALMOST/wiki/Compilation)

## Plotting capabilites:

Thanks to the C++ [sciplot](https://github.com/sciplot/sciplot/) library, Almost is able to generate plots for neutron flux and power density spatial distributions.

![Neutron flux Almost plot](https://github.com/FrancisKhan/Wiki/blob/c64b2e447c19588091681c461ba999a606d418ed/neutronflux.jpg)

## Serpent to Almost Input Generator GUI application:

Neutron cross sections need to be provided in the input. They can be generated automatically through a Python application, Serpent to Almost Input Generator, that can be found in the *scripts* folder. More info to be found in [Serpent to Almost Input Generator](https://github.com/FrancisKhan/ALMOST/wiki/Serpent-to-Almost-Input-Generator)

![Serpent-to-Almost-Input-Generator](https://github.com/FrancisKhan/Wiki/blob/main/GUI_Picture.png)

Author's email: tntfnc3@gmail.com
