.PHONY: all clean build test

PYMODULE=example

all: clean build

build:
	@echo "Building Example extension ..."
	@python setup.py build --force

install:
	@echo "Installing Example ..."
	@python setup.py install --user

build-wheel:
	@python setup.py bdist_wheel

install-wheel: build-wheel
	@pip install --force-reinstall --upgrade dist/*.whl --user

clean:
	@echo "Cleaning up existing build files..."
	@rm -rf build dist MANIFEST *.egg-info htmlcov tests/tmp .cache .benchmarks
	@find . -name '__pycache__' -delete -print -o -name '*.pyc' -delete -print
