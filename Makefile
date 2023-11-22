ifeq ($(shell uname),MSYS_NT-10.0-WOW)
develop:
	python setup.py build_ext --inplace --compiler=mingw32

clean:
	rm -Rf build
	rm sudoku_c.cp311-win_amd64.pyd

else
develop:
	python setup.py build_ext --inplace

clean:
	rm -Rf build
endif

test:
	python test.py
