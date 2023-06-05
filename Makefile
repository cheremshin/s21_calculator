###########################################
#    _____ ___  __    _____      _        #
#   / ____|__ \/_ |  / ____|    | |       #
#  | (___    ) || | | |     __ _| | ___   #
#   \___ \  / / | | | |    / _` | |/ __|  #
#   ____) |/ /_ | | | |___| (_| | | (__   #
#  |_____/|____||_|  \_____\__,_|_|\___|  #
#                                         #
#               Version: 1.0              #
#           Author: Skyte Kelsi           #
#                                         #
###########################################

MAKEFLAGS += --no-print-directory

all: install

install:
	cmake -S . -B build
	cmake --build ./build
	@echo "\nType './build/s21_calculator' to run program"

clean:
	rm -rf build