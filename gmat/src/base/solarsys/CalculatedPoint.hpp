//$Id: CalculatedPoint.hpp 11945 2013-06-14 14:21:07Z wendys-dev $
//------------------------------------------------------------------------------
//                                  CalculatedPoint
//------------------------------------------------------------------------------
// GMAT: General Mission Analysis Tool.
//
// Copyright (c) 2002-2011 United States Government as represented by the
// Administrator of The National Aeronautics and Space Administration.
// All Other Rights Reserved.
//
// Developed jointly by NASA/GSFC and Thinking Systems, Inc. under contract
// number S-67573-G
//
// Author: Wendy C. Shoan
// Created: 2005.04.01 (no foolin')
//
/**
 * This is the base class for calculated points.
 *
 * @note This is an abstract class.
 */
//------------------------------------------------------------------------------

#ifndef CalculatedPoint_hpp
#define CalculatedPoint_hpp

#include "gmatdefs.hpp"
#include "GmatBase.hpp"
#include "SpacePoint.hpp"
#include "A1Mjd.hpp"
#include "Rmatrix.hpp"
#include "Rvector6.hpp"
#include "TimeTypes.hpp"

/**
 * CalculatedPoint base class, from which all types of calculated points 
 * will derive.
 *
 * The CalculatedPoint class is primarily an intermediate base class, from which
 * all types of calculated points will derive.  CalculatedPoint itself derives 
 * from SpacePoint.
 *
 * @note Bodies are set on a(n) (sub)object of this class via the SetRefObject
 *       method.
 */
class GMAT_API CalculatedPoint : public SpacePoint
{
public:
   // default constructor, specifying calculated point type and name
   CalculatedPoint(const std::string &ptType = "LibrationPoint", 
                   const std::string &itsName = "");
   // copy constructor
   CalculatedPoint(const CalculatedPoint &cp);
   // operator=
   CalculatedPoint& operator=(const CalculatedPoint &cp);
   // destructor
   virtual ~CalculatedPoint();
   
   virtual bool         IsBuiltIn();
   virtual void         SetIsBuiltIn(bool builtIn, const std::string &ofType);
   virtual StringArray  GetBuiltInNames() = 0;

   virtual Real         GetEpoch();
   virtual Real         SetEpoch(const Real ep);
   virtual Rvector6     GetLastState();

   // methods inherited from SpacePoint, that must be implemented
   // in the derived classes
   //virtual const Rvector6           GetMJ2000State(const A1Mjd &atTime);
   //virtual const Rvector3           GetMJ2000Position(const A1Mjd &atTime);
   //virtual const Rvector3           GetMJ2000Velocity(const A1Mjd &atTime);   
   
   // Parameter access methods - overridden from GmatBase
   virtual std::string  GetParameterText(const Integer id) const;
   virtual Integer      GetParameterID(const std::string &str) const; 
   virtual Gmat::ParameterType 
                        GetParameterType(const Integer id) const;
   virtual std::string  GetParameterTypeString(const Integer id) const;
   virtual bool         IsParameterReadOnly(const Integer id) const;
   virtual bool         IsParameterReadOnly(const std::string &label) const;
   
   virtual Integer      GetIntegerParameter(const Integer id) const;
   virtual Integer      GetIntegerParameter(const std::string &label) const;
   virtual Real         GetRealParameter(const Integer id) const;
   virtual Real         SetRealParameter(const Integer id,
                                      const Real value);
   virtual Real         GetRealParameter(const std::string &label) const;
   virtual Real         SetRealParameter(const std::string &label,
                                      const Real value);
   virtual std::string  GetStringParameter(const Integer id) const;
   virtual std::string  GetStringParameter(const Integer id,
                                           const Integer index) const;
   virtual std::string  GetStringParameter(const std::string &label,
                                           const Integer index) const;
   virtual bool         SetStringParameter(const Integer id, 
                                           const std::string &value);
   virtual bool         SetStringParameter(const std::string &label, 
                                           const std::string &value);
   virtual bool         SetStringParameter(const Integer id, 
                                           const std::string &value,
                                           const Integer index);
   virtual bool         SetStringParameter(const std::string &label, 
                                           const std::string &value,
                                           const Integer index);
   
   virtual const StringArray&  
                        GetStringArrayParameter(const Integer id) const;
   virtual const StringArray&  
                        GetStringArrayParameter(const std::string &label) const;
   virtual GmatBase*    GetRefObject(const Gmat::ObjectType type,
                                     const std::string &name,
                                     const Integer index);
   virtual bool         SetRefObject(GmatBase *obj, 
                                     const Gmat::ObjectType type,
                                     const std::string &name = "");
   virtual bool         RenameRefObject(const Gmat::ObjectType type,
                                        const std::string &oldName,
                                        const std::string &newName);
   virtual bool         HasRefObjectTypeArray();
   virtual const ObjectTypeArray&
                        GetRefObjectTypeArray();
   virtual const StringArray& 
                        GetRefObjectNameArray(const Gmat::ObjectType type);
   virtual bool         TakeAction(const std::string &action,  
                                   const std::string &actionData = "");
   virtual bool         TakeRequiredAction(const Integer id);

   
   virtual void         SetDefaultBody(const std::string &defBody);
   virtual const StringArray&
                        GetDefaultBodies() const;

   DEFAULT_TO_NO_CLONES

protected:
   
   enum
   {
      NUMBER_OF_BODIES = SpacePointParamCount, 
      BODY_NAMES,
      CalculatedPointParamCount
   };
   
   static const std::string
      PARAMETER_TEXT[CalculatedPointParamCount - SpacePointParamCount];
   static const Gmat::ParameterType
      PARAMETER_TYPE[CalculatedPointParamCount - SpacePointParamCount];
   
   /// number of bodies
   Integer                  numberOfBodies;
   /// list of bodies
   std::vector<SpacePoint*> bodyList;
   /// list of body names
   StringArray              bodyNames;

   // names of the default bodies to use
   StringArray              defaultBodies;

   /// flag indicating whether or not this is a built-in CalculatedPoint
   bool                        isBuiltIn;
   std::string                 builtInType;

   A1Mjd                       lastStateTime;
   Rvector6                    lastState;

   bool ValidateBodyName(const std::string &itsName, bool addToList = true, bool addToEnd = true, Integer index = 0);
    
private:
      
   //------------------------------------------------------------------------------
   //  void CheckBodies()
   //------------------------------------------------------------------------------
   /**
    * Abstract method for derived classes that checks to make sure the bodyList has
    * been defined appropriately (i.e. all are of a type that makes sense).
    *
    */
    //------------------------------------------------------------------------------
   virtual void CheckBodies() = 0;
};
#endif // CalculatedPoint_hpp

