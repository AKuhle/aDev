/*******************************************************************************
* \file qVarPool.h
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
* include
*******************************************************************************/
#include "qBaseVarPool.h"
// #include "poolVar_bool.h"
// #include "poolVar_rgba.h"
// #include "poolVar_dbl.h"
// #include "poolVar_s32.h"
// #include "poolVar_string.h"
// #include "poolVar_u32.h"


namespace qLib
{
    /*******************************************************************************
    * class qGuiVarPool
    *******************************************************************************/
    class qGuiVarPool : public qBaseVarPool
	{
        protected:

		public:
            qGuiVarPool();
            qGuiVarPool(const qGuiVarPool &_rhs);
            virtual ~qGuiVarPool();

            qGuiVarPool&            operator=(const qGuiVarPool &_rhs);

            virtual bool            WriteToJsonFile(const qString16 &_sFilename) const override;
            virtual bool            ReadFromJsonFile(const qString16 &_sFilename) override;

            virtual void            ClearAllEntries() override;

    }; // class qGuiVarPool

} // namespace qLib
