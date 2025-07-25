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
#include "aUtil_def.h"
#include "aWin_def.h"

using namespace aFrame::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* class aStyleParser
*******************************************************************************/
class aStyleParser
{
    private:
        std::unique_ptr<aJsonFile>                  m_pStyleFile;
        std::map<aString, std::vector<aString>>     m_mapClassOrder;

    public:
        aStyleParser(const aPath    &_path);
        virtual ~aStyleParser();

        bool                            isValid() const;

        void                            setStyle(aBaseWin_i   *_pBaseWin);

    private:
        void                            setStyle4Class(aBaseWin_i       *_pBaseWin,
                                                       const aString    &_sStyleClass);

        void                            setBg(aBaseWin_i                    *_pBaseWin,
                                              const std::vector<aString>    &_vStyleClass);

        std::shared_ptr<aStyleItemFill> parseFillItem(aString _sValue) const;
}; // class aStyleParser


} // namespace aWin
} // namespace aFrame
