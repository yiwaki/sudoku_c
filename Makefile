develop:
	uv run setup.py build_ext

ifeq ($(OS),Windows_NT)
clean:
	uv pip uninstall sudoku-c
	rm -Rf build
	rm src/sudoku_c.cp*-win_amd64.pyd
else ifeq ($(shell uname),Darwin)
clean:
	rm -Rf build
	rm sudoku_c.cpython-*-darwin.so
else
clean:
	rm -Rf build
	rm sudoku_c.cpython-*-x86_64-linux-gnu.so
endif

sample:
	python sample.py
