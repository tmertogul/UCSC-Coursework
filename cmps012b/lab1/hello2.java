/*Tim Mertogul
 * 1331402
 * CMPS12B
 * 07/01/13
 * Modified HelloWorld Program designed to print "Welcome Banana Slugs"
 * hello2.java
 */


// hello. java
// Prints “Hello World” to stdout, then prints out some // environment information.

import static java.lang.System.*;

class hello2{

   public static void main( String[] args ){
      String os = System.getProperty("os.name");
      String osVer = System.getProperty("os.version");
      String jre = System.getProperty("java.runtime.name"); String jreVer = System.getProperty("java.runtime.version"); String jvm = System.getProperty("java.vm.name");
      String jvmVer = System.getProperty("java.vm.version"); String home = System.getProperty("java.home");
      double freemem = Runtime.getRuntime().freeMemory();
      long time = currentTimeMillis();

      System.out.println("Welcome Banana Slugs"); System.out.println("OS: "+os+" "+osVer); System.out.println("Runtime envi: "+jre+" "+jreVer); System.out.println("VM: "+jvm+" "+jvmVer); System.out.println("Java home directory: "+home); System.out.println("Free mem: "+freemem+" bytes"); System.out.printf("Time: %tc.%n", time);

   }
}
