/* emacs edit mode for this file is -*- C++ -*- */
/* $Id: ftest_io.cc,v 1.11 1998-03-11 16:10:54 schmidt Exp $ */

//{{{ docu
//
// ftest_io.cc - io utilities for the factory test environment.
//
//}}}

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <iostream.h>
#include <strstream.h>

#include <factory.h>

#include "ftest_util.h"

//
// - external functions.
//

//{{{ CanonicalForm ftestGetCanonicalForm ( const char * canFormSpec )
//{{{ docu
//
// ftestGetCanonicalForm() - read a canonical form from canFormSpec,
//   return it.
//
//}}}
CanonicalForm
ftestGetCanonicalForm ( const char * canFormSpec )
{
    const char * stringF = canFormSpec;
    stringF = ftestSkipBlancs( stringF );
    if ( *stringF == '<' ) {
	CanonicalForm f;
	
	stringF++;
	if ( *stringF == '-' ) {
	    // read canonical form from stdin
	    cin >> f;
	} else
	    ftestError( CanFormSpecError,
			"not a valid canonical form specification `<%s'\n",
			stringF );
	return f;
    } else {
	// get string to read canonical form from
	if ( *stringF == '$' ) {
	    const char * tokenCursor = ftestSkipBlancs( stringF+1 );
	    // read canonical form from environment
	    stringF = getenv( tokenCursor );
	    if ( ! stringF )
		ftestError( CanFormSpecError,
			    "no environment variable `$%s' set\n",
			    tokenCursor );
	}

	// create terminated CanonicalForm
	int i = strlen( stringF );
	char * terminatedStringF = new char[i+2];
	char * stringCursor = terminatedStringF;
	while ( *stringF ) {
	    switch ( *stringF ) {
	    case '.': *stringCursor = '*'; break;
	    case '{': *stringCursor = '('; break;
	    case '}': *stringCursor = ')'; break;
	    default: *stringCursor = *stringF; break;
	    }
	    stringF++; stringCursor++;
	}
	*stringCursor++ = ';';
	*stringCursor = '\0';

	// read f and return it
	CanonicalForm f;
	istrstream( terminatedStringF ) >> f;
	delete [] terminatedStringF;
	return f;
    }
}
//}}}

//{{{ Variable ftestGetVariable ( const char * stringVariable )
//{{{ docu
//
// ftestGetVariable() - read a variable from stringVariable,
//   return it.
//
//}}}
Variable
ftestGetVariable ( const char * stringVariable )
{
    Variable v;
    stringVariable = ftestSkipBlancs( stringVariable );

    if ( isalpha( *stringVariable ) )
	v = Variable( *stringVariable );
    else if ( isdigit( *stringVariable ) )
	v = Variable();
    else
	ftestError( CommandlineError,
		    "variable expected at `%s'\n", stringVariable );

    stringVariable = ftestSkipBlancs( stringVariable+1 );
    if ( *stringVariable )
	ftestError( CommandlineError,
		    "extra characters after var spec `%s'\n", stringVariable );

    return v;
}
//}}}

//{{{ int ftestGetint ( const char * stringInt )
//{{{ docu
//
// ftestGetint() - read an integer from stringInt,
//   return it.
//
//}}}
int
ftestGetint ( const char * stringInt )
{
    const char * tokenCursor;

    int i = (int)strtol( stringInt, (char**)&tokenCursor, 0 );

    // do error checks
    if ( stringInt == tokenCursor )
	ftestError( CommandlineError,
		    "integer expected at `%s'\n", stringInt );

    stringInt = ftestSkipBlancs( tokenCursor );
    if ( *stringInt )
	ftestError( CommandlineError,
		    "extra characters after int spec `%s'\n", stringInt );

    return i;
}
//}}}

//{{{ bool ftestGetbool ( const char * stringBool )
//{{{ docu
//
// ftestGetbool() - read an boolean from stringBool,
//   return it.
//
//}}}
bool
ftestGetbool ( const char * stringBool )
{
    const char * tokenCursor;

    bool b;
    // skip blancs
    stringBool = ftestSkipBlancs( stringBool );

    // look for "true" or "false"
    tokenCursor = ftestSubStr( "true", stringBool );
    if ( stringBool != tokenCursor )
	b = true;
    else {
	tokenCursor = ftestSubStr( "false", stringBool );
	b = false;
    }

    // do error checks
    if ( stringBool == tokenCursor )
	ftestError( CommandlineError,
		    "bool expected at `%s'\n", stringBool );

    // check for extra characters
    stringBool = ftestSkipBlancs( tokenCursor );
    if ( *stringBool )
	ftestError( CommandlineError,
		    "extra characters after bool spec `%s'\n", stringBool );

    return b;
}
//}}}

//{{{ void ftestPrintResult ( const char * resultName, const CanonicalForm & result )
//{{{ docu
//
// ftestPrintResult() - print a canonical form.
//
//}}}
void
ftestPrintResult ( const char * resultName, const CanonicalForm & result )
{
    if ( ftestPrintResultFlag ) {
	cout << "Result:\t\t" << resultName << ":" << endl;
	cout << result << endl;
    } else if ( ! ftestPrintFlag )
	cout << "(" << result << ")" << endl;
}
//}}}

//{{{ void ftestPrintResult ( const char * resultName, const CFFList & result )
//{{{ docu
//
// ftestPrintResult() - print a list of canonical form factors
//
//}}}
void
ftestPrintResult ( const char * resultName, const CFFList & result )
{
    CFFListIterator I;

    if ( ftestPrintResultFlag ) {
	cout << "Result:\t\t" << resultName << ":" << endl;
	for ( I = result; I.hasItem(); I++ )
	    cout << I.getItem() << endl;
    } else if ( ! ftestPrintFlag )
	for ( I = result; I.hasItem(); I++ )
	    cout << "(" << I.getItem() << ")" << endl;
}
//}}}

//{{{ void ftestPrintResult ( const char * resultName, const int result )
//{{{ docu
//
// ftestPrintResult() - print an integer.
//
//}}}
void
ftestPrintResult ( const char * resultName, const int result )
{
    if ( ftestPrintResultFlag )
	cout << "Result:\t\t" << resultName << ": " << result << endl;
    else if ( ! ftestPrintFlag )
	cout << result << endl;
}
//}}}
