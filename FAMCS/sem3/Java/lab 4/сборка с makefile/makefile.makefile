#makefile
.SUFFIXES: .class .java

PACK = lab4
TARG = Main
JC = javac -g
JM = java -ea -jar
JR = jar -cfe

OBJ = $(PACK)/NonlinearEquation.class    \
      $(PACK)/Main.class

.java.class:
	$(JC) $<

run: build
	$(JM) $(TARG).jar

build: $(OBJ)
	$(JR) $(TARG).jar $(PACK).Main $(OBJ)

clean:
	for %%f in ($(OBJ)) do del %%f
	del $(TARG).jar

$(PACK)/NonlinearEquation.class: $(PACK)/NonlinearEquation.java makefile

$(PACK)/Main.class: $(PACK)/Main.java makefile

#eof
