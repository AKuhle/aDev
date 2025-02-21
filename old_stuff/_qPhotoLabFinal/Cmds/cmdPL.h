/*******************************************************************************
* \file CmdPL .h
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
#include "qLib.h"


/*******************************************************************************
* forwards
*******************************************************************************/
using namespace qLib;


/*******************************************************************************
* class CmdPL
*******************************************************************************/
class CmdPL  : public qCmdThread
{
    protected:
        shared_ptr<qLayerStack> m_pPreLS;       // layer stack before processing
        shared_ptr<qLayerStack> m_pPostLS;      // layer stack after processing

    public:
        CmdPL(const u32               _u32CmdID,
              const qString16         &_sCmdName,
              const enumCmdType       _eCmdType,
              shared_ptr<qLayerStack> _pPreLS,
              qProgress               *_pProgress);

        virtual ~CmdPL();

        shared_ptr<qLayerStack>&        GetPreLS();
        const shared_ptr<qLayerStack>&  GetPreLS() const;

        shared_ptr<qLayerStack>&        GetPostLS();
        const shared_ptr<qLayerStack>&  GetPostLS()const;

//        Dimension2D<s32>                Dimension() const       { return (m_pPostLayerStack != nullptr)?   m_pPostLayerStack->GetDimension() : qlMath::qlSize2D<s32>(0, 0); }
//        s32                             W() const               { return (m_pPostLayerStack != nullptr)?   m_pPostLayerStack->GetW() : 0; }
//        s32                             H() const               { return (m_pPostLayerStack != nullptr)?   m_pPostLayerStack->GetH() : 0; }

        // updates the given Image, creates a new one if neccessary or leaves it
        // unchanged if no changes done
//        void                            GetPreviewQImage(s32        _s32W,
//                              s32        _s32H,
//                              QImage     *&_pImage) const;


    /*******************************************************************************
    * interface of Cmd
    *******************************************************************************/
    public:
        virtual bool                    Prepare() override;
        virtual bool                    Undo() override;
        virtual bool                    Redo() override;
}; // class CmdPL
