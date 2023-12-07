ifeq ($(shell uname),MSYS_NT-10.0-WOW)
develop:
	python setup.py build_ext --inplace --compiler=mingw32
else
develop:
	python setup.py build_ext --inplace
endif

ifeq ($(shell uname),MSYS_NT-10.0-WOW)
clean:
	rm -Rf build
	rm sudoku_c.cp*-win_amd64.pyd
else ifeq ($(shell uname),Darwin)
clean:
	rm -Rf build
	rm sudoku_c.cpython-*-darwin.so
else
clean:
	rm -Rf build
	rm sudoku_c.cpython-*-x86_64-linux-gnu.so
endif

test:
	python test.py
