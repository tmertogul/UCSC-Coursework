/*Tim Mertogul
* 1331402
* CMPS101 Summer14
* 07/02/14
* ADD DESCRIPTION
* Lex.java
*/

import java.io.*;
import java.util.Scanner;


class Lex {
	
	 /*static List InsertionSort(List Lu, String[] a) {
				
		//System.out.print(Lu);
		return Lu;
	}*/
		 
	public static void main(String[] args) throws IOException{
		Scanner Lin = null;
		Scanner in = null;
		PrintWriter out = null;
		String line = null;
		//String[] elements = null;
		List Lu = new List();
		List Ls = new List();
	    int i, j, n=0;

		if(args.length != 2){
			throw new IOException("Usage: Lex input output");
			//System.exit(1);
		}
		Lin = new Scanner(new File(args[0]));
		int linecount = 0;		
		while ( Lin.hasNext() ) {
			Lin.next();
			linecount++;
		}
		Lin.close();
		in = new Scanner(new File(args[0]));
		out = new PrintWriter(new FileWriter(args[1]));
		//L=0;
		String[] words = new String[linecount];
		String[] copy = new String[linecount];

		int temp = 0;
		while( in.hasNextLine() ){
			line = in.nextLine();
			copy[n] = line;
			words[n] = line;
			n++;
		}
		int T = 0;
		/*System.out.println("words.length = "+words.length);
		while (T < words.length ){
			System.out.println("words[T] = "+words[T]);
			T++;
			
		}*/
		in.close();
		
		for(i=0; i<linecount; i++){
			Lu.append(i);
		}
		//System.out.println("unsorted indices = "+Lu);
		

		//Ls = InsertionSort(Lu, words);
		//out.println(Ls);
		//Ls.moveTo(0);
		
		//new String[] a = words;
		//new String[words.length()] copy;
		//copy = words;

		for(int x=1; x<words.length; x++){
					String tempy = words[x];
					Lu.moveTo(x);
					int Pt = Lu.getIndex();
					int Ti;
					int jk;
					for (jk=x-1; jk>=0 && tempy.compareTo(words[jk])<0; jk--){
						//System.out.println("Lu = "+Lu);
						//System.out.println("getIndexB"+Lu.getIndex());

						//System.out.println("i="+i);
						//System.out.println("j="+j);
						//Lu
						Lu.moveTo(x);
						Ti = Lu.getElement();
						//System.out.println("getIndexDELETE"+Lu.getIndex());
						Lu.delete();
						//System.out.println("getIndexj = "+j);
						//System.out.println("getLENGTHj = "+Lu.length());
						Lu.moveTo(jk);
						Lu.insertBefore(Ti);
						//System.out.println("getIndexE"+Lu.getIndex());
						x--;
						words[jk+1] = words[jk];
					}
					if(Lu.getIndex() >= 0){
						Lu.movePrev();
					}
					words[jk+1] = tempy;
		}
		int Ti = 0;
		/*while (Ti < words.length ){
			System.out.println("a[T] = "+words[Ti]);
			Ti++;
		}
		Ti = 0;*/
		while (Ti < copy.length ){
			Lu.moveTo(Ti);
			out.println(copy[ Lu.getElement() ]);
			Ti++;
		}
		//copy = a;
		Lu.moveTo(0);
		
		/*for(Lu.getIndex(); Lu.getIndex() < Lu.length(); Lu.moveNext()){
			out.println(copy[Lu.getElement()]);
		}*/
		
		out.close();

		
	}
		
}

//public static String[] InsertionSort(String[] toList, int length){
	//String[] Sorted = new String[length]; 
	
	
	/*for (int i=1; i < toList.length; i++){
		String tem = toList[i];
		int j;
		for (j=i-1; j>=0 && tem<toList[j]; j--)
			toList[j+1] = toList[j];
		toList[j+1] = tem;
		
	}*/
	//return toList;
//}