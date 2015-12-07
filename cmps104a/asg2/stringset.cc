
#include <string>
#include <unordered_set> 
using namespace std;

#include "stringset.h"
 
typedef unordered_set<string> stringset;
typedef stringset::const_iterator stringset_citor;
typedef stringset::const_local_iterator stringset_bucket_citor;

stringset set;
 
const string* intern_stringset (const char* string) {
   pair<stringset_citor,bool> handle = set.insert (string);
   return &*handle.first;
}

void dump_stringset (FILE* strout) {
   size_t max_bucket_size = 0; 
   for (size_t bucket = 0; bucket < set.bucket_count(); ++bucket) {
      bool need_index = true;
      size_t curr_size = set.bucket_size (bucket);
      if (max_bucket_size < curr_size) max_bucket_size = curr_size;
      for (stringset_bucket_citor itor = set.cbegin (bucket);
           itor != set.cend (bucket); ++itor) {
         if (need_index) fprintf (strout, "string[%4lu]: ", bucket);
                    else fprintf (strout, "       %4s   ", "");
         need_index = false;
         const string* str = &*itor;
         fprintf (strout, "%22lu %p->\"%s\"\n",
                  set.hash_function()(*str), str, str->c_str());
      }
   }
   fprintf (strout, "load_factor = %.3f\n", set.load_factor());
   fprintf (strout, "bucket_count = %lu\n", set.bucket_count());
   fprintf (strout, "max_bucket_size = %lu\n", max_bucket_size);
}


