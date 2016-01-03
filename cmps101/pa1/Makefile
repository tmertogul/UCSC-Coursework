# Tim Mertogul
# 1331402
# CMPS101 Summer14
# 07/02/14
# Creates executable jar file called Lex
# Makefile for pa1

MAINCLASS = Lex
JAVAC = javac
JAVASRC = $(wildcard *.java)
SOURCES = $(JAVASRC) makefile README
CLASSES = $(patsubst %.java, %.class, $(JAVASRC)) 
JARCLASSES = $(patsubst %.class, %*.class, $(CLASSES)) 
JARFILE = $(MAINCLASS)
SUBMIT  = submit cmps101-pt.u14 pa1
all: $(JARFILE)
$(JARFILE): $(CLASSES)
	echo Main-class: $(MAINCLASS) > Manifest
	jar cvfm $(JARFILE) Manifest $(JARCLASSES)
	chmod +x $(JARFILE)
	rm Manifest
%.class: %.java
	$(JAVAC) $<
clean:
	rm -f *.class $(JARFILE)
submit: ${SOURCES}
	${SUBMIT} ${SOURCES}
check:
	cd /afs/cats.ucsc.edu/class/cmps101-pt.u14/pa1/tmertogu; ls; cd -
