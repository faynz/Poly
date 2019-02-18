# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# Olivier Dion <olivier.dion@polymtl.ca>


# Project
TARGET = $(BIN_DIR)/tp2

# Directories
BIN_DIR = bin
INC_DIR = include
OBJ_DIR = build

SRC = $(shell find . -name *.$(SRC_EXT))
OBJ = $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:%.$(SRC_EXT)=%.$(OBJ_EXT))))

VPATH = src

# Extension
SRC_EXT = cpp
INC_EXT = h
OBJ_EXT = o
DEP_EXT = d

# Sources and Objects
INC := $(shell echo $(INC_DIR)/*.$(INC_EXT))

# Preprocessor
CPPFLAGS = -I$(INC_DIR) -DHZ=100 -DASM_DEBUG

# Compiler
CXX := g++
OPTIMIZATION := -O0
DEBUG := -ggdb
STD := -std=c++11
WARNINGS := -Wall
ERRORS := -Wfatal-errors
CXXFLAGS := $(DEBUG) $(OPTIMIZATION) $(WARNINGS) $(ERRORS) $(STD)

# Utils
RM := rm -rf

# To clean
CLEANER := $(OBJ_DIR)/
CLEAN := $(BIN_DIR)/

all: directories $(TARGET)

directories: $(OBJ_DIR) $(BIN_DIR)

$(OBJ_DIR):
	@echo "CREATE $(OBJ_DIR)/"
	@mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	@echo "CREATE $(BIN_DIR)/"
	@mkdir -p $(BIN_DIR)

$(TARGET): $(OBJ)
	@echo "LD $^ -> $@"
	@$(CXX) $(CPPFLAGS) -o $@ $^

-include $(OBJ:%.$(OBJ_EXT)=%.$(DEP_EXT))

$(OBJ_DIR)/%.$(OBJ_EXT): %.$(SRC_EXT)
	@echo "CC $< -> $@"
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "CLEAN $(CLEAN)"
	@$(RM) $(CLEAN)

cleaner: clean
	@echo "CLEAN $(CLEANER)"
	@$(RM) $(CLEANER)


.PHONY: all clean cleaner
