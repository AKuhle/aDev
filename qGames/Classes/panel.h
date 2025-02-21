/*******************************************************************************
* \file qColor.h
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
#include <QtWidgets>

#include "gamesDefs.h"
#include "qString16.h"
#include "qColor.h"
#include "gameInfo.h"


/*******************************************************************************
* class Panel
*******************************************************************************/
class Panel : public QWidget
{
    Q_OBJECT

    private:
        enumPages                   m_ePages;
        qLib::qColor                m_colFrame          { qLib::qColor::FromU8(50, 226, 255) };
        QImage                      m_imgFigure;
        QImage                      m_imgFigureResized;
        qLib::qString16             m_sFigurePath;
        std::shared_ptr<GameInfo>   m_pGameInfo;

    public:
        Panel(QWidget           *_pParent,
              enumPages         _ePages);
        ~Panel();

        void                SetFrameColor(const qLib::qColor  &_col);

        void                SetFigure(qLib::qString16 _sFigurePath);

        void                SetGameInfo(std::shared_ptr<GameInfo> _pGameInfo);

    protected:
        virtual void        resizeEvent(QResizeEvent *_pEvent) override;
        virtual void        paintEvent(QPaintEvent *_pEvent) override;
        virtual void        mouseDoubleClickEvent(QMouseEvent *event) override;

}; // class Panel
