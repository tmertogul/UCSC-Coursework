#/*Tim Mertogul
# * 1331402
# * CMPS12B
# * 08/16/13
# * Makefile that compiles DictionaryClient
# * makefile
# */

JAVAC      = javac 
MAINCLASS  = DictionaryClient
JAVASRC    = $(wildcard *.java)
SOURCES    = $(JAVASRC) makefile README
CLASSES    = $(patsubst %.java, %.class, $(JAVASRC))
JARCLASSES = $(patsubst %.class, %*.class, $(CLASSES))
JARFILE    = $(MAINCLASS) 
SUBMIT     = submit cmps012b-pt.u13 lab7


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
	cd /afs/cats.ucsc.edu/class/cmps012b-pt.u13/lab7/tmertogu; ls; cd -

