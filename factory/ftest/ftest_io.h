/* emacs edit mode for this file is -*- C++ -*- */
/* $Id: ftest_io.h,v 1.6 1998-03-11 16:11:01 schmidt Exp $ */

#ifndef INCL_FTEST_IO_H
#define INCL_FTEST_IO_H

//{{{ docu
//
// ftest_io.h - header to ftest_io.cc.
//
//}}}

#include <factory.h>

CanonicalForm ftestGetCanonicalForm ( const char * canFormSpec );
Variable ftestGetVariable ( const char * stringVariable );
int ftestGetint ( const char * stringInt );
bool ftestGetbool ( const char * stringBool );

void ftestPrintResult ( const char * resultName, const CanonicalForm & result );
void ftestPrintResult ( const char * resultName, const CFFList & result );
void ftestPrintResult ( const char * resultName, const int result );

#endif /* ! INCL_FTEST_IO_H */
