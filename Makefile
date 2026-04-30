develop:
	uv run python setup.py build_ext --inplace
	pytest -v

ifeq ($(OS),Windows_NT)
clean:
	uv pip uninstall sudoku-c
	rmdir /s /q build
	del /q src\sudoku_c\sudoku_c.cp*-win_amd64.pyd
else ifeq ($(shell uname),Darwin)
clean:
	rmdir -Rf build
	rm src/sudoku_c/sudoku_c.cpython-*-darwin.so
else
clean:
	rmdir -Rf build
	rm src/sudoku_c/sudoku_c.cpython-*-x86_64-linux-gnu.so
endif

sample:
	python py/sample.py data/evil_2.csv
