# Molecular Model

A molecular model visualization tool. 3D and 2D visualization of molecules.

## Description

This project is a molecular model visualization tool. It is programmed in C++ using OpenGL 3.3+ and GLSL 3.3+. It uses Axolote Engine, a self-made engine for OpenGL, take a look at the engine [https://github.com/JotaEspig/axolote-engine](https://github.com/JotaEspig/axolote-engine).

The idea of the project came from the college subject "Computação na educação" (Computing in education), where we had to develop a software designed to help the area of education. We chose to develop a software that could help students to visualize molecules in 3D and 2D.

## Getting Started

### Dependencies

* Axolote Engine 0.8.0
* CMake 2.8.5+
* OpenGL 3.3+
* GLFW3
* GLM
* OpenBabel 3.1.0
* PkgConfig 2.1.1
* ANTLR 4.13.2
* Doxygen (Optional)

### Installing dependencies on Linux

Ubuntu:
```bash
sudo apt-get install cmake
sudo apt-get install libglm-dev
sudo apt-get install libglfw3-dev libglfw3
sudo apt-get install libassimp-dev
sudo apt-get install openbabel
sudo apt-get install pkg-config
sudo apt-get install antlr4
```

Arch:
```bash
sudo pacman -S cmake
sudo pacman -S glm
sudo pamcan -S glfw
sudo pacman -S assimp
sudo pacman -S openbabel
sudo pacman -S pkg-config
sudo pacman -S antlr4
```

### Compiling and running

Clone the repository:
```bash
git clone https://github.com/JotaEspig/molecular-model
cd molecular-model
```

Install Axolote Engine:
```bash
git clone https://github.com/JotaEspig/axolote-engine
cd axolote-engine
bash install.sh ..
cd ..
```

Compile and run:
```bash
mkdir build
cd build
cmake ..
make
./bin/molecular-model
```

## Help

Contact the authors

## Authors

 * João Vitor Espig ([JotaEspig](https://github.com/JotaEspig))
 * Mickael Reichert ([mickaelrei](https://github.com/mickaelrei))
 * Gustavo Tramontin Pedro ([gustatramontin](https://github.com/gustatramontin))

## Version History

See [CHANGELOG.md](CHANGELOG.md)

## License

This project is licensed under the [MIT] License - see the LICENSE.md file for details

## Acknowledgments

* [Axolote Engine](https://github.com/JotaEspig/axolote-engine)
* [OpenBabel](https://github.com/openbabel/openbabel)
* [README-Template.md](https://gist.github.com/DomPizzie/7a5ff55ffa9081f2de27c315f5018afc)
