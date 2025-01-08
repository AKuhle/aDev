/*******************************************************************************
* \file qUniquePtrList.inl
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


namespace qLib
{
    /*******************************************************************************
    * qUniquePtrDeque<T>::GetAndPopBack
    *******************************************************************************/
    template <typename T>
    std::unique_ptr<T> qUniquePtrDeque<T>::GetAndPopBack()
    {
        std::unique_ptr<T>  p = std::move(back());
        pop_back();

        return p;
    } // qUniquePtrDeque<T>::GetAndPopBack


    /*******************************************************************************
    * qUniquePtrDeque<T>::GetAndPopFront
    *******************************************************************************/
    template <typename T>
    std::unique_ptr<T> qUniquePtrDeque<T>::GetAndPopFront()
    {
        std::unique_ptr<T>  p = std::move(front());
        pop_front();

        return p;
    } // qUniquePtrDeque<T>::GetAndPopFront

} // namespace qLib
