/*******************************************************************************
* \file aStyleParser.cpp
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

#include "aStyleParser.h"
#include "aPath.h"
#include "aJsonFile.h"

#include "aMainWin.h"
#include "aStyleItemFillSolid.h"

using namespace std;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aStyleParser::aStyleParser
*******************************************************************************/
aStyleParser::aStyleParser(const aPath    &_path)
{
    m_pStyleFile = make_unique<aJsonFile> (_path);

    // try to read the bg from aBaseWin
    aString sBg = m_pStyleFile->readStringValue("aBaseWin:bg");
    if (sBg == "")
    {
        cout << "style " << _path.canonicalPath() << " not read" << endl;
        m_pStyleFile = nullptr;
    }

    m_mapClassOrder["aMainWin"] = std::vector<aString>   { "aMainWin", "aBaseWin" };
    m_mapClassOrder["aBaseWin"] = std::vector<aString>   { "aBaseWin" };
} // aStyleParser::aStyleParser


/*******************************************************************************
* aStyleParser::~aStyleParser
*******************************************************************************/
aStyleParser::~aStyleParser()
{
} // aStyleParser::~aStyleParser


/*******************************************************************************
* aStyleParser::isValid
*******************************************************************************/
bool aStyleParser::isValid() const
{
    return m_pStyleFile != nullptr;
} // aStyleParser::isValid


/*******************************************************************************
* aStyleParser::setStyle
*******************************************************************************/
void aStyleParser::setStyle(aBaseWin_i   *_pBaseWin)
{
    if (m_pStyleFile)
    {
        if (dynamic_cast<aMainWin *> (_pBaseWin) != nullptr)
            setStyle4Class(_pBaseWin, "aMainWin");
        else
            setStyle4Class(_pBaseWin, "aBaseWin");
    }
} // aStyleParser::setStyle


/*******************************************************************************
* aStyleParser::setStyle4Class
*******************************************************************************/
void aStyleParser::setStyle4Class(aBaseWin_i        *_pBaseWin,
                                  const aString     &_sStyleClass)
{
    std::map<aString, std::vector<aString>>::iterator it = m_mapClassOrder.find(_sStyleClass);

    if (it != m_mapClassOrder.end())
    {
        // set Bg
        setBg(_pBaseWin, it->second);
    }
} // aStyleParser::setStyle4Class


/*******************************************************************************
* aStyleParser::setBg
*******************************************************************************/
void aStyleParser::setBg(aBaseWin_i                 *_pBaseWin,
                         const std::vector<aString> &_vStyleClass)
{
    // iterate over the class chain
    for (const aString &s : _vStyleClass)
    {
        aString sVal = m_pStyleFile->readStringValue(s + ":bg");

        if (sVal != "")
        {
            // value found => set the value and cancel the class chain
            _pBaseWin->setBgStyle(parseFillItem(sVal));
            return;
        }
    }
} // aStyleParser::setBg


/*******************************************************************************
* aStyleParser::parseFillItem
*******************************************************************************/
shared_ptr<aStyleItemFill> aStyleParser::parseFillItem(aString    _sValue) const
{
    shared_ptr<aStyleItemFill>  pFillItem;

    // check for solid color
    if (_sValue.contains("solid"))
    {
        if (_sValue.contains("rgb"))
        {
            std::string     sValue      = _sValue.to_stdString();
            std::smatch     matches;
            // Regex pattern für rgb(zahl, zahl, zahl, zahl)  -> rgb(r,g,b,a)
            std::regex      solidRgbPattern(R"(.*\(\s*rgb\s*\(\s*(\d+)\s*,\s*(\d+)\s*,\s*(\d+)\s*(?:,\s*(\d+))?\s*\)*s*\))");

            if (std::regex_match(sValue, matches, solidRgbPattern))
            {
                // matches[0] ist der komplette Match, matches[1-4] sind die Gruppen
                auto col = aColor::fromU8(std::stoi(matches[1].str()),
                                          std::stoi(matches[2].str()),
                                          std::stoi(matches[3].str()),
                                          std::stoi(matches[4].str()));

                pFillItem = make_shared<aStyleItemFillSolid> (col);
            }
        }
    } // if (_sValue.contains("solid"))

    return pFillItem;
} // aStyleParser::parseFillItem


} // namespace aWin
} // namespace aFrame
