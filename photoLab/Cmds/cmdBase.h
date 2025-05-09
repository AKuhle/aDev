/*******************************************************************************
* \file CmdBase .h
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
#include "aCmdThread.h"
#include "layerStack.h"

using namespace aLib::aUtil;
using namespace aLib::aPic;


/*******************************************************************************
* class CmdBase
*******************************************************************************/
class CmdBase  : public aCmdThread
{
    protected:
        shared_ptr<SynchronizedLS> m_pPreLS;       // layer stack before processing
        shared_ptr<SynchronizedLS> m_pPostLS;      // layer stack after processing


    public:
        CmdBase(const u32                   _u32ID,
                const aString               &_sName,
                const enumCmdType           _eType,
                shared_ptr<SynchronizedLS>  _pPreLS,
                aProgressCb                 *_pProgressCb);

        virtual ~CmdBase();

        shared_ptr<SynchronizedLS>&         preLS();
        const shared_ptr<SynchronizedLS>&   preLS() const;

        shared_ptr<SynchronizedLS>&         postLS();
        const shared_ptr<SynchronizedLS>&   postLS()const;

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
        bool                            prepare() override;
        bool                            undo() override;
        bool                            redo() override;
}; // class CmdBase
