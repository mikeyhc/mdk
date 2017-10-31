# Overview

K supports 4 "types", some of which have subtypes. These are
  * atom
    * name / symbol
    * character
    * int
    * float
  * list
    * vector
    * general
  * dict
  * func (NOTE: need to define a func header)

# Representation

Types are determined by the bit pattern in the LSB of a value.

## atom

If the LSB of a value is 1 then that value is an atom i.e.
```
xxxxx1
```

### name / symbol

A name has a bit pattern of
```
xx001
```
The remaining bits are a pointer to a character array. (Might find a way to
share these later in a symbol table)

### character

A character has a bit pattern of
```
xx011
```
The next 8 LSB (12-4) are the character (remaining bits unused)

### int

A int has a bit pattern of
```
xx101
```
The remaining bits are the integer (this gives int's the systems pointer size
minus - 3 width)

### float

A float has a bit pattern of
```
xx111
```
The remaining bits are the floats (this gives floats's the systems pointer size
minus - 3 width)

## list

### vector

A vector has a bit pattern
```
00xx0
```
Where the xx is the atomic type of the elements in the vector, the remaining
bits are a pointer to the vector

### general

A general list has a bit pattern of
```
01xx0
```
The remaining bits are a pointer to the general list

## dict

A dict has a bit pattern of
```
10xx0
```
The remaining bits point to a pair of lists (either vector or general)

## func

A function has a bit pattern of
```
11xx0
```
The remaining bits point to a function header
