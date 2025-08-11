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
    m_mapClassOrder["aBaseWin"] = std::vector<aString>   { "aBaseWin" };
    m_mapClassOrder["aMainWin"] = std::vector<aString>   { "aMainWin", "aBaseWin" };
    m_mapClassOrder["aTitleBar"] = std::vector<aString>   { "aTitleBar", "aBaseWin" };
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
    m_pStyleFile = make_unique<aJsonFile> (_path);

    // try to read the bg from aBaseWin => we have a valid style file
    aString sBg = m_pStyleFile->readStringValue("aBaseWin:bg");
    if (sBg == "")
    {
        cout << "style " << _path.canonicalPath() << " not read" << endl;
        m_pStyleFile = nullptr;
    }
} // aWinStyle::setStyleFile


/*******************************************************************************
* aWinStyle::isValid
*******************************************************************************/
bool aWinStyle::isValid() const
{
    return m_pStyleFile != nullptr;
} // aWinStyle::isValid


/*******************************************************************************
* aWinStyle::setStyle
*******************************************************************************/
void aWinStyle::setStyle()
{
    if (m_pStyleFile)
    {
        aBaseWin_i   *pBaseWin = dynamic_cast<aBaseWin_i *> (this);
        CHECK_PRE_CONDITION_VOID(pBaseWin != nullptr);

        if (dynamic_cast<aMainWin *> (pBaseWin) != nullptr)
        {
            setStyle4WinClass("aMainWin");
        }
        else if (dynamic_cast<aTitleBar *> (pBaseWin) != nullptr)
        {
            setStyle4WinClass("aTitleBar");
        }
        else
        {
            setStyle4WinClass("aBaseWin");
        }
    }
} // aWinStyle::setStyle


/*******************************************************************************
* aWinStyle::setStyle4WinClass
*******************************************************************************/
void aWinStyle::setStyle4WinClass(const aString     &_sWinClass)
{
    // find the class order for the given win class
    std::map<aString, std::vector<aString>>::iterator it = m_mapClassOrder.find(_sWinClass);

    if (it != m_mapClassOrder.end())
    {
        setMetricsW(it->second);        // set metricsW
        setMetricsH(it->second);        // set metricsH
        setBorder(it->second);          // set border
        setBg(it->second);              // set bg
    }
} // aWinStyle::setStyle4WinClass


/*******************************************************************************
* aWinStyle::setMetricsW
*******************************************************************************/
void aWinStyle::setMetricsW(const std::vector<aString> &_vStyleClass)
{
    // iterate over the class chain
    for (const aString &s : _vStyleClass)
    {
        aString sVal = m_pStyleFile->readStringValue(s + ":sysMetricsW");

        if (sVal != "")
        {
            // value found => set the value and cancel the class chain
            m_dimSysMetrics.w() = parseValueS32(sVal);
            return;
        }
    }
} // aWinStyle::setMetricsW


/*******************************************************************************
* aWinStyle::setMetricsH
*******************************************************************************/
void aWinStyle::setMetricsH(const std::vector<aString> &_vStyleClass)
{
    // iterate over the class chain
    for (const aString &s : _vStyleClass)
    {
        aString sVal = m_pStyleFile->readStringValue(s + ":sysMetricsH");

        if (sVal != "")
        {
            // value found => set the value and cancel the class chain
            m_dimSysMetrics.h() = parseValueS32(sVal);
            return;
        }
    }
} // aWinStyle::setMetricsH


/*******************************************************************************
* aWinStyle::setBorder
*******************************************************************************/
void aWinStyle::setBorder(const std::vector<aString> &_vStyleClass)
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
} // aWinStyle::setBorder


/*******************************************************************************
* aWinStyle::setBg
*******************************************************************************/
void aWinStyle::setBg(const std::vector<aString> &_vStyleClass)
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
} // aWinStyle::setBg


/*******************************************************************************
* aWinStyle::parseValueS32
*******************************************************************************/
s32 aWinStyle::parseValueS32(aString _sValue)
{
    std::string     sValue = _sValue.to_stdString();
    std::smatch     matches;
    std::regex      reVal(m_reU32);

    // check for solid color
    if (std::regex_match(sValue, matches, reVal))
    {
        return std::stoi(matches[1].str());
    }

    return 0;
} // aWinStyle::parseValueS32


/*******************************************************************************
* aWinStyle::parseFillItem
*******************************************************************************/
shared_ptr<aStyleItemFill> aWinStyle::parseFillItem(aString _sValue)
{
    std::string     sValue = _sValue.to_stdString();
    std::smatch     matches;

    std::regex      solid(m_reAny + R"(\s*solid\s*\()" +
                          m_reRgb + R"(\s*\))");

    std::regex      gradient(m_reAny + R"(\s*gradient\s*\()" +
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
* aWinStyle::parseBorderItem
*******************************************************************************/
bool aWinStyle::parseBorderItem(aString _sValue)
{
    std::string     sValue = _sValue.to_stdString();
    std::smatch     matches;

    // check for solid border
    std::regex      solid(m_reAny + R"(\s*solid\s*\()" +
                          m_reRgb + m_reColon +
                          m_reU32 + m_reColon +
                          m_reU32 + m_reColon +
                          m_reU32 + m_reColon +
                          m_reU32 +
                          R"(\s*\))");

    // check for solid borderFrame
    std::regex      solidFrame(m_reAny + R"(\s*solidFrame\s*\()" +
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
