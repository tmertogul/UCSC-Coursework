// Tim Mertogul
// tmertogu@ucsc.edu
// Michael Lowe
// mimlowe@ucsc.edu
// CMPS109
// Spring 2015
// ASG 1

#ifndef __INODE_H__
#define __INODE_H__

#include <exception>
#include <iostream>
#include <memory>
#include <map>
#include <vector>
using namespace std;

#include "util.h"

//
// inode_t -
//    An inode is either a directory or a plain file.
//

enum inode_t {PLAIN_INODE, DIR_INODE};
class inode;
class file_base;
class plain_file;
class directory;
using inode_ptr = shared_ptr<inode>;
using file_base_ptr = shared_ptr<file_base>;
using plain_file_ptr = shared_ptr<plain_file>;
using directory_ptr = shared_ptr<directory>;




//
// inode_state -
//    A small convenient class to maintain the state of the simulated
//    process:  the root (/), the current directory (.), and the
//    prompt.
//

class inode_state {
   friend class inode;
   friend ostream& operator<< (ostream& out, const inode_state&);
   private:
      inode_state (const inode_state&) = delete; // copy ctor
      inode_state& operator= (const inode_state&) = delete; // op=
      inode_ptr root {nullptr};
      inode_ptr cwd {nullptr};
      //inode_ptr c_path {nullptr};
      inode_ptr save {nullptr};
      string prompt {"% "};
   public:
      inode_state();
      ~inode_state();
      inode_ptr& get_cwd();
      //inode_ptr& get_c_path();
      inode_ptr& get_root();
      inode_ptr& get_save();
      void set_prompt(string& p);
      void set_save(inode_ptr& s);
      void set_cwd_to_root();
      void reset();
      void set_cwd(inode_ptr& current);
      void cd(const string& path);
      string prompt_print();
    };

//
// class inode -
//
// inode ctor -
//    Create a new inode of the given type.
// get_inode_nr -
//    Retrieves the serial number of the inode.  Inode numbers are
//    allocated in sequence by small integer.
// size -
//    Returns the size of an inode.  For a directory, this is the
//    number of dirents.  For a text file, the number of characters
//    when printed (the sum of the lengths of each word, plus the
//    number of words.
//    

class inode {
   friend class inode_state;
   private:
      static int next_inode_nr;
      int inode_nr;
      string node_name;
      string node_path;
      inode_t type;
      inode_ptr parent {nullptr};
      file_base_ptr contents;
   public:
      inode (inode_t init_type);
      ~inode();
      int get_type();
      int get_inode_nr() const;
      file_base_ptr get_contents();
      void mkdir(const string& dirname, const inode_state& state);
      void make_file(const wordvec& words, const inode_state& state);
      void rm_file(const wordvec& file, const inode_state& state);
      void print_file(const wordvec& file, const inode_state& state);

      void name_node(const string& name);
      void name_path(const string& path_name);
      inode_ptr get_child_dir(const string& name);
      string get_name();
      string get_path();
      inode_ptr& get_parent();
      void set_parent(const inode_ptr& p);
    
};

//
// class file_base -
//
// Just a base class at which an inode can point.  No data or
// functions.  Makes the synthesized members useable only from
// the derived classes.
//

class file_base {
   protected:
      file_base () = default;
      file_base (const file_base&) = default;
      file_base (file_base&&) = default;
      file_base& operator= (const file_base&) = default;
      file_base& operator= (file_base&&) = default;
      virtual ~file_base () = default;
      virtual size_t size() const = 0;
   public:
      friend plain_file_ptr plain_file_ptr_of (file_base_ptr);
      friend directory_ptr directory_ptr_of (file_base_ptr);

};

//
// class plain_file -
//
// Used to hold data.
// synthesized default ctor -
//    Default vector<string> is a an empty vector.
// readfile -
//    Returns a copy of the contents of the wordvec in the file.
//    Throws an yshell_exn for a directory.
// writefile -
//    Replaces the contents of a file with new contents.
//    Throws an yshell_exn for a directory.
//

class plain_file: public file_base {
   private:
      wordvec data;
   public:
      size_t size() const override;
      const wordvec& readfile() const;
      void writefile (const wordvec& newdata);
    

};

//
// class directory -
//
// Used to map filenames onto inode pointers.
// default ctor -
//    Creates a new map with keys "." and "..".
// remove -
//    Removes the file or subdirectory from the current inode.
//    Throws an yshell_exn if this is not a directory, the file
//    does not exist, or the subdirectory is not empty.
//    Here empty means the only entries are dot (.) and dotdot (..).
// mkdir -
//    Creates a new directory under the current directory and 
//    immediately adds the directories dot (.) and dotdot (..) to it.
//    Note that the parent (..) of / is / itself.  It is an error
//    if the entry already exists.
// mkfile -
//    Create a new empty text file with the given name.  Error if
//    a dirent with that name exists.

class directory: public file_base {
   private:
      map<string,inode_ptr> dirents;
   public:
      size_t size() const override;
      void remove (const string& filename);
      inode_ptr mkdir (const string& dirname, const inode_ptr& parent);
      inode_ptr make_file (const wordvec& dirname, 
                                              const inode_ptr& parent);
      inode_ptr rm_file (const wordvec& dirname, 
                                              const inode_ptr& parent);
      inode_ptr print_file (const wordvec& dirname,
                                              const inode_ptr& parent);
      inode_ptr get_child_dir(const string& name);
      inode_ptr traverse(inode_state& state, const wordvec& words,
                         size_t start, size_t end);
      inode_ptr path_func(inode_state& state, const wordvec& words);
      int get_f_type(string filename);
      void init_root(inode_ptr root);
      void init_dir(inode_ptr dir);
      inode_ptr mkfile (const string& dirname);
      map<string, inode_ptr> get_dirents();
    
    
    
};

#endif

