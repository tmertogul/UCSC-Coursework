#/*Tim Mertogul
# * 1331402
# * CMPS12B
# * 07/10/13
# * Makefile that compiles Search.java
# * makefile
# */




JAVASRC    = Search.java
SOURCES    = README makefile ${JAVASRC}
MAINCLASS  = Search
CLASSES    = Search.class
JARFILE    = Search
JARCLASSES = ${CLASSES}
SUBMIT     = submit cmps012b-pt.u13 pa2

all: ${JARFILE}

${JARFILE}: ${CLASSES}
	echo Main-class: ${MAINCLASS} > Manifest
	jar cvfm ${JARFILE} Manifest ${JARCLASSES}
	rm Manifest
	chmod +x ${JARFILE}

${CLASSES}: ${JAVASRC}
	javac -Xlint ${JAVASRC}

clean:
	rm ${CLASSES} ${JARFILE}
submit: ${SOURCES}
	${SUBMIT} ${SOURCES}

