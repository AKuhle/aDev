/*******************************************************************************
* \file aView.h
* \author Andreas Kuhlewind
*
* \brief
*
* $Revision: 69 $
* $LastChangedDate: 2010-08-17 14:10:45 +0200 (Di, 17 Aug 2010) $
* $LastChangedBy: akuhlewi $
*
*  Detailed description starts here.
*******************************************************************************/
#pragma once



/*******************************************************************************
* includes
*******************************************************************************/
#include "aLib_def.h"
#include "aPlainWin.h"

using namespace std;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aView
*******************************************************************************/
class aView : public aPlainWin
{
    shared_ptr<aDoc>    m_pDoc;

    protected:
        aView(SysWin *_pParent);

        aView(SysWin                   *_pParent,
              const std::shared_ptr<aDoc>   &_pDoc);

    public:
        virtual ~aView();

        shared_ptr<aDoc>    doc() const;
        void                setDoc(const std::shared_ptr<aDoc> &_pDoc);

    private:
        aView(const aView& _rhs) = delete;
        aView(aView&& _rhs) = delete;
        aView& operator=(const aView& _rhs) = delete;
        aView& operator=(aView&& _rhs) = delete;
}; // class aView


} // namespace aWin
} // namespace aLib
