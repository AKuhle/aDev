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
#include "aDimension.h"
#include "aMargin.h"

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

        aMargin                         m_margin;
        aMargin                         m_padding;

        // win metrics
        aDimension                      m_dimSysMetrics;
        static float                    m_fSysMetricsFactor;

        // style
        shared_ptr<aStyleItemFill>      m_pBgStyle          { std::make_shared<aStyleItemFillSolid> (colBlack) };
        shared_ptr<aStyleItemBorder>    m_pBorderStyle;

        // color, individual used by the window classes
        // e.g. buttons use them all
        aColor                          m_colNormal;
        aColor                          m_colActive;
        aColor                          m_colHover;
        aColor                          m_colDisabled;

        // regular expressions for items
        //std::string m_reAny = R"(.*)";
        std::string m_reU32 = R"(\s*(\d+))";
        std::string m_reColon = R"(\s*,)";

        std::string m_reRgb = R"(\s*rgba\s*\()" +
                              m_reU32 + m_reColon +
                              m_reU32 + m_reColon +
                              m_reU32 + m_reColon +
                              m_reU32 +
                              R"(\s*\))";

    protected:
        aWinStyle();

    public:
        virtual ~aWinStyle();

        static void                         setStyleFile(const aPath    &_path);
        void                                setWinStyle();

        // style getter
        aDimension                          sysMetrics() const          { return m_dimSysMetrics * m_fSysMetricsFactor; }
        shared_ptr<aStyleItemFill>          bgStyle() const             { return m_pBgStyle; }
        shared_ptr<aStyleItemBorder>        borderStyle() const         { return m_pBorderStyle; }

        aMargin                           	marginMargin() const        { return m_margin; }
        aMargin                             borderMargin() const;
        aMargin                             paddingMargin() const       { return m_padding; }


        void                                setNormalColor(const aColor &_col)      { m_colNormal = _col; }
        const aColor&                       normalColor() const                     { return m_colNormal; }

        void                                setActiveColor(const aColor &_col)      { m_colActive = _col; }
        const aColor&                       activeColor() const                     { return m_colActive; }

        void                                setHoverColor(const aColor &_col)       { m_colHover = _col; }
        const aColor&                       hoverColor() const                      { return m_colHover; }

        void                                setDisabledColor(const aColor &_col)    { m_colDisabled = _col; }
        const aColor&                       disabledColor() const                   { return m_colDisabled; }


    private:
        bool                                isValid() const;

        void                                setStyle4WinClass(const aString    &_sWinClass);

        void                                setMetricsW(const std::vector<aString> &_vStyleClass);
        void                                setMetricsH(const std::vector<aString> &_vStyleClass);

        void                                setMarginStyle(const std::vector<aString> &_vStyleClass);
        void                                setBorderStyle(const std::vector<aString> &_vStyleClass);
        void                                setBgStyle(const std::vector<aString> &_vStyleClass);

        void                                setNormalColor(const std::vector<aString> &_vStyleClass);
        void                                setActiveColor(const std::vector<aString> &_vStyleClass);
        void                                setHoverColor(const std::vector<aString> &_vStyleClass);
        void                                setDisabledColor(const std::vector<aString> &_vStyleClass);

        bool                                parseS32Value(aString   _sValue,
                                                          s32       &_s32Val);

        bool                                parseColorValue(aString _sValue,
                                                            aColor  &_col);   // rgba, hsl etc (future)

        std::shared_ptr<aStyleItemFill>     parseFillItem(aString _sValue);
        bool                                parseMarginItem(aString _sValue);
        bool                                parseBorderItem(aString _sValue);
}; // class aWinStyle


} // namespace aWin
} // namespace aFrame
