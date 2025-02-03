#include "MySqlMgr.h"

MySqlMgr::~MySqlMgr() {
}

MySqlMgr::MySqlMgr() {
}

int MySqlMgr::RegUser(const std::string &name, const std::string &email, const std::string &pwd) {
    return _dao.RegUser(name, email, pwd);
}

bool MySqlMgr::CheckEmail(const std::string &name, const std::string &email) {
    return _dao.CheckEmail(name, email);
}

bool MySqlMgr::UpdatePwd(const std::string &name, const std::string &pwd) {
    return _dao.UpdatePwd(name, pwd);
}

bool MySqlMgr::CheckPwd(const std::string &email, const std::string &pwd, UserInfo &userInfo) {
    return _dao.CheckPwd(email, pwd, userInfo);
}