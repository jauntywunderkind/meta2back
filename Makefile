.PHONY: setup build install

setup:
	meson setup --reconfigure builddir

build:
	cd builddir; ninja; echo ok

install:
	cd builddir; sudo cp meta2back /usr/local/bin/meta2back

all: setup build
