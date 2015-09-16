# Memoized Factorial

## Contents
- [Intro](#intro)
- [Pseudocode](#pseudocode)
- [C++ translation](#c-translation)
  - [Footnotes](#footnotes)

### Intro

This is a tutorial for those that want to get a better understanding of static variables, what 
memoization is, and overall learn a nifty trick to optimize function computation.

In this example, we'll be using the good 'ol factorial function. For a fairly clean and easy to 
follow along memoized factorial computation, we'll need three functions:

- `int getFactorial(int n);` for user (easier to remember/type this than memoFact)
- `int memoFact(int n);`     for programmer and efficiency-boost (returns factorial)
- `int computeFact(int n);`  for actually computing a factorial

Like any program, the two major steps in writing this code will be:
- [Pseudocode](http://www.unf.edu/~broggio/cop2221/2221pseu.htm) 
- C++ translation (from pseudocode)

And footnotes for the C++ translation are included (to explain hairy parts).

### Pseudocode

As all awesome programmers do, let's write up some 
[pseudocode](http://www.unf.edu/~broggio/cop2221/2221pseu.htm) first. That way, it's easier to plan 
code, to correct mistakes, and make __more better__ code in general.

Below is my (messy) pseudocode for this problem:

__getFactorial__:
```
int getFactorial(int n):
    if n is 0 or n is 1: (this is our simple case which doesn't need any real computation)
        return 1
    else:
        set an integer (fact) equal to memoFact(n)
        return fact
```

__memoFact__:
```
int memoFact(int n):

    create a static list for storing n and its factorial (n_list and fact_list, which are parallel)
    
    set a boolean found_fact to false
    
    create an integer return_fact, for returning n!
        
    create a static integer next_index for keeping track of the next index to replace
    
    check n_list if n exists in the list:
        if n is in n_list:
            return_fact = the corresponding position in fact_list
            found_fact = true
            break out of the for loop
    
    if found_fact is false:
        return_fact = computeFact(n)
        replace the oldest n and corresponding n! in n_list and fact_list with n and return_fact
        
    return return_fact;
```

__computeFact__:
```
int computeFact(int n):
    set integer fact to 1
    
    while n is greater than 1
        fact = fact * n
        decrement n
    
    return fact
```

Take a few moments to go over the above and make sure it makes sense. Although pseudocode is mostly
English, I'm not necessarily the best English speaker (then again, who is?).

### C++ Translation

After the hard work of creating our pseudocode, we now translate the above to valid C++ syntax:

__ISSUE__: Unfortunately for us, pseudocode to C++ translation is very unlikely to be 1 to 1. This means 
           there is a high chance a C++ representation requires more lines than the pseudocode version 
           (or, rarely, the other way around).

__NOTE__: I will try to find a way to include color coding. For now, you'll have to guess which 
      portions of the C++ code matches the pseudocode (it shouldn't be too hard, hopefully).
      
      
__getFactorial__:
```C++
int getFactorial(int n)
{
  if(n == 0 || n == 1)
  {
    return 1;
  }
  else                       // READ FOOTNOTE #1:
  {
    int fact = memoFact(n);  // get n! (how fast this works depends on if n! is saved in memoFact)
    return fact;
  }
}
```

__memoFact__:
```C++
int memoFact(int n)
{
  const int MAX_STORAGE = 3;         // READ FOOTNOTE #2
  
  static int n_list[MAX_STORAGE],    // holds n values  (parallel to fact_list)
             fact_list[MAX_STORAGE]; // holds n! values ("                   ")
  
  int return_fact;                   // factorial value to be returned (i.e. return_fact = n!)
  
  static int real_count = 0,         // actual number of stored factorials (can be < MAX_STORAGE)
             next_index = 0;         // holds index to place next-computed factorials in later 
                                     // function calls
  
  bool found_fact = false;           // for checking if n! was found in the storage lists
  
  for(int i = 0; i < real_count; ++i)  // check list for 
  {
    if(n == n_list[i])                 // if n value was already computed
    {
      return_fact = fact_list[i];      // get corresponding n!
      found_fact = true;               // mark flag to true
      break;                           // no need to check rest of list so escape the for-loop
    }
  }
  
  if(!found_fact)                    // if we unfortunately did not find the factorial in the list
  {
    int new_index = next_index;            // new_index is the index we plan to store n and n! at
    next_index++;                          // move next_index forward (to get to next oldest spot) 
    next_index %= MAX_STORAGE;             // READ FOOTNOTE #3
    
    return_fact = computeFactorial(n);     // get n!
    fact_list[new_index] = return_fact;    // store n! into the factorial list
    n_list[new_index] = n;                 // store corresponding n value in the n-value list
  }
  
  return return_fact;                // return the factorial the user requested (from getFactorial)
}
```

__computeFact__:
```C++
int computeFact(int n)
{
  int fact = 1;
  while(n > 1)
  {
    fact*=n;
    n--; // this is by-value so n will not be affected outside this function
  }
  
  return fact;
}
```

That's all there is to it.


#### Footnotes

Below are the list of footnotes I mentioned in the C++ translation section.

__FOOTNOTE #1__:

  If we wanted to, we could do one of two things:
  
  1. Make more if-checks for small factorial values (e.g. 2! = 2, 3! = 6, etc.) to improve 
       computation time
       
  2. Replace getFactorial with the following:
     
     ```C++
     int getFactorial(int n)
     {
       switch(n) // no need for breaks since the return escapes the function immediately)
       {
         case 0: // fall-through to case 1
         case 1: return 1;
         case 2: return 2;
         case 3: return 6;
         //...any more factorial values we want to insert ourselves...
         default: return memoFact(n); // for all factorial values we don't want to compute
       }
     }
     ```
         
__FOOTNOTE #2__:

  `MAX_STORAGE` is an arbitrary value and is determined by testing. It represents the maximum number of 
  factorial values you wish to store.
  
  If we have a large value for `MAX_STORAGE`, over time checking to see if a factorial has been 
  computed already will eventually take more time than actually computing the factorial!
  
  For instance, assume `MAX_STORAGE` is 40 and we've computed every factorial except 2!. To compute 
  2!, our program would take...
  ```
    num_steps = num_steps_to_check_storage_list + num_steps_compute_factorial    
    num_steps = 40 + 2 = 42
  ```      
  Which is a heck of a lot more than the two steps originally needed to compute 2!.
  
__FOOTNOTE #3__:
  
  __FIRSTMOST__: To best explain this, assume in the below that `MAX_STORAGE = 3`.
  
  This is a bit of a cool trick, and what it is doing is resetting `next_index` for later usage. It 
  makes `next_index` equal to either 0, 1, or 2, depending on what its value is currently. It 
  resets every time `next_index` reaches `MAX_STORAGE`.
  
  Three things to recall (before my explanation of how this works):
  
  1. The number of indexes in each list is `MAX_STORAGE`
  2. `next_index %= MAX_STORAGE` means `next_index = next_index % MAX_STORAGE`.
  3. The valid indexes for an array of size 3 are 0, 1, or 2.
  
  Now, for a visual and step-by-step explanation (step 4 does the reset):
  
  ```
    Assume memoFact is called with n-values 3, 4, 3, 5, 6, and 7 (in order presented)
  
    FIRST STEP:  n = 3, we have next_index = 0. Since !found, after the if-check we have:
    
    n_list    = [3, 0, 0] (uninitialized values in an int array are on default 0)
    fact_list = [6, 0, 0] ("                                                   ")
    next_index++;                          (this is 0+1 which makes next_index = 1)
    next_index = next_index % MAX_STORAGE; (this is 1 % 3 which makes next_index = 1)
    
    SECOND STEP: n = 4. Not stored and next_index = 1. Since !found again, we have:
    
    n_list    = [3, 4, 0] 
    fact_list = [6, 24, 0] 
    next_index++;                          (this is 1+1 which makes next_index = 2)
    next_index = next_index % MAX_STORAGE; (this is 2 % 3 which makes next_index = 2)
    
    THIRD STEP:  n = 3. This is already stored so no changes to lists and next_index are made.
    
    FOURTH STEP: n = 5, which is not stored. next_index = 2 and after the !found if-check we have:
    
    n_list    = [3, 4, 5] 
    fact_list = [6, 24, 120] 
    next_index++;                          (this is 2+1 which makes next_index = 3)
    next_index = next_index % MAX_STORAGE; (this is 3 % 3 which makes next_index = 0; RESET HERE!)
    
    FIFTH STEP: n = 6, which is not stored. next_index = 0, and following the same pattern we get:
    
    n_list    = [6, 4, 5] 
    fact_list = [720, 24, 120] 
    next_index++;                          (this is 0+1 which makes next_index = 1)
    next_index = next_index % MAX_STORAGE; (this is 1 % 3 which makes next_index = 1)
    
    SIXTH STEP: n = 7. This is not stored, next_index = 1, and following the same pattern we get:
    
    n_list    = [6, 7, 5] 
    fact_list = [720, 5040, 120] 
    next_index++;                          (this is 1+1 which makes next_index = 2)
    next_index = next_index % MAX_STORAGE; (this is 2 % 3 which makes next_index = 2)
    
    From here on we get a repeat. If we had a seventh n-value which was not 5, 6, or 7, we would 
    replace index 2 in n_list and fact_list, then reset next_index (like in step 4).
    
  ```
  
  Hopefully this all helps. I know the above is a lot, but with practice and effort you'll be making 
  awesome code (for both yourself and others).

-------------------------------------------------------------------------------

Copyright &copy; 2015 Joseph Greene <joeisgreene@csu.fullerton.edu>  
Released under [The MIT License] (http://opensource.org/licenses/MIT)  
Project located at <https://github.com/joegreene/2015-Spring-CS-121>
