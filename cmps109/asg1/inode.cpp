// Tim Mertogul
// tmertogu@ucsc.edu
// Michael Lowe
// mimlowe@ucsc.edu
// CMPS109
// Spring 2015
// ASG 1

#include <iostream>
#include <stdexcept>

using namespace std;

#include "debug.h"
#include "inode.h"

extern bool DNE;


//======= inode methods  ========//

int inode::next_inode_nr {1};

// inode constructor
inode::inode(inode_t init_type):
   inode_nr (next_inode_nr++), type (init_type)
{
   switch (type) {
      case PLAIN_INODE:
           contents = make_shared<plain_file>();
           break;
      case DIR_INODE:
           contents = make_shared<directory>();
           break;
   }
   DEBUGF ('i', "inode " << inode_nr << ", type = " << type);
}
inode::~inode() {
    parent = nullptr;
    contents = nullptr;
}

int inode::get_inode_nr() const {
   DEBUGF ('i', "inode = " << inode_nr);
   return inode_nr;
}

inode_ptr& inode::get_parent() {
    return parent;
}

void inode::set_parent(const inode_ptr& p) {
    parent = p;
}

string inode::get_name() {
    return node_name;
}

string inode::get_path() {
    return node_path;
}

// type 0 = PLAIN_INODE
// type 1 = DIR_INODE
int inode::get_type() {
    if (type == DIR_INODE) {
        return 1;
    }
    return 0;
}

file_base_ptr inode::get_contents() {
    return contents;
}


// used to assign names to inodes
void inode::name_node(const string& name) {
    node_name = name;
}

void inode::name_path(const string& path_name) {
    node_path = path_name;
}

// uses inode as an access point for
// directory::mkdir
void inode::mkdir(const string& dirname, const inode_state& state) {
    directory_ptr dir = directory_ptr_of(contents);
    inode_ptr p = state.cwd;
    dir->mkdir(dirname, p);
    
    DEBUGF('n', get_name());
}

void inode::make_file(const wordvec& file, const inode_state& state) {
    //const string& f_name = file.at(1);
    //cout << "1" << endl;
    directory_ptr fil = directory_ptr_of(contents);
    inode_ptr p = state.cwd;
    
    
    
    fil->make_file(file, p);
    
    DEBUGF('n', get_name());
}

void inode::rm_file(const wordvec& file, const inode_state& state) {

    directory_ptr fil = directory_ptr_of(contents);
    inode_ptr p = state.cwd;
    fil->rm_file(file, p);
    
    DEBUGF('n', get_name());
}

void inode::print_file(const wordvec& file, const inode_state& state){

    directory_ptr fil = directory_ptr_of(contents);
    inode_ptr p = state.cwd;
    fil->print_file(file, p);
    
    
    DEBUGF('n', get_name());
}


//********* end inode ***************//

//=======  directory class methods  ========//

// modifies dirents map to include
// appropriate subdirectories . ..
inode_ptr directory::make_file(const wordvec& file, 
                                            const inode_ptr& parent){
    //cout << "2" << endl;
    
    const string& f_name = file.at(0);
    
    //cout << "filename =" << f_name << endl;
    
    
    inode_ptr new_file;
    
    new_file = make_shared<inode>(PLAIN_INODE);
    new_file->name_node(f_name);
    new_file->set_parent(parent);
    dirents.insert(make_pair(f_name, new_file));
    
    plain_file_ptr file_stuff = 
                        plain_file_ptr_of(new_file->get_contents());
    wordvec temp = file;
    temp.erase(temp.begin());
    const wordvec& newdata = temp;
    
    file_stuff->writefile(newdata);
    
    DEBUGF ('i', new_file);
    DEBUGF ('i', parent);
    return new_file;
}

inode_ptr directory::rm_file (const wordvec& file, 
                                         const inode_ptr& parent) {
    //cout << "2" << endl;
    
    const string& f_name = file.at(0);
    //cout << f_name << endl;
    inode_ptr rm_file = dirents.find(f_name)->second;
    dirents.erase(f_name);
    
    
    DEBUGF ('i', rm_file);
    DEBUGF ('i', parent);
    return rm_file;
}

inode_ptr directory::print_file (const wordvec& file,
                              const inode_ptr& parent) {
    //cout << "2" << endl;
    
    const string& f_name = file.at(0);
    //cout << f_name << endl;
    inode_ptr print_file = dirents.find(f_name)->second;
    //dirents.erase(f_name);
    
    
    DEBUGF ('i', print_file);
    DEBUGF ('i', parent);
    return print_file;
}


inode_ptr directory::mkdir (const string& dirname,
                                         const inode_ptr& parent) {
    inode_ptr new_dir = make_shared<inode>(DIR_INODE);
    new_dir->name_node(dirname);
    
    string path_node = parent->get_path();
    path_node += "/" + dirname;
    new_dir->name_path(path_node);
    new_dir->set_parent(parent);
    
    dirents.insert(make_pair(dirname, new_dir));
    DEBUGF ('i', new_dir);
    DEBUGF ('i', parent);
    return new_dir;
}

size_t directory::size() const {
    size_t size {0};
    size = dirents.size();
    DEBUGF ('i', "size = " << size);
    return size;
}

// Requires modification
void directory::remove (const string& filename) {
    DEBUGF ('i', filename);
}

void directory::init_root(inode_ptr root) {
    dirents.insert(make_pair(".", root));
    dirents.insert(make_pair("..", root));
    root->name_node("/");
    //root->name_path("/");
}

void directory::init_dir(inode_ptr dir) {
    dirents.insert(make_pair(".", dir));
    dirents.insert(make_pair("..", dir->get_parent()));
}

int directory::get_f_type(string filename){
    
    inode_ptr t = get_child_dir(filename);
    if (DNE == false) {
        return t->get_type();
    }
    return -1;
}

inode_ptr directory::path_func(inode_state& state,
                              const wordvec& words) {
    state.get_cwd()->get_contents();

    string filename = words.at(1);
    inode_ptr file(nullptr);

    if( get_child_dir(filename) != nullptr){
        file = dirents.find(filename)->second;
    }
    return file;
}

// finds directory's child by name and
// returns the inode_pointer associated with it
inode_ptr directory::get_child_dir(const string& name) {
    map<string, inode_ptr>::const_iterator itor = dirents.begin();
    map<string, inode_ptr>::const_iterator end = dirents.end();
    for (; itor != end; ++itor) {
        if (name.compare(itor->first) == 0)
            return itor->second;
    }
    DNE = true;
    return nullptr;
}
map<string, inode_ptr> directory::get_dirents() {
    return dirents;
}
//********* end directory ***************//

plain_file_ptr plain_file_ptr_of (file_base_ptr ptr) {
    plain_file_ptr pfptr = dynamic_pointer_cast<plain_file> (ptr);
    if (pfptr == nullptr) throw invalid_argument ("plain_file_ptr_of");
    return pfptr;
}

directory_ptr directory_ptr_of (file_base_ptr ptr) {
    directory_ptr dirptr = dynamic_pointer_cast<directory> (ptr);
    if (dirptr == nullptr) throw invalid_argument ("directory_ptr_of");
    return dirptr;
}



//======= plain file methods  ========//

size_t plain_file::size() const {
    size_t size {0};
    int spaces = -1;
    for(wordvec::const_iterator i=data.begin(); i != data.end(); ++i){
        if (data.begin() == data.end()) {
                break;
        }
        size += sizeof(char) * i->length();
        spaces++;
    }
    DEBUGF ('i', "size = " << size);
    return size;
}


// Requires modification
const wordvec& plain_file::readfile() const {
    
    for(wordvec::const_iterator i=data.begin(); i != data.end(); ++i){
        // print words in sequence
        cout << *i + " ";
    }
    cout << "\n";
    
    DEBUGF ('i', data);
    return data;
}


// Requires modification
void plain_file::writefile (const wordvec& words) {
    
    data = words;
    
    //readfile();
    
    DEBUGF ('i', words);
}
//********* end plain file ***************//




// ======= inode_state class methods  =======//

// inode_state constructor
inode_state::inode_state() {
    root =  make_shared<inode>(DIR_INODE);
    cwd = root;
    directory_ptr init = directory_ptr_of(root->contents);
    init->init_root(root);
    DNE = false;
        
    DEBUGF ('i', "root = " << root << ", cwd = " << cwd
            << ", prompt = \"" << prompt << "\"");
}

inode_state::~inode_state() {
  /* cwd->set_parent(nullptr);
    cwd->contents = nullptr;
    cwd = nullptr;
    
    save->set_parent(nullptr);
    save->contents = nullptr;
    save = nullptr;
    
    root->set_parent(nullptr);
    root->contents = nullptr;
    root = nullptr;*/
    cwd = nullptr;
    root = nullptr;
    save = nullptr;
}

inode_ptr& inode_state::get_cwd() {
    return cwd;
}
inode_ptr& inode_state::get_root() {
    return root;
}
inode_ptr& inode_state::get_save() {
    return save;
}

void inode_state::set_prompt(string& p) {
    prompt = p;
}

void inode_state::set_save(inode_ptr& s) {
    save = s;
}
void inode_state::set_cwd_to_root(){
    cwd = root;
}
void inode_state::reset(){
    cwd = save;
}


void inode_state::set_cwd(inode_ptr& current) {
    if (current->get_type() == 1) {
        cwd = current;
        directory_ptr dir_setup = 
                            directory_ptr_of(current->get_contents());
        dir_setup->init_dir(current);
    }
    else throw yshell_exn("set_cwd: inode is not directory");
}

string inode_state::prompt_print(){
    return prompt;
}
//********* end inode state ***************//



ostream& operator<< (ostream& out, const inode_state& state) {
   out << "inode_state: root = " << state.root
       << ", cwd = " << state.cwd;
   return out;
}

