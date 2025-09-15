/*******************************************************************************
* includes
*******************************************************************************/
#include "ui_mainWin.h"
#include "mainWin.h"

using namespace std;


/*******************************************************************************
* MainWin::MainWin
*******************************************************************************/
MainWin::MainWin(QWidget *parent)
: QMainWindow(parent),
  m_pUi(new Ui::MainWin)
{
    m_pUi->setupUi(this);

    // connect the items
    connect(m_pUi->m_pActionOpenFile, &QAction::triggered, this, &MainWin::onFileOpen);
    connect(m_pUi->m_pActionSaveFile, &QAction::triggered, this, &MainWin::onFileSave);

    connect(m_pUi->m_pActionController, &QAction::triggered, this, &MainWin::onController);
    connect(m_pUi->m_pActionUniverse, &QAction::triggered, this, &MainWin::onUniverse);


    unique_ptr<Controller>  pController = make_unique<Controller> ("Showtec NET-2/3 POCKET", "192.168.1.245");
    m_lstController.push_back(std::move(pController));
} // MainWin::MainWin


/*******************************************************************************
* MainWin::~MainWin
*******************************************************************************/
MainWin::~MainWin()
{
    delete m_pUi;
} // MainWin::~MainWin

