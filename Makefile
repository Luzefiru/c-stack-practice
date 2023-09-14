# change implementations here by editing the IMPLEMENTATION variable
# available options: array | list | cursor
IMPLEMENTATION := cursor
JAVA_PATH := ./src/stack/java
JAVAC_FLAGS := -cp $(JAVA_PATH)/
 
start: main
	./main.exe

start-java: $(JAVA_PATH)/Main.class
	cd $(JAVA_PATH) && java Main

$(JAVA_PATH)/Main.class: $(JAVA_PATH)/Stack.class
	javac $(JAVAC_FLAGS) $(JAVA_PATH)/Main.java

$(JAVA_PATH)/Stack.class: $(JAVA_PATH)/IStack.class
	javac $(JAVAC_FLAGS) $(JAVA_PATH)/Stack.java

$(JAVA_PATH)/IStack.class:
	javac $(JAVAC_FLAGS) $(JAVA_PATH)/IStack.java

main: main.o stack.o
	gcc -o main main.o stack.o

main.o:
	gcc -c ./src/main.c

stack.o:
	gcc -c ./src/stack/$(IMPLEMENTATION)/stack.c

clean:
	rm -fr main.* stack.* $(JAVA_PATH)/*.class $(JAVA_PATH)/build/