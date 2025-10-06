/*******************************************************************************
* \file Scene.cpp
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


/*******************************************************************************
* includes
*******************************************************************************/
#include "scene.h"
#include "universe.h"



/*******************************************************************************
* Scene::Scene
*******************************************************************************/
Scene::Scene(const QString  &_sName)
: m_sName(_sName)
{
} // Scene::Scene


/*******************************************************************************
* Scene::~Scene
*******************************************************************************/
Scene::~Scene()
{
} // Scene::~Scene


/*******************************************************************************
* Scene::addUniverses
*******************************************************************************/
void Scene::addUniverses(const list<shared_ptr<Universe>>  &_lstUniverse)
{
    for (auto pUniverse : _lstUniverse)
    {
        UniverseTuple tup = std::make_tuple(pUniverse, pUniverse->dmxData());
        m_lstUniverse.push_back(tup);
    }
} // Scene::addUniverses
