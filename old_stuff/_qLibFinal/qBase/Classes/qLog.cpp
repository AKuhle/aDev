/*******************************************************************************
* \file qLog.cpp
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
#include "qLog.h"
#include "qString16.h"

using namespace std;


namespace qLib
{
    /*******************************************************************************
    * qLog::Error
    *******************************************************************************/
    void qLog::Error(const char *_pError)
    {
        SetColor(enumCoutColor::red);

        cout << _pError;

        SetNormColor();
        cout << endl;
    } // qLog::Error


    // /*******************************************************************************
    // * qLog::Log
    // *******************************************************************************/
    void qLog::Log(const char *_pFunction)
    {
        CoutFunc(_pFunction);
        SetNormColor();
        cout << endl;
    } // qLog::Log


    // /*******************************************************************************
    // * qLog::Log
    // *******************************************************************************/
    // void qLog::Log(const char       *_pFunction,
    //                enumCoutColor   _eCoutColor,
    //                const char      *_pText)
    // {
    //     CoutFunc(_pFunction);

    //     SetColor(_eCoutColor);

    //     cout << _pText;

    //     SetNormColor();

    //     cout << endl;
    // } // qLog::Log


    // /*******************************************************************************
    // * qLog::Log
    // *******************************************************************************/
    // void qLog::Log(const char       *_pFunction,
    //                enumCoutColor    _eCoutColor,
    //                const char       *_pText,
    //                u64              _u64Value)
    // {
    //     CoutFunc(_pFunction);

    //     SetColor(_eCoutColor);
    //     cout << _pText << " = " << _u64Value;

    //     SetNormColor();
    //     cout << endl;
    // } // qLog::Log


    // /*******************************************************************************
    // * qLog::Log
    // *******************************************************************************/
    // void qLog::Log(const char       *_pFunction,
    //                enumCoutColor    _eCoutColor,
    //                const char       *_pText,
    //                void             *_pAdress)
    // {
    //     CoutFunc(_pFunction);

    //     SetColor(_eCoutColor);

    //     SetColor(_eCoutColor);
    //     cout << _pText << " = " << _pAdress;

    //     SetNormColor();
    //     cout << endl;
    // } // qLog::Log


    // /*******************************************************************************
    // * qLog::Log
    // *******************************************************************************/
    // void qLog::Log(const char       *_pFunction,
    //                enumCoutColor    _eCoutColor,
    //                const char       *_pText1,
    //                u64              _u64Value1,
    //                const char       *_pText2,
    //                u64              _u64Value2)
    // {
    //     CoutFunc(_pFunction);

    //     SetColor(_eCoutColor);

    //     SetColor(_eCoutColor);
    //     cout << _pText1 << " = " << _u64Value1 << ", "
    //          << _pText2 << " = " << _u64Value2;

    //     SetNormColor();
    //     cout << endl;
    // } // qLog::Log


    /*******************************************************************************
    * qLog::Log
    *******************************************************************************/
    void qLog::Log(enumCoutColor   _eCoutColor,
                   const qString16 &_sText)
    {
        SetColor(_eCoutColor);

        cout << _sText;

        SetNormColor();
        cout << endl;
    } // qLog::Log


    /*******************************************************************************
    * qLog::Log
    *******************************************************************************/
    void qLog::Log(enumCoutColor   _eCoutColor,
                   const qString16 &_sText,
                   s32             _s32Value)
    {
        SetColor(_eCoutColor);

        cout << _sText << _s32Value;

        SetNormColor();
        cout << endl;
    } // qLog::Log


    /*******************************************************************************
    * qLog::Log
    *******************************************************************************/
    void qLog::Log(enumCoutColor   _eCoutColor,
                   const qString16 &_sText1,
                   s32             _s32Value1,
                   const qString16 &_sText2,
                   s32             _s32Value2)
    {
        SetColor(_eCoutColor);

        cout << _sText1 << _s32Value1 << _sText2 << _s32Value2;

        SetNormColor();
        cout << endl;
    } // qLog::Log


    // /*******************************************************************************
    // * qLog::SetColor
    // *******************************************************************************/
    // void qLog::LogQuad(enumCoutColor   _eCoutColor,
    //                    const qString16 &_sText,
    //                    s32             _s32_1,
    //                    s32             _s32_2,
    //                    s32             _s32_3,
    //                    s32             _s32_4)
    // {
    //     SetColor(_eCoutColor);

    //     cout << _sText << " ("
    //          << _s32_1 << ", "
    //          << _s32_2 << ", "
    //          << _s32_3 << ", "
    //          << _s32_4 << ")";

    //     SetNormColor();
    //     cout << endl;
    // } // qLog::Log


    /*******************************************************************************
    * qLog::SetColor
    *******************************************************************************/
    void qLog::SetColor(enumCoutColor    _eCoutColor)
    {
        // e.g. blue: ":\033[34m";

        cout <<"\033[" << (int) (_eCoutColor) << "m";
    } // qLog::SetColor


    /*******************************************************************************
    * qLog::SetNormColor
    *******************************************************************************/
    void qLog::SetNormColor()
    {
        // normal: "\033[0m";

        cout << "\033[0m";
    } // qLog::SetNormColor


    // /*******************************************************************************
    // * qLog::CoutFunc
    // *******************************************************************************/
    void qLog::CoutFunc(const char      *_pFunction)
    {
        SetColor(enumCoutColor::blue);

        cout << _pFunction << ": ";
    } // qLog::CoutFunc

} // namespace qLib
