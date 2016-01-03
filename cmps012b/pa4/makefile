#/*Tim Mertogul
# * 1331402
# * CMPS12B
# * 08/01/13
# * Makefile that compiles Queue ADT
# * makefile
# */

JAVAC      = javac 
MAINCLASS  = Simulation
JAVASRC    = $(wildcard *.java)
SOURCES    = $(JAVASRC) makefile README
CLASSES    = $(patsubst %.java, %.class, $(JAVASRC))
JARCLASSES = $(patsubst %.class, %*.class, $(CLASSES))
JARFILE    = $(MAINCLASS) 
SUBMIT     = submit cmps012b-pt.u13 pa4

all: $(JARFILE)

$(JARFILE): $(CLASSES)
	echo Main-class: $(MAINCLASS) > Manifest
	jar cvfm $(JARFILE) Manifest $(JARCLASSES)
	chmod +x $(JARFILE)
	rm Manifest
	
%.class: %.java
	$(JAVAC) $<

clean:
	rm *.class $(JARFILE)
submit: ${SOURCES}
	${SUBMIT} ${SOURCES}
check: 
	cd /afs/cats.ucsc.edu/class/cmps012b-pt.u13/pa4/tmertogu; ls; cd -

