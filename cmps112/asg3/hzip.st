#!/afs/cats.ucsc.edu/courses/cmps112-wm/usr/smalltalk/bin/gst -f

" Tim Mertogul tmertogu@ucsc.edu "
" Sean McGrath ssmcgrat@ucsc.edu "

"--------------------------------------------------------------------"
"boolean flags for cmd line options"
"--------------------------------------------------------------------"
optD := false.
optT := false.
optC := false.
optU := false. 
optError := false.
nl := Character nl.

"--------------------------------------------------------------------"
"checking the correct number of arguments"
"--------------------------------------------------------------------"
(Smalltalk arguments size) > 3 ifTrue: [
       status := 127.
       stderr << 'Usage: ' << 'Too many arguments ' << status << nl.
       ObjectMemory quit: status.
   ].
(Smalltalk arguments size) < 2 ifTrue: [
       status := 127.
       stderr << 'Usage: ' << 'Too few arguments ' << status << nl.
       ObjectMemory quit: status.
   ].

"--------------------------------------------------------------------"
"creating our I/O stream, defaults to STDOUT if no outfile specified"
"--------------------------------------------------------------------"
outFile := ''.
|oFile|
(Smalltalk arguments size) = 3 ifTrue: [
   outFile := (Smalltalk arguments at: 3).
   oFile := FileStream open: outFile
                    mode: FileStream write. ]. 
(Smalltalk arguments size) = 2 ifTrue: [ oFile := stdout. ].

inFile := (Smalltalk arguments at: 2).
FileStream extend [
   nl := Character nl.
   catFile [
      |count|
      count := 0.
      [self atEnd not] whileTrue: [
         count := count + 1.
         count asString size to: 5 do: [:skip| stdout << ' '].
         stdout << count << ': ' << self nextLine << nl.
      ]
   ]
]
|iFile|
iFile := FileStream open: inFile
                    mode: FileStream read.
"iFile catFile."
iReset := [
    iFile close.
    iFile := FileStream open: inFile
                        mode: FileStream read.
].

"--------------------------------------------------------------------"
"this code is based off of bitstream.st, outbits.st by mackey"
"--------------------------------------------------------------------"
Object subclass: BitStream [
   |bitIndex byte myStream|
   BitStream class >> new: fileStream [
      |result|
      result := super new.
      result init: fileStream.
      ^result
   ]
   init: fileStream [
      myStream := fileStream.
      bitIndex := 1.
   ]
   nextBit [
      bitIndex = 1 ifTrue: [
         byte := myStream next.
         bitIndex := 9.
      ].
      bitIndex := bitIndex - 1.
      ^byte value bitAt: bitIndex
   ]
   atEnd [
      ^bitIndex = 1 and: [myStream atEnd]
   ]
]

Object subclass: OutBits [
   |bitIndex currentByte myStream|
   OutBits class >> new [
      self shouldNotImplement.
   ]
   OutBits class >> new: fileStream [
      |result|
      result := super new.
      result init: fileStream.
      ^result
   ]
   clearByte [
      bitIndex := 8.
      currentByte := 0.
   ]
   init: fileStream [
      myStream := fileStream.
      self clearByte.
   ]
   flushByte [
      currentByte = 8 ifFalse: [
         myStream nextPutByte: currentByte.
         self clearByte.
      ]
   ]
   writeBit: bit [
      currentByte := currentByte bitAt: bitIndex put: bit.
      bitIndex := bitIndex - 1.
      bitIndex = 0 ifTrue: [self flushByte].
   ]
]


"--------------------------------------------------------------------"
"checks options, turns on appropriate flags"
"--------------------------------------------------------------------"
Smalltalk arguments: '-d -t -c -u'
do: [:opt :arg |

   arg = nil ifTrue: [
   "reads in opts, sets opt flags"
   (opt asInteger) = 100 ifTrue: [ optD := true. ].
   (opt asInteger) = 116 ifTrue: [ optT := true. ].
   (opt asInteger) = 99 ifTrue: [ optC := true. ].
   (opt asInteger) = 117 ifTrue: [ optU := true. ].

   "checks exactly one of the options "
   "-t, -c, or -u specified"
   optT ifTrue: [ 
       optC ifTrue: [ optError := true. ].
       optU ifTrue: [ optError := true. ].
   ].

   optC ifTrue: [ 
       optT ifTrue: [ optError := true. ].
       optU ifTrue: [ optError := true. ].
   ].

   optU ifTrue: [ 
       optC ifTrue: [ optError := true. ].
       optT ifTrue: [ optError := true. ].
   ].
   "if opt error, set exit status to 127"
   optError ifTrue: [
       status := 127.
       stderr << 'hzip: ' << 'Quitting with status ' << status << nl.
       ObjectMemory quit: status.
   ]. ].

]
ifError: [
   'Error: invalid option' displayNl.
   '--foo'
].

"--------------------------------------------------------------------"
"some helper functions written by us"
"--------------------------------------------------------------------"
bitArray := #().
bitArrayOut := #().
|bFile|
bFile := OutBits new: oFile.

   "writes a single bit, before the array"
   "bFile writeBit: 0."

strToBit := [:index|
    encodStr := encodeTable at: index. 
    encodStr do: [:ch |         
        (ch asInteger) = 48 ifTrue: [ bitArray := bitArray, #(0). ].
        (ch asInteger) = 49 ifTrue: [ bitArray := bitArray, #(1). ].
    ].
].
strToBitRAW := [:index|
    index do: [:ch |         
        (ch asInteger) = 48 ifTrue: [ bitArray := bitArray, #(0). ].
        (ch asInteger) = 49 ifTrue: [ bitArray := bitArray, #(1). ].
    ].
].

decBin := '' asString.
decToBin := [:n |
    |num bit quot count|
    decBin := '' asString.
    count := 0.
    num := n.
    [num > 0] whileTrue: [ 
        bit := num\\2.
        quot := num quo:2.
        tmp := decBin.
        decBin := bit asString, tmp.
        num := quot.
        count := count +1.
    ].
    count to: 7 do: [:x |
        decBin := '0', decBin.
    ]. 
    decBin do: [:ch |         
       (ch asInteger) = 48 ifTrue:[bitArrayOut := bitArrayOut, #(0).].
       (ch asInteger) = 49 ifTrue:[bitArrayOut := bitArrayOut, #(1).].
    ].
].

writeBitArray := [:outfile|
   |outBytes|
   outBytes := OutBits new: outfile.

   "writes a single bit, before the array"
   "outBytes writeBit: 0."

   bitArray do: [:bit| outBytes writeBit: bit].
   outBytes writeBit: 0.
   outBytes flushByte.
].

writeBitArryOut := [:outfile|
   |outBytes|
   outBytes := OutBits new: outfile.

   bitArrayOut do: [:bit| outBytes writeBit: bit].
].

lVal := 0.
huff := OrderedCollection new.
binToDec := [:x |
    |result num|
    lVal := 0.
    num := 128.
    result := 0.
    x do: [:ch | 
        ch asInteger = 49 ifTrue: [
            result := result + num.
        ].
        num := num/2.
    ].
    result = 128 ifTrue:[ result := 256.].
    lVal := result.
].


"--------------------------------------------------------------------"
"this code is based off of tree.st written by mackey"
"--------------------------------------------------------------------"
Object subclass: Leaf [
   |char count str|
   char [ ^ char ]
   count [ ^ count ]
   str [ ^ str ]
   Leaf class >> new [
      self shouldNotImplement
   ]
   Leaf class >> new: aChar count: aCount[
      |result|
      result := super new.
      result setChar: aChar andCount: aCount.
      ^result
   ]
   isLeaf [
      ^true
   ]
   setChar: aChar andCount: aCount [
      char := aChar.
      count := aCount.
   ]
   setStr: aStr [
      str := aStr.
   ]
   <= other [
      ^ (count < other count)
      | ((count = other count) & (char <= other char))
   ]
   printBase: aStream [
      ^ aStream << self class << '(' << char << ',' << count << 
                                                         ',' << str
   ]
   printOn: aStream [
      (self printBase: aStream) << ')'.
   ]
   inorder: visitor prefix: string [
      visitor value: char value: string.
      self setStr: string.
   ]
   inorderBits: visitor collection: col [
      col add: self.
   ]   
   postorder: visitor collection: sortcol[
      sortcol add: self.
   ]
   simple: n bArr: bitArray [
      |num bit quot count decBin bitA tmp|
      decBin := '' asString.
      count := 0.
      num := n.
      bitA := bitArray.
      [num > 0] whileTrue: [ 
          bit := num\\2.
          quot := num quo:2.
          tmp := decBin.
          decBin := bit asString, tmp.
          num := quot.
          count := count +1.
      ].
      count to: 7 do: [:x |
           decBin := '0', decBin.
      ].
      decBin do: [:ch |         
           (ch asInteger) = 48 ifTrue: [ 
               bitA := bitA, #(0). ].
           (ch asInteger) = 49 ifTrue: [ 
               bitA := bitA, #(1). ].
       ].
       n = 256 ifTrue: [
          bitA := bitA, #(1). ].
       n = 0 ifTrue: [
          bitA := bitA, #(0). ].
      ^bitA.
   ]
   postorderBits: visitor bArr: bitArray [
      |bitA|
       bitA := bitArray, #(0).
       ^bitA := (self simple: (self char) bArr: bitA).
   ]
]

Leaf subclass: Tree [
   |left right|
   left [ ^ left ]
   right [ ^ right ]
   Tree class >> new: aChar count: aCount [
      self shouldNotImplement
   ]
   Tree class >> new: aChar count: aCount left: aLeft right: aRight [
      |result|
      result := super new: aChar count: aCount.
      result setLeft: aLeft andRight: aRight.
      ^ result
   ]
   isLeaf [
      ^false
   ]
   setLeft: aLeft andRight: aRight [
      left := aLeft.
      right := aRight.
   ]
   printOn: aStream [
      (self printBase: aStream) << ',' << left << ',' << right << ')'.
   ]
   inorder: visitor prefix: string [
      left inorder: visitor prefix: string, '0'.
      right inorder: visitor prefix: string, '1'.
   ]
   inorderBits: visitor collection: col [
      left inorderBits: visitor collection: col.
      right inorderBits: visitor collection: col.
   ]    
   postorder: visitor collection: sortcol[
      left postorder: visitor collection: sortcol.
      right postorder: visitor collection: sortcol.
   ]
   postorderBits: visitor bArr: bitArray [
       |tmp bitA|
       bitA := left postorderBits: visitor bArr: bitArray.
       bitA := bitA, (right postorderBits: visitor bArr: bitArray).
       ^bitA := bitA, #(1).
   ]    
]

"This is our priority queue."
sortcol := SortedCollection new.

collection := OrderedCollection new.

"--------------------------------------------------------------------"
"this code is based off of charfreq.st written by mackey"
"--------------------------------------------------------------------"
Character extend [
   isPrint [
      ^ (Character space <= self) & (self <= $~)
   ]
   visible [
      self isPrint ifTrue: [^  self asString]
                   ifFalse: [^ self asInteger printStringRadix: 8]
   ]
]

Object subclass: ZeroArray [
   |theArray|
   ZeroArray class >> new [
      self shouldNotImplement.
   ]
   ZeroArray class >> new: size [
      |result|
      result := super new.
      result init: size.
      ^ result
   ]
   init: size [
      theArray := Array new: size.
   ]
   size [
      ^ theArray size.
   ]
   at: index [
      ^ theArray at: index + 1.
   ]
   at: index put: value[
      ^ theArray at: index + 1 put: value.
   ]
   incr: index [
      (self at: index) isNil ifTrue: [ self at: index put: 0].
      self at: index put: (self at: index) + 1.
   ]
   keysAndValuesDo: aBlock [
      (0 to: (self size) - 1) do: [:index |
         aBlock value: index value: (self at: index).
      ]
   ]
]


"-------------------------------------------------------------------"
"Creating our frequency table"
"-------------------------------------------------------------------"
optU ifFalse: [
    freqtable := ZeroArray new: 257.

    [iFile atEnd not] whileTrue: [
        |ordChar|
        ordChar := iFile next asInteger. 
        freqtable incr: ordChar.
    ].
    "trying to insert EOF into freqtable as stated in 3(a)"
    freqtable incr: 256.

    "Iterate through freqtable, for each non-nil entry, create a new"
    "leaf node and add it to the priority queue."
    freqtable keysAndValuesDo: [:key :value |
        (value notNil and: [value > 0]) ifTrue: [
            tmp := Leaf new: key count: value.
            sortcol add: tmp.
        ].
    ].
].

"--------------------------------------------------------------------"
"Building our huffman tree by iterating through sortcol"
"--------------------------------------------------------------------"
optU ifFalse: [
    sc_size := (sortcol size).

    [(sortcol size) > 1] whileTrue:[
        tmpl := sortcol removeFirst.
        tmpr := sortcol removeFirst.
        str := (tmpl char)+ (tmpr char).
        t := Tree new: str count: ((tmpl count) + (tmpr count)) 
                                              left: tmpl right: tmpr.
        sortcol add: t.
    ]. 
].        



"--------------------------------------------------------------------"
"For each char in sortcol, construct an encoding string, using "
"depth-first traversal. Encoding string is a sequence of bits "
"indicating path from root to leaf. Left -> 0; Right -> 1;"
"--------------------------------------------------------------------"
optU ifFalse: [
    tree := sortcol removeFirst.
    tree inorder: [:char :string | ]prefix: ''.
    tree postorder: [:char :string | ] collection: sortcol. 

    "a second sortedCollection for sorting leafs by char"
    sortcolChar := SortedCollection new.

    "copy each element from sortcol into sortcolChar"
    sortcol do: [:element | 
        sortcolChar add: element. 
    ]. 
    sortcolChar sortBlock: [:a :b | a char < b char].
].

"-------------------------------------------------------------------"
"creating our encoding table"
"-------------------------------------------------------------------"
optU ifFalse: [
    encodeTable := ZeroArray new: 257.

   sortcol do:[:element |
      encodeTable at: (element char) put: (element str).
   ].
].

"print out all characters when -t option is selected"
optT ifTrue:[
   (0 to: encodeTable size - 1)
   do: [:index |
      |char great32 less127 count string|
      great32 := index > 32.
      less127 := index < 127.
      count := freqtable at: index.
      string := encodeTable at: index.
      count isInteger ifTrue: [
         great32 & less127 ifTrue: [
            char := index asCharacter.
            1 to: (1 - (char size)) do: [:x | stdout << ' '. ].
            stdout << char << '    '.
            1 to: (2 - (count size)) do: [:x | stdout << ' '. ].
            stdout << count << '  ' << string << nl.
         ] ifFalse: [
            great32 ifFalse: [ stdout << ' '. ].
            stdout << index << ' '.
            1 to: (2 - (count size)) do: [:x | stdout << ' '. ].
            99 < count ifFalse: [ stdout << ' '. ].
            9 < count ifFalse: [ stdout << ' '. ].
            stdout << count << '  ' << string << nl.
         ].
      ].
   ].
].

"-------------------------------------------------------------------"
"Performing the compression"
"-------------------------------------------------------------------"
optC ifTrue: [
    iReset.
    "call the inorderbits for the tree"    
    "tree inorderBits: [] collection: collection."
    bitArray := (tree postorderBits: [] bArr: bitArray).

    "bitArray := bitArray, #(1)."

    iFile close.
    iFile := FileStream open: inFile
                        mode: FileStream read.
    [iFile atEnd not] whileTrue: [
        |index|
        index := iFile next asInteger.
        strToBit value: index.
    ].   
    strToBit value: 256.
    writeBitArray value: oFile.
].


"-------------------------------------------------------------------"
"Uncompression"
"-------------------------------------------------------------------"
bIn := #().
bInT := #().
addBit := [:cBit|
    cBit = 0 ifTrue:[ bIn := bIn, #(0). ].
    cBit = 1 ifTrue:[ bIn := bIn, #(1). ].
].
optU ifTrue: [
    rFlag := true.
    "stdout << 'Uncompression: ' << nl."
    "reads infile in bit by bit, stores in bit array"
    stdinBits := BitStream new: iFile.

    [rFlag] whileTrue: [
       currBit := stdinBits nextBit.
       "if bit = 0, its a leaf"
       currBit = 0 ifTrue: [ 
           tmp := '' asString.
           bIn := #().
           1 to:8 do: [:x |
               currBit := (stdinBits nextBit).
               addBit value: currBit.
               tmp := tmp, currBit asString.
           ].
           tmp = '10000000' ifTrue: [ 
               "stdout << '-- FOUND: 10000000' << nl."
               currBit := (stdinBits nextBit).
               addBit value: currBit.
               tmp := tmp, currBit asString.
           ].
           tmp = '00000000' ifTrue: [ 
               stdout << '-- found: 0000000' << nl.
               currBit := (stdinBits nextBit).
               addBit value: currBit.
               tmp := tmp, currBit asString.
           ].
           binToDec value: tmp.
           tmpLeaf := Leaf new: lVal count: lVal.
           huff addFirst: tmpLeaf.
       ] 
       ifFalse: [ 
           leaf1 := huff removeFirst.
           (huff size) = 0 ifTrue:[
               rFlag := false.
               huff addFirst: leaf1.
           ] ifFalse:[
               leaf0 := huff removeFirst.
               t := Tree new: '' count: 0 left: leaf0 right: leaf1.
               huff addFirst: t.
           ].
        ].
        "stdout << 'inspecting bIn: ' << nl.
        bIn inspect."
    ].

    "-----------------------------------------------------------"     
    "for each remaining bit, iterate thru huffman tree"
    "when a leaf node found, write to the output file"
    "-----------------------------------------------------------"
    navT := huff removeFirst.
    ptr := navT.
 
    (navT isLeaf) ifFalse: [ 
        [stdinBits atEnd] whileFalse: [
        currBit := stdinBits nextBit.
            currBit = 0 ifTrue:[
               ptr := ptr left.
               (ptr isLeaf) ifTrue: [
                   (ptr char) = 256 ifTrue: [  
                       [stdinBits atEnd] whileFalse: [
                           currBit := stdinBits nextBit.
                       ].
                   ] ifFalse: [
                       decToBin value: (ptr char).                   
                   ].
                   ptr := navT.
               ].           
            ] ifFalse:[
               ptr := ptr right.
               (ptr isLeaf) ifTrue: [
                   (ptr char) = 256 ifTrue: [ 
                   stdout << 'reached EOF R' << nl.
                      [stdinBits atEnd] whileFalse: [
                           currBit := stdinBits nextBit.
                       ].
                   ] ifFalse: [
                       decToBin value: (ptr char).                   
                   ].
                   ptr := navT.
               ].           
            ].
        ]. 
    ] ifTrue: [
        "stdout << 'found leaf' << nl."
    ].
    stdout << 'inspecting bitArrayOut: ------------' << nl.
    bitArrayOut inspect.
    writeBitArryOut value: oFile.
].

"optC ifTrue: [ bitArray inspect.].
tree inspect."

iFile close.
oFile close.     
















