/*******************************************************************************
* \file qScrollWin.h
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
#include "qWin.h"


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    class qDocI;
    class qViewI;
    class qDockWin;
    class qScrollBar;


    /*******************************************************************************
    * class qScrollWin
    *******************************************************************************/
    class qScrollWin : public qWin
    {
        private:
            qScrollBar      *m_pHoriSb      { nullptr };
            qScrollBar      *m_pVertSb      { nullptr };
            SysWin_t        *m_pCentralWin  { nullptr };

        protected:
            qScrollWin(SysWin_t  *_pParent = nullptr);
            ~qScrollWin();

            virtual void        OnHoriScroll(s32 _s32Pos) = 0;
            virtual void        OnVertScroll(s32 _s32Pos) = 0;

        public:
            void                SetCentralWin(SysWin_t   *_pWin);
            SysWin_t*           CentralWin() const;

            void                SetHoriSbRange(s32  _s32Min,
                                               s32  _s32Max);

            void                SetVertSbRange(s32  _s32Min,
                                               s32  _s32Max);

            void                SetHoriSbPos(s32 _s32Pos);
            void                SetVertSbPos(s32 _s32Pos);

            s32                 HoriSbPos() const;
            s32                 VertSbPos() const;



            //void                SetHorizontalScrollBarPolicy(enumScrollBarPolicy _ePolicy);
            //void                SetVerticalScrollBarPolicy(enumScrollBarPolicy _ePolicy);
            //void                SetScrollBarPolicy(enumScrollBarPolicy _eHoriPolicy,
            //                                         enumScrollBarPolicy _eVertPolicy);

        private:
            void                ArrangeChilds();


        /*******************************************************************************
        * qCtrlManager interface
        *******************************************************************************/
        protected:
            virtual void        OnRegisterCtrl() override;
            virtual void        OnUpdateCtrl(qCtrlI *_pCtrl) override;

            virtual void        OnCtrlMessage(qCtrlI    *_pCtrl,
                                              u32       _u32Mes,
                                              s64       _s64Value   = 0,
                                              void      *_pVoid1    = nullptr,
                                              void      *_pVoid2    = nullptr) override;


        /*******************************************************************************
        * qSysWin interface
        *******************************************************************************/
        protected:
            virtual bool        OnSysCreate() override;

            virtual void        OnSysResize(const qDimension2D<s32>    &_d2dOld,
                                            const qDimension2D<s32>    &_d2dNew) override;

        DECLARE_RESIZE_EVENT

    }; // class qScrollWin

} // namespace aLib

#endif // _USE_QT_
