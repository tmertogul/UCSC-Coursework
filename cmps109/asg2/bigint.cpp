// Tim Mertogul
// tmertogu@ucsc.edu
// Michael Lowe
// mimlowe@ucsc.edu
// CMPS109
// Spring 2015
// ASG 2

// $Id: bigint.cpp,v 1.61 2014-06-26 17:06:06-07 - - $

#include <cstdlib>
#include <exception>
#include <limits>
#include <stack>
#include <stdexcept>
using namespace std;

#include "bigint.h"
#include "debug.h"
#include <math.h>

bigint::bigint (long that): long_value (that),  negative(false) {
    init(to_string(that));
    DEBUGF ('~', this << " -> " << long_value)
}

bigint::bigint (const string& that) :negative(false) {
    init(that);
    // long_value = isnegative ? - newval : + newval;
  //  DEBUGF ('~', this << " -> " << long_value)
    
}

void bigint::init (const string& that) {
    auto itor = that.cbegin();
    if (itor != that.cend() and *itor == '_') {
        negative = true;
        ++itor;
    }
    long newval = 0;
    while (itor != that.end()) newval = newval * 10 + *itor++ - '0';
    long_value = newval;
    

    for (auto ritor  = that.crbegin();
         ritor != that.crend() && *ritor != '_';
         ritor++) {
       big_value.push_back(*ritor - '0');
    }

}

bool isZero(const bigvalue_t& value) {
    if (value.back() == 0) {
        return true;
    }
    return false;
}

bool do_bigless(const bigvalue_t& left, const bigvalue_t& right) {
    
    if (left.size() < right.size()) {
        //cout << "t" << endl;
        return true;
    } else if (left.size() > right.size()){
        //cout << "f" << endl;
        return false;
    }
    size_t itor = left.size();
    digit_t l = 0;
    digit_t r = 0;
    while (itor !=0) {
        itor--;
        //cout << "Equal" << endl;
        l = left.at(itor);
        r = right.at(itor);
        //cout << "l: " << l << ", r: " << r << endl;
        if (l > r) {
            return false;
        } else if (l < r){
            return true;
        }
    }
    if (l >= r) {
        return false;
    }
    return true;
}

bigvalue_t do_bigadd (const bigvalue_t& left, const bigvalue_t& right) {
    digit_t carry = 0;
    digit_t i_digit = 0;
    bigvalue_t result;
    bigvalue_t larger;
    
    if (do_bigless(left,right))
        larger = right;
    else larger = left;

    size_t reps = min(left.size(), right.size());
    size_t itor;
    for (itor = 0; itor < reps; itor++) {
        i_digit = left.at(itor) + right.at(itor) + carry;
        
        if (i_digit > 9) {
            carry = 1;
            i_digit -= 10;
        } else {
            carry = 0;
        }
        result.push_back(i_digit);
    }
    
    while (itor < larger.size()) {
        i_digit = larger.at(itor) + carry;
        
        if (i_digit > 9) {
            carry = 1;
            i_digit -= 10;
        } else {
            carry = 0;
        }
        result.push_back(i_digit);
        itor++;
    }
    
    if (carry == 1) {
        result.push_back(1);
    }
    return result;
}

bigvalue_t do_bigsub(const bigvalue_t& left, const bigvalue_t& right) {
    digit_t carry = 0;
    digit_t i_digit = 0;
    bigvalue_t result;
    size_t itor;
    for (itor = 0; itor < right.size(); itor++) {
       
        if (left.at(itor) - carry < right.at(itor)) {
            i_digit = 10 + left.at(itor) - right.at(itor) - carry;
            carry = 1;
        }
        else {
            i_digit = left.at(itor) - right.at(itor) - carry;
            carry = 0;
        }
        result.push_back(i_digit);
    }
    while (itor < left.size()) {
        if (left.at(itor) < carry) {
            i_digit = 10 + left.at(itor) - carry;
            carry = 1;
        }
        else {
            i_digit = left.at(itor) - carry;
            carry = 0;
        }
        result.push_back(i_digit);
        itor++;
    }
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    return result;
}

bigvalue_t do_bigmul (const bigvalue_t& left, const bigvalue_t& right) {
    digit_t carry = 0;
    digit_t i_digit = 0;
    bigvalue_t result;
    bigvalue_t larger;
    
    result.resize(left.size() + right.size());
    
    size_t itor;
    size_t jtor;
    for (itor = 0; itor < left.size(); itor++) {
        carry = 0;
        for (jtor = 0; jtor < right.size(); jtor++) {
            i_digit = result.at(itor+jtor) +
                                 (left.at(itor)*right.at(jtor)) + carry;
            result.at(itor+jtor) = i_digit % 10;
            carry = floor (i_digit / 10);
        }
        result.at(itor+right.size()) = carry;
    }
    while(result.at(result.size()-1) == 0 && result.size() != 1){
        result.resize(result.size()-1);
    }
    return result;
}

bigvalue_t halve( bigvalue_t number){
    bigvalue_t result;
    result.resize(number.size());
    digit_t carry = 0;
    digit_t i_digit = 0;
    size_t itor;
    for (itor = number.size(); 0 < itor ; itor--){
        i_digit = number.at(itor-1);
        result.at(itor-1) = floor(i_digit/2) + carry;
        if( i_digit % 2 == 0 ){
            carry = 0;
        } else {
            carry = 5;
        }
    }
    while(result.at(result.size()-1) == 0 && result.size() != 1){
        result.resize(result.size()-1);
    }
    return result;
}

bigvalue_t set_bigvalue_t(const string& that){
    bigint i_temp;
    for (auto ritor = that.crbegin();
         ritor != that.crend() && *ritor != '_';
         ritor++) {
        i_temp.big_value.push_back(*ritor - '0');
    }
    return i_temp.big_value;
}

bigint signInt(bigint result){
    if (isZero(result.big_value)) {
        result.negative = false;
    }
    return result;
}

bigint operator+ (const bigint& left, const bigint& right) {
/*    if (left < right) {
        cout << "left < right? yes" << endl;
    } else {
        cout << "left < right? no" << endl;
    }
    
    if (left == right) {
        cout << "left == right? yes" << endl;
    } else {
        cout << "left == right? no" << endl;
    }*/
    bigint result;
    if (left.negative == right.negative) {
       result.big_value = do_bigadd(left.big_value, right.big_value);
       result.negative = left.negative;
       return result;
    } else {
       if (left > right) {
          result.big_value = do_bigsub(right.big_value, left.big_value);
          result.negative = right.negative;
       } else {
          result.big_value = do_bigsub(left.big_value, right.big_value);
          result.negative = left.negative;
       }
    }
    return signInt(result);
}

bigint operator- (const bigint& left, const bigint& right) {
    bigint result;
    if (left.negative == right.negative) {
        if (left > right) {
            result.big_value = do_bigsub(left.big_value, 
                                                     right.big_value);
            result.negative = left.negative;
        } else {
            result.big_value = do_bigsub(right.big_value, 
                                                     left.big_value);
            result.negative = !right.negative;
        }
    } else {
        result.big_value = do_bigadd(left.big_value, right.big_value);
        result.negative = left.negative;
    }
    return signInt(result);
}

bigint operator+ (const bigint& right) {
    bigint pos = right;
    pos.negative = false;
    return pos;
}

bigint operator- (const bigint& right) {
    bigint neg = right;
    neg.negative = true;
    return signInt(neg);
}

bool to_long(bigvalue_t number) {
    //bigint long_size = (10);   for testing
    bigint long_size = (2147483647);
    if( do_bigless(long_size.big_value, number)){
        cout << "Runtime error: exponent too large in raise" << endl;
        return false;
    }
    return true;
}

bigint::quot_rem divide (const bigint& left, const bigint& right) {
    if (isZero(right.big_value)){
        cout << "ydc: divide by 0" << endl;
    }
    //if (right == 0) throw domain_error ("divide by 0");
    
    bigint i_temp = (1);
    bigint j_temp = (1);
    bigvalue_t powerof2 = i_temp.big_value;
    i_temp = (0);
    bigvalue_t zero = i_temp.big_value;
    i_temp = (2);
    bigvalue_t two = i_temp.big_value;
    
    //if (right == 0) throw domain_error ("bigint::divide");
    
    bigvalue_t divisor = right.big_value;
    bigvalue_t quotient = zero;
    bigvalue_t remainder = left.big_value;

    bigint temp;
    temp.negative = false;
    
    while (do_bigless (divisor, remainder)) {
        divisor = do_bigmul(divisor, two);
        powerof2 = do_bigmul(powerof2, two);
    }
    while (do_bigless (zero, powerof2)) {
        if (not do_bigless (remainder, divisor)) {
            remainder = do_bigsub(remainder, divisor);
            quotient = do_bigadd(quotient, powerof2);
        }
        divisor = halve(divisor);
        powerof2 = halve(powerof2);
    }
    i_temp.big_value = quotient;
    j_temp.big_value = remainder;
    return {i_temp, j_temp};
}

bigint operator* (const bigint& left, const bigint& right) {
    bigint result;
    if (left.negative == right.negative) {
        result.negative = false;
    } else{
        result.negative = true;
    }
    result.big_value = do_bigmul(left.big_value, right.big_value);
    return signInt(result);
}

bigint operator/ (const bigint& left, const bigint& right) {
    //cout << "dc: divide by zero" << endl;
    bigint result;
    if (left.negative == right.negative) {
        result.negative = false;
    } else{
        result.negative = true;
    }
    return divide (left, right).first;
}

bigint operator% (const bigint& left, const bigint& right) {
    bigint result;
    if (left.negative == right.negative) {
        result.negative = false;
    } else{
        result.negative = true;
    }
    return divide (left, right).second;
}

bool operator== (const bigint& left, const bigint& right) {
    if (left.big_value.size() != right.big_value.size()) {
        return false;
    } else {
        auto l_itor = left.big_value.begin();
        auto r_itor = right.big_value.begin();
        int r = 0;
        int l = 0;
    
        while (r_itor != right.big_value.end()) {
            l = (int) *r_itor;
            r = (int) *l_itor;
            if (l != r) {
                return false;
            }
            ++r_itor;
            ++l_itor;
        }
    }
   return true;
}

bool operator< (const bigint& left, const bigint& right) {
   
    if (left.negative && !right.negative) {
        return true;
    } else if (left.negative && right.negative) {
        return do_bigless(left.big_value, right.big_value);
    } else if (!left.negative && right.negative) {
        return false;
    } else {
        return do_bigless(left.big_value, right.big_value);
    }
}

ostream& operator<< (ostream& out, const bigint& that) {
    if (that.negative) {
        out << '-';
    }
    auto itor = that.big_value.crbegin();
    int i = 1;
    int j = 1;
    while (itor != that.big_value.crend()) {
        if (i == 70*j) {
            out << "\\" << endl;
            j++;
            i++;
        }
        out << (int) *itor;
        ++itor;
        i++;
    }
    
    return out;
}

bigint pow (const bigint& base_i, const bigint& exponent_i) {
    DEBUGF ('^', "base = " << base_i << ", exponent = " << exponent_i);
    bigint result  = (1);
    
    //if ( ) throw ydc_exn ("ydc: exponent not a long");
    bigvalue_t one = result.big_value;
    bigint base = base_i;
    bigint exponent = exponent_i;

    if (exponent.negative == true){
        base = divide(result, base).first;
        exponent.negative = false;
    }
    
    if (isZero(exponent.big_value)) return result;
    else if (isZero(base.big_value)) return result = (0);

    bigvalue_t base_copy = base.big_value;
    bigvalue_t expt = exponent.big_value;
    
    if(not to_long(expt)){
        return result;
    };
    
    digit_t i_digit;
    while (not isZero(expt)) {
        i_digit = expt.at(0);
        if (not i_digit % 2 == 0) {       //odd
            result.big_value = do_bigmul(result.big_value, base_copy);
            expt = do_bigsub(expt, one);
        }else { //even
            base_copy = do_bigmul(base_copy, base_copy);
            expt = halve(expt);
        }
    }
    DEBUGF ('^', "result = " << result);
    return result;
}












