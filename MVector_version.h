/***************************************************************************
 *
 * Copyright Crown (c) 2012. All rights reserved.
 *
 * Module: MVector_version.h
 *
 * Description: Mathmatical Vector code version control file
 *
 * Original Author: Darren Muff
 *
 * CLASSIFICATION        :  UNCLASSIFIED
 * Date of CLASSN        :  3rd April 2012
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * THE SOFTWARE IN ITS ENTIRETY OR ANY SUBSTANTIAL PORTION SHOULD NOT BE
 * USED AS A WHOLE OR COMPONENT PART OF DERIVATIVE SOFTWARE THAT IS BEING
 * SOLD TO THE GOVERNMENT OF THE UNITED KINGDOM OF GREAT BRITAIN AND NORTHERN
 * IRELAND.
 *
 ***************************************************************************/


#ifndef MVECTOR_VERSION_MAJOR
#  define MVECTOR_VERSION_MAJOR    2
#  define MVECTOR_VERSION_MINOR    2
#  define MVECTOR_VERSION_REV      1
#  define MVECTOR_VERSION_BUILD    0
#endif

#ifndef MVECTOR_VERSION_NUM
#  define MVECTOR_VERSION_NUM      (MVECTOR_VERSION_MAJOR*1000+MVECTOR_VERSION_MINOR*100+MVECTOR_VERSION_REV*10+MVECTOR_VERSION_BUILD)
#endif

#ifndef MVECTOR_RELEASE_DATE
#  define MVECTOR_RELEASE_DATE     201205117
#endif
#ifndef MVECTOR_RELEASE_NAME
#  define MVECTOR_RELEASE_NAME     "2.2.1"
#endif
