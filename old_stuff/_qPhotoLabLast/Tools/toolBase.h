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
#include "qLib.h"
#include "defsPl.h"

using namespace qLib;


/*******************************************************************************
* forward
*******************************************************************************/
class ViewBase;


/*******************************************************************************
* class ToolBase
*******************************************************************************/
class ToolBase : public qTool
{
    private:
        qVector2D<s32>  m_v2dMoveStart_pic;

        // xor-member
        qVector2D<s32>  m_v2dMoveStart;

    protected:
        ToolBase(ViewBase   *_pOwnerView,
                 u32        _u32ToolId,
                 u64        _u64ToolBaseFunction);

        ViewBase*                   OwnerView() const;
        shared_ptr<qLayerStack>     OwnerLS() const;

        void                        SetZoomFactorFit() const;
        void                        SetZoomFactor1() const;
        void                        SetZoomFactor2() const;

    private:
        void                        DrawSections() const;
        void                        DrawSectionsHalfCut() const;
        void                        DrawSectionsThirdCut() const;
        void                        DrawSectionsGoldenCut() const;
        void                        DrawSectionsGoldenCoil() const;

    public:
        virtual ~ToolBase();


    /*******************************************************************************
    * qTool interface
    *******************************************************************************/
    protected:
        virtual void                OnSetCursor() override;
        virtual void                OnPaintToolMarker() override;

        virtual enumToolResult      OnWheel(u32                     _u32Modifiers,
                                            s32                     _s32Degree,
                                            const qVector2D<s32>    &_v2dLocal,
                                            const qVector2D<s32>    &_v2dGlobal) override;

        virtual enumToolResult      OnLMousePress(u32                   _u32Modifiers,
                                                  const qVector2D<s32>  &_v2dLocal,
                                                  const qVector2D<s32>  &_v2dGlobal) override;

        virtual enumToolResult      OnLMouseMove(u32                    _u32Modifiers,
                                                 const qVector2D<s32>   &_v2dLocal,
                                                 const qVector2D<s32>   &_v2dGlobal) override;

        virtual enumToolResult      OnLMouseRelease(u32                     _u32Modifiers,
                                                    const qVector2D<s32>    &_v2dLocal,
                                                    const qVector2D<s32>    &_v2dGlobal) override;

        virtual enumToolResult      OnMMousePress(u32                   _u32Modifiers,
                                                  const qVector2D<s32>  &_v2dLocal,
                                                  const qVector2D<s32>  &_v2dGlobal) override;

        virtual enumToolResult      OnMMouseMove(u32                    _u32Modifiers,
                                                 const qVector2D<s32>   &_v2dLocal,
                                                 const qVector2D<s32>   &_v2dGlobal) override;

        virtual enumToolResult      OnMMouseRelease(u32                     _u32Modifiers,
                                                    const qVector2D<s32>    &_v2dLocal,
                                                    const qVector2D<s32>    &_v2dGlobal) override;
}; // class ToolBase
