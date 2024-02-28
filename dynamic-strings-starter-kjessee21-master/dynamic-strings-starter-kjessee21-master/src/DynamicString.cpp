#include "DynamicString.h"
#include <cctype>
#include <stdexcept>

using std::out_of_range;
using std::tolower;
using std::toupper;
using std::ostream;

//constructs an empty strings for null character
DynamicString::DynamicString(){
    cstr = new char[1];
    cstr[0] = '\0';
}

//constructs a string by copying characters from str arry
DynamicString::DynamicString(const char* str){
    int count = 0;
    //create enough memory from str
    while(str[count]){
        count++;
    }
    //allocate space, this->cstr
    this->cstr = new char[count + 1];
    //put str into cstr
    for(int i = 0; i < count; ++i){
        this->cstr[i] = str[i];
    }
    //include null character at end
    this->cstr[count] = '\0';
}

int DynamicString::len() const{
   int count = 0;
   //get length of cstr
   while(cstr[count]){
       count++;
   }
   return count;
}

const char* DynamicString::c_str() const{
//   /*Delete this garbage and just return cstr
//    * once you have your constructors implemented
//    */
//   char* garbage = new char[1];
//   garbage[0] = '\0';
//   return garbage;
    return cstr;
}
//return position of cstr
char DynamicString::char_at(int position) const{
    //additional tests handle out of range such as less than 0
    //or greater than the length
    if(position < 0 || position > len()){
        throw out_of_range("Out of range");
    }
   return cstr[position];
}
//nearly the same thing as before
char& DynamicString::operator[](int position){
    //additional tests handle out of range such as less than 0
    //or greater than the length
    if(position < 0 || position > len()){
        throw out_of_range("Out of range");
    }
   return cstr[position];
}

bool DynamicString::startsWith(const DynamicString& other) const{
    //if other string less/equal length
   if(other.len() <= len()){
       //loop through
       for(int i = 0; i < other.len(); ++i){
           //return false if not equal at i
           if(cstr[i] != other.cstr[i]){
               return false;
           }
       }
       return true;
   }
   return false;
}

bool DynamicString::endsWith(const DynamicString& other) const{
    //get og length
   int lengthOne = len();
   //get length of other
   int lengthTwo = other.len();
   //if og < other
   if(lengthTwo <= lengthOne){
       //loop through
       for(int i = 0; i < lengthTwo; ++i){
           //if positions aren't equal return false
           if(cstr[lengthOne - i - 1] != other.cstr[lengthTwo - i - 1]){
               return false;
           }
       }
       return true;
   }
   return false;
}

int DynamicString::compare(const DynamicString& other) const{
    //get sizes
   int sizeOne = this->len();
   int sizeTwo = other.len();
    int i = 0;
    //compare sizes at 0
    if(sizeOne == 0 || sizeTwo == 0){
        if(sizeOne > sizeTwo) return 1;
        if(sizeOne < sizeTwo) return -1;
    }
    //compare sizes from i
   while((i != sizeOne) || (i != sizeTwo)){
       if(cstr[i] < other.cstr[i]){
           return -1;
       }
       else if(cstr[i] > other.cstr[i]){
           return 1;
       }
       i++;
   }
   return 0;
}

int DynamicString::iCompare(const DynamicString& other) const{
    //same thing as before
    int sizeOne = this->len();
    int sizeTwo = other.len();

    int i = 0;
    if(sizeOne == 0 || sizeTwo == 0){
        if(sizeOne > sizeTwo) return 1;
        if(sizeOne < sizeTwo) return -1;
    }
    while((i != sizeOne) || (i != sizeTwo)){
        if(tolower(cstr[i]) < tolower(other.cstr[i])){
            return -1;
        }else if(tolower(cstr[i]) > tolower(other.cstr[i])){
            return 1;
        }
        i++;
    }
    return 0;
}

DynamicString& DynamicString::toLower(){
    //loop thru and pass through toLower()
   for(int i = 0; i < len(); ++i){
       cstr[i] = tolower(cstr[i]);
   }
   return *this;
}

DynamicString& DynamicString::toUpper(){
    //loop through and pass toUpper()
    for(int i = 0; i <= len(); i++){
        cstr[i] = toupper(cstr[i]);
    }
    return *this;
}

DynamicString& DynamicString::replace(char old, char newCh){
    //declare letter for replacing
    char letter;
    //loop through
    for(int i = 0; i < len(); ++i){
        //put character into letter
        letter = cstr[i];
        if(letter == old){
            //store newCH into cstr
            cstr[i] = newCh;
        }
    }
    return *this;
}

int DynamicString::find(char c, int start) const{
    //loop through and find where cstr == c
    for(int i = start; i < len(); ++i){
        if(cstr[i] == c){
            return i;
        }
    }
    return -1;
}

int DynamicString::reverseFind(char c, int start) const{
    //same thing as before but reverse
    for(int i = start; i >= 0; --i){
        if(cstr[i] == c){
            return i;
        }
    }
    return -1;
}

int DynamicString::reverseFind(char c) const{
    //same thing as reverse but declare end/start yourself
    int end = len() - 1;
    for(int i = end; i >= 0; --i){
        if(cstr[i] == c){
            return i;
        }
    }
   return -1;
}

ostream& operator<<(ostream& out, const DynamicString& str){
    //simple out operator that just displays the char at i
    for(int i = 0; i < str.len(); ++i){
        out << str.char_at(i);
    }

   return out;
}

DynamicString::DynamicString(const DynamicString & other){
    int len = other.len();
    this->cstr = new char[len + 1];
    for(int i = 0; i < len; i++){
        this->cstr[i] = other.cstr[i];
    }
    this->cstr[len] = '\0';
    //this->cstr = other.cstr
}

DynamicString& DynamicString::operator=(const DynamicString &other) {
    delete []cstr;
    int len = other.len();
    this->cstr = new char[len + 1];
    for(int i = 0; i < len; i++){
        this->cstr[i] = other.cstr[i];
    }
    this->cstr[len] = '\0';
    return *this;
}

DynamicString::~DynamicString() {
    delete[] this->cstr;
}