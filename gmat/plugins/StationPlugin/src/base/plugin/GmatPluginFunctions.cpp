//$Id: GmatPluginFunctions.cpp 11219 2013-01-14 18:42:58Z djcinsb $
//------------------------------------------------------------------------------
//                            GmatPluginFunctions
//------------------------------------------------------------------------------
// GMAT: General Mission Analysis Tool
//
// Copyright (c) 2002-2011 United States Government as represented by the
// Administrator of The National Aeronautics and Space Administration.
// All Other Rights Reserved.
//
// Developed jointly by NASA/GSFC and Thinking Systems, Inc. under the FDSS 
// contract, Task Order 28.
//
// Author: Darrel J. Conway, Thinking Systems, Inc.
// Created: January 10, 2013
//
/**
 * Implementation for library code interfaces.
 * 
 * This is prototype code.
 */
//------------------------------------------------------------------------------

#include "GmatPluginFunctions.hpp"
#include "MessageInterface.hpp"

// Modify this line to match your factory list:
#include "StationFactory.hpp"

extern "C"
{
   //------------------------------------------------------------------------------
   // Integer GetFactoryCount()
   //------------------------------------------------------------------------------
   /**
    * Returns the number of plug-in factories in this module
    *
    * @return The number of factories
    */
   //------------------------------------------------------------------------------
   Integer GetFactoryCount()
   {
      // Update this line with the total number of factories you support:
      return 1;
   }
   
   //------------------------------------------------------------------------------
   // Factory* GetFactoryPointer(Integer index)
   //------------------------------------------------------------------------------
   /**
    * Retrieves a pointer to a specific factory
    *
    * @param index The index to the Factory
    *
    * @return The Factory pointer
    */
   //------------------------------------------------------------------------------
   Factory* GetFactoryPointer(Integer index)
   {
      Factory* factory = NULL;

	  // Update this code with your factories, one index per factory
      switch (index)
      {
         case 0:
            factory = new StationFactory;
            break;
            
         default:
            break;
      }

      return factory;
   }
   
   //------------------------------------------------------------------------------
   // void SetMessageReceiver(MessageReceiver* mr)
   //------------------------------------------------------------------------------
   /**
    * Sets the messaging interface used for GMAT messages
    *
    * @param mr The message receiver
	*
	* @note This function is deprecaged, and may not be needed in future builds
    */
   //------------------------------------------------------------------------------
   void SetMessageReceiver(MessageReceiver* mr)
   {
      MessageInterface::SetMessageReceiver(mr);
   }
};