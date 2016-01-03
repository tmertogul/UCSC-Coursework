/*Tim Mertogul
* 1331402
* CMPS101 Summer14
* 07/19/14
* Matrix ADT for PA3
* Matrix.java
*/

public class Matrix {

	private class Entry {
		double val;        //
		int col; 
				
		Entry(int col, double val){  //constructor
			  //this.element = element;
			this.col = col;
			this.val = val;
			  //this.index = index;
			//this.next = next;
			//this.prev = prev;
		}
		public String toString() {
			String s = "";
		    s += "(";
			s += String.valueOf(col);
			s += ", ";
			s += String.valueOf(val);
			s += ")";
			return s;
		}
		public boolean equals(Object x){
			Entry E = (Entry)x;
			if(E.col == this.col){
				if(E.val == this.val){
					return true;
				}
			}
			return false;
		}
	}		
	private int size;  
	private int NNZ;  
	private List[] Rows;
	
	Matrix(int n){
		if (n < 1) {
			throw new RuntimeException("Matrix Error: Matrix() unable to construct zero Matrix");
		}
		size = n;
		NNZ = 0;
		Rows = new List[n];
		for (int i=0; i<n; i++){
			Rows[i] = new List();
		}
	}
	
	// Access functions
	int getSize(){
		return size;
	} // Returns n, the number of rows and columns of this Matrix
	
	int getNNZ(){
		return NNZ;
	}// Returns the number of non-zero entries in this Matrix

	public boolean equals(Object x){
		Matrix M = (Matrix)x;
		List L;
		List Lx;
		Entry E;
		Entry Ex;
		if (M.getSize() == this.getSize()) {
			if(M.getNNZ() == this.getNNZ()) {
				for(int i = 1; i <= size; i++){
					L = Rows[i-1];
					Lx = M.Rows[i-1];
					if(L.length() == Lx.length()){
						L.moveTo(0);
						Lx.moveTo(0);
						while (L.getIndex() != -1 || Lx.getIndex() != -1 ) {
							E = (Entry)L.getElement();
							Ex = (Entry)Lx.getElement();
							if( E.equals(Ex) ){
								L.moveNext();
								Lx.moveNext();
							} else { return false; }
						}
					}
				}
				return true;
			}
		} return false; 
}

	// Manipulation procedures 
	void makeZero(){
		NNZ = 0;
		Rows = new List[size];
		for (int i=0; i<size; i++){
			Rows[i] = new List();
		}

	} // sets this Matrix to the zero state
	
	Matrix copy(){
		Matrix M = new Matrix(size);
		List L;
		Entry E;
		for (int i=1; i<size; i++) {
			L = Rows[i-1];
			if(L.length() != 0){
				L.moveTo(0);
				while (L.getIndex() != -1) {
					E = (Entry)L.getElement();
					M.changeEntry(i, E.col, E.val);
					L.moveNext();
				}
			}
		}
		return M;
	}// returns a new Matrix having the same entries as this Matrix 
	
	void changeEntry(int i, int j, double x){
		if ( 1>i || 1>j || 1>getSize() ) {
			throw new RuntimeException("Matrix Error: changeEntry() called on invalid indices");
		}
		//Matrix M = new Matrix(size);
		Entry E;
		Entry newE = new Entry(j,x);
		List L = Rows[i-1];
		if (x == 0.0) {
			//System.out.println("adding 0.0 (null) entry to matrix");
			L.moveTo(0);
			while (L.getIndex() != -1) {
				E = (Entry)L.getElement();
				if (E.col == newE.col) {
					L.delete();
					NNZ--;
					return;
				}
				if(E.col > newE.col){
					return;
				}
				L.moveNext();
			}
		} 
		else {
			//System.out.println("changing entry");
			if(L.length()==0){
				L.prepend(newE);
				NNZ++;
				return;
			}
			L.moveTo(0);
			E = (Entry)L.getElement();
			while (L.getIndex() != -1) {
				E = (Entry)L.getElement();
				if (E.col == newE.col) {
					E.val = newE.val;
					return;
				}
				if(E.col > newE.col){
					L.insertBefore(newE);
					NNZ++;
					return;
				}					
				L.moveNext();
				if (L.getIndex() == -1) {
					L.append(newE);
					NNZ++;
					return;
				}
			}
		}
	} // changes ith row, jth column of this Matrix to x.  pre: 1<=i<=getSize(), 1<=j<=getSize()

	Matrix scalarMult(double x){
		Matrix Mx = new Matrix(size);
		List Lx;
		Entry Ex;
		//System.out.println("changing scalarMult");
		for (int i=1; i<=size; i++) {
			Lx = Rows[i-1];
			if(Lx.length() != 0){
				Lx.moveTo(0);
				while (Lx.getIndex() != -1) {
					Ex = (Entry)Lx.getElement();
					Mx.changeEntry(i, Ex.col, Ex.val*x);
					Lx.moveNext();
				}
			}
		}
		return Mx;
	} // returns a new Matrix that is the scalar product of this Matrix with x 
	
	Matrix add(Matrix M) {
	        if(this.getSize() != M.getSize()){
	            throw new RuntimeException("Matrix Error: add() called on invalid matrices");
	        }
			//System.out.println("calling add");	
	        Matrix aM = new Matrix(size);
	        List L;
	        List LM;
	        Entry EL;
	        Entry ELM;
	        if(equals(M)){
	            aM = scalarMult(2.0);
	            return aM;
	        }
	        for(int i = 1; i <= size; i++) {
	            L = Rows[i-1];
	            LM = M.Rows[i-1];
	            if(L.length() != 0){
	                L.moveTo(0);
	            }
	            if(LM.length() != 0){
	                LM.moveTo(0);
	            }
				double val;
				double valL = 0.0;
				double valLM = 0.0;
	            for(int j = 1; j <= size; j++){
					val = 0.0;
	                if(L.getIndex() != -1) {
	                    EL = (Entry)L.getElement();
	                    if(EL.col == j){
	                        valL += EL.val;
	                        L.moveNext();
	                    }
	                }
	                if(LM.getIndex() != -1) {
	                    ELM = (Entry)LM.getElement();
	                    if(ELM.col == j){
	                        valLM += ELM.val;
	                        LM.moveNext();
	                    }
	                }
					val = valL + valLM;
					aM.changeEntry(i, j, val);
					valL = 0.0;
					valLM = 0.0;
	            }
	        }
	        return aM;
	    } // returns a new Matrix that is the sum of this Matrix with M.  pre: getSize()==M.getSize()


	Matrix sub(Matrix M) {
	        if(this.getSize() != M.getSize()){
	            throw new RuntimeException("Matrix Error: sub() called on invalid matrices");
	        }
			//System.out.println("calling sub");	
	        Matrix sM = new Matrix(size);
	        if(equals(M)){
	            return sM;
			}
	        List L;
	        List LM;
	        Entry EL;
	        Entry ELM;	        
			for(int i = 1; i <= size; i++){
	            L = Rows[i-1];
	            LM = M.Rows[i-1];
	            if(L.length() != 0){
	                L.moveTo(0);
	            }
	            if(LM.length() != 0){
	                LM.moveTo(0);
	            }
				double val;
				double valL = 0.0;
				double valLM = 0.0;
	            for(int j = 1; j <= size; j++) {
	                val = 0.0;
	                if(L.getIndex() != -1){
	                    EL = (Entry)L.getElement();
	                    if(EL.col == j){
	                        valL += EL.val;
	                        L.moveNext();
	                    }
	                }
	                if(LM.getIndex() != -1) {
	                    ELM = (Entry)LM.getElement();
	                    if(ELM.col == j){
	                        valLM -= ELM.val;
	                        LM.moveNext();
	                    }
	                }
					val = valL + valLM;
					sM.changeEntry(i, j, val);
					valL = 0.0;
					valLM = 0.0;
	            }
	        }
	        return sM;
	    }	// returns a new Matrix that is the difference of this Matrix with M
		    // pre: getSize()==M.getSize()

	Matrix transpose(){
		//System.out.println("calling transpose");
		Matrix M = new Matrix(size);
		List L;
		Entry E;
		for (int i=1; i<=size; i++) {
			L = Rows[i-1];
			if(L.length() != 0){
				L.moveTo(0);
				while (L.getIndex() != -1) {
					E = (Entry)L.getElement();
					M.changeEntry(E.col, i, E.val);
					L.moveNext();
				}
			}
		}
		return M;
	} // returns a new Matrix that is the transpose of this Matrix 
	
	Matrix mult(Matrix M){
		if ( getSize() != M.getSize() ) {
			throw new RuntimeException("Matrix Error: mult() called on unequal sized Matrices");
		}
		//System.out.println("calling mult");
		Matrix mM = new Matrix(getSize());
		M = M.transpose();
		List L;
		List LM;
		for (int i=1; i <= size; i++) {
			L = Rows[i-1];
			double dot = 0.0;
			for (int j=1; j <= size; j++) {
				LM = M.Rows[j-1];
				if(L.length() != 0 && LM.length() != 0){
					dot = dot(L, LM);
					mM.changeEntry(i, j, dot);
				}
				dot = 0.0;
			}
		}
		return mM;		
	} // returns a new Matrix that is the product of this Matrix with M // pre: getSize()==M.getSize()*/
	
	
	// Other functions
	public String toString(){
		//System.out.println("toString methog called");
		String s = "";
		List L;
		Entry E;
		for (int i=1; i<=size; i++) {
			L = Rows[i-1];
			if(L.length() != 0){
				L.moveTo(0);
				s += i + ": ";
				while (L.getIndex() != -1) {
					E = (Entry)L.getElement();
					s += "("+E.col+", "+E.val+") ";
					L.moveNext();
				}
				s += "\n";
			}
		}
		return s;
	} // overrides Object's toString() method
	
	private static double dot(List P, List Q){
		double pP = 0.0;
		double pQ = 0.0;
		double pT = 0.0;
		double dot = 0.0;
		int i = 1;
		Entry E;
		if (Q.length() != 0 && Q.length() !=0 ) {
			P.moveTo(0);
			Q.moveTo(0);
			while (P.getIndex() != -1 || Q.getIndex() != -1 ) {
				if(P.getIndex() != -1){
					E = (Entry)P.getElement();
					if(E.col == i){
						pP += E.val;
						P.moveNext();
					}
				}
				if(Q.getIndex() != -1){
					E = (Entry)Q.getElement();
					if(E.col == i){
						pQ += E.val;
						Q.moveNext();
					}
				}
				pT = pP * pQ;	
				dot = dot + pT;
				pP = pQ = pT = 0.0;
				i++;	
			}
		}
		return dot;
	}
	/*
	private static double dot(List P, List Q) {
		double answer = 0;

		//traverse through list P, find identical columns in Q
		for (int ptor = 0; ptor < P.length(); ptor++) {
			P.moveTo(ptor);
			for (int qtor = 0; qtor < Q.length(); qtor++) {
				Q.moveTo(qtor);
				Entry PE = (Entry)P.getElement();
				Entry QE = (Entry)Q.getElement();

				//check columns, if equal add product to answer
				if (PE.col == QE.col) {
					answer += PE.val * QE.val;
				}
			}
		}

		return answer;
	}*/
	
}