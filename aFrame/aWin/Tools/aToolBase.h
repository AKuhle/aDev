/*******************************************************************************
* \file qWin.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once

#ifdef _USE_QT_


/*******************************************************************************
* includes
*******************************************************************************/
#include "aFrame_def.h"
#include "aUtil_def.h"
#include "aWin_def.h"

using namespace aFrame;
using namespace aFrame::aUtil;
using namespace aFrame::aWin;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aToolBase
*******************************************************************************/
class aToolBase
{
    private:
        aBaseWin   *m_pOwner        { nullptr };
        u32        m_u32ToolId      { 0 };
        u32        m_u32Flags       { TF_NONE };


    /*******************************************************************************
    * con-/destruction
    *******************************************************************************/
    protected:
        aToolBase(aBaseWin   *_pOwner,
                  u32        _u32ToolId,
                  u32        _u32Flags       = TF_NONE);


    public:
        ~aToolBase();

        u32             toolId() const      { return m_u32ToolId; }
        aBaseWin*       ownerWin() const    { return m_pOwner; }


    public:
        virtual bool    onToolLDoubleClick(u16          _u16Modifier,
                                           const aPoint &_pntLocal,
                                           const aPoint &_pntGlobal);

        virtual bool    onToolMDoubleClick(u16          _u16Modifier,
                                           const aPoint &_pntLocal,
                                           const aPoint &_pntGlobal);

        virtual bool    onToolRDoubleClick(u16          _u16Modifier,
                                           const aPoint &_pntLocal,
                                           const aPoint &_pntGlobal);


    protected:
        virtual bool    onLDoubleClick(u16          _u16Modifier,
                                       const aPoint &_pntLocal,
                                       const aPoint &_pntGlobal);

        virtual bool    onMDoubleClick(u16          _u16Modifier,
                                       const aPoint &_pntLocal,
                                       const aPoint &_pntGlobal);

        virtual bool    onRDoubleClick(u16          _u16Modifier,
                                       const aPoint &_pntLocal,
                                       const aPoint &_pntGlobal);

}; // class aToolBase


} // namespace aWin
} // namespace aFrame


#endif //_USE_QT_
