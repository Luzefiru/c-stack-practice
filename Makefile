# USAGE:
#   make start
#   make start-java
#   make start TYPE=[array | list | cursor]
#   TYPE=[array | list | cursor] make start

# available options: array | list | cursor, defaults to array
TYPE ?= array
JAVA_PATH := ./src/stack/java
JAVAC_FLAGS := -cp $(JAVA_PATH)/
 
start:
	make clean && make main && ./main.exe

start-java:
	make clean && make java-main && cd $(JAVA_PATH) && java Main

javadoc: $(JAVA_PATH)/Main.class
	mkdir javadoc && cd javadoc/ && javadoc ../$(JAVA_PATH)/*.java

java-main: $(JAVA_PATH)/Main.class

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
	gcc -c ./src/stack/$(TYPE)/stack.c

clean:
	rm -fr main.* stack.* $(JAVA_PATH)/*.class $(JAVA_PATH)/build/ && find $(JAVA_PATH) ! -name '*.java' -delete