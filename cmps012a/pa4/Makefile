# Makefile for the Roots Program
# Tim Mertogul
# 1331402
# pa4

Roots: Roots.class
	echo Main-class: Roots > Manifest
	jar cvfm Roots Manifest Roots.class
	rm Manifest
	chmod u+x Roots

Roots.class: Roots.java
	javac -Xlint Roots.java

clean:
	rm -f Roots.class Roots

submit: Makefile Roots.java
	submit cmps012a-pt.w13 pa4 Makefile Roots.java

check:
	cd /afs/cats.ucsc.edu/class/cmps012a-pt.w13/pa4/tmertogu; ls; cd -
	

