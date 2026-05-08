develop:
	uv run python setup.py build_ext --inplace
	uv run pytest -v

ifeq ($(OS),Windows_NT)
clean:
	rmdir /s /q build
	del /q src\sudoku_c\sudoku_c.cp*-win_amd64.pyd
else ifeq ($(shell uname),Darwin)
clean:
	rm -Rf build
	rm -Rf dist
	rm -Rf src/sudoku_c.egg-info/
	rm src/sudoku_c/sudoku_c.cpython-*-darwin.so
else
clean:
	rm -Rf build
	rm -Rf dist
	rm -Rf src/sudoku_c.egg-info/
	rm src/sudoku_c/sudoku_c.cpython-*-x86_64-linux-gnu.so
endif

sample:
	uv run python py/sample.py data/evil_2.csv
