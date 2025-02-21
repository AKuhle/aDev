/*******************************************************************************
* \file aLabel.h
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
#include "aWin/aWin_def.h"
#include "aWin/Ctrl/aCtrl.h"

#include "aUtil/aString.h"

using namespace aLib::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aLabel
*******************************************************************************/
class aLabel : public aCtrl
{
    private:
        aString             m_sText;
        enumAlignmentHori   m_eAlignmentHori    { enumAlignmentHori::AlignHCenter };
        enumAlignmentVert   m_eAlignmentVert    { enumAlignmentVert::AlignVCenter };

    public:
        aLabel(aBaseWin    *_pParent,
               u32         _u32Id = CTRL_ID_LABEL);
        virtual ~aLabel();

        void            setText(const aString &_sText);
        aString         text() const;

        void            setHoriAlignment(enumAlignmentHori _eHori);
        void            setVertAlignment(enumAlignmentVert _eVert);
        void            setAlignment(enumAlignmentHori _eHori,
                                     enumAlignmentVert _eVert);


        /*******************************************************************************
        * aBaseWin interface
        *******************************************************************************/
        virtual void    onPaintContent() override;
}; // class aLabel


} // namespace aWin
} // namespace aLib
