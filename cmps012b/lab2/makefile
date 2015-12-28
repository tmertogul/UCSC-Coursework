#/*Tim Mertogul
# * 1331402
# * CMPS12B
# * 07/09/13
# * Makefile that compiles FileReverse.java
# * makefile
# */



JAVASRC    = FileReverse.java
SOURCES    = README makefile ${JAVASRC}
MAINCLASS  = FileReverse
CLASSES    = FileReverse.class
JARFILE    = FileReverse
JARCLASSES = ${CLASSES}
SUBMIT     = submit cmps012b-pt.u13 lab2

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
