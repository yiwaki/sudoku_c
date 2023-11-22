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
	rm sudoku_c.cp311-win_amd64.pyd
else ifeq ($(shell uname),Linux)
clean:
	rm -Rf build
	rm sudoku_c.cpython-312-x86_64-linux-gnu.so
endif

test:
	python test.py
