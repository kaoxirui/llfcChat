#include "MySqlPool.h"
#include "Singleton.h"

class MySqlDao;

class MySqlMgr : public Singleton<MySqlMgr> {
    friend class Singleton;

public:
    ~MySqlMgr();
    int RegUser(const std::string &name, const std::string &email, const std::string &pwd);
    bool CheckEmail(const std::string &name, const std::string &email);
    bool UpdatePwd(const std::string &name, const std::string &newpwd);
    bool CheckPwd(const std::string &name, const std::string &pwd, UserInfo &userInfo);

private:
    MySqlMgr();

private:
    MySqlDao _dao;
};