# sudoku_c

Python module to solve Sudoku puzzle written in C.

For more information on Sudoku, see [Wikipedia](https://en.wikipedia.org/wiki/Sudoku).

## Install make command

- For Windows:

Download the installation kit for your Windows from [here](http://gnuwin32.sourceforge.net/packages/make.htm) and run it.

- For macOS:

```
xcode-select --install
```

- For Debian/Ubuntu:

```
sudo apt install -y make
```

- For CentOS/Fedora:

```
sudo yum install -y make
```

## Install uv - Python package and project manager

- For Windows:

```
powershell -ExecutionPolicy ByPass -c "irm https://astral.sh/uv/install.ps1 | iex"
```

- For macOS, linux, or another Unix-like OS:

```
curl -LsSf https://astral.sh/uv/install.sh | sh
```

## Install C compiler and other development tools.

- For Windows

```
Install MinGW or C compiler with Vusual Studio.
```

- For macOS

```
xcode-select --install
```

- For linux, or another Unix-like OS:

Install C compiler according to the installation instructions for your Linux distribution.

- Ubuntu:

```
sudo apt install build-essential
```

## Download this kit

```
cd [your project directory]
git clone https://github.com/yiwaki/sudoku_c.git
```

## Make your environment

- For Windows:

```
cd sudoku_c
./make_env.ps1
```

- For macOS, linux, or another Unix-like OS:

```
cd sudoku_c
source ./make_env.sh
```

## Compile and install

```
make develop
```

## Run sample program

```
make sample
```

## How to make Sudoku puzzle

see sample data -> data/easy.csv
