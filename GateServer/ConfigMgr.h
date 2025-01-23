#pragma once
#include "const.h"

//用来管理key和value
/*
config_map

section
[GateServer]   
port=8080      sectioninfo:key-value

section
[VarifyServer]
port=50051
*/
struct SectionInfo {
    SectionInfo() {}
    ~SectionInfo() { _section_datas.clear(); }
    SectionInfo &operator=(const SectionInfo &src) {
        if (&src == this) {
            return *this;
        }
        this->_section_datas = src._section_datas;
        return *this;
    }
    std::map<std::string, std::string> _section_datas;
    std::string operator[](const std::string &key) {
        if (_section_datas.find(key) == _section_datas.end()) {
            return "";
        }
        return _section_datas[key];
    }
};
//用configmgr管理section和其包含的key与value
class ConfigMgr {
private:
    //存储section和key-value对的map
    std::map<std::string, SectionInfo> _config_map;

private:
    ConfigMgr();

public:
    ~ConfigMgr() { _config_map.clear(); }
    SectionInfo operator[](const std::string &section) {
        if (_config_map.find(section) == _config_map.end()) {
            return SectionInfo();
        }
        return _config_map[section];
    }

    ConfigMgr &operator=(const ConfigMgr &src) {
        if (&src == this) {
            return *this;
        }
        this->_config_map = src._config_map;
    }

    static ConfigMgr &Inst() {
        //局部静态变量生命周期是和进程同步的，但是可见范围只在这个局部作用域
        //局部静态变量只在第一次初始化，其他时候用共有的这一份
        static ConfigMgr cfg_mgr;
        return cfg_mgr;
    }
};
