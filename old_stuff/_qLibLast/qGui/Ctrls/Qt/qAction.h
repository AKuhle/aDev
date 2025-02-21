/*******************************************************************************
* \file qAction.h
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
#include "qCtrl_I.h"


namespace qLib
{
    /*******************************************************************************
    * \class qAction
    *******************************************************************************/
    class qAction : public QObject,
                    public qCtrlI
    {
        Q_OBJECT

        private:
            QAction *m_pAction;

        public:
            qAction(QAction *_pAction);
            virtual ~qAction();


        /*******************************************************************************
        * interface of qCtrlI
        *******************************************************************************/
        public:
            virtual void    SetCtrlEnabled(bool _bEnabled) override;
            virtual bool    IsCtrlEnabled() const override;

            virtual void    SetCtrlCheckable(bool _bCheckable) override;
            virtual bool    IsCtrlCheckable() const override;

            virtual void    SetCtrlChecked(bool _bChecked) override;
            virtual bool    IsCtrlChecked() const override;

            virtual void    SetCtrlEnabledChecked(bool    _bEnabled,
                                                  bool    _bChecked) override;


        /*******************************************************************************
        * slots
        *******************************************************************************/
        private slots:
            void            SlotTriggered(bool _bChecked);

    }; // class qAction

} // namespace qLib

#endif // _USE_QT_
