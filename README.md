# animal-park-project-cplusplus

Wrote a set of 7 functions in C++ in the file animalpark.cpp to check the validity of and process C++ strings containing information about animals and people leaving/entering a park.

**The aims of the project:**

1. To check the validity of the strings and process the strings
2. To calculate the new state of animals and people in the park after the string was processed

**Specifications to note:**<br/>

- The animal park starts out empty. No humans, dogs or cats.<br/>
- The animal park has no memory beyond the processing of one animal park string:<br/>
  This means, each time a new animal park string is called by the set of 7 functions, the number of humans, dogs and cats in the park is reset to zero before the number of humans, dogs, and cats in the new animal park string is counted to produce the new number of humans, dogs, and cats in the park.

- The string can only contain the characters:<br/>

  - 'C', 'c', 'D', 'd', 'P', 'p', '+', '-', <br/>
    Where:<br/>
    "C" represents an adult cat,<br/>
    "c" represents a kitten,<br/>
    "D" represents an adult dog,<br/>
    "d" represents a puppy,<br/>
    "P" represents an adult person,<br/>
    "p" represents a child

- The string must be a collection of smaller substrings representing a group of people and animals<br/>
  Each of these smaller substrings must be separated by a single + or - sign indicating whether that group of people and animals is entering or leaving the park respectively.<br/>

  - The format of each of these substrings must be of the form:<br/>
    - [Any number and ordering of adult and child persons][any number of (adult and child cats only) or (adult and child dogs only)]

- Other restrictions were:<br/>
  - Dogs and cats cannot be in the same group (substring)<br/>
    There must be both animals and humans in order for a group to enter the park (substrings with only animals or only humans are invalid).<br/>
    The substring must have all of its people characters come after all of its animal characters.<br/>
    Dogs and cats cannot be mixed in the same group.

**Examples of valid substrings would be:**<br/>

- ccCCccPpPP<br/>
  DDddDpPpp<br/>
  But not:<br/>
  cDp<br/>
  CdP<br/>
  cPPpcp<br/>
  dPdddDpppp<br/>

**Examples of valid overall animal park strings are:**<br/>

- ccCCccPpPP+DDddDpPpp<br/>
  but not:<br/>
  ccCCccPpPP++DDddDpPpp (there can only be one operator between 2 substrings)<br/>
  ccCCccPpPP+DDddDpPpp+ (cannot end with an operator)<br/>
  +ccCCccPpPP+DDddDpPpp (cannot start with an operator)

**The code also checked for these additional case scenarios :**<br/>

- Within the same overall string, the change in the number of adult dogs, puppies, adult cats, kittens, adult persons, and children caused by that overall string itself was always >= 0 <br/>
  The overall animal park string was not an empty string<br/>
  The overall animal park string cannot start or end with a + or -<br/>

**To achieve the aim of checking the validity of the strings according to the above restrictions,** I wrote the 3 functions:<br/>

```C++
    bool checkcharacters(string animalparkString);
    bool checkorder(string animalparkString);
    bool checklogic(string animalparkString);
```

**A fourth function** was written to call all of the above 3 functions in a single validity checking function:<br/>

```C++
    bool isValidAnimalParkString(string animalparkString);
```

**The remaining 3 functions**

- These were written to allow us to calculate the number of persons (total of adults and children), the number of dogs (total of adults and puppies), and the number of cats (total of adults and kittens) that were left in the park respectively after the overall animal park string was processed.<br/>

- The processing of the overall animal park string to acquire information on the new number of people, dogs and cats in the park is also done
  by these 3 remaining functions:<br/>

```C++
        int peopleLeft(string animalparkString);
        int dogsLeft(string animalparkString);
        int catsLeft(string animalparkString);
```
