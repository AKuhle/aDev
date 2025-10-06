/*******************************************************************************
* \file aJsonFile.h
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

#ifdef _USE_QT_

/*******************************************************************************
* includes
*******************************************************************************/
#include "aFrame_def.h"
#include "aPath.h"
#include <nlohmann/json.hpp>


/*******************************************************************************
* namespace
*******************************************************************************/
namespace aFrame {
namespace aUtil {


/*******************************************************************************
* class aJsonFile
*******************************************************************************/
class aJsonValue;


struct Value;
using Object = std::map<std::string, Value>;

struct Value : std::variant<int,
                            double,
                            std::string,
                            std::vector<u8>,
                            std::vector<std::string>,
                            Object>
{
    using variant::variant;
};


/*******************************************************************************
* class aJsonFile
*******************************************************************************/
class aJsonFile
{
    private:
        Object                          m_root;


    public:
        aJsonFile();
        virtual ~aJsonFile();


    // add members
    public:
        void                            addValue(const aString  &_sKey,
                                                 bool           _bValue);

        void                            addValue(const aString  &_sKey,
                                                 int            _iValue);

        void                            addValue(const aString  &_sKey,
                                                 double         _dValue);

        void                            addValue(const aString  &_sKey,
                                                 const aString  &_sValue);

        void                            addValue(const aString          &_sKey,
                                                 const std::vector<u8>  &_vValue);

        void                            addValue(const aString              &_sKey,
                                                 const std::vector<aString> &_vValue);

        // read members
    public:
        bool                            readBoolValue(const aString &_sKey) const;

        int                             readIntValue(const aString &_sKey) const;

        double                          readDoubleValue(const aString &_sKey) const;

        aString                         readStringValue(const aString &_sKey) const;

        //std::vector<u8>                 readVectorU8(const aString &_sKey) const;

        std::vector<aString>            readVectorString(const aString &_sKey) const;


    // read/write the file
    public:
        bool                            writeJsonFile(const aPath &_sPath) const;

        bool                            readJsonFile(const aPath &_sPath);


    // helper
    private:
        static std::vector<std::string> splitKey(const std::string &_key);

        Value*                          getOrCreate(std::vector<std::string> &_vKeys);

        const Value*                    getValue(const std::vector<std::string> &_vKeys) const;

        void                            writeJson(std::ostream  & os,
                                                  const Value   &value,
                                                  int           indent = 0) const;
}; // class aJsonFile


} // namespace aUtil
} // namespace aFrame


#endif // _USE_QT_
