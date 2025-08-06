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
#include "aStyleItemFillSolid.h"
#include "aStyleItemFillGradient.h"

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


/*******************************************************************************
* aWinStyle::aWinStyle
*******************************************************************************/
aWinStyle::aWinStyle()
{
    m_mapClassOrder["aMainWin"] = std::vector<aString>   { "aMainWin", "aBaseWin" };
    m_mapClassOrder["aBaseWin"] = std::vector<aString>   { "aBaseWin" };
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
            setStyle4WinClass("aMainWin");
        else
            setStyle4WinClass("aBaseWin");
    }
} // aWinStyle::setStyle


/*******************************************************************************
* aWinStyle::setStyle4WinClass
*******************************************************************************/
void aWinStyle::setStyle4WinClass(const aString     &_sWinClass)
{
    std::map<aString, std::vector<aString>>::iterator it = m_mapClassOrder.find(_sWinClass);

    if (it != m_mapClassOrder.end())
    {
        // set Bg
        setBg(it->second);
    }
} // aWinStyle::setStyle4WinClass


/*******************************************************************************
* aWinStyle::setBg
*******************************************************************************/
void aWinStyle::setBg(const std::vector<aString> &_vStyleClass)
{
    // iterate over the class chain
    // e.g. aMainWin -> aBaseWin
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
* aWinStyle::parseFillItem
*******************************************************************************/
shared_ptr<aStyleItemFill> aWinStyle::parseFillItem(aString    _sValue) const
{

    std::string     reAny = R"(.*)";
    std::string     reRgb = R"(rgba\s*\(\s*(\d+)\s*,\s*(\d+)\s*,\s*(\d+)\s*,\s*(\d+)\s*\))";

    std::string     sValue = _sValue.to_stdString();
    std::smatch     matches;

    std::regex      solidRgbPattern(reAny + R"(solid\s*\(\s*)" + reRgb + reAny + R"(\s*\))");
    std::regex      gradientRgbPattern(reAny + R"(gradient\s*\(\s*)" + reRgb + reAny + reRgb + R"(\s*,\s*(\d+)\s*\))");

    // check for solid color
    if (std::regex_match(sValue, matches, solidRgbPattern))
    {
        // matches[0] ist der komplette Match, matches[1-4] sind die Gruppen
        auto col = aColor::fromU8(std::stoi(matches[1].str()),
                                  std::stoi(matches[2].str()),
                                  std::stoi(matches[3].str()),
                                  std::stoi(matches[4].str()));

        return make_shared<aStyleItemFillSolid> (col);
    }

    // check for solid color
    else if (std::regex_match(sValue, matches, gradientRgbPattern))
    {
        // matches[0] ist der komplette Match, matches[1-4] sind die Gruppen
        auto col1 = aColor::fromU8(std::stoi(matches[1].str()),
                                   std::stoi(matches[2].str()),
                                   std::stoi(matches[3].str()),
                                   std::stoi(matches[4].str()));

        auto col2 = aColor::fromU8(std::stoi(matches[5].str()),
                                   std::stoi(matches[6].str()),
                                   std::stoi(matches[7].str()),
                                   std::stoi(matches[8].str()));

        auto angle = std::stoi(matches[9].str());

        return make_shared<aStyleItemFillGradient> (col1, col2, angle);
    }

    return nullptr;
} // aWinStyle::parseFillItem


} // namespace aWin
} // namespace aFrame
