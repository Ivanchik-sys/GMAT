//$Id: BplaneParameters.hpp 9513 2011-04-30 21:23:06Z djcinsb $
//------------------------------------------------------------------------------
//                             File: BplaneParameters.hpp
//------------------------------------------------------------------------------
// GMAT: General Mission Analysis Tool
//
// Copyright (c) 2002-2011 United States Government as represented by the
// Administrator of The National Aeronautics and Space Administration.
// All Other Rights Reserved.
//
// Developed jointly by NASA/GSFC and Thinking Systems, Inc. under contract
// number S-67573-G
//
// Author: Linda Jun
// Created: 2005/06/15
//
/**
 * Declares B-Plane related parameter classes.
 *   BdotT, BdotR, BVectorMag, BVectorAngle
 *
 */
//------------------------------------------------------------------------------
#ifndef BplaneParameters_hpp
#define BplaneParameters_hpp

#include "BplaneReal.hpp"


//==============================================================================
//                              BdotT
//==============================================================================
/**
 * Declares B dot T class.
 */
//------------------------------------------------------------------------------

class GMAT_API BdotT : public BplaneReal
{
public:

   BdotT(const std::string &name = "", GmatBase *obj = NULL);
   BdotT(const BdotT &copy);
   const BdotT& operator=(const BdotT &right);
   virtual ~BdotT();
   
   // The inherited methods from Parameter
   virtual bool Evaluate();
   
   // methods inherited from GmatBase
   virtual GmatBase* Clone(void) const;
   
protected:

};


//==============================================================================
//                              BdotR
//==============================================================================
/**
 * Declares BdotR class.
 */
//------------------------------------------------------------------------------

class GMAT_API BdotR : public BplaneReal
{
public:

   BdotR(const std::string &name = "", GmatBase *obj = NULL);
   BdotR(const BdotR &copy);
   const BdotR& operator=(const BdotR &right);
   virtual ~BdotR();
   
   // The inherited methods from Parameter
   virtual bool Evaluate();
   
   // methods inherited from GmatBase
   virtual GmatBase* Clone(void) const;
   
protected:

};


//==============================================================================
//                              BVectorMag
//==============================================================================
/**
 * Declares BVectorMag class.
 */
//------------------------------------------------------------------------------

class GMAT_API BVectorMag : public BplaneReal
{
public:

   BVectorMag(const std::string &name = "", GmatBase *obj = NULL);
   BVectorMag(const BVectorMag &copy);
   const BVectorMag& operator=(const BVectorMag &right);
   virtual ~BVectorMag();
   
   // The inherited methods from Parameter
   virtual bool Evaluate();
   
   // methods inherited from GmatBase
   virtual GmatBase* Clone(void) const;
   
protected:

};


//==============================================================================
//                              BVectorAngle
//==============================================================================
/**
 * Declares BVectorAngle class.
 */
//------------------------------------------------------------------------------

class GMAT_API BVectorAngle : public BplaneReal
{
public:

   BVectorAngle(const std::string &name = "", GmatBase *obj = NULL);
   BVectorAngle(const BVectorAngle &copy);
   const BVectorAngle& operator=(const BVectorAngle &right);
   virtual ~BVectorAngle();
   
   // The inherited methods from Parameter
   virtual bool Evaluate();
   
   // methods inherited from GmatBase
   virtual GmatBase* Clone(void) const;
   
protected:

};

#endif // BplaneParameters_hpp
