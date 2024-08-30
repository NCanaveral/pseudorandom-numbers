CXX ?= g++
CXXFLAGS = -Wall -g -std=c++11
BUILD_DIR = constructores
HEADERS_DIR = encabezados
COMPONENTS_DIR = componentes

ifeq ($(OS),Windows_NT)
	MKDIR = powershell -Command "if (!(Test-Path '$(BUILD_DIR)')) { New-Item -ItemType Directory -Path '$(BUILD_DIR)' }"
	RM = cmd.exe /c "for %f in ($(BUILD_DIR)\*.o) do del %f"
	RMDIR = cmd.exe /c rmdir /S /Q
	REXE = cmd.exe /c "del /f pseudorandom_numbers.exe"
else
	MKDIR = mkdir -p $(BUILD_DIR)
	RM = rm -f
	RMDIR = rm -rf
	REXE = rm -f pseudorandom_numbers.exe
endif

pseudorandom_numbers: $(BUILD_DIR)/main.o $(BUILD_DIR)/Generadores.o $(BUILD_DIR)/Pruebas.o
	$(CXX) $(CXXFLAGS) $(BUILD_DIR)/main.o $(BUILD_DIR)/Generadores.o $(BUILD_DIR)/Pruebas.o -o pseudorandom_numbers

$(BUILD_DIR)/main.o: main.cpp $(HEADERS_DIR)/Generadores.h $(HEADERS_DIR)/Pruebas.h | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/Generadores.o: $(COMPONENTS_DIR)/Generadores.cpp $(HEADERS_DIR)/Generadores.h | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $(COMPONENTS_DIR)/Generadores.cpp -o $(BUILD_DIR)/Generadores.o

$(BUILD_DIR)/Pruebas.o: $(COMPONENTS_DIR)/Pruebas.cpp $(HEADERS_DIR)/Pruebas.h | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $(COMPONENTS_DIR)/Pruebas.cpp -o $(BUILD_DIR)/Pruebas.o

$(BUILD_DIR):
	$(MKDIR)

clean:
	$(RM)
	$(RMDIR) $(BUILD_DIR)
	$(REXE)
