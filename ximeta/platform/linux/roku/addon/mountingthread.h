/*
 -------------------------------------------------------------------------
 Copyright (c) 2002-2005, XIMETA, Inc., IRVINE, CA, USA.
 All rights reserved.

 LICENSE TERMS

 The free distribution and use of this software in both source and binary 
 form is allowed (with or without changes) provided that:

   1. distributions of this source code include the above copyright 
      notice, this list of conditions and the following disclaimer;

   2. distributions in binary form include the above copyright
      notice, this list of conditions and the following disclaimer
      in the documentation and/or other associated materials;

   3. the copyright holder's name is not used to endorse products 
      built using this software without specific written permission. 
      
 ALTERNATIVELY, provided that this notice is retained in full, this product
 may be distributed under the terms of the GNU General Public License (GPL),
 in which case the provisions of the GPL apply INSTEAD OF those given above.
 
 DISCLAIMER

 This software is provided 'as is' with no explcit or implied warranties
 in respect of any properties, including, but not limited to, correctness 
 and fitness for purpose.
 -------------------------------------------------------------------------
*/
#ifndef _MOUNTING_THREAD_
#define _MOUNTING_THREAD_

#include <string> 

#include "pthreadclass.h"
#include "defs.h"

class DeviceWidget;

class MountingThread : public PThreadClass
{
    int m_index;
    DeviceWidget* m_win;
public:    

    virtual bool Unmount();
    virtual bool UnregisterAll();
    virtual bool Enable(string serial);
    
    virtual void CreateNode(int slot);
    
    virtual void run();
    
    virtual void start(DeviceWidget* win, int index) 
    {
        m_win = win;
        m_index = index;
        PThreadClass::start();
    }
};

#endif