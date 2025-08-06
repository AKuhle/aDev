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
#include "aFrame_def.h"
#include "aUtil_def.h"
#include "aWin_def.h"

#include "aColor.h"

#include "aStyleItemFillSolid.h"



using namespace std;
using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aWinStyle
*******************************************************************************/
class aWinStyle
{
    private:
        // style json file, one instance for all windows
        static std::unique_ptr<aJsonFile>               m_pStyleFile;
        static std::map<aString, std::vector<aString>>  m_mapClassOrder;

        // style
        shared_ptr<aStyleItemFill>  m_pBgStyle      { std::make_shared<aStyleItemFillSolid> (colBlack) };


    public:
        aWinStyle();
        virtual ~aWinStyle();

        static void                     setStyleFile(const aPath    &_path);

        void                            setStyle();


        // style getter
        shared_ptr<aStyleItemFill>      bgStyle() const             { return m_pBgStyle; }


    private:
        bool                            isValid() const;

        void                            setStyle4WinClass(const aString    &_sWinClass);

        void                            setBg(const std::vector<aString>    &_vStyleClass);

        std::shared_ptr<aStyleItemFill> parseFillItem(aString _sValue) const;
}; // class aWinStyle


} // namespace aWin
} // namespace aFrame
