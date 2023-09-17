# USAGE:
#   make start
#   make start-java
#   make start TYPE=[array | list | cursor]
#   TYPE=[array | list | cursor] make start

# available options: array | list | cursor, defaults to array
TYPE ?= array
JAVA_PATH := ./src/java
JAVAC_FLAGS := -cp $(JAVA_PATH)/
 
start:
	make clean && make main && ./main.exe

start-java:
	make clean && make java-main && cd $(JAVA_PATH) && java Main

javadoc-deploy:
	git branch gh-pages || git checkout gh-pages && make javadoc && git add . && git commit -m "script: deploy javadoc api page to gh-pages" && git push origin gh-pages

javadoc:
	make clean && make $(JAVA_PATH)/Main.class && javadoc $(JAVA_PATH)/*.java || echo "Done making javadoc files."

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
		rm -fr javadoc main.* stack.* $(JAVA_PATH)/*.class $(JAVA_PATH)/build/ && find . -maxdepth 1 ! -name '.git*' ! -name 'include' ! -name 'src' ! -name 'Makefile' -exec rm -rf {} + || echo "Done cleaning."