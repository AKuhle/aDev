/*******************************************************************************
* \file Scene.h
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
#include "aFrame_def.h"

#include <QByteArray>
#include <QString>

using namespace std;

class Universe;



/*******************************************************************************
* class Scene
*******************************************************************************/
class Scene
{
    private:
        QString                 m_sName;
        shared_ptr<Universe>    m_pUniverse;
        QByteArray              m_dmxData;

    public:
        Scene(const QString   &_sName);

        ~Scene();

        QString                 name() const        { return m_sName; }

        shared_ptr<Universe>    universe() const    { return m_pUniverse; }

        const QByteArray&       dmxData() const     { return m_dmxData; }

        void                    addUniverse(shared_ptr<Universe>    _pUniverse,
                                            const QByteArray        &_dmxData);
}; // class Scene
