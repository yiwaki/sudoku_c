# sudoku_c

Python module to solve Sudoku puzzle written in C.

For more information on Sudoku, see [Wikipedia](https://en.wikipedia.org/wiki/Sudoku).

## Install Python
Install Python with your preferred method - pyenv, anaconda, and so on.

And install required package of Python with the following command.
```
pip install setuptools
```
For anaconda
```
conda install setuptools
```

## Install C compiler and other development tools.
- For Windows, install MinGW or C compiler with Vusual Studio.
- For macOS, run the following shell command.
```
xcode-select --install
```
- For linux, or another Unix-like OS, install C compiler according to the installation instructions for your Linux distribution.

example (Ubuntu):
```
sudo apt install build-essential
```

## Download this kit
```
git clone https://github.com/yiwaki/sudoku_c.git
```

## Compile and install
- For Windows with MinGW
```
cd sudoku_rust
python setup.py build_ext --inplace --compiler=mingw32
```
- For others
```
cd sudoku_rust
python setup.py build_ext --inplace
```

## Run sample program
```
python test.py
```

## How to make Sudoku puzzle
see sample data -> data/easy.csv
