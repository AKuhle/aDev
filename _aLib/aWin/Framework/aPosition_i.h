/*******************************************************************************
* \file qWin.h
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
#include "aWin/aWin_def.h"

#include "aWin/Framework/aBaseWin.h"

using namespace std;
using namespace aLib::aUtil;


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aLib {
namespace aWin {


/*******************************************************************************
* class aPositionI
*******************************************************************************/
class aPositionI
{
    private:
        enumPosition    m_ePosition     { enumPosition::None };


    protected:
        aPositionI();


    public:
        virtual ~aPositionI();

        void            setPosition(enumPosition _ePosition);
        enumPosition    position() const;

        virtual void    onPositionChanged(enumPosition _eNewPosition);

}; // class aPositionI


} // namespace aWin
} // namespace aLib
