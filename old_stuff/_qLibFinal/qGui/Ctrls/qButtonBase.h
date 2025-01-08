/*******************************************************************************
* \file qButtonBase.h
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
#include "qCtrlBase.h"


namespace qLib
{
    /*******************************************************************************
    * forward
    *******************************************************************************/
    class qPixmap;

    /*******************************************************************************
    * class qButtonBase
    *******************************************************************************/
    class qButtonBase : public qCtrlBase
    {
        DeclareTypeProperty(enumButtonStyle, e, ButtonStyle, enumButtonStyle::MASKED_MODE)
        DeclareBoolProperty(Selectable, false)
        DeclareBoolProperty(Selected, false)

        private:
            unique_ptr<qPixmap>         m_pPixmap       { nullptr };


        public:
            qButtonBase(qWin  *_pParent,
                        u32   _u32Id);
            virtual ~qButtonBase();

            qPixmap*                GetPixmap() const;
            void                    SetPixmap(const char    *_pRscName);


        /*******************************************************************************
        * qWin interface
        *******************************************************************************/
        public:
            virtual bool            OnSysCreate();

    }; // class qButtonBase

} // namespace qLib
