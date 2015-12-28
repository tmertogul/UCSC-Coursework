#/*Tim Mertogul
# * 1331402
# * CMPS12B
# * 08/12/13
# * Makefile that compiles List ADT
# * makefile
# */

# Variables
SOURCES    = List.java ListInterface.java ListTest.java\
             ListIndexOutOfBoundsException.java
MAINCLASS  = ListTest
CLASSES    = List.class ListInterface.class ListTest.class List\$$Node.class\
             ListIndexOutOfBoundsException.class
JARFILE    = ListTest
FILES      = $(SOURCES) makefile README ListTest.java
SUBMIT     = submit cmps012b-pt.u13 lab6


# Build Targets
all: $(JARFILE)

$(JARFILE): $(CLASSES)
	echo Main-class: $(MAINCLASS) > Manifest
	jar cvfm $(JARFILE) Manifest $(CLASSES)
	rm Manifest
	chmod +x $(JARFILE)

$(CLASSES): $(SOURCES)
	javac -Xlint:all,-serial $(SOURCES)  

clean:
	rm -f $(CLASSES) $(JARFILE) 
	
submit: ${SOURCES}
	${SUBMIT} ${FILES}
check: 
	cd /afs/cats.ucsc.edu/class/cmps012b-pt.u13/lab6/tmertogu; ls; cd -