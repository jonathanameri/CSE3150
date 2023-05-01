CC = g++

CFLAGS = -std=c++11

TARGET = ECTextDocumentTest
OUTPUT = myeditor
EXTRAS = Document.cpp ECCommand.cpp ECTextViewImp.cpp Observers.cpp

all: $(TARGET)

$(TARGET) : $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(OUTPUT) $(TARGET).cpp $(EXTRAS)

clean:
	rm  -f $(OUTPUT)