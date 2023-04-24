CC = g++

CFLAGS = -std=c++11

TARGET = ECTextDocumentTest
OUTPUT = editorTest
EXTRAS = Document.cpp ECCommand.cpp ECEditorView.cpp ECTextViewImp.cpp

all: $(TARGET)

$(TARGET) : $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(OUTPUT) $(TARGET).cpp $(EXTRAS)

clean:
	rm  -f $(OUTPUT)





# # Compiler
# CC=g++

# # Compiler flags
# CFLAGS=-c -Wall

# # Linker flags
# LDFLAGS=

# # Source files
# SOURCES=Document.cpp ECCommand.cpp ECTextDocumentTest.cpp

# # Object files
# OBJECTS=$(SOURCES:.cpp=.o)

# # Executable
# EXECUTABLE=ECTextDocumentTest

# all: $(SOURCES) $(EXECUTABLE)

# $(EXECUTABLE): $(OBJECTS)
# 	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

# .cpp.o:
# 	$(CC) $(CFLAGS) $< -o $@

# clean:
# 	rm -rf $(OBJECTS) $(EXECUTABLE)
