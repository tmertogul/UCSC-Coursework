# A simple Makefile for the Queens program

Queens: Queens.class
	echo Main-class: Queens > Manifest
	jar cvfm Queens Manifest Queens.class
	rm Manifest
	chmod u+x Queens

Queens.class: Queens.java
	javac -Xlint Queens.java

clean:
	rm -f Queens.class Queens

submit: Makefile Queens.java
	submit cmps012a-pt.w13 pa5 Makefile Queens.java

check:
	cd /afs/cats.ucsc.edu/class/cmps012a-pt.w13/pa5/tmertogu; ls; cd -

