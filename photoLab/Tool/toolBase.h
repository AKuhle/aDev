/*******************************************************************************
* \file ToolBase.h
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
#include "aLib_def.h"

#include "aToolBase.h"
#include "aVector2D.h"

#include "viewBase.h"
#include "editScrollWin.h"

using namespace aLib;
using namespace aLib::aMath;
using namespace aLib::aWin;


/*******************************************************************************
* class ToolBase
*******************************************************************************/
class ToolBase : public aToolBase
{
    private:
        // aVector2D<s32>  m_v2dMoveStart_pic;

        // xor-member
        // aVector2D<s32>  m_v2dMoveStart;

    protected:
        ToolBase(ViewBase   *_pOwnerView,
                 u32        _u32ToolId,
                 u64        _u64ToolBaseFunction);

        ViewBase*                   ownerView() const;
        // EditScrollWin*              ownerScrollWin() const;
        // aMdiWin*                    ownerMdiWin() const;
        // shared_ptr<qLayerStack>     OwnerLS() const;

        // e.g. wheel cannot be handled, if the owner doesn't hav the focus
        bool                        canHandleEvent() const;

        // void                        SetZoomFactorFit() const;
        // void                        SetZoomFactor1() const;
        // void                        SetZoomFactor2() const;

    private:
        // void                        DrawSectionsHalfCut() const;
        // void                        DrawSectionsThirdCut() const;
        // void                        DrawSectionsGoldenCut() const;
        // void                        DrawSectionsGoldenCoil() const;
        // void                        DrawSections() const;

    public:
        virtual ~ToolBase();


    /*******************************************************************************
    * aToolBase interface
    *******************************************************************************/
    protected:
        virtual enumToolResult      onWheel(u32                     _u32Modifiers,
                                            s32                     _s32Degree,
                                            const aVector2D<s32>    &_v2dLocal,
                                            const aVector2D<s32>    &_v2dGlobal) override;
}; // class ToolBase
