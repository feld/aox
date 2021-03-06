// Copyright 2009 The Archiveopteryx Developers <info@aox.org>

#ifndef GLOBAL_H
#define GLOBAL_H

#include <stddef.h>

//#define shared_ptr P
//#define weak_ptr W
//#include <boost/shared_ptr.hpp>
//#include <boost/weak_ptr.hpp>
//#undef shared_ptr
//#undef weak_ptr

#if !defined(U32_MAX)
#define U32_MAX (0xffffffffU)
#endif

#if !defined(UINT_MAX)
#define UINT_MAX ((uint)~0)
#endif

#if !defined(INT_MAX)
#define INT_MAX 0x7fffffff
#endif

typedef short int int16;
typedef unsigned int uint;
typedef unsigned int uint32;
typedef unsigned short ushort;
typedef long long int int64;

enum Exception {
    Invariant,
    Memory,
    FD
};

void die( Exception );


class Garbage
{
public:
    Garbage() {}

    void *operator new( size_t );
    void *operator new[]( size_t );
    void operator delete( void * );
    void operator delete[]( void * );

    void setFirstNonPointer( const void * ) const;
};

#endif
