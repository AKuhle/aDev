/*******************************************************************************
* \file qWinStyle.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "Win/WinStyle/qWinStyle.h"
#include "Graphic/qBorderObj.h"
#include "Graphic/qFillObj.h"

/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Win {


/*******************************************************************************
* qWinStyle::qWinStyle
*******************************************************************************/
qWinStyle::qWinStyle()
{
} // qWinStyle::qWinStyle


/*******************************************************************************
* qWinStyle::~qWinStyle
*******************************************************************************/
qWinStyle::~qWinStyle()
{
} // qWinStyle::~qWinStyle


/*******************************************************************************
* qWinStyle::setBorderObj
*******************************************************************************/
void qWinStyle::setBorderObj(unique_ptr<qBorderObj> _pObj)
{
    m_pBorderObj = std::move(_pObj);
} // qWinStyle::setBorderObj


/*******************************************************************************
* qWinStyle::borderObj
*******************************************************************************/
qBorderObj* qWinStyle::borderObj() const
{
    return m_pBorderObj.get();
} // qWinStyle::borderObj


/*******************************************************************************
* qWinStyle::setContentObj
*******************************************************************************/
void qWinStyle::setContentObj(unique_ptr<qFillObj> _pObj)
{
    m_pContentObj = std::move(_pObj);
} // qWinStyle::setContentObj


/*******************************************************************************
* qWinStyle::contentObj
*******************************************************************************/
qFillObj* qWinStyle::contentObj() const
{
    return m_pContentObj.get();
} // qWinStyle::borderObj


} // namespace Win
} // namespace qLib
