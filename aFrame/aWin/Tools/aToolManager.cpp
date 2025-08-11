/*******************************************************************************
* \file aToolManager.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "aToolManager.h"
#include "aToolBase.h"



/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aWin {


/*******************************************************************************
* aToolManager::aToolManager
*******************************************************************************/
aToolManager::aToolManager()
{
} // aToolManager::aToolManager


/*******************************************************************************
* aToolManager::~aToolManager
*******************************************************************************/
aToolManager::~aToolManager()
{
} // aToolManager::~aToolManager


/*******************************************************************************
* aToolManager::addTool
*******************************************************************************/
void aToolManager::addTool(std::unique_ptr<aToolBase>  _pTool)
{
    m_vTools.push_back(std::move(_pTool));
} // aToolManager::addTool


/*******************************************************************************
* aToolManager::onToolManagerLDoubleClick
*******************************************************************************/
bool aToolManager::onToolManagerLDoubleClick(u16              _u16Modifier,
                                             const aPoint     &_pntLocal,
                                             const aPoint     &_pntGlobal)
{
    bool bHandled = false;

    if (m_vTools.back() != nullptr)
    {
        bHandled = m_vTools.back()->onToolLDoubleClick(_u16Modifier, _pntLocal, _pntGlobal);
    }

    return bHandled;
} // aToolManager::onToolManagerLDoubleClick


/*******************************************************************************
* aToolManager::onToolManagerMDoubleClick
*******************************************************************************/
bool aToolManager::onToolManagerMDoubleClick(u16              _u16Modifier,
                                             const aPoint     &_pntLocal,
                                             const aPoint     &_pntGlobal)
{
    bool bHandled = false;

    if (m_vTools.back() != nullptr)
    {
        bHandled = m_vTools.back()->onToolMDoubleClick(_u16Modifier, _pntLocal, _pntGlobal);
    }

    return bHandled;
} // aToolManager::onToolManagerMDoubleClick


/*******************************************************************************
* aToolManager::onToolManagerRDoubleClick
*******************************************************************************/
bool aToolManager::onToolManagerRDoubleClick(u16              _u16Modifier,
                                             const aPoint     &_pntLocal,
                                             const aPoint     &_pntGlobal)
{
    bool bHandled = false;

    if (m_vTools.back() != nullptr)
    {
        bHandled = m_vTools.back()->onToolRDoubleClick(_u16Modifier, _pntLocal, _pntGlobal);
    }

    return bHandled;
} // aToolManager::onToolManagerRDoubleClick



} // namespace aWin
} // namespace aFrame
