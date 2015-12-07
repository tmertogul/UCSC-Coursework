// Tim Mertogul
// tmertogu@ucsc.edu
// Michael Lowe
// mimlowe@ucsc.edu
// CMPS109
// Spring 2015
// ASG 1


#include "commands.h"
#include "debug.h"

inode_ptr memory;
inode_ptr current;
bool DNE;
bool recursive;


commands::commands(): map ({
   {"cat"   , fn_cat   },
   {"cd"    , fn_cd    },
   {"echo"  , fn_echo  },
   {"exit"  , fn_exit  },
   {"ls"    , fn_ls    },
   {"lsr"   , fn_lsr   },
   {"make"  , fn_make  },
   {"mkdir" , fn_mkdir },
   {"prompt", fn_prompt},
   {"pwd"   , fn_pwd   },
   {"rm"    , fn_rm    },
   {"rmr"   , fn_rmr   },
   {"#"     , fn_com   },
}){}

command_fn commands::at (const string& cmd) {
   // Note: value_type is pair<const key_type, mapped_type>
   // So: iterator->first is key_type (string)
   // So: iterator->second is mapped_type (command_fn)
   command_map::const_iterator result = map.find (cmd);
   if (result == map.end()) {
      throw yshell_exn (cmd + ": no such function");
   }
   return result->second;
}

bool is_num(const string& s){
    for(size_t i = 0; i < s.length(); i++) {
        if(! ((s[i] >= '0' && s[i] <='9') || s[i] ==' '))
            return false;
    }
    return true;
}

bool path_is_valid(inode_state& state, wordvec& words){
    DNE = false;
    directory_ptr dir = 
             directory_ptr_of(state.get_cwd()->get_contents());
    inode_ptr go = dir->path_func(state, words);
    
    if (dir->get_f_type(words.at(1)) == -1) {
        throw yshell_exn("error: " + words[0] +
                         ": Directory or File does not exist");
    } else{
        return 1;
    }
    return 0;
}

string path_set(inode_state& state, wordvec& words){
    
    state.set_save(current);
    
    wordvec path = split(words.at(1),"/");

    string cwd_name = path.back();
    path.insert ( path.begin() , "root" );

    while (path.size() > 2) {
        directory_ptr dir =
                directory_ptr_of(state.get_cwd()->get_contents());
        inode_ptr go = dir->path_func(state, path);
        
        for(size_t i = 0; i < path.size(); i++){
            //cout << "path " << path.at(i) << cwd_name << endl;
        }
        
        if (path_is_valid(state, path) && go->get_type() == 1){
            state.set_cwd(go);
            current = go;
        } else if (go->get_type() == 1) {
            throw yshell_exn("cd: " + words[1] +
                             ": Directory is a file");
        }
        path.erase (path.begin());
    }
    return cwd_name;
}

void fn_com (inode_state& state, const wordvec& words) {
    state.get_cwd()->get_contents();
    words.at(0);
}

void fn_cd (inode_state& state, const wordvec& words){
    
    
    
    if (words.size() == 1){
        state.set_cwd_to_root();
    }
    else if (words.size() == 2){
        
        current = state.get_cwd();
        state.set_save(current);
        wordvec input = words;
        
        if (input.at(1) == "/"){
            cout << "found a rood" << endl;
            //input.erase(input.begin());
            state.set_cwd_to_root();
        } else {
            string filename = path_set(state, input);
            input.at(1) = filename;
            //cout << "this is filename " << input.at(1) << endl;
            inode_ptr curr = state.get_cwd();
            directory_ptr dir =
                  directory_ptr_of(state.get_cwd()->get_contents());
            inode_ptr go = dir->path_func(state, input);
            if (go == NULL) {
                throw yshell_exn("cd: " + input[1] +
                                    ": No such file or directory");
            } else if (go->get_type() == 1){
                state.set_cwd(go);
            } else {
                throw yshell_exn("cd: " + input[1] +
                             ": Directory is a file");
            }
        }
    } else {
        string error = "cd:";
        wordvec::const_iterator itor = words.begin() + 1;
        while ( itor != words.end() ) error += " " + *itor++;
        error += ": No such file or directory.";
        throw yshell_exn(error);
    }
    
   // state.reset();

   DEBUGF ('c', state);
   DEBUGF ('c', words);
}

void fn_echo (inode_state& state, const wordvec& words){
   // iterate through words
   for (wordvec::const_iterator i = words.begin(); i 
                                         != words.end(); ++i) {
      // skip the command token
     if (i == words.begin()) continue;
     // print words in sequence
     cout << *i + " ";
   }
   cout << "\n";
   DEBUGF ('c', state);
   DEBUGF ('c', words);
}

void fn_exit (inode_state& state, const wordvec& words){

    int e_stat = 0;
    string code;
    if (words.size() == 1) {
        e_stat = 0;
    } else {
        code =  words.at(1);
        if(!is_num(code))
            e_stat = 127;
        else
            e_stat = atoi(code.c_str());
    }
    
    exit_status().set(e_stat);
    
    throw ysh_exit_exn();
    
    DEBUGF ('c', state);
    DEBUGF ('c', words);
}

void fn_ls (inode_state& state, const wordvec& words){
    if (words.size() > 2){
        throw yshell_exn("usage: ls pathname");
    }
    current = state.get_cwd();
    state.set_save(current);
    if (words.size() == 1) {
        // use cwd
    } else {
        if (words.at(1) == "..") {
            if (state.get_cwd() != state.get_root()){
                current = state.get_cwd()->get_parent();
            }
        } else if (words.at(1) == "." || words.at(1) == "/") {
            // use cwd
        } else {
            fn_cd(state, words);
            current = state.get_cwd();
            // path
        }
    }
    
    string name = current->get_name();
    cout << name << ":  " << endl;
    directory_ptr curr_dir = 
                           directory_ptr_of(current->get_contents());
    map<string, inode_ptr> ents = curr_dir->get_dirents();
    map<string, inode_ptr>::const_iterator itor;
    
    for (itor = ents.begin(); itor != ents.end(); ++itor) {
        cout << "   ";
        cout << itor->second->get_inode_nr();
        cout << "   ";
        
        if (itor->second->get_type() == 1) {
            directory_ptr cur_dir = 
                       directory_ptr_of(itor->second->get_contents());
            cout << cur_dir->get_dirents().size();
         } else {
            plain_file_ptr cur_file = 
                      plain_file_ptr_of(itor->second->get_contents());
            cout << cur_file->size();
         }
        
        cout << "   ";
        cout << itor->first;
        (itor->second->get_type() == 1 && itor->first != "." 
                                             && itor->first != "..")?
            cout << "/": cout << "";
        cout << endl;
    }
    state.reset();
    
    //state.set_cwd(memory);

   DEBUGF ('c', state);
   DEBUGF ('c', words);
}

void fn_cat (inode_state& state, const wordvec& words){
    
    current = state.get_cwd();
    state.set_save(current);
    
    //wordvec input = words;
    
    if (words.size() < 2){
        throw yshell_exn("usage: cat filename");
    }
    else {
        wordvec input = words;
        string filename = path_set(state, input);
        input.at(1) = filename;
        //cout << "this is filename " << input.at(1) << endl;
        
        inode_ptr curr = state.get_cwd();
        for( size_t i=1; i< input.size(); i++){
            
            if (path_is_valid(state, input)){
                current = state.get_cwd();
                directory_ptr dir =
                        directory_ptr_of(current->get_contents());
                map<string, inode_ptr> map_d = dir->get_dirents();
                inode_ptr file = map_d.find(input.at(i))->second;
                
                plain_file_ptr contents =
                            plain_file_ptr_of(file->get_contents());
                
                contents->readfile();
            }
            input.erase(input.begin());
        }
    }
    
    state.reset();
    
    DEBUGF ('c', state);
    DEBUGF ('c', words);
}

void fn_lsr (inode_state& state, const wordvec& words){
    if (words.size() > 2){
        throw yshell_exn("usage: lsr pathname");
    }
    current = state.get_cwd();
    if (!recursive){
        state.set_save(current);
        if (words.size() == 1) {
            // use cwd
        } else {
            if (words.at(1) == "..") {
                current = state.get_cwd()->get_parent();
            } else if (words.at(1) == "." || words.at(1) == "/") {
                // use cwd
            } else {
                fn_cd(state, words);
                current = state.get_cwd();
                // path
            }
        }
    }
    string name;
    name = current->get_name();
    cout << name << ":  " << endl;
    directory_ptr curr_dir =
                         directory_ptr_of(current->get_contents());
    map<string, inode_ptr> ents = curr_dir->get_dirents();
    map<string, inode_ptr>::const_iterator itor;
    for (itor = ents.begin(); itor != ents.end(); ++itor) {
        cout << "   ";
        cout << itor->second->get_inode_nr();
        cout << "   ";
        if (itor->second->get_type() == 1) {
            directory_ptr cur_dir = 
                    directory_ptr_of(itor->second->get_contents());
            cout << cur_dir->get_dirents().size();
        } else {
            plain_file_ptr cur_file = 
                   plain_file_ptr_of(itor->second->get_contents());
            cout << cur_file->size();
        }
        cout << "   ";
        cout << itor->first;
        (itor->second->get_type() == 1 && itor->first != "." 
                                          && itor->first != "..")?
        cout << "/": cout << "";
        cout << endl;
        if (itor->second->get_type() ==1 && itor->first != "."
                                         && itor->first != "..") {
            inode_ptr change = itor->second;
            state.set_cwd(change);
            recursive = true;
            fn_lsr(state, words);
        }
    }
    state.reset();
    recursive = false;
    DEBUGF ('c', state);
    DEBUGF ('c', words);
}

void fn_make (inode_state& state, const wordvec& words){
    if (words.size() == 1) {
        throw yshell_exn("usage: make filename contents");
    }
    
    
    current = state.get_cwd();
    state.set_save(current);
    
    wordvec input = words;
    string filename = path_set(state, input);
    input.at(1) = filename;
    inode_ptr curr = state.get_cwd();
    
    
    DNE = false;
    directory_ptr dir =
                directory_ptr_of(state.get_cwd()->get_contents());
    inode_ptr go = dir->path_func(state, input);
    //inode_ptr curr = state.get_cwd();

    int t = dir->get_f_type(input.at(1));
    
    wordvec temp = input;
    // remove the command token
    temp.erase(temp.begin());
    //temp.emplace ( temp.begin(), filename );
    const wordvec& file = temp;
    
    if (t == 1){
        throw yshell_exn("make: " + input[0] +
                         ": File already exists as directory");
    }
    if (t == -1) {
        curr->make_file(file, state);
    } else{
        plain_file_ptr fil = plain_file_ptr_of(go->get_contents());
        wordvec temp = file;
        // remove the command token
        temp.erase(temp.begin());
        //temp.emplace ( temp.begin(), filename );
        const wordvec& text = temp;
        fil->writefile(text);
    }
    
    state.reset();
    
    DEBUGF ('c', state);
    DEBUGF ('c', file);
}

void fn_mkdir (inode_state& state, const wordvec& words){
    if (words.size() != 2) {
        throw yshell_exn("usage: mkdir pathname");
    }
    
    current = state.get_cwd();
    state.set_save(current);
    
    wordvec input = words;
    string filename = path_set(state, input);
    input.at(1) = filename;
    //cout << "this is filename " << input.at(1) << endl;

    
    inode_ptr curr = state.get_cwd();
    DNE = false;
    directory_ptr dir =
            directory_ptr_of(state.get_cwd()->get_contents());
    inode_ptr go = dir->path_func(state, input);

    int t = dir->get_f_type(input.at(1));
    //int t = dir->get_f_type(filename);

    if (t == 0){
        throw yshell_exn("mkdir: " + input[0] +
                         ": Directory already exists as a file");
    }
    if (t == -1) {
        curr->mkdir(input.at(1), state);
    } else{
        throw yshell_exn("mkdir: " + input[0] +
                         ": Directory already exists");
    }
    
    state.reset();
    
    DEBUGF ('c', state);
    DEBUGF ('c', words);
    
}

void fn_prompt (inode_state& state, const wordvec& words){
    // create a temporary vector
    wordvec temp = words;
    // remove the command token
    temp.erase(temp.begin());
    string new_prompt;
    for (unsigned int itor=0; itor < temp.size(); itor++) {
        // build a string from temp vector
        new_prompt.append(temp[itor]);
    }
    //inode_state modifying method
    state.set_prompt(new_prompt);
 
    DEBUGF ('c', state);
    DEBUGF ('c', words);
}

void fn_pwd (inode_state& state, const wordvec& words){
    
    current = state.get_cwd();
    inode_ptr root = state.get_root();
   
    if (current == root) {
        cout << "/" << endl;
    } else {
        cout << current->get_path() << endl;
    }

    DEBUGF ('c', state);
    DEBUGF ('c', words);
}

void fn_rm (inode_state& state, const wordvec& words){
    current = state.get_cwd();
    state.set_save(current);
    wordvec input = words;
    if (words.size() != 2 ){
        throw yshell_exn("usage: rm filename");
    }
    else {
        wordvec input = words;
        string filename = path_set(state, input);
        input.at(1) = filename;
        if (path_is_valid(state, input)){
            
            inode_ptr curr = state.get_cwd();
            wordvec temp = words;
            temp.erase(temp.begin());

            const wordvec& file = temp;
            curr->rm_file(file, state);
            

        } /*else {
            cout << "Path is invalid" << endl;
        }*/
    }
    state.reset();

    DEBUGF ('c', state);
    DEBUGF ('c', words);
}

void fn_rmr (inode_state& state, const wordvec& words){
    while(recursive){ break;
    if (words.size() != 2){
        throw yshell_exn("usage: rmr pathname");
    }
    
    current = state.get_cwd();
    if (!recursive){
        state.set_save(current);
        if (words.size() == 1) {
            // use cwd
        } else {
            if (words.at(1) == "..") {
                current = state.get_cwd()->get_parent();
            } else if (words.at(1) == ".") {
                // use cwd
            } else {
                fn_cd(state, words);
                current = state.get_cwd();
                // path
            }
        }
    }
    wordvec temp;
    directory_ptr dir = directory_ptr_of(current->get_contents());
    map<string,inode_ptr> ents = dir->get_dirents();
    map<string,inode_ptr>::const_iterator itor;;

    string name;
    name = current->get_name();
    //cout << name << ":  " << endl;
    directory_ptr curr_dir =
    directory_ptr_of(current->get_contents());
    //map<string, inode_ptr> ents = curr_dir->get_dirents();
    //map<string, inode_ptr>::const_iterator itor;
    for (itor = ents.begin(); itor != ents.end(); ++itor) {
        if (itor->second->get_type() == 1) {
            dir = directory_ptr_of(itor->second->get_contents());
            if (dir->size() == 0) {
                dir->remove("");
            } else {
                recursive = true;
                temp = words;
                temp.erase(temp.begin());
                fn_cd(state, temp);
            }
    
        } else {
            temp = words;
            temp.erase(temp.begin());
            const wordvec& file = temp;
            current->rm_file(file, state);
    
        }
    }
    state.reset();
    }
    fn_rm(state, words);
    recursive = false;
    
    DEBUGF ('c', state);
    DEBUGF ('c', words);
}


int exit_status_message() {
    int exit_status = exit_status::get();
    cout << execname() << ": exit(" << exit_status << ")" << endl;
    return exit_status;
}

