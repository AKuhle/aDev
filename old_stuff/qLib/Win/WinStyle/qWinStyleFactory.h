/*******************************************************************************
* \file qWinStyleFactory.h
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
#include "Win/FrameWin/qWin.h"

#include "Object/qMargin.h"

using namespace qLib::Object;
//using namespace qLib::Graphic;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Win {


/*******************************************************************************
* class qWinStyleFactory
*******************************************************************************/
using namespace std;


/*******************************************************************************
* class qWinStyleFactory
*******************************************************************************/
class qWinStyleFactory
{
    public:
        qWinStyleFactory();
        ~qWinStyleFactory();

        qMargin    m_Distance;
        qMargin    m_Margin;
        qMargin    m_Border;
        qMargin    m_Padding;

    public:
        const qMargin&      distanceEdge() const;
        const qMargin&      marginEdge() const;
        const qMargin&      borderEdge() const;
        const qMargin&      paddingEdge() const;

        qMargin&            distanceEdge();
        qMargin&            marginEdge();
        qMargin&            borderEdge();
        qMargin&            paddingEdge();

        virtual void        setWinStyle(qWin &_win) = 0;
}; // class qWinStyleFactory


} // namespace Win
} // namespace qLib
