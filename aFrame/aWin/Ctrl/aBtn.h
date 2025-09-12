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
#include "aToolMgr.h"
#include "aVector.h"

using namespace std;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aBtn
*******************************************************************************/
class aBtn : public aCtrl,
             public aToolMgr
{
    // the button tool has access to the callback handlers
    friend class aBtnTool;

    public:
        using ClickHandler = std::function<void (aBtn*)>;

    private:
        shared_ptr<aPixmap>     m_pPixmap;
        aString                 m_sRsc;
        aString                 m_sInfoText;

        // state
        enumBtnStyle            m_eBtnStyle     { enumBtnStyle::MASKED_MODE };
        bool                    m_bCheckable    { false };
        bool                    m_bChecked      { false };

        aVector<ClickHandler>   m_vClickHandler;

    protected:
        aBtn(aBaseWin        *_pParent,
             const aString   &_sRsc,
             const aString   &_sInfoText);


    public:
        virtual ~aBtn();

        void                setInfoText(const aString &_sInfoText)  { m_sInfoText = _sInfoText; }
        aString             infoText() const                        { return m_sInfoText; }

        shared_ptr<aPixmap> pixmap() const                          { return m_pPixmap; }

        void                setBtnStyle(enumBtnStyle _eBtnStyle)    { m_eBtnStyle = _eBtnStyle; }
        enumBtnStyle        btnStyle() const                        { return m_eBtnStyle; }

        void                setCheckable(bool _bCheckable)          { m_bCheckable = _bCheckable; }
        bool                isCheckable() const                     { return m_bCheckable; }

        void                setChecked(bool _bChecked)              { m_bChecked = _bChecked; }
        bool                isChecked() const                       { return m_bChecked; }


    // callback handler
    public:
        void                addClickHandler(ClickHandler _handler);


    protected:
        aColor              stateColor() const;


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
