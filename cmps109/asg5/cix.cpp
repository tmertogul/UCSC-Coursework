// Tim Mertogul
// tmertogu@ucsc.edu
// Michael Lowe
// mimlowe@ucsc.edu
// CMPS109
// Spring 2015
// ASG 5

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
using namespace std;

#include <libgen.h>
#include <sys/types.h>
#include <unistd.h>

#include "protocol.h"
#include "logstream.h"
#include "sockets.h"

logstream log (cout);
struct cix_exit: public exception {};

unordered_map<string,cix_command> command_map {
   {"exit", CIX_EXIT},
   {"help", CIX_HELP},
   {"ls"  , CIX_LS  },
   {"get",  CIX_GET },
   {"put",  CIX_PUT },
   {"rm",   CIX_RM  },
};

void cix_help() {
   static vector<string> help = {
      "exit         - Exit the program.  Equivalent to EOF.",
      "get filename - Copy remote file to local host.",
      "help         - Print help summary.",
      "ls           - List names of files on remote server.",
      "put filename - Copy local file to remote host.",
      "rm filename  - Remove file from remote server.",
   };
   for (const auto& line: help) cout << line << endl;
}

void cix_ls (client_socket& server) {
   cix_header header;
   header.command = CIX_LS;
   log << "sending header " << header << endl;
   send_packet (server, &header, sizeof header);
   recv_packet (server, &header, sizeof header);
   log << "received header " << header << endl;
   if (header.command != CIX_LSOUT) {
      log << "sent CIX_LS, server did not return CIX_LSOUT" << endl;
      log << "server returned " << header << endl;
   }else {
      char buffer[header.nbytes + 1];
      recv_packet (server, buffer, header.nbytes);
      log << "received " << header.nbytes << " bytes" << endl;
      buffer[header.nbytes] = '\0';
      cout << buffer;
   }
}

void cix_get (client_socket& server, char* fname) {
   cix_header header;
   header.command = CIX_GET;
   strcpy (header.filename, fname); 

   log << "sending header " << header << endl;
   send_packet (server, &header, sizeof header);
   recv_packet (server, &header, sizeof header);
   log << "received header " << header << endl;

   if (header.command != CIX_FILE) {
      log << "sent CIX_GET, server did not return CIX_FILE" << endl;
      log << "server returned " << header << endl;
   }else {
      char buffer[header.nbytes + 1];
      recv_packet (server, buffer, header.nbytes);
      log << "received " << header.nbytes << " bytes" << endl;
      buffer[header.nbytes] = '\0';
      string get_output = "";
    
      ofstream out(fname, ios::binary);
      out.write (buffer,header.nbytes);
      out.close();
   }
}

void cix_put (client_socket& server, char* fname) {

   string put_output = "";
   ifstream in(fname, ios::binary);
   while (in) {
      char c;
      in.get(c);
      if (in) {
         put_output += char(c);
      }
   }   
   in.close();  
   
   cix_header header;
   header.command = CIX_PUT;
   header.nbytes = put_output.size();
   memset (header.filename, 0, FILENAME_SIZE);
   strcpy (header.filename, fname); 

   log << "sending header " << header << endl;
   send_packet (server, &header, sizeof header);
  send_packet (server, put_output.c_str(), put_output.size());
   recv_packet (server, &header, sizeof header);
   log << "received header " << header << endl;

   if (header.command != CIX_ACK) {
      log << "sent CIX_PUT, server did not return CIX_ACK" << endl;
      log << "server returned " << header << endl;
   }else{
      cout << "returned ACK, put successful" << endl;
      
   }
   
}

void cix_rm (client_socket& server, char* fname) {
   cix_header header;
   header.command = CIX_RM;
   memset (header.filename, 0, FILENAME_SIZE);
   strcpy (header.filename, fname);
      
   log << "sending header " << header << endl;
   send_packet (server, &header, sizeof header);
   recv_packet (server, &header, sizeof header);
   log << "received header " << header << endl;
   
   if (header.command != CIX_ACK) {
      log << "sent CIX_RM, server did not return CIX_ACK" << endl;
      log << "server returned " << header << endl;
   }
}



void usage() {
   cerr << "Usage: " << log.execname() << " [host] [port]" << endl;
   throw cix_exit();
}

char* filename(string line){
    string filename = 
              line.substr(line.find_first_of(' ', 0) +1, string::npos);
    char* fname = new char[filename.size()];
    copy(filename.begin(), filename.end(), fname);
    fname[filename.size()] = '\0';
    cout << "fname: " << fname << endl;
    return fname;
}

string cmdn(string line){
    string cmd = line.substr(0, line.find_first_of(' ', 0));
    cout << "cmd: " << cmd << endl;
    return cmd;
}

int main (int argc, char** argv) {
   int h, p;
   log.execname (basename (argv[0]));
   log << "starting" << endl;
   vector<string> args (&argv[1], &argv[argc]);
   if (args.size() > 2) usage();
   else if (args.size() == 1) { h=1; p=0; }
   else { h=0; p=1; }
   string host = get_cix_server_host (args, h);
   in_port_t port = get_cix_server_port (args, p);
   
   log << to_string (hostinfo()) << endl;
   try {
      log << "connecting to " << host << " port " << port << endl;
      client_socket server (host, port);
      log << "connected to " << to_string (server) << endl;
      for (;;) {
         string line;
         getline (cin, line);
         if (cin.eof()) throw cix_exit();
         log << "command " << line << endl;
         string cmdname = cmdn(line);
         const auto& itor = command_map.find (cmdname);
         cix_command cmd = itor == command_map.end()
                         ? CIX_ERROR : itor->second;
         char* fname = filename(line);
         switch (cmd) {
            case CIX_EXIT:
               throw cix_exit(); 
               break;
            case CIX_HELP:
               cix_help();
               break;
            case CIX_LS:
               cix_ls (server);
               break;
            case CIX_PUT:
               cix_put (server, fname);
               break;
            case CIX_GET:
               cix_get (server, fname);
               break;
            case CIX_RM:
               cix_rm (server, fname);
               break;
            default:
               log << line << ": invalid command" << endl;
               break;
         }
      }
   }catch (socket_error& error) {
      log << error.what() << endl;
   }catch (cix_exit& error) {
      log << "caught cix_exit" << endl;
   }
   log << "finishing" << endl;
   return 0;
}

