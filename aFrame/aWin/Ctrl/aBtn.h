/*******************************************************************************
* \file qWin.h
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
#include "aString.h"
#include "aCtrl.h"

using namespace std;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aBtn
*******************************************************************************/
class aBtn : public aCtrl
{
    private:
        shared_ptr<aPixmap>     m_pPixmap;
        aString                 m_sRsc;
        aString                 m_sInfoText;

        aColor                  m_colNormal;
        aColor                  m_colActive;
        aColor                  m_colHover;
        aColor                  m_colDisabled;

    protected:
        aBtn(aBaseWin        *_pParent,
             const aString   &_sRsc,
             const aString   &_sInfoText);

    public:
        virtual ~aBtn();

        void                setInfoText(const aString &_sInfoText)  { m_sInfoText = _sInfoText; }
        aString             infoText() const                        { return m_sInfoText; }

        shared_ptr<aPixmap> pixmap() const                          { return m_pPixmap; }

        void                setNormalColor(const aColor &_col)      { m_colNormal = _col; }
        const aColor&       normalColor() const                     { return m_colNormal; }

        void                setActiveColor(const aColor &_col)      { m_colActive = _col; }
        const aColor&       activeColor() const                     { return m_colActive; }

        void                setHoverColor(const aColor &_col)       { m_colHover = _col; }
        const aColor&       hoverColor() const                      { return m_colHover; }

        void                setDisabledColor(const aColor &_col)    { m_colDisabled = _col; }
        const aColor&       disabledColor() const                   { return m_colDisabled; }


    private:
        void                createPixmap();


    /*******************************************************************************
    * aBaseWin interface
    *******************************************************************************/
    protected:
        virtual bool        onSysCreateWin() override;

}; // class aBtn


} // namespace aWin
} // namespace aFrame
