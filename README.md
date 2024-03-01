# propulsion_system_analysis

A simple yet powerful tool designed to analyse and optimize the aerodynamics and conceptual layout of propulsion systems. In the era of Unmanned Aerial Vehicles (UAVs) and electric Vertical Take-Off and Landing (eVTOL) aircraft, the need for an efficient algorithm to evaluate the performance of propulsion system layouts at the conceptual phase is more critical than ever. To address this need, I have developed this tool.

This tool employs a non-linear vortex wake Blade Element Momentum Theory model, augmented with correction factors. The model solves for induced wake vorticies at certain locations of the propeller plane and sends the velocity data to aerosandbox (a python library, called from pybind11 interpreter) to accurately calculate the aerodynamics data at each blade section. By analyzing the aerodynamic matrices, the tool can calculate the performance of the propulsion system, facilitating rapid and precise modelling of propulsion systems at the early stages of the development cycle. 

The tool also offers versatile control options, including blade pitch, RPM, or a combination of both, facilitating the exploration of both fixed and pitch-controlled propeller variants. Additionally, it incorporates features for modeling non-linear twist and taper, enhancing its capability to simulate complex aerodynamic behaviour.

## How to use?
The tool is packaged as a Docker file, creating a virtual environment on your system and installing all necessary dependencies with minimal user interaction. To utilize this tool, ensure **Docker is installed on your system** and follow the steps below:

``` bash
  git clone https://github.com/harshabose/propulsion_system_analysis.git
  cd propulsion_system
  docker build -t propulsion_system_image --progress=plain .
```
Executing these commands builds an image named *propulsion_system_image* within your Docker environment. You can then run this image in a container, which should automatically launch an example case for demonstration.

**NOTE:** __This programme is CPU-intensive. A high-performance system is recommended for optimal operation.__

To analyse your specific design parameters, simply modify the main.cpp file with your data and repeat the steps above to see the changes reflected. For those preferring a local setup, the following dependencies are required:

- [NLOPT](https://github.com/stevengj/nlopt)
- python3.10-dev
- numpy
- [pybind11](https://github.com/pybind/pybind11)
- [aerosandbox](https://github.com/peterdsharpe/AeroSandbox?tab=readme-ov-file)

This tool is aimed at conceptual and pre-conceptual stage design iteration where rapid calculations and trade-off studies are needed.
This should allow the user to quickly conduct analyses and narrow the search space for possible configurations and effeciency.

NOTE: documentation work is pending
