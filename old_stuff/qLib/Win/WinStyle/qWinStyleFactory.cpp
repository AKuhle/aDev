/*******************************************************************************
* \file qWinStyleFactory.cpp
* \author Andreas Kuhlewind
*
* \brief
*
*  Detailed description starts here.
*******************************************************************************/


/*******************************************************************************
* includes
*******************************************************************************/
#include "Win/WinStyle/qWinStyleFactory.h"


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Win {


/*******************************************************************************
* qWinStyleFactory::qWinStyleFactory
*******************************************************************************/
qWinStyleFactory::qWinStyleFactory()
{
} // qWinStyleFactory::qWinStyleFactory


/*******************************************************************************
* qWinStyleFactory::~qWinStyleFactory
*******************************************************************************/
qWinStyleFactory::~qWinStyleFactory()
{
} // qWinStyleFactory::~qWinStyleFactory


/*******************************************************************************
* qWinStyleFactory::distanceEdge
*******************************************************************************/
const qMargin& qWinStyleFactory::distanceEdge() const
{
    return m_Distance;
} // qWinStyleFactory::distanceEdge


/*******************************************************************************
* qWinStyleFactory::marginEdge
*******************************************************************************/
const qMargin& qWinStyleFactory::marginEdge() const
{
    return m_Margin;
} // qWinStyleFactory::marginEdge


/*******************************************************************************
* qWinStyleFactory::borderEdge
*******************************************************************************/
const qMargin& qWinStyleFactory::borderEdge() const
{
    return m_Border;
} // qWinStyleFactory::borderEdge


/*******************************************************************************
* qWinStyleFactory::paddingEdge
*******************************************************************************/
const qMargin& qWinStyleFactory::paddingEdge() const
{
    return m_Padding;
} // qWinStyleFactory::paddingEdge


/*******************************************************************************
* qWinStyleFactory::distanceEdge
*******************************************************************************/
qMargin& qWinStyleFactory::distanceEdge()
{
    return m_Distance;
} // qWinStyleFactory::distanceEdge


/*******************************************************************************
* qWinStyleFactory::marginEdge
*******************************************************************************/
qMargin& qWinStyleFactory::marginEdge()
{
    return m_Margin;
} // qWinStyleFactory::marginEdge


/*******************************************************************************
* qWinStyleFactory::borderEdge
*******************************************************************************/
qMargin& qWinStyleFactory::borderEdge()
{
    return m_Border;
} // qWinStyleFactory::borderEdge


/*******************************************************************************
* qWinStyleFactory::paddingEdge
*******************************************************************************/
qMargin& qWinStyleFactory::paddingEdge()
{
    return m_Padding;
} // qWinStyleFactory::paddingEdge


} // namespace Win
} // namespace qLib
