#ifndef __SYMTABLE_H__
#define __SYMTABLE_H__

#include <string>  
#include <unordered_map>
#include <vector> 
#include <map>
#include "astree.h"
#include <stdio.h> 
#include <bitset>

using namespace std;

// The enum for all the possible flags
//   ATTR_bitset_size is not actually used
//   but its value is equal to the number of attributes
enum { ATTR_void, ATTR_bool, ATTR_char, ATTR_int, ATTR_null,
       ATTR_string, ATTR_struct, ATTR_typeid, ATTR_array,
       ATTR_function, ATTR_variable, ATTR_field, ATTR_lval, 
       ATTR_param, ATTR_const, ATTR_vreg, ATTR_vaddr,
       ATTR_bitset_size,
};

// Create a shorthand notation for the bitset
using attr_bitset = bitset<ATTR_bitset_size>;

// Forward declaration of the symbol struct
struct symbol;

// Create a shorthand notation for a symbol_table
using symbol_table = unordered_map<string*, symbol*>;
using symbol_entry = pair<string*,symbol*>;

// The actual definition of the symbol struct
struct symbol {
   attr_bitset attributes;
   symbol_table* fields;
   size_t filenr, linenr, offset;
   size_t block_nr;
   vector<symbol*>* parameters;
   
   string name;
   string type;
};

symbol* new_symbol (attr_bitset attributes, string key, string type,
                    size_t filenr, size_t linenr, size_t offset);
void test_sym();
void dump_symtable (symbol* root);

int numberSym();



#endif


