/*******************************************************************************
* \file aLayerStack.h
* \author Andreas Kuhlewind
*
* \brief
*
* $Revision: 69 $
* $LastChangedDate: 2010-08-17 14:10:45 +0200 (Di, 17 Aug 2010) $
* $LastChangedBy: akuhlewi $
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once



/*******************************************************************************
* includes
*******************************************************************************/
#include "aUtil/Collection/aUniquePtrVec.h"
#include "aPic/qPicDefs.h"

#include "aLib_def.h"

#include "aUtil/aString.h"

#include "aMath/Obj2D/aDimension2D.h"

using namespace std;

using namespace aLib::aUtil;
using namespace aLib::aMath;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aPic {


/*******************************************************************************
* class aLayerStack
*******************************************************************************/
class aLayerStack :  public aUniquePtrVec<aLayerI>
{
    // front() is the background layer, which defines
    // the basic layerformat of this stack

    protected:
        enumLayerType       m_eType      { enumLayerType::None };
        aDimension2D<s32>   m_d2dDimension;
        aString             m_sName;   // e.g. the filename

    public:
        aLayerStack();
        //aLayerStack(const aLayerStack& _rhs);
        virtual ~aLayerStack();

        shared_ptr<aLayerStack>     createClone(bool    _bCopyImageData) const;

        shared_ptr<aLayerStack>     createClone(s32        _s32NewW,
                                                s32        _s32NewH) const;

        enumLayerType               type() const;
        void                        setType(enumLayerType  _eType);

        aDimension2D<s32>           dimension() const;
        void                        setDimension(const aDimension2D<s32> &_s2dDim);
        void                        setDimension(s32        _s32W,
                                                 s32        _s32H);

        s32                         w() const;
        s32                         h() const;

        aString                     name() const;
        void                        setName(const aString& _sName);

        bool                        isValid() const;

        void                        removeAllLayers();
        void                        addLayer(unique_ptr<aLayerI> _pLayer);
        //aLayerI*                    findLayer(u32   _u32LayerID);

    public:
        bool                        loadFromFile(const aString    &_sFileName);
                                                 //qProgress*         _pProgressCb = nullptr);
}; // class aLayerStack


} // namespace aPic
} // namespace aLib
