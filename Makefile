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



# Configure
MAKEFLAGS += --no-print-directory
PROGRAM_NAME = s21_calculator

INSTALLATION_PATH =
OS = $(shell uname)
ifeq ($(OS), Darwin)
	INSTALLATION_PATH += "/Applications"
else
	INSTALLATION_PATH += "/usr/local"
endif


# Commands
all: build

build:
	cmake -S . -B build
	cmake --build ./build
	@echo "Successfully built."

install: check_su build
	@cp build/${PROGRAM_NAME} ${INSTALLATION_PATH}/${PROGRAM_NAME}
	@echo "${PROGRAM_NAME} installed to '${INSTALLATION_PATH}/'"

uninstall: check_su clean
	@rm ${INSTALLATION_PATH}/${PROGRAM_NAME}
	@echo "${PROGRAM_NAME} deleted"

rebuild: clean build

clean:
	@rm -rf build
	@echo "Successfully cleaned!"

check_su:
ifneq ($(OS), Darwin)
ifneq ($(shell id -u), 0)
	@echo "You must be root to perform this action."
	exit 1
endif
endif