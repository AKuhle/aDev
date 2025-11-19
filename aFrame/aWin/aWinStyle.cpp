/*******************************************************************************
* \file aWinStyle.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aFrame_def.h"

#include "aWinStyle.h"
#include "aPath.h"
#include "aJsonFile.h"

#include "aMainWin.h"
#include "aPushBtn.h"
#include "aToolBtn.h"

#include "aTitleBar.h"
#include "aStyleItemFillSolid.h"
#include "aStyleItemFillGradient.h"
#include "aStyleItemBorderSolid.h"
#include "aStyleItemBorderSolidFrame.h"

using namespace std;



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* statics
*******************************************************************************/
std::unique_ptr<aJsonFile>               aWinStyle::m_pStyleFile;
std::map<aString, std::vector<aString>>  aWinStyle::m_mapClassOrder;
float                                    aWinStyle::m_fSysMetricsFactor { 1. };


/*******************************************************************************
* aWinStyle::aWinStyle
*******************************************************************************/
aWinStyle::aWinStyle()
{
    m_mapClassOrder["aBaseWin"] = std::vector<aString>  { "aBaseWin" };
    m_mapClassOrder["aMainWin"] = std::vector<aString>  { "aMainWin", "aBaseWin" };
    m_mapClassOrder["aToolBar"] = std::vector<aString>  { "aToolBar", "aBaseWin" };
    m_mapClassOrder["aTitleBar"] = std::vector<aString> { "aTitleBar", "aToolBar", "aBaseWin" };
    m_mapClassOrder["aPushBtn"] = std::vector<aString>  { "aPushBtn", "aBtn", "aBaseWin" };
    m_mapClassOrder["aToolBtn"] = std::vector<aString>  { "aToolBtn", "aBtn", "aBaseWin" };
} // aWinStyle::aWinStyle


/*******************************************************************************
* aWinStyle::~aWinStyle
*******************************************************************************/
aWinStyle::~aWinStyle()
{
} // aWinStyle::~aWinStyle


/*******************************************************************************
* aWinStyle::setStyleFile
*******************************************************************************/
void aWinStyle::setStyleFile(const aPath    &_path)
{
    // create a new json file
    m_pStyleFile = make_unique<aJsonFile> ();
    m_pStyleFile->readJsonFile(_path);

    // try to read the bg from aBaseWin => we have a valid style file
    aString sBg = m_pStyleFile->readStringValue("aBaseWin:bg");
    if (sBg == "")
    {
        cout << "style " << _path.canonicalPath() << " not read" << endl;
        m_pStyleFile = nullptr;
    }
} // aWinStyle::setStyleFile


/*******************************************************************************
* aWinStyle::setWinStyle
*******************************************************************************/
void aWinStyle::setWinStyle()
{
    if (m_pStyleFile)
    {
        aBaseWin   *pBaseWin = dynamic_cast<aBaseWin *> (this);
        CHECK_PRE_CONDITION_VOID(pBaseWin != nullptr);

        if (dynamic_cast<aMainWin *> (pBaseWin) != nullptr)
        {
            setStyle4WinClass("aMainWin");
        }

        else if (dynamic_cast<aTitleBar *> (pBaseWin) != nullptr)
        {
            setStyle4WinClass("aTitleBar");
        }

        else if (dynamic_cast<aToolBar *> (pBaseWin) != nullptr)
        {
            setStyle4WinClass("aToolBar");
        }

        else if (dynamic_cast<aPushBtn *> (pBaseWin) != nullptr)
        {
            setStyle4WinClass("aPushBtn");
        }

        else if (dynamic_cast<aToolBtn *> (pBaseWin) != nullptr)
        {
            setStyle4WinClass("aToolBtn");
        }

        else
        {
            setStyle4WinClass("aBaseWin");
        }
    }
} // aWinStyle::setWinStyle


/*******************************************************************************
* aWinStyle::borderMargin
*******************************************************************************/
aMargin aWinStyle::borderMargin() const
{
    aMargin     m;

    if (m_pBorderStyle)
    {
        m = m_pBorderStyle->margin();
    }

    return m;
} // aWinStyle::borderMargin


/*******************************************************************************
* aWinStyle::isValid
*******************************************************************************/
bool aWinStyle::isValid() const
{
    return m_pStyleFile != nullptr;
} // aWinStyle::isValid


/*******************************************************************************
* aWinStyle::setStyle4WinClass
*******************************************************************************/
void aWinStyle::setStyle4WinClass(const aString     &_sWinClass)
{
    // find the class order for the given win class
    std::map<aString, std::vector<aString>>::iterator it = m_mapClassOrder.find(_sWinClass);

    if (it != m_mapClassOrder.end())
    {
        // metrics
        setMetricsW(it->second);        // set metricsW
        setMetricsH(it->second);        // set metricsH

        // margins
        setMarginStyle(it->second);     // set margin
        setBorderStyle(it->second);     // set border
        setBgStyle(it->second);         // set bg

        // colors
        setNormalColor(it->second);     // set normal color
        setActiveColor(it->second);     // set active color
        setHoverColor(it->second);      // set hover color
        setDisabledColor(it->second);   // set disabled color
    }
} // aWinStyle::setStyle4WinClass


/*******************************************************************************
* aWinStyle::setMetricsW
*******************************************************************************/
void aWinStyle::setMetricsW(const std::vector<aString> &_vStyleClass)
{
    s32     s32Val;

    // iterate over the class chain
    for (const aString &s : _vStyleClass)
    {
        aString sVal = m_pStyleFile->readStringValue(s + ":sysMetricsW");

        if (parseS32Value(sVal, s32Val))
        {
            // value found => set the value and cancel the class chain
            m_dimSysMetrics.w() = s32Val;
            return;
        }
    }
} // aWinStyle::setMetricsW


/*******************************************************************************
* aWinStyle::setMetricsH
*******************************************************************************/
void aWinStyle::setMetricsH(const std::vector<aString> &_vStyleClass)
{
    s32     s32Val;

    // iterate over the class chain
    for (const aString &s : _vStyleClass)
    {
        aString sVal = m_pStyleFile->readStringValue(s + ":sysMetricsH");

        if (parseS32Value(sVal, s32Val))
        {
            // value found => set the value and cancel the class chain
            m_dimSysMetrics.h() = s32Val;
            return;
        }
    }
} // aWinStyle::setMetricsH


/*******************************************************************************
* aWinStyle::setMarginStyle
*******************************************************************************/
void aWinStyle::setMarginStyle(const std::vector<aString> &_vStyleClass)
{
    // iterate over the class chain
    for (const aString &s : _vStyleClass)
    {
        aString sVal = m_pStyleFile->readStringValue(s + ":margin");

        if (sVal != "")
        {
            // value found => set the value and cancel the class chain
            if (parseMarginItem(sVal))
            {
                return;
            }
        }
    }
} // aWinStyle::setMarginStyle


/*******************************************************************************
* aWinStyle::setBorderStyle
*******************************************************************************/
void aWinStyle::setBorderStyle(const std::vector<aString> &_vStyleClass)
{
    // iterate over the class chain
    for (const aString &s : _vStyleClass)
    {
        aString sVal = m_pStyleFile->readStringValue(s + ":border");

        if (sVal != "")
        {
            // value found => set the value and cancel the class chain
            if (parseBorderItem(sVal))
            {
                return;
            }
        }
    }
} // aWinStyle::setBorderStyle


/*******************************************************************************
* aWinStyle::setBgStyle
*******************************************************************************/
void aWinStyle::setBgStyle(const std::vector<aString> &_vStyleClass)
{
    // iterate over the class chain
    for (const aString &s : _vStyleClass)
    {
        aString sVal = m_pStyleFile->readStringValue(s + ":bg");

        if (sVal != "")
        {
            // value found => set the value and cancel the class chain
            shared_ptr<aStyleItemFill> pFI = parseFillItem(sVal);
            if (pFI)
            {
                m_pBgStyle = pFI;
                return;
            }
        }
    }
} // aWinStyle::setBgStyle


/*******************************************************************************
* aWinStyle::setNormalColor
*******************************************************************************/
void aWinStyle::setNormalColor(const std::vector<aString> &_vStyleClass)
{
    aColor  col;

    // iterate over the class chain
    for (const aString &s : _vStyleClass)
    {
        aString sVal = m_pStyleFile->readStringValue(s + ":normal");

        if (sVal != "")
        {
            // value found => set the value and cancel the class chain
            if (parseColorValue(sVal, col))
            {
                setNormalColor(col);
                return;
            }
        }
    }
} // aWinStyle::setNormalColor


/*******************************************************************************
* aWinStyle::setActiveColor
*******************************************************************************/
void aWinStyle::setActiveColor(const std::vector<aString> &_vStyleClass)
{
    aColor  col;

    // iterate over the class chain
    for (const aString &s : _vStyleClass)
    {
        aString sVal = m_pStyleFile->readStringValue(s + ":active");

        if (sVal != "")
        {
            // value found => set the value and cancel the class chain
            if (parseColorValue(sVal, col))
            {
                setActiveColor(col);
                return;
            }
        }
    }
} // aWinStyle::setActiveColor


/*******************************************************************************
* aWinStyle::setHoverColor
*******************************************************************************/
void aWinStyle::setHoverColor(const std::vector<aString> &_vStyleClass)
{
    aColor  col;

    // iterate over the class chain
    for (const aString &s : _vStyleClass)
    {
        aString sVal = m_pStyleFile->readStringValue(s + ":hover");

        if (sVal != "")
        {
            // value found => set the value and cancel the class chain
            if (parseColorValue(sVal, col))
            {
                setHoverColor(col);
                return;
            }
        }
    }
} // aWinStyle::setHoverColor


/*******************************************************************************
* aWinStyle::setDisabledColor
*******************************************************************************/
void aWinStyle::setDisabledColor(const std::vector<aString> &_vStyleClass)
{
    aColor  col;

    // iterate over the class chain
    for (const aString &s : _vStyleClass)
    {
        aString sVal = m_pStyleFile->readStringValue(s + ":disabled");

        if (sVal != "")
        {
            // value found => set the value and cancel the class chain
            if (parseColorValue(sVal, col))
            {
                setDisabledColor(col);
                return;
            }
        }
    }
} // aWinStyle::setDisabledColor


/*******************************************************************************
* aWinStyle::parseS32Value
*******************************************************************************/
bool aWinStyle::parseS32Value(aString   _sValue,
                              s32       &_s32Val)
{
    std::string     sValue = _sValue.to_stdString();
    std::smatch     matches;
    std::regex      reVal(m_reU32);

    // check for solid color
    if (std::regex_match(sValue, matches, reVal))
    {
        _s32Val =  std::stoi(matches[1].str());
        return true;
    }

    return false;
} // aWinStyle::parseS32Value


/*******************************************************************************
* aWinStyle::parseColorValue
*******************************************************************************/
bool aWinStyle::parseColorValue(aString _sValue,
                                aColor  &_col)
{
    std::string     sValue = _sValue.to_stdString();
    std::smatch     matches;
    std::regex      reRgb(m_reRgb);

    // check for solid color
    if (std::regex_match(sValue, matches, reRgb))
    {
        _col=  aColor::fromU8(std::stoi(matches[1].str()),
                              std::stoi(matches[2].str()),
                              std::stoi(matches[3].str()),
                              std::stoi(matches[4].str()));

        return true;
    }

    return false;
} // aWinStyle::parseColorValue


/*******************************************************************************
* aWinStyle::parseFillItem
*******************************************************************************/
shared_ptr<aStyleItemFill> aWinStyle::parseFillItem(aString _sValue)
{
    std::string     sValue = _sValue.to_stdString();
    std::smatch     matches;

    std::regex      solid(R"(\s*solid\s*\()" +
                          m_reRgb + R"(\s*\))");

    std::regex      gradient(+ R"(\s*gradient\s*\()" +
                             m_reRgb + m_reColon +
                             m_reRgb + m_reColon +
                             m_reU32 + R"(\s*\))");

    // check for solid color
    if (std::regex_match(sValue, matches, solid))
    {
        // matches[0] ist der komplette Match, matches[1-4] sind die Gruppen
        aColor col = aColor::fromU8(std::stoi(matches[1].str()),
                                    std::stoi(matches[2].str()),
                                    std::stoi(matches[3].str()),
                                    std::stoi(matches[4].str()));

        return make_shared<aStyleItemFillSolid> (col);
    }

    // check for gradient
    else if (std::regex_match(sValue, matches, gradient))
    {
        // matches[0] ist der komplette Match, matches[1-4] sind die Gruppen
        aColor col1 = aColor::fromU8(std::stoi(matches[1].str()),
                                     std::stoi(matches[2].str()),
                                     std::stoi(matches[3].str()),
                                     std::stoi(matches[4].str()));

        aColor col2 = aColor::fromU8(std::stoi(matches[5].str()),
                                     std::stoi(matches[6].str()),
                                     std::stoi(matches[7].str()),
                                     std::stoi(matches[8].str()));

        s32 angle = std::stoi(matches[9].str());

        return make_shared<aStyleItemFillGradient> (col1, col2, angle);
    }

    return nullptr;
} // aWinStyle::parseFillItem


/*******************************************************************************
* aWinStyle::parseMarginItem
*******************************************************************************/
bool aWinStyle::parseMarginItem(aString _sValue)
{
    std::string     sValue = _sValue.to_stdString();
    std::smatch     matches;

    // check for solid border
    std::regex      lrtb(m_reU32 + m_reColon +
                         m_reU32 + m_reColon +
                         m_reU32 + m_reColon +
                         m_reU32);

    if (std::regex_match(sValue, matches, lrtb))
    {
        // matches[0] ist der komplette Match, matches[1-4] sind die Gruppen
        m_margin.set(std::stoi(matches[1].str()),
                     std::stoi(matches[2].str()),
                     std::stoi(matches[3].str()),
                     std::stoi(matches[4].str()));

        return true;
    }

    return false;
} // aWinStyle::parseMarginItem


/*******************************************************************************
* aWinStyle::parseBorderItem
*******************************************************************************/
bool aWinStyle::parseBorderItem(aString _sValue)
{
    std::string     sValue = _sValue.to_stdString();
    std::smatch     matches;

    // check for solid border
    std::regex      solid(R"(\s*solid\s*\()" +
                          m_reRgb + m_reColon +
                          m_reU32 + m_reColon +
                          m_reU32 + m_reColon +
                          m_reU32 + m_reColon +
                          m_reU32 +
                          R"(\s*\))");

    // check for solid borderFrame
    std::regex      solidFrame(R"(\s*solidFrame\s*\()" +
                               m_reU32 + m_reColon +
                               m_reRgb + m_reColon +
                               m_reRgb + m_reColon +
                               m_reU32 + m_reColon +
                               m_reU32 + m_reColon +
                               m_reU32 + m_reColon +
                               m_reU32 +
                               R"(\s*\))");


    if (std::regex_match(sValue, matches, solid))
    {
        // matches[0] ist der komplette Match, matches[1-4] sind die Gruppen
        aColor col = aColor::fromU8(std::stoi(matches[1].str()),
                                    std::stoi(matches[2].str()),
                                    std::stoi(matches[3].str()),
                                    std::stoi(matches[4].str()));

        aMargin mar(std::stoi(matches[5].str()),
                    std::stoi(matches[6].str()),
                    std::stoi(matches[7].str()),
                    std::stoi(matches[8].str()));

        m_pBorderStyle = make_shared<aStyleItemBorderSolid> (mar, col);
        return true;
    }

    else if (std::regex_match(sValue, matches, solidFrame))
    {
        s32     s32Thick = std::stoi(matches[1].str());

        // matches[0] ist der komplette Match, matches[1-4] sind die Gruppen
        aColor colFrame = aColor::fromU8(std::stoi(matches[2].str()),
                                         std::stoi(matches[3].str()),
                                         std::stoi(matches[4].str()),
                                         std::stoi(matches[5].str()));

        aColor colBorder = aColor::fromU8(std::stoi(matches[6].str()),
                                          std::stoi(matches[7].str()),
                                          std::stoi(matches[8].str()),
                                          std::stoi(matches[9].str()));

        aMargin mar(std::stoi(matches[10].str()),
                    std::stoi(matches[11].str()),
                    std::stoi(matches[12].str()),
                    std::stoi(matches[13].str()));

        m_pBorderStyle = make_shared<aStyleItemBorderSolidFrame> (mar, colBorder, s32Thick, colFrame);
        return true;
    }

    return false;
} // aWinStyle::parseBorderItem


} // namespace aWin
} // namespace aFrame
