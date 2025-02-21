/*******************************************************************************
* \file qWinStyle.h
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
#include "qLibDefs.h"
#include "Graphic/graphicDefs.h"

using namespace std;
using namespace qLib::Graphic;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace qLib {
namespace Win {


/*******************************************************************************
* class qWinStyle
*******************************************************************************/
using namespace std;


/*******************************************************************************
* class qWinStyle
*******************************************************************************/
class qWinStyle
{
    private:
        unique_ptr<qBorderObj>  m_pBorderObj;
        unique_ptr<qFillObj>    m_pContentObj;

    public:
        qWinStyle();
        ~qWinStyle();

        void                setBorderObj(unique_ptr<qBorderObj> _pObj);
        qBorderObj*         borderObj() const;

        void                setContentObj(unique_ptr<qFillObj> _pObj);
        qFillObj*           contentObj() const;
}; // class qWinStyle


} // namespace Win
} // namespace qLib
