/*******************************************************************************
* \file aButton.h
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
#include "aGraphic/aPixmap.h"

#include "aWin/aWin_def.h"
#include "aWin/Ctrl/aCtrl.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aButton
*******************************************************************************/
class aButton : public aCtrl
{
    private:
        enumButtonStyle             m_eButtonStyle      { enumButtonStyle::MASKED_MODE };
        unique_ptr<aPixmap>         m_pPixmap           { nullptr };

        bool                        m_bSelected         { false };
        bool                        m_bSelectable       { false };

        aColor                      m_colSelected;


    public:
        aButton(aBaseWin    *_pParent,
                u32         _u32Id);
        virtual ~aButton();


        void                    setSelectedColor(const aColor  &_color);
        const aColor&           selectedColor() const;

        enumButtonStyle         buttonStyle() const;
        void                    setButtonStyle(enumButtonStyle _eStyle);

        aPixmap*                pixmap() const;
        void                    setPixmap(const char    *_pRscName);

        bool                    isSelected() const;
        void                    setSelected(bool _bSelected);

        bool                    isSelectable() const;
        void                    setSelectable(bool _bSelectable);


    /*******************************************************************************
    * aCtrl interface
    *******************************************************************************/
    protected:
        virtual aColor          stateColor() const override;


    /*******************************************************************************
    * qWin interface
    *******************************************************************************/
    public:
        virtual bool            onSysCreate() override;

}; // class aButton


} // namespace aWin
} // namespace aLib
