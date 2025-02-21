/*******************************************************************************
* \file qScrollWin.h
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once


/*******************************************************************************
* includes
*******************************************************************************/
#include "qWin.h"
#include "qCtrlMgr.h"


namespace qLib
{
    /*******************************************************************************
    * forwards
    *******************************************************************************/
    class qScrollBar;

    /*******************************************************************************
    * class qScrollWin
    *******************************************************************************/
    class qScrollWin : public qWin,
                       public qCtrlMgr
    {
        qScrollBar      *m_pHori    { nullptr };
        qScrollBar      *m_pVert    { nullptr };

        public:
            qScrollWin(qWin  *_pParent = nullptr);
            ~qScrollWin();

            qWin*               GetCenterWin() const;
            void                SetCenterWin(qWin *_pWin);

            void                EnableTracking(bool _bTracking);

            // hori sb
            void                SetHoriVisible(bool _bVisible);

            void                SetHoriRange(s32 _s32MinValue,
                                             s32 _s32MaxValue);
            void                SetHoriPageStep(s32 _s32Step);

            void                SetHoriValue(s32 _s32Value); // !!! no trigger of OnHoriChanged
            s32                 GetHoriValue() const;

            // vert sb
            void                SetVertVisible(bool _bVisible);

            void                SetVertRange(s32 _s32MinValue,
                                             s32 _s32MaxValue);
            void                SetVertPageStep(s32 _s32Step);

            void                SetVertValue(s32 _s32Value); // !!! no trigger of OnVertChanged
            s32                 GetVertValue() const;

            // both sb's
            void                SetHoriVertVisible(bool _bHoriVisible,
                                                   bool _bVertVisible);

        protected:
            virtual void        OnHoriChanged(s32 _s32Value);
            virtual void        OnVertChanged(s32 _s32Value);


        /*******************************************************************************
        * qWin interface
        *******************************************************************************/
        public:
            virtual void        OnRegisterCtrl() override;
            virtual void        OnUpdateCtrl(qCtrlBase *_pCtrl) override;

            virtual void        OnCtrlValueChanged(qCtrlBase *_pCtrl);


        /*******************************************************************************
        * qWin interface
        *******************************************************************************/
        public:
            virtual bool        OnSysCreate() override;
            virtual bool        OnClose() override;
    }; // class qScrollWin

} // namespace aLib
