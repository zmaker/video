TARGET = button
CC = gcc
CFLAGS = -Wall
HEADER =
LIBS = -lwiringPi

%.o: %.c $(HEADER)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(TARGET).o  
	$(CC) -o $(TARGET) $(TARGET).o $(LIBS)
	
clean:
	rm -f *.o 
	rm -f $(TARGET)
