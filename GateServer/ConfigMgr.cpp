#include "ConfigMgr.h"
#include "const.h"

ConfigMgr::ConfigMgr() {
    // 获取当前工作目录
    boost::filesystem::path current_path = boost::filesystem::current_path();
    // 构建config.ini文件的完整路径
    boost::filesystem::path config_path = current_path / "config.ini";

    // 使用Boost.PropertyTree来读取INI文件
    boost::property_tree::ptree pt;
    boost::property_tree::read_ini(config_path.string(), pt);
    //遍历ini文件加载所有配置项
    for (const auto &section_pair : pt) {
        const std::string &section_name = section_pair.first;
        const boost::property_tree::ptree &section_tree = section_pair.second;
        //每个section遍历存储所有kv对
        std::map<std::string, std::string> section_config;
        for (const auto &kv_pair : section_tree) {
            const std::string &key = kv_pair.first;
            const std::string &value = kv_pair.second.get_value<std::string>();
            section_config[key] = value;
        }
        SectionInfo sectioninfo;
        sectioninfo._section_datas = section_config;
        _config_map[section_name] = sectioninfo;
    }
    // 输出所有的section和key-value对
    for (const auto &section_entry : _config_map) {
        const std::string &section_name = section_entry.first;
        SectionInfo section_config = section_entry.second;
        std::cout << "[" << section_name << "]" << std::endl;
        for (const auto &key_value_pair : section_config._section_datas) {
            std::cout << key_value_pair.first << "=" << key_value_pair.second << std::endl;
        }
    }
}