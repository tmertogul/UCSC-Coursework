/*Tim Mertogul
* 1331402
* CMPS101 Summer14
* 07/19/14
* Sparse handles in/out for PA3
* Sparse.java
*/

import java.io.*;
import java.util.Scanner;

public class Sparse{
	public static void main(String[] args) throws IOException{
		//System.out.println("Sparse Compiled and running");
		
		Scanner in = null;
		PrintWriter out = null;
		String line = null;
		String inData[] = null;
	
		if(args.length != 2){
			throw new IOException("Usage: Sparse input output");
		}

		in = new Scanner(new File(args[0]));
		out = new PrintWriter(new File(args[1]));

		line = in.nextLine() + " ";
		inData = line.split("\\s+");
		int n = Integer.parseInt(inData[0]);
		int a = Integer.parseInt(inData[1]);
		int b = Integer.parseInt(inData[2]);
		line = in.nextLine();
	
		Matrix A = new Matrix(n);
		Matrix B = new Matrix(n);	
		int Al, Bl;	
		for(int i = 0; i < a; i++){
			line = in.nextLine() + " ";
			inData = line.split("\\s+");
			Al = inData.length;
			int Ax = Integer.parseInt(inData[0]);
			int Acol = Integer.parseInt(inData[1]);
			double Aval = Double.parseDouble(inData[2]);
			A.changeEntry(Ax, Acol, Aval);
		}
		line = in.nextLine();

		for(int j = 0; j < b; j++){
			line = in.nextLine() + " ";
			inData = line.split("\\s+");
			Bl = inData.length;
			int Bx = Integer.parseInt(inData[0]);
			int Bcol = Integer.parseInt(inData[1]);
			double Bval = Double.parseDouble(inData[2]);
			B.changeEntry(Bx, Bcol, Bval);
		}
		
		out.println("A has: " + A.getNNZ() + " non-zero entries:\n");
		out.println(A);

		out.println("B has: " + B.getNNZ() + " non-zero entries:\n");
		out.println(B);

		
		out.println("(1.5)*A =\n");
		out.println(A.scalarMult(1.5));
		
		out.println("A+B =");
		out.println(A.add(B));
		
		out.println("A+A =");
		out.println(A.add(A));
		
		out.println("B-A =");
		out.println(B.sub(A));
		
		out.println("B-A =");
		out.println(A.sub(B));

		out.println("A-A =");
		out.println(A.sub(A));

		out.println("Transpose(A) =");
		out.println(A.transpose());
		
		out.println("A*B =\n");
		out.println(A.mult(B));
	
		out.println("B*B =\n");
		out.println(B.mult(B));
		
		in.close();
		out.close();
	}
}